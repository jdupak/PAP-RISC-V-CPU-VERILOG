module ProgramCounter(
    input Clock clk,
    input Bool stall,
    input Bool jump_enable,
    input Addr jump_address,
    output Addr address_out,
    output Addr next_address_out
);
    AddrReg pc = 'b0;

    assign next_address_out = pc + 'd4;
    assign address_out = pc;
    
    always @ (posedge clk) begin
        pc <= (jump_enable) ? jump_address : next_address_out;
        // $display("====================================================");
        // $display("PC: 0x%h [jump=%h]", (jump_enable) ? jump_address : next_address_out, jump_enable);
    end

endmodule
