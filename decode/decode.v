module Decode(
    input [0:0]     clk,
    input  [31:0]   instruction,
    output reg [2:0]    alu_op,
    output reg [4:0]    alu_rs1,
    output reg [4:0]    alu_rs2,
    output reg [4:0]    alu_rd,
    output reg [0:0]    alu_use_imm,
    output reg [0:0]    alu_rs2_neg,
    output reg [31:0]   imm,
    output reg [0:0]    break,              // DEBUG
    output reg [0:0]    illegal_instruction // DEBUG
);
    localparam OP =     'b011;
    localparam OP_IMM = 'b001;

    wire [6:0] opcode =     instruction[6:2];       // Assuming only 32bit instruction support
    wire [4:0] rd =         instruction[11:7];
    wire [2:0] funct3 =     instruction[14:12];
    wire [4:0] rs1 =        instruction[19:15];
    wire [4:0] rs2 =        instruction[24:20];
    wire [6:0] funct7 =     instruction[31:25];
    wire [0:0] imm_sign =   instruction[31];
    wire [31:0] I_imm =     {{20{imm_sign}}, funct7, rs2};
    wire [31:0] S_imm =     {{20{imm_sign}}, funct7, rd};
    wire [31:0] U_imm =     {{12{imm_sign}}, funct7, rs2, rs1, funct3};
    wire [31:0] B_imm =     {{19{imm_sign}}, imm_sign, instruction[7], instruction[30:25], instruction[11:8]};
    wire [31:0] J_imm =     {{12{imm_sign}}, imm_sign, rs1, funct3, instruction[20], instruction[30:21]};

    always @ (posedge clk) begin
        case (opcode)
            OP: begin
                alu_op = funct3;
                alu_rs1 = rs1;
                alu_rs2 = rs2;
                alu_rd = rd;
                alu_rs2_neg = (funct3 == 'b0 && funct7 == 'd32); // Subtraction
                alu_use_imm = 0;
                illegal_instruction = 0;
                break = 0;
                // Assign garbage to imm?
//                $display("AluOp %h x=%b %h", funct3, alu_rs2_neg, alu_use_imm);
            end
            OP_IMM: begin
                alu_op = funct3;
                alu_rs1 = rs1;
                alu_rs2 = rs2;
                alu_rd = rd;
                alu_rs2_neg = (funct3 == 'b0 && funct7 == 'd32); // Subtraction
                alu_use_imm = 1;
                imm = I_imm;
                illegal_instruction = 0;
                break = 0;
                $display("AluImmOp %h %h %h", rs1, rs2, rd);
            end
            default: illegal_instruction = 'b1;
        endcase
    end

endmodule