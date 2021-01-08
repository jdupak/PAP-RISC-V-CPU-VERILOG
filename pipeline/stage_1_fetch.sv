module Stage1Fetch(
    input Clock clk,
    input Bool stall,
    input Bool jump_enable,
    input Addr jump_address,
    output InstrReg instruction_out = `NOP,
    output AddrReg next_address_out = 'b0
);
    Addr address, next_address_wire;
    Instr intruction_wire;

    ProgramCounter pc(
        .clk(clk),
        .stall(stall),
        .jump_enable(jump_enable),
        .jump_address(jump_address),
        .address_out(address),
        .next_address_out(next_address_wire)
    );

    InstructionMemory imem(
        .address(address),
        .instruction_out(intruction_wire)
    );

    always @(posedge clk) begin
        instruction_out <= (stall) ? instruction_out : intruction_wire;
        next_address_out <= (stall) ? next_address_out : next_address_wire;
    end

endmodule
