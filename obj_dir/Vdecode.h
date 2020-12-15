// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VDECODE_H_
#define _VDECODE_H_  // guard

#include "verilated_heavy.h"

//==========

class Vdecode__Syms;

//----------

VL_MODULE(Vdecode) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_OUT8(alu_op,2,0);
    VL_OUT8(alu_rs1,4,0);
    VL_OUT8(alu_rs2,4,0);
    VL_OUT8(alu_rd,4,0);
    VL_OUT8(alu_use_imm,0,0);
    VL_OUT8(alu_rs1_pc,0,0);
    VL_OUT8(alu_rs2_neg,0,0);
    VL_OUT8(alu_res_neg,0,0);
    VL_OUT8(mem_load,0,0);
    VL_OUT8(mem_store,0,0);
    VL_OUT8(write_enable,0,0);
    VL_OUT8(jump_enable,0,0);
    VL_OUT8(debug,1,0);
    VL_IN(_instruction,31,0);
    VL_OUT(imm,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    IData/*31:0*/ Decode__DOT__I_imm;
    IData/*31:0*/ Decode__DOT__B_imm;
    IData/*31:0*/ Decode__DOT__instruction;
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vdecode__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vdecode);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vdecode(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vdecode();
    
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
    static void _eval_initial_loop(Vdecode__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vdecode__Syms* symsp, bool first);
  private:
    static QData _change_request(Vdecode__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vdecode__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__1(Vdecode__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vdecode__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vdecode__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vdecode__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
