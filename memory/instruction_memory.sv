module InstructionMemory(
    input wire[31:0] address,
    output wire[31:0] instruction_out
);
    reg[31:0] mem[128:0];
    integer fd, i;

    assign instruction_out = mem[address[9:2]];

    initial begin
        fd = $fopen("gcd.bin","rb");
        i = $fread(mem, fd);
        $fclose(fd);
    end
endmodule
