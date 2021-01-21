module PipelineCPU (
    input  Clock       clk,
    output DebugStatus debug
);
  // 1 -> 2
  Instr intruction_12;
  Addr next_address_12;
  // 3 -> 1
  Bool jump_enable_31;
  Addr jump_address_31;
  Bool discard;
  // 2 -> 1
  Bool should_stall_s1;

  Stage1Fetch s1 (
      .clk            (clk),
      .stall          (should_stall_s1),
      .discard        (discard),
      // 1 -> 2
      .instruction_out(intruction_12),
      .pc_out         (next_address_12),
      .jump_enable    (jump_enable_31),
      .jump_address   (jump_address_31)
  );

  // 2 -> 3
  wire Data rs1_val_23, rs2_val_23, imm_23;
  wire RegId rd_idx_23;
  wire ALUOp alu_op_23;
  wire Bool use_imm_23, alu_op_mod_23, mem_load_enable_23, mem_store_enable_23, reg_write_enable_23,
      branch_enable_23, jump_enable_23, fwd1_enable_23, fwd2_enable_23, rs2_neg_23;
  wire Addr jump_address_23;
  // 4 -> 2
  wire Data write_data_42;
  wire RegId write_idx_42;
  wire Bool write_enable_42;

  Stage2Decode s2 (
      .clk                 (clk),
      .discard             (discard),
      // 1 -> 2
      .instruction         (intruction_12),
      .pc                  (next_address_12),
      // 2 -> 3
      .alu_op_out          (alu_op_23),
      .rs1_val_out         (rs1_val_23),
      .rs2_val_out         (rs2_val_23),
      .rd_idx_out          (rd_idx_23),
      .imm_out             (imm_23),
      .use_imm_out         (use_imm_23),
      .alu_op_mod_out      (alu_op_mod_23),
      .mem_load_enable_out (mem_load_enable_23),
      .mem_store_enable_out(mem_store_enable_23),
      .reg_write_enable_out(reg_write_enable_23),
      .jump_enable_out     (jump_enable_23),
      .branch_enable_out   (branch_enable_23),
      .jump_address_out    (jump_address_23),
      .fwd1_enable_out     (fwd1_enable_23),
      .fwd2_enable_out     (fwd2_enable_23),
      .rs2_neg             (rs2_neg_23),
      // 4 -> 2
      .write_data          (write_data_42),
      .write_idx           (write_idx_42),
      .write_enable        (write_enable_42),

      .debug_out          (debug),
      .should_stall_s1_out(should_stall_s1)
  );

  // 3 -> 4
  wire Data alu_res_34, rs2_val_34;
  wire RegId rd_idx_34;
  wire Bool mem_store_enable_34, mem_load_enable_34, reg_write_enable_34;

  Stage3Exec s3 (
      .clk(clk),
      // 2 -> 3
      .alu_op(alu_op_23),
      .rs1_val(rs1_val_23),
      .rs2_val(rs2_val_23),
      .imm(imm_23),
      .rd_idx(rd_idx_23),
      .alu_op_modified(alu_op_mod_23),
      .use_imm(use_imm_23),
      .reg_write_enable(reg_write_enable_23),
      .mem_load_enable(mem_load_enable_23),
      .mem_store_enable(mem_store_enable_23),
      .jump_enable(jump_enable_23),
      .jump_address(jump_address_23),
      .branch_enable(branch_enable_23),
      .use_forwared_as_rs1(fwd1_enable_23),
      .use_forwared_as_rs2(fwd2_enable_23),
      .rs2_neg(rs2_neg_23),
      // 3 -> 4
      .alu_res_out(alu_res_34),
      .rs2_val_out(rs2_val_34),
      .rd_idx_out(rd_idx_34),
      .reg_write_enable_out(reg_write_enable_34),
      .mem_load_enable_out(mem_load_enable_34),
      .mem_store_enable_out(mem_store_enable_34),
      .jump_enable_out(jump_enable_31),
      .jump_address_out(jump_address_31),
      // 3 -> 1+2
      // Flush pipeline before, jump mispredicted.
      // The is no branch predictor at this moment, all branches are not taken.
      .discard_out(discard),
      // 4 -> 3
      .forwarded_result(write_data_42
          )  // Write is intented in stage 2, I am only spying on this wire.
  );

  Stage4Mem s4 (
      .clk             (clk),
      // 3 -> 4
      .alu_res         (alu_res_34),
      .rs2_val         (rs2_val_34),
      .rd_idx          (rd_idx_34),
      .reg_write_enable(reg_write_enable_34),
      .mem_load_enable (mem_load_enable_34),
      .mem_store_enable(mem_store_enable_34),
      // 4 -> 2
      .write_enable_out(write_enable_42),
      .write_idx_out   (write_idx_42),
      .write_data_out  (write_data_42)
  );
endmodule
