// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VSTAGE_1_FETCH_H_
#define _VSTAGE_1_FETCH_H_  // guard

#include "verilated_heavy.h"

//==========

class Vstage_1_fetch__Syms;

//----------

VL_MODULE(Vstage_1_fetch) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(stall,0,0);
    VL_IN8(jump_enable,0,0);
    VL_IN(jump_address,31,0);
    VL_OUT(instruction,31,0);
    VL_OUT(next_address,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    IData/*31:0*/ Stage1Fetch__DOT__address;
    IData/*31:0*/ Stage1Fetch__DOT__imem__DOT__fd;
    IData/*31:0*/ Stage1Fetch__DOT__imem__DOT__mem[129];
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vclklast__TOP__clk;
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vstage_1_fetch__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vstage_1_fetch);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vstage_1_fetch(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vstage_1_fetch();
    
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
    static void _eval_initial_loop(Vstage_1_fetch__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vstage_1_fetch__Syms* symsp, bool first);
  private:
    static QData _change_request(Vstage_1_fetch__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vstage_1_fetch__Syms* __restrict vlSymsp);
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vstage_1_fetch__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vstage_1_fetch__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vstage_1_fetch__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__1(Vstage_1_fetch__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__2(Vstage_1_fetch__Syms* __restrict vlSymsp);
    static void _settle__TOP__3(Vstage_1_fetch__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
