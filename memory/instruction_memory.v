module InstructionMemory(
    input wire[0:0] clk,
    input wire[31:0] read_idx,
    output reg[31:0] read_data
);
    reg[31:0] mem[128:0];
    integer fd, i;

    always @ (read_idx) begin
        read_data = mem[read_idx[9:2]];
    end

    initial begin
        fd = $fopen("gcd.bin","rb");
        i = $fread(mem, fd);
        $fclose(fd);
    end
endmodule
