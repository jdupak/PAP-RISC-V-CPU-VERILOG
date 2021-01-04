module ProgramCounter(
    input [0:0] clk,
    input [0:0] jump_enable,
    input [31:0] jump_address,
    output wire[31:0] address_out,
    output wire[31:0] next_address_out
);
    reg [31:0] pc = 'b0;
    assign next_address_out = pc + 'd4;
    assign address_out = pc;

    always @ (posedge clk) begin
        pc <= (jump_enable) ? jump_address : next_address_out;
        $display("====================================================");
        $display("PC: 0x%h [jump=%h]", (jump_enable) ? jump_address : next_address_out, jump_enable);
    end

endmodule
