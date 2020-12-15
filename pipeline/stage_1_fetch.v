module Stage1Fetch(
    input wire[0:0] clk,
    input wire[0:0] stall,
    input wire[0:0] jump_enable,
    input wire[31:0] jump_address,
    output reg[31:0] instruction,
    output reg[31:0] next_address
);
    wire [31:0] address;

    ProgramCounter pc(
        .clk(clk),
        .jump_enable(jump_enable),
        .jump_address(jump_address),
        .address(address),
        .next_address(next_address)
    );

    InstructionMemory imem(
        .address(address),
        .instruction(instruction)
    );

endmodule
