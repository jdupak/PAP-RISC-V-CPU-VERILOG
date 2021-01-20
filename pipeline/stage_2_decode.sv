module Stage2Decode (
    input  Clock       clk,
    input  Bool        discard,
    input  Data        instruction,
    input  Addr        pc,
    input  Bool        write_enable,
    input  RegId       write_idx,
    input  Data        write_data,
    output ALUOpReg    alu_op_out = 'b0,
    output DataReg     rs1_val_out = 'b0,
    output DataReg     rs2_val_out = 'b0,
    output DataReg     imm_out = 'b0,
    output BoolReg     use_imm_out = FALSE,
    output RegIdReg    rd_idx_out = 'b0,
    output BoolReg     alu_op_mod_out = FALSE,
    output BoolReg     mem_load_enable_out = FALSE,
    output BoolReg     mem_store_enable_out = FALSE,
    output BoolReg     jump_enable_out = FALSE,
    output BoolReg     branch_enable_out = FALSE,
    output BoolReg     reg_write_enable_out = FALSE,
    output AddrReg     jump_address_out = 'b0,
    output Bool        should_stall_s1_out,
    output BoolReg     fwd1_enable_out,
    output BoolReg     fwd2_enable_out,
    output DebugStatus debug_out = OK
);
  Data rs1_val_wire, rs2_val_wire;
  DecodeOutput decoded;
  Bool fwd1_enable_wire, fwd2_enable_wire;

  Decode decode (
      .instruction(instruction),
      .decoded_out(decoded)
  );

  GPRegisterFile gpr (
      .clk            (clk),
      .read_idx_1     (decoded.alu_rs1),
      .read_idx_2     (decoded.alu_rs2),
      .write_enable   (write_enable),
      .write_idx      (write_idx),
      .write_data     (write_data),
      .read_data_1_out(rs1_val_wire),
      .read_data_2_out(rs2_val_wire)
  );

  Bool should_stall;
  Bool is_hazard;

  HazardUnit hz (
      .clk      (clk),
      .rs1      (decoded.alu_rs1),
      .rs2      (decoded.alu_rs2),
      .rd       ((discard || ~decoded.reg_write) ? 5'd0 : decoded.alu_rd),
      .pc       (pc),
      .stall_out(is_hazard),
      .fwd1_enable_out  (fwd1_enable_wire),
      .fwd2_enable_out  (fwd2_enable_wire)
  );

  assign should_stall = is_hazard | discard;
  assign should_stall_s1_out = is_hazard;

  always @(posedge clk) begin
    alu_op_out <= (should_stall) ? ADD : decoded.alu_op;
    rs1_val_out <= (should_stall) ? 'b0 : ((decoded.alu_rs1_pc) ? pc : rs1_val_wire);
    rs2_val_out <= (should_stall) ? 'b0 : ((decoded.alu_rs2_neg) ? -rs2_val_wire : rs2_val_wire);
    imm_out <= decoded.imm;
    use_imm_out <= (should_stall) ? FALSE : decoded.alu_use_imm;
    rd_idx_out <= (should_stall) ? 'b0 : decoded.alu_rd;
    alu_op_mod_out <= (should_stall) ? FALSE : decoded.alu_op_mod;
    jump_address_out <= pc + $signed(decoded.imm);
    jump_enable_out <= (should_stall) ? FALSE : decoded.jump_enable;
    branch_enable_out <= (should_stall) ? FALSE : decoded.branch_enable;
    reg_write_enable_out <= (should_stall) ? FALSE : decoded.reg_write;
    mem_load_enable_out <= (should_stall) ? FALSE : decoded.mem_load;
    mem_store_enable_out <= (should_stall) ? FALSE : decoded.mem_store;
    fwd1_enable_out <= (should_stall) ? FALSE : fwd1_enable_wire;
    fwd2_enable_out <= (should_stall) ? FALSE : fwd2_enable_wire;
    debug_out <= (should_stall) ? OK : decoded.debug;

    if (should_stall) $display("STALL");
  end
endmodule
