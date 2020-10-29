module ProgramCounter(
    input [0:0] clk,
    input [31:0] jump_address,
    input [0:0] jump_enable,
    output reg[31:0] address
);
    initial address = 'b0;

    always @ (posedge clk) begin
        address <= (jump_enable) ? jump_address : address + 'd4;

        $display("====================================================");
        $display("PC: 0x%h", address);
    end

endmodule
