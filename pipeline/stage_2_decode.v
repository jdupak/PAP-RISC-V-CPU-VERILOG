module Stage2Decode(
    input wire[0:0] clk,
    input wire[0:0] stall,
    input wire[31:0] instruction,
    input wire[31:0] pc,
    input wire[0:0] write_enable,
    input wire[4:0] write_idx,
    input wire[31:0] write_data,
    output reg[2:0] alu_op,
    output reg[31:0] rs1_val,
    output reg[31:0] rs2_val,
    output reg[31:0] imm,
    output reg[0:0] use_imm,
    output reg[4:0] rd_idx,
    output reg[0:0] alu_rs2_neg, alu_res_neg, mem_load_enable,
                    mem_write_enable, jump_enable, reg_write_enable,
    output reg[31:0] jump_address,
    output wire[1:0] debug
);
    wire[4:0] rs1_idx, rs2_idx;
    wire[0:0] rs1_use_pc, rs2_neg;
    wire[31:0] rs1_reg_val;

    always @(posedge clk) begin
        rs1_val <= (rs1_use_pc) ? pc : rs1_reg_val;
        jump_address <= pc;
    end

    Decode decode(
        ._instruction(instruction),
        .alu_op(alu_op),
        .alu_rs1(rs1_idx),
        .alu_rs2(rs2_idx),
        .alu_rd(rd_idx),
        .alu_use_imm(use_imm),
        .alu_rs1_pc(rs1_use_pc),
        .alu_rs2_neg(rs2_neg),
        .alu_res_neg(alu_res_neg),
        .imm(imm),
        .mem_load(mem_load_enable),
        .mem_store(mem_write_enable),
        .write_enable(reg_write_enable),
        .jump_enable(jump_enable),
        .debug(debug)
    );

    GPRegisterFile gpr(
        .clk(clk),
        .read_idx_1(rs1_idx),
        .read_idx_2(rs2_idx),
        .read_data_1(rs1_reg_val),
        .read_data_2(rs2_val),
        .write_enable(write_enable),
        .write_idx(write_idx),
        .write_data(write_data)
    );
endmodule