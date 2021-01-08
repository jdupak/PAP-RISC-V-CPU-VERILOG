/**
 * Hazard unit to solve data hazards and stall after branches.
 * Structural hazerds are not handled and need to be handled via
 * duplication.
 */
module HazardUnit (
    input  Clock   clk,
    input  RegId   rs1,
    input  RegId   rs2,
    input  Bool    branch,
    input  RegId   rd,
    input  Bool    is_stall,
    output BoolReg stall_out = FALSE
);
  // We need at most 2 stall cycles stall. On branch, we stall next 2 cycles. 
  // On hazard detection, we stall this and the next cycle.
  // Branch may need both conditions. (Stalls before and after.)
  reg [1:0] counter = 'b0;
  // Check last to destinations to be compared with currently required data.
  // Request to zero registers are not a reason to stall, therefore zero
  // register can be used as neutral element here.
  RegIdReg current_rd = 'b0;
  RegIdReg last_rd = 'b0;
  RegIdReg prelast_rd = 'b0;

  always @(negedge clk) begin
    // If fetch is already stalled, the instruction data received were already
    // observed in previous cycle. Therefore we shall not evaluate them again
    // and we only count down the stall we are supposed to perform.
    if (~is_stall) begin
        if ((counter == 'd2) ||
            ((current_rd != 'b0) && ((rs1 == current_rd) || (rs2 == current_rd)))) begin
            // Ppending 2 cycle stall or dependency on the last instruction.
            counter <= 'd1;
            stall_out <= TRUE;
        end
        else if ((counter == 'd1) ||
            ((last_rd != 'b0) && ((rs1 == last_rd) || (rs2 == last_rd)))) begin
            // Pendning 1 stall or dependency on prelast.
            counter <= 'd0;
            stall_out <= TRUE;
        end else
        if (branch) begin
            // Execute branch and schedule 2 stalls.
            counter <= 'd2;
            stall_out <= FALSE;
        end else begin
            // Countdown ended, can execute again.
            stall_out <= FALSE;
        end
    end else begin
      // Evaluate the already accumulated stalls.
      if (counter == 'd2) begin
        counter <= 'd1;
        stall_out <= TRUE;
      end if (counter == 'd1) begin
        counter <= 'd0;
        stall_out <= TRUE;
      end else begin
        // Countdown ended, can execute again.

        // If branch has also dependency, the above code will not get triggered as
        // branch. We need to detect it here.
        if (branch) begin
            counter <= 'd2;
        end
        stall_out <= FALSE;
      end
    end

    // Shift the history of destionation regs.
    prelast_rd <= last_rd;
    last_rd <= current_rd;
    current_rd <= rd;
  end
endmodule
