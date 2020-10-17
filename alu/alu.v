module ALU (
    input [0:0] clk,
    input [31:0] a,
    input [31:0] b,
    input [2:0] op,
    input [0:0] mod,    // Modifier: used for arithmetic shift
    output reg [31:0] res
);
    localparam ADD  = 'h0;
    localparam SLL  = 'h1;
    localparam SLT  = 'h2;
    localparam SLTU = 'h3;
    localparam XOR  = 'h4;
    localparam SR   = 'h5;
    localparam OR   = 'h6;
    localparam AND  = 'h7;

    always @ (posedge clk) begin
        case (op)
            ADD: res = a + b;
            SLL: res = a << b;
            SLT: res = $signed(a) < $signed(b);
            SLTU: res = a < b;
            XOR: res = a ^ b;
            SR: res = (mod) ? (a >>> b) : (a >> b);
            OR: res = a | b;
            AND: res = a & b;
        endcase
        $display("ALU: %h -> %h (%h %h)", op, res, a, b);
    end
endmodule