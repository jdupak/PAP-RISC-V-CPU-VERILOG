module test();
    reg [0:0] clk;
    reg [31:0] instruction;
    wire [31:0] imm;
    wire [0:0] use_imm;
    wire [2:0] op;
    wire [0:0] mod;
    wire [0:0] neg;
    wire [4:0] void;


    wire [4:0] read_idx_1;
    wire [4:0] read_idx_2;
    wire [4:0] write_idx;
    wire [31:0] write_data;
    wire [0:0] write_enable;
    wire [31:0] read_data_1;
    wire [31:0] read_data_2;

    GPRegisterFile gpr(clk, read_idx_1, read_idx_2, write_idx, write_data, 'b1, read_data_1, read_data_2);
    AluWrapped alu(clk, read_data_1, read_data_2, imm, use_imm, op, mod, neg, write_data);
    Decode decode(clk, instruction, op, read_idx_1, read_idx_2, write_idx, use_imm, neg, imm, void[0:0], void[0:0]);

    initial begin
        instruction = 32'b0000000_00010_00001_000_00001_0010000;
        clk = 0;
    end

    always #100 clk = ~clk;

endmodule