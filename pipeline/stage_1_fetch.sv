module Stage1Fetch(
    input wire[0:0] clk,
    input wire[0:0] stall,
    input wire [0:0] jump_enable,
    input wire[31:0] jump_address,
    output reg[31:0] instruction = 'b0,
    output reg[31:0] next_address = 'b0
);
    wire [31:0] address, intruction_wire, next_address_wire;

    ProgramCounter pc(
        .clk(clk),
        .jump_enable(jump_enable),
        .jump_address(jump_address),
        .address_out(address),
        .next_address_out(next_address_wire)
    );

    InstructionMemory imem(
        .address(address),
        .instruction_out(intruction_wire)
    );

    always @(negedge clk) begin
        instruction <= (stall) ? instruction : intruction_wire;
        next_address <= (stall) ? next_address : next_address_wire;
    end

endmodule
