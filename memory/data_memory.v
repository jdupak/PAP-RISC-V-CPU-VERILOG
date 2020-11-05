module DataMemory(
    input wire[0:0] clk,
    input wire[31:0] idx,
    input wire[31:0] write_data,
    input wire[0:0] write_enable,
    output wire[31:0] read_data
);
    reg[31:0] mem[128:0];

    assign read_data = mem[idx[9:2]];

    initial begin
        mem[1] = 'd15;
        mem[2] = 'd96;
    end

    always @ (posedge clk) begin
        if (write_enable == 1) begin
            mem[idx[9:2]] <= write_data;
            $display("MEM: write [%h]=%h", idx, write_data);
         end
    end
endmodule
