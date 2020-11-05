module test();
    reg[0:0] clk;

    wire[31:0] pc_address;

    wire[31:0] instruction;

    wire[4:0] read_idx_1, read_idx_2, write_idx;
    wire[31:0] write_data, read_data_1, read_data_2;

    wire[31:0] imm;
    wire[2:0] op;
    wire[0:0] use_imm, mod, neg;
    wire[1:0] debug;
    wire[0:0] load_enable;
    wire[0:0] store_enable;
    wire[0:0] write_enable;
    wire[0:0] jump_enable;
    wire[0:0] jump_take;

    wire[0:0] alu_rs1_pc;
    wire[0:0] alu_res_neg;
    wire[31:0] alu_res;

    wire[31:0] load_data;
    wire[31:0] jump_address;

    assign write_data = load_enable ? load_data : alu_res;
    assign jump_address = pc_address + $signed(imm);
    assign jump_take = jump_enable & (write_enable | ((alu_res == 0) ^ alu_res_neg)); // JAL writes, BRANCH does not

    ProgramCounter pc(clk, jump_take, jump_address, pc_address);
    InstructionMemory imem(clk, pc_address, instruction);
    Decode decode(clk, instruction, op, read_idx_1, read_idx_2, write_idx,
        use_imm, alu_rs1_pc, neg, alu_res_neg, imm, load_enable, store_enable, write_enable, jump_enable, debug);
    GPRegisterFile gpr(clk, read_idx_1, read_idx_2, write_idx, write_data,
        write_enable, read_data_1, read_data_2);
    AluWrapped alu(clk, read_data_1, read_data_2, imm, use_imm, alu_rs1_pc, pc_address, op, mod, neg, alu_res);
    DataMemory dmem(clk, alu_res, read_data_2, store_enable, load_data);

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