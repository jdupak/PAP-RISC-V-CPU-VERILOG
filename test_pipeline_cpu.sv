module test ();
  ClockReg clk = 'b0;
  DebugStatus debug;

  PipelineCPU cpu(
    .clk(clk),
    .debug(debug)
  );

  always @(debug) begin
    case (debug)
      'b01: begin
        #(6); // Let CPU finish
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
