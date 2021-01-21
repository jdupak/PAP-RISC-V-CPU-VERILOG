module ALU (
    input Data a,
    input Data b,
    input ALUOp op,
    input Bool mod,    // Modifier: used for arithmetic shift
    output DataReg res_out
);
    assign res_out = alu(a, b, op, mod);

    // always @ (a, b, op, mod) begin
    //     $display("ALU: %h -> (%d %d) = %d", op, a, $signed(b), $signed(res_out));
    // end
endmodule

function Data alu(
    input Data a, b,
    input ALUOp op,
    input Bool mod
);
    case (op)
        ADD: alu = a + b;
        SLL: alu = a << b;
        SLT: alu = {{31{1'b0}}, $signed(a) < $signed(b)};
        SLTU: alu = {{31{1'b0}}, a < b};
        XOR: alu = a ^ b;
        SR: alu = (mod) ? (a >>> b) : (a >> b);
        OR: alu = a | b;
        AND: alu = a & b;
    endcase

    if (op == ADD) $display("DBG::ALU\t%d\t%d\t%d\t%d\t%d", op, a, b, mod, alu);
endfunction