module Stage4Mem(
    input wire[0:0] clk,
    input wire[0:0] stall,
    input wire[31:0] alu_res,
    input wire[31:0] rs2_val,
    input wire[4:0] rd_idx,
    input wire[0:0] mem_read_enable,
    input wire[0:0] mem_write_enable,
    input wire[0:0] reg_write_enable,

    output reg[0:0] write_enable_out,
    output reg[4:0] write_idx_out,
    output reg[31:0] write_data_out
);
    wire[31:0] mem_read_data;

    DataMemory dmem(
        .clk(clk),
        .read_data(mem_read_data),
        .write_enable(mem_write_enable),
        .write_data(rs2_val),
        .idx(alu_res)
    );

    always @(posedge clk) begin
        write_enable_out <= reg_write_enable;
        write_idx_out <= rd_idx;
        write_data_out <= (mem_read_enable) ? mem_read_data : alu_res;
    end
endmodule