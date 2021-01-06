typedef bit [31:0] Data;
typedef reg [31:0] DataReg;
typedef bit [0:0] Clock;
typedef bit [31:0] Addr;
typedef reg [31:0] AddrReg;
typedef bit [31:0] Instr;
typedef reg [31:0] InstrReg;
typedef bit [4:0] RegId;
typedef reg [4:0] RegIdReg;

enum bit [4:0] {
  OP = 'b01100,
  OP_IMM = 'b00100,
  SYSTEM = 'b11100,
  LOAD = 'b00000,
  STORE = 'b01000,
  JAL = 'b11011,
  BRANCH = 'b11000
} Opcode;

typedef enum bit [2:0] {
  ADD = 'h0,
  SLL = 'h1,
  SLT = 'h2,
  SLTU = 'h3,
  XOR = 'h4,
  SR = 'h5,
  OR = 'h6,
  AND = 'h7
} ALUOp;

typedef bit [2:0] ALUOpReg;

typedef enum bit [1:0] {
  OK = 2'b00,
  BREAK = 2'b01,
  FAIL = 2'b10
} DebugStatus;

typedef enum bit [0:0] {
  FALSE = 1'b0,
  TRUE = 1'b1
} Bool;

typedef reg [0:0] BoolReg;

typedef struct packed {
  ALUOp alu_op;
  RegId alu_rs1;
  RegId alu_rs2;
  RegId alu_rd;
  Bool alu_use_imm;
  Bool alu_rs1_pc;
  Bool alu_rs2_neg;
  Bool alu_op_mod;
  Data imm;
  Bool mem_load;
  Bool mem_store;
  Bool reg_write;
  Bool jump_enable;
  Bool branch_enable;
  DebugStatus debug;
} DecodeOutput;

`define NONE 'bx

typedef struct packed {
  bit [4:0] opcode;
  bit [6:0] funct7;
  bit [2:0] funct3;
  bit [4:0] rs1, rs2, rd;
  bit [0:0] imm_sign;
  bit [31:0] I_imm, S_imm, U_imm, B_imm, J_imm;
} ParsedInstruction;

module test ();
  reg Clock clk;

  // 1 -> 2
  wire Instr intruction_12;
  wire Addr next_address_12;
  // 3 -> 1
  wire Bool jump_enable_31;
  wire Addr jump_address_31;

  Stage1Fetch s1 (
      .clk         (clk),
      .stall       (1'b0),
      // 1 -> 2
      .instruction (intruction_12),
      .next_address(next_address_12),
      .jump_enable (jump_enable_31),
      .jump_address(jump_address_31)
  );

  // 2 -> 3
  wire Data rs1_val_23, rs2_val_23, imm_23;
  wire RegId rd_idx_23;
  wire ALUOp alu_op_23;
  wire Bool use_imm_23, alu_op_mod_23, mem_load_enable_23, mem_store_enable_23,
      reg_write_enable_23, branch_enable_23;
  wire Addr jump_address_23;
  // 4 -> 2
  wire Data write_data_42;
  wire RegId write_idx_42;
  wire Bool write_enable_42;

  wire DebugStatus debug;

  Stage2Decode s2 (
      .clk             (clk),
      .stall           (1'b0),
      // 1 -> 2
      .instruction     (intruction_12),
      .pc              (next_address_12),
      // 2 -> 3
      .alu_op          (alu_op_23),
      .rs1_val         (rs1_val_23),
      .rs2_val         (rs2_val_23),
      .rd_idx          (rd_idx_23),
      .imm             (imm_23),
      .use_imm         (use_imm_23),
      .alu_op_mod      (alu_op_mod_23),
      .mem_load_enable (mem_load_enable_23),
      .mem_store_enable(mem_store_enable_23),
      .reg_write_enable(reg_write_enable_23),
      .jump_enable     (jump_enable_23),
      .branch_enable   (branch_enable_23),
      .jump_address    (jump_address_23),
      // 4 -> 2
      .write_data      (write_data_42),
      .write_idx       (write_idx_42),
      .write_enable    (write_enable_42),

      .debug(debug)
  );

  // 3 -> 4
  wire Data alu_res_34, rs2_val_34;
  wire RegId rd_idx_34;
  wire Bool mem_store_enable_34, mem_load_enable_34, reg_write_enable_34;

  Stage3Exec s3 (
      .clk                 (clk),
      .stall               (1'b0),
      // 2 -> 3
      .alu_op              (alu_op_23),
      .rs1_val             (rs1_val_23),
      .rs2_val             (rs2_val_23),
      .imm                 (imm_23),
      .rd_idx              (rd_idx_23),
      .alu_op_modified     (alu_op_mod_23),
      .use_imm             (use_imm_23),
      .reg_write_enable    (reg_write_enable_23),
      .mem_load_enable     (mem_load_enable_23),
      .mem_store_enable    (mem_store_enable_23),
      .jump_enable         (jump_enable_23),
      .jump_address        (jump_address_23),
      .branch_enable       (branch_enable_23),
      // 3 -> 4
      .alu_res_out         (alu_res_34),
      .rs2_val_out         (rs2_val_34),
      .rd_idx_out          (rd_idx_34),
      .reg_write_enable_out(reg_write_enable_34),
      .mem_load_enable_out (mem_load_enable_34),
      .mem_store_enable_out(mem_store_enable_34),
      .jump_enable_out     (jump_enable_31),
      .jump_address_out    (jump_address_31)
  );

  Stage4Mem s4 (
      .clk             (clk),
      .stall           (1'b0),
      // 3 -> 4
      .alu_res         (alu_res_34),
      .rs2_val         (rs2_val_34),
      .rd_idx          (rd_idx_34),
      .reg_write_enable(reg_write_enable_34),
      .mem_load_enable (mem_load_enable_34),
      .mem_store_enable(mem_store_enable_34),
      // 4 -> 2
      .write_enable_out(write_enable_42),
      .write_idx_out   (write_idx_42),
      .write_data_out  (write_data_42)
  );


  always @(debug) begin
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

  initial begin
    $dumpfile("test.vcd");
    $dumpvars;
    clk = 0;
  end

  always #2 begin
    clk = ~clk;
  end
  always #10000 $finish; // Terminate the program in case of infinite loop
endmodule
