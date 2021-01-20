module Stage3Exec (
    input Clock clk,
    input ALUOp alu_op,
    input Bool  alu_op_modified,
    input Data  rs1_val,
    input Data  rs2_val,
    input Data  imm,
    input Bool  use_imm,
    input RegId rd_idx,
    input Bool  mem_store_enable,
    input Bool  mem_load_enable,
    input Bool  reg_write_enable,
    input Bool  jump_enable,
    input Bool  branch_enable,
    input Bool  use_forwared_as_rs1,
    input Bool  use_forwared_as_rs2,
    input Addr  jump_address,
    input Data  forwarded_result,

    output DataReg  alu_res_out = 'b0,
    output DataReg  rs2_val_out = 'b0,
    output RegIdReg rd_idx_out = 'b0,
    output BoolReg  jump_enable_out = FALSE,
    output DataReg  jump_address_out = 'b0,
    output BoolReg  mem_store_enable_out = FALSE,
    output BoolReg  mem_load_enable_out = FALSE,
    output BoolReg  reg_write_enable_out = FALSE,
    output Bool     discard_out
);
  Data alu_res;

  ALU alu (
      .a      ((use_forwared_as_rs1) ? forwarded_result : rs1_val),
      .b      ((use_imm) ? imm : ((use_forwared_as_rs2) ? forwarded_result : rs2_val)),
      .op     (alu_op),
      .mod    (alu_op_modified),
      .res_out(alu_res)
  );

  // Flush pipeline as a result of branch misprediction.
  assign discard_out = (jump_enable || (branch_enable && (alu_op_modified ^ (alu_res == 'b0))));

  always @(posedge clk) begin
    rd_idx_out <= rd_idx;
    rs2_val_out <= rs2_val;
    mem_load_enable_out <= mem_load_enable;
    mem_store_enable_out <= mem_store_enable;
    reg_write_enable_out <= reg_write_enable;
    alu_res_out <= alu_res;
    jump_enable_out <= discard_out;
    jump_address_out <= jump_address;
  end
endmodule
