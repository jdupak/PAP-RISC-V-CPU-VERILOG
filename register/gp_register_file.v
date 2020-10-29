module GPRegisterFile(
    input [0:0] clk,
    input [4:0] read_idx_1,
    input [4:0] read_idx_2,
    input [4:0] write_idx,
    input [31:0] write_data,
    input [0:0] write_enable,
    output [31:0] read_data_1,
    output [31:0] read_data_2
);
    reg [31:0] gp[31:0];

    initial gp[0] = 'b0;
    initial gp[1] = 'b1;
    initial gp[2] = 'b1;

    assign read_data_1 = gp[read_idx_1];
    assign read_data_2 = gp[read_idx_2];

    always @ (posedge clk) begin
        if (write_enable) begin
            if (write_idx != 0) gp[write_idx] <= write_data;
            $display("REG: r1=%h r2=%h w[%d]=%h", gp[1], gp[2], write_idx, write_data);
        end
    end
endmodule