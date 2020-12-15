// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VSTAGE_3_EXEC_H_
#define _VSTAGE_3_EXEC_H_  // guard

#include "verilated_heavy.h"

//==========

class Vstage_3_exec__Syms;

//----------

VL_MODULE(Vstage_3_exec) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(stall,0,0);
    VL_IN8(alu_op,2,0);
    VL_IN8(alu_op_modified,0,0);
    VL_IN8(use_imm,0,0);
    VL_IN8(rd_idx,4,0);
    VL_IN8(mem_write_enable,0,0);
    VL_IN8(mem_read_enable,0,0);
    VL_IN8(reg_write_enable,0,0);
    VL_OUT8(rd_idx_out,4,0);
    VL_OUT8(mem_write_enable_out,0,0);
    VL_OUT8(mem_read_enable_out,0,0);
    VL_OUT8(reg_write_enable_out,0,0);
    VL_IN(rs1_val,31,0);
    VL_IN(rs2_val,31,0);
    VL_IN(imm,31,0);
    VL_OUT(alu_res,31,0);
    VL_OUT(rs2_val_out,31,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vclklast__TOP__clk;
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vstage_3_exec__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vstage_3_exec);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vstage_3_exec(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vstage_3_exec();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vstage_3_exec__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vstage_3_exec__Syms* symsp, bool first);
  private:
    static QData _change_request(Vstage_3_exec__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vstage_3_exec__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__2(Vstage_3_exec__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vstage_3_exec__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vstage_3_exec__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vstage_3_exec__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__1(Vstage_3_exec__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__4(Vstage_3_exec__Syms* __restrict vlSymsp);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
