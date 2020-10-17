module InstructionMemory(
    input wire[0:0] clk,
    input wire[31:0] read_idx,
    output reg[31:0] read_data
);
    reg[31:0] mem[128:0];

    always @ (read_idx) begin
        read_data = mem[read_idx[31:2]];

        $display("Read from instruction memory: %b_%b_%b_%b_%b_%b (at 0x%h, idx: %d)",
            read_data[31:25], read_data[24:20], read_data[19:15], read_data[14:12],
            read_data[11:7], read_data[6:0], read_idx, read_idx[31:2]);
    end

    initial begin
        mem[0] = 32'b0000000_00010_00001_000_00001_0010011;
        mem[1] = 32'b0000000_00010_00001_000_00001_0010011;
        mem[2] = 32'b0000000_00010_00001_000_00001_0010011;
        mem[3] = 32'b0000000_00010_00001_000_00001_0010011;
        mem[4] = 32'b0000000_00010_00001_000_00001_0010011;
        mem[5] = 32'b0000000_00010_00001_000_00001_0010011;
        mem[6] = 32'b0000000_00010_00001_000_00001_0010011;
        mem[7] = 32'b0000000_00001_00000_000_00000_1110011; // BREAK
    end
endmodule
