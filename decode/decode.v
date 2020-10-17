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
    output reg [1:0]    debug
);
    localparam OP =     'b01100;
    localparam OP_IMM = 'b00100;
    localparam SYSTEM = 'b11100;

    localparam OK     = 'b00;
    localparam BREAK  = 'b01;
    localparam FAIL   = 'b10;

    reg [6:0] opcode, funct7;
    reg [2:0] funct3;
    reg [4:0] rs1, rs2, rd;
    reg [0:0] imm_sign;
    reg [31:0] I_imm, S_imm, U_imm, B_imm, J_imm;

    always @ (instruction) begin
        opcode   = instruction[6:2];       // Assuming only 32bit instruction support
        rd       = instruction[11:7];
        funct3   = instruction[14:12];
        rs1      = instruction[19:15];
        rs2      = instruction[24:20];
        funct7   = instruction[31:25];
        imm_sign = instruction[31];
        I_imm    = {{20{imm_sign}}, funct7, rs2};
        S_imm    = {{20{imm_sign}}, funct7, rd};
        U_imm    = {{12{imm_sign}}, funct7, rs2, rs1, funct3};
        B_imm    = {{19{imm_sign}}, imm_sign, instruction[7], instruction[30:25], instruction[11:8]};
        J_imm    = {{12{imm_sign}}, imm_sign, rs1, funct3, instruction[20], instruction[30:21]};

        case (opcode)
            OP: begin
                alu_op = funct3;
                alu_rs1 = rs1;
                alu_rs2 = rs2;
                alu_rd = rd;
                alu_rs2_neg = (funct3 == 'b0 && funct7 == 'd32); // Subtraction
                alu_use_imm = 0;
                debug = OK;
                // Assign garbage to imm?
                $display("AluOp %h x=%b %h", funct3, alu_rs2_neg, alu_use_imm);
            end
            OP_IMM: begin
                alu_op = funct3;
                alu_rs1 = rs1;
                alu_rs2 = rs2;
                alu_rd = rd;
                alu_rs2_neg = (funct3 == 'b0 && funct7 == 'd32); // Subtraction
                alu_use_imm = 1;
                imm = I_imm;
                debug = OK;
                $display("AluImmOp %h %h %h", rs1, rs2, rd);
            end
            SYSTEM: begin
                case ({funct7, rs2, rs1, funct3, rd})
                    32'b000000000001_00000_000_00000: debug = BREAK;
                    default: debug = FAIL;
                endcase
                $display("Sytem instruction invoked");
            end
            default: begin
                debug = FAIL;
                $display("Unknown instruction");
            end
        endcase
    end

endmodule