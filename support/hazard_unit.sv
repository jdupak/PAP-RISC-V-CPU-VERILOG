/**
 * Hazard unit to solve data hazards and stall after branches.
 * Structural hazerds are not handled and need to be handled via
 * duplication.
 */
module HazardUnit (
    input  Clock clk,
    input  RegId rs1,
    input  RegId rs2,
    input  RegId rd,
    output Bool  stall_out,
    output Bool  fwd1_enable_out,
    output Bool  fwd2_enable_out
);
  // Check last to destinations to be compared with currently required data.
  // Request to zero registers are not a reason to stall, therefore zero
  // register can be used as neutral element here.
  RegIdReg last_rd = 'd0;
  RegIdReg prelast_rd = 'd0;

  assign fwd1_enable_out = ((prelast_rd != 'd0) && (rs1 == prelast_rd));
  assign fwd2_enable_out = ((prelast_rd != 'd0) && (rs2 == prelast_rd));
  assign stall_out = ((last_rd != 'd0) && ((rs1 == last_rd) || (rs2 == last_rd)));

  always @(posedge clk) begin
    // Shift the history of destionation regs.
    prelast_rd <= last_rd;
    last_rd <= (stall_out) ? 'd0 : rd;
  end
endmodule

