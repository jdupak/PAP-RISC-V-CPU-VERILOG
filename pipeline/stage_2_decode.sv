module Stage2Decode (
    input  Clock       clk,
    input  Data        instruction,
    input  Data        pc,
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
    output DebugStatus debug_out = OK
);
  Data rs1_val_wire, rs2_val_wire;
  DecodeOutput decoded;

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

  always @(posedge clk) begin
    alu_op_out <= decoded.alu_op;
    rs1_val_out <= (decoded.alu_rs1_pc) ? pc : rs1_val_wire;
    rs2_val_out <= (decoded.alu_rs2_neg) ? -rs2_val_wire : rs2_val_wire;
    imm_out <= decoded.imm;
    use_imm_out <= decoded.alu_use_imm;
    rd_idx_out <= decoded.alu_rd;
    alu_op_mod_out <= decoded.alu_op_mod;
    jump_address_out <= pc + $signed(decoded.imm) - 'd4; //
    jump_enable_out <= decoded.jump_enable;
    branch_enable_out <= decoded.branch_enable;
    reg_write_enable_out <= decoded.reg_write;
    mem_load_enable_out <= decoded.mem_load;
    mem_store_enable_out <= decoded.mem_store;
    debug_out <= decoded.debug;
  end
endmodule
