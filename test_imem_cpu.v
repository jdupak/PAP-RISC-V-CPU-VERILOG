module test();
    reg[0:0] clk;

    wire[31:0] pc_address;
    ProgramCounterLinear pc(clk, pc_address);

    wire[31:0] instruction;
    InstructionMemory imem(clk, pc_address, instruction);

    wire[4:0] read_idx_1, read_idx_2, write_idx;
    wire[31:0] write_data, read_data_1, read_data_2;
    wire[0:0] write_enable = 1;
    GPRegisterFile gpr(clk, read_idx_1, read_idx_2, write_idx, write_data,
        write_enable, read_data_1, read_data_2);

    wire[31:0] imm;
    wire[2:0] op;
    wire[0:0] use_imm, mod, neg;
    wire[1:0] debug;
    Decode decode(clk, instruction, op, read_idx_1, read_idx_2, write_idx,
        use_imm, neg, imm, debug);

    AluWrapped alu(clk, read_data_1, read_data_2, imm, use_imm, op, mod, neg, write_data);

    initial begin
        clk = 0;
    end

    always #100 clk = ~clk;

    always @ (debug) begin
        case (debug)
            'b01: begin
                $display("Breakpoint reached");
                $stop;
             end
            'b10: begin
                $display("Illegal instruction - teminating");
                $finish;
             end
        endcase
    end
endmodule