module AluWrapped(
    input [0:0] clk,
    input [31:0] rs1_val,
    input [31:0] rs2_val,
    input [31:0] imm,
    input [0:0]  use_imm,
    input [0:0]  alu_rs1_pc,
    input [31:0] pc,
    input [2:0] op,
    input [0:0] mod,    // Modifier: used for arithmetic shift
    input [0:0] operand_2_neg,
    output [31:0] res
);
    wire[31:0] operand_2;
    assign operand_2 = use_imm ? imm : rs2_val;

    ALU alu(
        clk,
        alu_rs1_pc ? pc + 4 : rs1_val,
        operand_2_neg ? -operand_2 : operand_2,
        op,
        mod,
        res
    );
endmodule