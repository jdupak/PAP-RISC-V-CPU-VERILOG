module Decode(
    input [0:0]        clk,
    input [31:0]       instruction,
    output reg[2:0]    alu_op,
    output reg[4:0]    alu_rs1,
    output reg[4:0]    alu_rs2,
    output reg[4:0]    alu_rd,
    output reg[0:0]    alu_use_imm,
    output reg[0:0]    alu_rs1_pc,
    output reg[0:0]    alu_rs2_neg,
    output reg[0:0]    alu_res_neg,
    output reg[31:0]   imm,
    output reg[0:0]    mem_load,
    output reg[0:0]    mem_store,
    output reg[0:0]    write_enable,
    output reg[0:0]    jump_enable,
    output reg [1:0]   debug
);
    localparam OP =     'b01100;
    localparam OP_IMM = 'b00100;
    localparam SYSTEM = 'b11100;
    localparam LOAD   = 'b00000;
    localparam STORE  = 'b01000;
    localparam JAL    = 'b11011;
    localparam BRANCH = 'b11000;

    localparam OK     = 'b00;
    localparam BREAK  = 'b01;
    localparam FAIL   = 'b10;

    localparam NONE   = 'bx;

    reg[4:0] opcode;
    reg[6:0] funct7;
    reg[2:0] funct3;
    reg[4:0] rs1, rs2, rd;
    reg[0:0] imm_sign;
    reg[31:0] I_imm, S_imm, U_imm, B_imm, J_imm;

    initial begin
        alu_op = 'b00;
        alu_rs1 = 'b0;
        alu_rs2 = 'b0;
        alu_rd = 'b0;
        alu_use_imm = 0;
        alu_rs1_pc = 0;
        alu_rs2_neg = 0;
        alu_res_neg = 0;
        imm = NONE;
        mem_load = 0;
        mem_store = 0;
        write_enable = 0;
        jump_enable = 0;
        debug = OK;
    end

    always @ (instruction) begin
        $display("Instruction: %b_%b_%b_%b_%b_%b",
            instruction[31:25], instruction[24:20],
            instruction[19:15], instruction[14:12],
            instruction[11:7], instruction[6:0]);

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
        B_imm    = {{20{imm_sign}}, imm_sign, instruction[7], instruction[30:25], instruction[11:8]};
        J_imm    = {{13{imm_sign}}, rs1, funct3, instruction[20], instruction[30:21]};

        case (opcode)
            OP: begin
                alu_rs1 = rs1;
                alu_rs2 = rs2;
                alu_rd = rd;
                alu_op = funct3;
                alu_use_imm = 0;
                alu_rs1_pc = 0;
                alu_rs2_neg = (funct3 == 'b0 && funct7 == 'd32); // Subtraction
                imm = NONE;
                mem_load = 0;
                mem_store = 0;
                write_enable = 1;
                jump_enable = 0;
                debug = OK;
                $display("DEC: ALURegOp %h (%h <= %h %h)", funct3, rd, rs1, rs2);
            end
            OP_IMM: begin
                alu_rs1 = rs1;
                alu_rs2 = 'b0;
                alu_rd = rd;
                alu_op = funct3;
                alu_use_imm = 1;
                alu_rs1_pc = 0;
                alu_rs2_neg = (funct3 == 'b0 && funct7 == 'd32); // Subtraction
                alu_res_neg = 0;
                imm = I_imm;
                mem_load = 0;
                mem_store = 0;
                write_enable = 1;
                jump_enable = 0;
                debug = OK;
                $display("DEC: ALUImmOp %h (%h <= %h %h)", funct3, rd, rs1, I_imm);
            end
            LOAD: begin
                alu_rs1 = rs1;
                alu_rs2 = 'b0;
                alu_rd = rd;
                alu_op = 'h0;
                alu_use_imm = 1;
                alu_rs1_pc = 0;
                alu_rs2_neg = 0;
                alu_res_neg = 0;
                imm = I_imm;
                mem_load = 1;
                mem_store = 0;
                write_enable = 1;
                jump_enable = 0;
                debug = OK;
                $display("DEC: Load %h => %h+%h", rd, rs1, I_imm);
            end
            STORE: begin
                alu_rs1 = rs1;
                alu_rs2 = rs2;
                alu_rd = rd;
                alu_op = 'h0;
                alu_use_imm = 1;
                alu_rs1_pc = 0;
                alu_rs2_neg = 0;
                alu_res_neg = 0;
                imm = S_imm;    // Offset to rs1
                mem_load = 0;
                mem_store = 1;
                write_enable = 0;
                jump_enable = 0;
                debug = OK;
                $display("DEC: Store %h => %h+%h", rs2, rs1, I_imm);
            end
            JAL: begin
                alu_rs1 = 'b0;
                alu_rs2 = 'b0;
                alu_rd = rd;
                alu_op = 'h4;
                alu_use_imm = 0;
                alu_rs1_pc = 1;
                alu_rs2_neg = 0;
                alu_res_neg = 0;
                imm = J_imm << 1;
                mem_load = 0;
                mem_store = 0;
                write_enable = 1;
                jump_enable = 1;
                debug = OK;
                $display("DEC: Jump %h, %d", imm, $signed(imm));
            end
            BRANCH: begin
                alu_rs1 = rs1;
                alu_rs2 = rs2;
                alu_rd = NONE;
                alu_op = {1'b0, funct3[2:1]};
                alu_rs2_neg = ~funct3[2];
                alu_res_neg = funct3[0];
                alu_use_imm = 0;
                alu_rs1_pc = 0;
                imm = B_imm;
                mem_load = 0;
                mem_store = 0;
                write_enable = 0;
                jump_enable = 1;
                debug = OK;
                $display("DEC: Branch");
            end
            SYSTEM: begin
                alu_rs1 = 'b0;
                alu_rs2 = 'b0;
                alu_rd = 'b0;
                alu_rs1_pc = 0;
                alu_res_neg = 0;
                write_enable = 0;
                jump_enable = 0;
                case ({funct7, rs2, rs1, funct3, rd})
                    25'b0000000_00001_00000_000_00000: debug = BREAK;
                    default: debug = FAIL;
                endcase
                $display("DEC: System instruction invoked");
            end
            default: begin
                alu_rs1 = 'b0;
                alu_rs2 = 'b0;
                alu_rd = 'b0;
                alu_rs1_pc = 0;
                alu_res_neg = 0;
                write_enable = 0;
                jump_enable = 0;
                debug = FAIL;
                $display("DEC: Unknown instruction");
            end
        endcase
    end

endmodule