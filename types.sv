typedef bit [31:0] Data;
typedef reg [31:0] DataReg;
typedef bit [0:0] Clock;
typedef reg [0:0] ClockReg;
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
`define NOP 'b0010011000000000000000000000000

typedef struct packed {
  bit [4:0] opcode;
  bit [6:0] funct7;
  bit [2:0] funct3;
  bit [4:0] rs1, rs2, rd;
  bit [0:0] imm_sign;
  bit [31:0] I_imm, S_imm, U_imm, B_imm, J_imm;
} ParsedInstruction;