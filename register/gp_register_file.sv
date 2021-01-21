module GPRegisterFile (
    input  Clock clk,
    input  RegId read_idx_1,
    input  RegId read_idx_2,
    input  RegId write_idx,
    input  Data  write_data,
    input  Bool  write_enable,
    output Data  read_data_1_out,
    output Data  read_data_2_out
);
  DataReg gp[31:0];

  assign
      read_data_1_out = (write_enable && (write_idx == read_idx_1)) ? write_data : gp[read_idx_1];
  assign
      read_data_2_out = (write_enable && (write_idx == read_idx_2)) ? write_data : gp[read_idx_2];

  always @(posedge clk) begin
    if (write_enable) begin
      if (write_idx != 0) gp[write_idx] <= write_data;
      $display("DBG::REG\t%d\t%d\t%d\t%d\t%d", gp[0], gp[1], gp[2], gp[3], gp[4], gp[5]);
      // $display("REG: r1=%h r2=%h w[%d]=%h", gp[1], gp[2], write_idx, write_data);
    end
  end
endmodule
