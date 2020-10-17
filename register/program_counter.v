module ProgramCounterLinear(
    input [0:0] clk,
    output [31:0] address
);
    reg [31:0] current;

    assign address = current;

    always @ (posedge clk) begin
        current = current + 'd4;
    end
endmodule