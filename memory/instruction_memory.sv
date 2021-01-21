module InstructionMemory (
    input  Addr address,
    output Addr instruction_out
);
  DataReg mem[128:0];
  integer fd, i;

  assign instruction_out = mem[address[9:2]];

  initial begin
    fd = $fopen("gcd.bin", "rb");
    i = $fread(mem, fd);
    $fclose(fd);
  end
endmodule
