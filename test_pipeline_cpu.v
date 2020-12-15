module test();
    reg[0:0] clk;

    // 1 -> 2
    wire[31:0] intruction, pc, jump_address;
    wire[0:0] jump_enable;

    Stage1Fetch s1(
        .clk(clk),
        .stall('b0),
        // 1 -> 2
        .instruction(intruction),
        .next_address(pc),
        .jump_enable(jump_enable),
        .jump_address(jump_address)
    );

    // 2 -> 3
    wire[31:0] rs1_val, rs2_val, imm;
    wire[4:0] rd_idx;
    wire[2:0] alu_op;
    wire[0:0] use_imm, alu_rs2_neg, alu_res_neg, mem_load_enable,
              mem_write_enable, reg_write_enable;
    // 4 -> 2
    wire[31:0] write_data;
    wire[4:0] write_idx;
    wire[0:0] write_enable_42;
    wire[1:0] debug;

    Stage2Decode s2(
        .clk(clk),
        .stall('b0),
        // 1 -> 2
        .instruction(intruction),
        .pc(pc),
        // 2 -> 1
        .jump_address(jump_address),
        // 2 -> 3
        .alu_op(alu_op),
        .rs1_val(rs1_val),
        .rs2_val(rs2_val),
        .rd_idx(rd_idx),
        .imm(imm),
        .use_imm(use_imm),
        .alu_rs2_neg(alu_rs2_neg),
        .alu_res_neg(alu_res_neg),
        .mem_load_enable(mem_load_enable),
        .mem_write_enable(mem_write_enable),
        .reg_write_enable(reg_write_enable),
        .jump_enable(jump_enable),
        // 4 -> 2
        .write_data(write_data),
        .write_idx(write_idx),
        .write_enable(write_enable_42),

        .debug(debug)
    );

    // 3 -> 4
    wire[31:0] alu_res_34, rs2_val_34;
    wire[4:0] rd_idx_34;
    wire[0:0] mem_write_enable_34, mem_read_enable_34, reg_write_enable_34;

    Stage3Exec s3(
        .clk(clk),
        .stall('b0),
        // 2 -> 3
        .alu_op(alu_op),
        .rs1_val(rs1_val),
        .rs2_val(rs2_val),
        .imm(imm),
        .rd_idx(rd_idx),
        .alu_op_modified(alu_res_neg),
        .use_imm(use_imm),
        .mem_write_enable(mem_write_enable),
        .mem_read_enable(mem_load_enable),
        .reg_write_enable(reg_write_enable),
        // 3 -> 4
        .alu_res_out(alu_res_34),
        .rs2_val_out(rs2_val_34),
        .rd_idx_out(rd_idx_34),
        .reg_write_enable_out(mem_write_enable_34),
        .mem_read_enable_out(mem_read_enable_34),
        .mem_write_enable_out(reg_write_enable_34)
    );

    Stage4Mem s4(
        .clk(clk),
        .stall('b0),
        // 3 -> 4
        .alu_res(alu_res_34),
        .rs2_val(rs2_val_34),
        .rd_idx(rd_idx_34),
        .mem_write_enable(),
        .mem_read_enable(),
        .reg_write_enable(),
        // 4 -> 2
        .write_data_out(write_data),
        .write_idx_out(write_idx),
        .write_enable_out(write_enable_42)
    );

    initial begin
        clk = 0;
    end

    always #100 begin clk = ~clk; end

    always @ (debug) begin
        case (debug)
            'b01: begin
                $display("Breakpoint reached");
                $finish;
             end
            'b10: begin
                $display("Illegal instruction - teminating");
                $finish;
             end
        endcase
    end
endmodule