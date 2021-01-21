module ProgramCounter(
    input Clock clk,
    input Bool stall,
    input Bool jump_enable,
    input Addr jump_address,
    output AddrReg pc_out = 'b0
);    
    always @ (negedge clk) begin
        pc_out <= (jump_enable) ? jump_address : (stall) ? pc_out : (pc_out + 'd4);
    end

endmodule
