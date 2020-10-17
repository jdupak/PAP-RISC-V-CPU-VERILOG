module GPRegisterFile(
    input [0:0] clk,
    input [4:0] read_idx_1,
    input [4:0] read_idx_2,
    input [4:0] write_idx,
    input [31:0] write_data,
    input [0:0] write_enable,
    output reg [31:0] read_data_1,
    output reg [31:0] read_data_2
);
    reg [31:0] gp[31:0];

    initial gp[0] = 'b10;
    initial gp[1] = 'b01;

    always @ (posedge clk) begin
//        $display("GP %d %d %d %d %d", read_idx_1, read_idx_2, write_idx, write_enable, write_data);
        if (write_enable & (write_data != 'b0))
            gp[write_idx] <= write_data;
        read_data_1 = gp[read_idx_1];
        read_data_2 = gp[read_idx_2];
    end
endmodule