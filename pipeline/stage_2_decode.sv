module Stage2Decode (
    input  Clock       clk,
    input  Bool        stall,
    input  Data        instruction,
    input  Data        pc,
    input  Bool        write_enable,
    input  RegId       write_idx,
    input  Data        write_data,
    output ALUOpReg    alu_op = 'b0,
    output DataReg     rs1_val = 'b0,
    output DataReg     rs2_val = 'b0,
    output DataReg     imm = 'b0,
    output BoolReg     use_imm = FALSE,
    output RegIdReg    rd_idx = 'b0,
    output BoolReg     alu_op_mod = FALSE,
    output BoolReg     mem_load_enable = FALSE,
    output BoolReg     mem_store_enable = FALSE,
    output BoolReg     jump_enable = FALSE,
    output BoolReg     branch_enable = FALSE,
    output BoolReg     reg_write_enable = FALSE,
    output AddrReg     jump_address = 'b0,
    output DebugStatus debug = OK
);
  RegId rs1_idx, rs2_idx;
  Bool rs1_use_pc, rs2_neg;
  Data rs1_val_wire, rs2_val_wire;

  DecodeOutput decoded;

  Decode decode (
      .instruction(instruction),
      .decoded_out(decoded)
  );


  GPRegisterFile gpr (
      .clk         (clk),
      .read_idx_1  (decoded.alu_rs1),
      .read_idx_2  (decoded.alu_rs2),
      .read_data_1 (rs1_val_wire),
      .read_data_2 (rs2_val_wire),
      .write_enable(write_enable),
      .write_idx   (write_idx),
      .write_data  (write_data)
  );

  always @(negedge clk) begin
    alu_op <= (stall) ? alu_op : decoded.alu_op;
    rs1_val <= (stall) ? rs1_val : ((decoded.alu_rs1_pc) ? pc : rs1_val_wire);
    rs2_val <= (stall) ? rs2_val : ((decoded.alu_rs2_neg) ? -$signed(rs2_val_wire) : rs2_val_wire);
    imm <= (stall) ? imm : decoded.imm;
    use_imm <= (stall) ? use_imm : decoded.alu_use_imm;
    rd_idx <= (stall) ? rd_idx : decoded.alu_rd;
    alu_op_mod <= (stall) ? alu_op_mod : decoded.alu_op_mod;
    jump_address <= (stall) ? jump_address : pc + $signed(decoded.imm);
    jump_enable <= (stall) ? jump_enable : decoded.jump_enable;
    branch_enable <= (stall) ? branch_enable : decoded.branch_enable;
    reg_write_enable <= (stall) ? reg_write_enable : decoded.reg_write;
    mem_load_enable <= (stall) ? mem_load_enable : decoded.mem_load;
    mem_store_enable <= (stall) ? mem_store_enable : decoded.mem_store;
    debug <= (stall) ? debug : decoded.debug;
  end
endmodule
