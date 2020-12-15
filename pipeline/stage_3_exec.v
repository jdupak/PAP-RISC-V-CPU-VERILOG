module Stage3Exec(
    input wire[0:0] clk,
    input wire[0:0] stall,
    input wire[2:0] alu_op,
    input wire[0:0] alu_op_modified,
    input wire[31:0] rs1_val,
    input wire[31:0] rs2_val,
    input wire[31:0] imm,
    input wire[0:0] use_imm,
    input wire[4:0] rd_idx,
    input wire[0:0] mem_write_enable, mem_read_enable, reg_write_enable,

    output reg[31:0] alu_res_out,
    output reg[31:0] rs2_val_out,
    output reg[4:0] rd_idx_out,
    output reg[0:0] mem_write_enable_out, mem_read_enable_out, reg_write_enable_out
);
    ALU alu(
        .a(rs1_val),
        .b((use_imm) ? imm : imm),
        .op(alu_op),
        .mod(alu_op_modified),
        .res(alu_res_out)
    );

    always @(posedge clk) begin
        rd_idx_out <= rd_idx;
        rs2_val_out <= rs2_val;
        rs2_val_out <= rs2_val;
        mem_read_enable_out <= mem_read_enable;
        mem_write_enable_out <= mem_write_enable;
    end
endmodule