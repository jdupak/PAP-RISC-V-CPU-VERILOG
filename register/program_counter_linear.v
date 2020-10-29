module ProgramCounterLinear(
    input [0:0] clk,
    output reg[31:0] address
);
    initial begin
        address = 'b0;
        $display("PC: 0x%h", address);
    end

    always @ (posedge clk) begin
        address <= address + 'd4;
        $display("====================================================");
        $display("PC: 0x%h", address + 'd4);
    end
endmodule

