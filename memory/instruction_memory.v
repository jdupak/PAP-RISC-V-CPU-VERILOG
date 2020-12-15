module InstructionMemory(
    input wire[31:0] address,
    output wire[31:0] instruction
);
    reg[31:0] mem[128:0];
    integer fd, i;

    assign instruction = mem[address[9:2]];

    initial begin
        fd = $fopen("gcd.bin","rb");
        i = $fread(mem, fd);
        $fclose(fd);
    end
endmodule
