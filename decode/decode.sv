module Decode(
    input Instr            instruction,
    output DecodeOutput    decoded_out
);    
    // Byteswap to fit specification description
    assign decoded_out = decode(parse(byteswap(instruction)));
endmodule

function bit[31:0] byteswap(input bit[31:0] x);
    byteswap = {x[7:0], x[15:8], x[23:16], x[31:24]};
endfunction

function ParsedInstruction parse(input Instr intruction);
    parse.opcode   = intruction[6:2];       // Assuming only 32bit instruction support
    parse.rd       = intruction[11:7];
    parse.funct3   = intruction[14:12];
    parse.rs1      = intruction[19:15];
    parse.rs2      = intruction[24:20];
    parse.funct7   = intruction[31:25];
    parse.imm_sign = intruction[31];
    parse.I_imm    = {{20{parse.imm_sign}}, parse.funct7, parse.rs2};
    parse.S_imm    = {{20{parse.imm_sign}}, parse.funct7, parse.rd};
    parse.U_imm    = {{12{parse.imm_sign}}, parse.funct7, parse.rs2, parse.rs1, parse.funct3};
    parse.B_imm    = {{20{parse.imm_sign}}, parse.imm_sign, intruction[7], intruction[30:25], intruction[11:8]};
    parse.J_imm    = {{13{parse.imm_sign}}, parse.rs1, parse.funct3, intruction[20], intruction[30:21]};
endfunction

function DecodeOutput decode(input ParsedInstruction i);
    decode = 60'bx;

    case (i.opcode)
        OP: begin
            decode.alu_rs1 = i.rs1;
            decode.alu_rs2 = i.rs2;
            decode.alu_rd = i.rd;
            decode.alu_op = i.funct3;
            decode.alu_use_imm = FALSE;
            decode.alu_rs1_pc = FALSE;
            decode.alu_rs2_neg = (i.funct3 == 'b0 && i.funct7 == 'd32); // Subtraction
            decode.alu_op_mod = FALSE;
            decode.imm = `NONE;
            decode.mem_load = FALSE;
            decode.mem_store = FALSE;
            decode.reg_write = TRUE;
            decode.jump_enable = FALSE;
            decode.debug = OK;
            $display("DEC: ALURegOp %h (%h <= %h %h)", i.funct3, i.rd, i.rs1, i.rs2);
        end
        OP_IMM: begin
            decode.alu_rs1 = i.rs1;
            decode.alu_rs2 = 'b0;
            decode.alu_rd = i.rd;
            decode.alu_op = i.funct3;
            decode.alu_use_imm = TRUE;
            decode.alu_rs1_pc = FALSE;
            decode.alu_rs2_neg = (i.funct3 == 'b0 && i.funct7 == 'd32); // Subtraction
            decode.alu_op_mod = FALSE;
            decode.imm = i.I_imm;
            decode.mem_load = FALSE;
            decode.mem_store = FALSE;
            decode.reg_write = TRUE;
            decode.jump_enable = FALSE;
            decode.debug = OK;
            $display("DEC: ALUImmOp %h (%h <= %h %h)", i.funct3, i.rd, i.rs1, i.I_imm);
        end
        LOAD: begin
            decode.alu_rs1 = i.rs1;
            decode.alu_rs2 = 'b0;
            decode.alu_rd = i.rd;
            decode.alu_op = 'h0;
            decode.alu_use_imm = TRUE;
            decode.alu_rs1_pc = FALSE;
            decode.alu_rs2_neg = FALSE;
            decode.alu_op_mod = FALSE;
            decode.imm = i.I_imm;
            decode.mem_load = TRUE;
            decode.mem_store = FALSE;
            decode.reg_write = TRUE;
            decode.jump_enable = FALSE;
            decode.debug = OK;
            $display("DEC: Load %h => %h+%h", i.rd, i.rs1, i.I_imm);
        end
        STORE: begin
            decode.alu_rs1 = i.rs1;
            decode.alu_rs2 = i.rs2;
            decode.alu_rd = i.rd;
            decode.alu_op = 'h0;
            decode.alu_use_imm = TRUE;
            decode.alu_rs1_pc = FALSE;
            decode.alu_rs2_neg = FALSE;
            decode.alu_op_mod = FALSE;
            decode.imm = i.S_imm;    // Offset to rs1
            decode.mem_load = FALSE;
            decode.mem_store = TRUE;
            decode.reg_write = FALSE;
            decode.jump_enable = FALSE;
            decode.debug = OK;
            $display("DEC: Store %h => %h+%h", i.rs2, i.rs1, i.I_imm);
        end
        JAL: begin
            decode.alu_rs1 = 'b0;
            decode.alu_rs2 = 'b0;
            decode.alu_rd = i.rd;
            decode.alu_op = 'h4;
            decode.alu_use_imm = FALSE;
            decode.alu_rs1_pc = TRUE;
            decode.alu_rs2_neg = FALSE;
            decode.alu_op_mod = FALSE;
            decode.imm = i.J_imm << 1;
            decode.mem_load = FALSE;
            decode.mem_store = FALSE;
            decode.reg_write = TRUE;
            decode.jump_enable = TRUE;
            decode.debug = OK;
            $display("DEC: Jump %h, %d", i.J_imm, $signed(i.J_imm));
        end
        BRANCH: begin
            decode.alu_rs1 = i.rs1;
            decode.alu_rs2 = i.rs2;
            decode.alu_rd = 'h0;
            decode.alu_op = {1'b0, i.funct3[2:1]};
            decode.alu_rs2_neg = ~i.funct3[2];
            decode.alu_op_mod = i.funct3[0];
            decode.alu_use_imm = FALSE;
            decode.alu_rs1_pc = FALSE;
            decode.imm = i.B_imm << 1;
            decode.mem_load = FALSE;
            decode.mem_store = FALSE;
            decode.reg_write = FALSE;
            decode.jump_enable = TRUE;
            decode.debug = OK;
            $display("DEC: Branch by %h", $signed(i.B_imm << 1));
        end
        SYSTEM: begin
            decode.alu_rs1 = 'b0;
            decode.alu_rs2 = 'b0;
            decode.alu_rd = 'b0;
            decode.alu_rs1_pc = FALSE;
            decode.alu_op_mod = FALSE;
            decode.reg_write = FALSE;
            decode.jump_enable = FALSE;
            case ({i.funct7, i.rs2, i.rs1, i.funct3, i.rd})
                25'b0000000_00001_00000_000_00000: decode.debug = BREAK;
                default: decode.debug = FAIL;
            endcase
            $display("DEC: System instruction invoked");
        end
        default: begin
            decode.alu_rs1 = 'b0;
            decode.alu_rs2 = 'b0;
            decode.alu_rd = 'b0;
            decode.alu_rs1_pc = FALSE;
            decode.alu_op_mod = FALSE;
            decode.reg_write = FALSE;
            decode.jump_enable = FALSE;
            decode.debug = FAIL;
            $display("DEC: Unknown instruction");
        end
    endcase
endfunction