module Stage1Fetch(
    input Clock clk,
    input Bool stall,
    input Bool jump_enable,
    input Addr jump_address,
    output InstrReg instruction_out = `NOP,
    output AddrReg pc_out = 'b0
);
    Addr pc_wire;
    Instr intruction_wire;

    ProgramCounter pc(
        .clk(clk),
        .stall(stall),
        .jump_enable(jump_enable),
        .jump_address(jump_address),
        .pc_out(pc_wire)
    );

    InstructionMemory imem(
        .address(pc_wire),
        .instruction_out(intruction_wire)
    );

    always @(posedge clk) begin
        instruction_out <= intruction_wire;
        pc_out <= pc_wire;
    end

endmodule
