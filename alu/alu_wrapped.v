module AluWrapped(
    input [0:0] clk,
    input [31:0] rs1_val,
    input [31:0] rs2_val,
    input [31:0] imm,
    input [0:0]  use_imm,
    input [2:0] op,
    input [0:0] mod,    // Modifier: used for arithmetic shift
    input [0:0] operand_2_neg,
    output [31:0] res
);
    reg[31:0] operand_2;

    always @ (posedge clk) operand_2 = use_imm ? imm : rs2_val;

    ALU alu(
        clk,
        rs1_val,
        operand_2_neg ? -operand_2 : operand_2,
        op,
        mod,
        res
    );
endmodule