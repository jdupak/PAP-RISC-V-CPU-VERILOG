module ProgramCounter(
    input [0:0] clk,
    input [0:0] jump_enable,
    input [31:0] jump_address,
    output reg[31:0] address
);
    initial begin
        address = 'b0;
        $display("PC: 0x%h", address);
    end

    always @ (posedge clk) begin
        address <= (jump_enable) ? jump_address : address + 'd4;

        $display("====================================================");
        $display("PC: 0x%h [jump=%h]", (jump_enable) ? jump_address : address + 'd4, jump_enable);
    end

endmodule
