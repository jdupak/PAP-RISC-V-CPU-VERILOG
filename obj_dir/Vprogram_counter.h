// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VPROGRAM_COUNTER_H_
#define _VPROGRAM_COUNTER_H_  // guard

#include "verilated_heavy.h"

//==========

class Vprogram_counter__Syms;

//----------

VL_MODULE(Vprogram_counter) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(jump_enable,0,0);
    VL_IN(jump_address,31,0);
    VL_OUT(address,31,0);
    VL_OUT(next_address,31,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vclklast__TOP__clk;
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vprogram_counter__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vprogram_counter);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vprogram_counter(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vprogram_counter();
    
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
    static void _eval_initial_loop(Vprogram_counter__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vprogram_counter__Syms* symsp, bool first);
  private:
    static QData _change_request(Vprogram_counter__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vprogram_counter__Syms* __restrict vlSymsp);
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vprogram_counter__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vprogram_counter__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vprogram_counter__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__1(Vprogram_counter__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__2(Vprogram_counter__Syms* __restrict vlSymsp);
    static void _settle__TOP__3(Vprogram_counter__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
