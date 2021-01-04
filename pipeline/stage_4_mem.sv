module Stage4Mem(
    input Clock clk,
    input Bool stall,
    input Data alu_res,
    input Data rs2_val,
    input RegId rd_idx,
    input Bool mem_load_enable,
    input Bool mem_store_enable,
    input Bool reg_write_enable,

    output BoolReg write_enable_out = FALSE,
    output RegIdReg write_idx_out = 'b0,
    output DataReg write_data_out = 'b0
);
    Data mem_read_data;

    DataMemory dmem(
        .clk(clk),
        .write_enable(mem_store_enable),
        .write_data(rs2_val),
        .idx(alu_res),
        .read_data_out(mem_read_data)
    );

    always @(negedge clk) begin
        // TODO stall
        write_enable_out <= reg_write_enable;
        write_idx_out <= rd_idx;
        write_data_out <= (mem_load_enable) ? mem_read_data : alu_res;
    end
endmodule