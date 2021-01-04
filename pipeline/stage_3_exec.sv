module Stage3Exec(
    input Clock clk,
    input Bool stall,
    input ALUOp alu_op,
    input Bool alu_op_modified,
    input Data rs1_val,
    input Data rs2_val,
    input Data imm,
    input Bool use_imm,
    input RegId rd_idx,
    input Bool mem_store_enable, mem_load_enable, reg_write_enable,

    output DataReg alu_res_out = 'b0,
    output DataReg rs2_val_out = 'b0,
    output RegIdReg rd_idx_out = 'b0,
    output BoolReg mem_store_enable_out, mem_load_enable_out, reg_write_enable_out
);
    Data alu_res;

    ALU alu(
        .a(rs1_val),
        .b((use_imm) ? imm : imm),
        .op(alu_op),
        .mod(alu_op_modified),
        .res_out(alu_res)
    );

    always @(negedge clk) begin
        rd_idx_out <= (stall) ? rd_idx_out : rd_idx;
        rs2_val_out <= (stall) ? rs2_val_out : rs2_val;
        mem_load_enable_out <= (stall) ? mem_load_enable_out : mem_load_enable;
        mem_store_enable_out <= (stall) ? mem_store_enable_out : mem_store_enable;
        reg_write_enable_out <= (stall) ? reg_write_enable_out : reg_write_enable;
        alu_res_out <= (stall) ? alu_res_out : alu_res;
    end
endmodule