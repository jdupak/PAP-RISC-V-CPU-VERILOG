// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VTEST_PIPELINE_CPU_H_
#define _VTEST_PIPELINE_CPU_H_  // guard

#include "verilated_heavy.h"

//==========

class Vtest_pipeline_cpu__Syms;

//----------

VL_MODULE(Vtest_pipeline_cpu) {
  public:
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*0:0*/ test__DOT__clk;
    CData/*0:0*/ test__DOT__jump_enable;
    CData/*4:0*/ test__DOT__rd_idx;
    CData/*2:0*/ test__DOT__alu_op;
    CData/*0:0*/ test__DOT__alu_res_neg;
    CData/*4:0*/ test__DOT__write_idx;
    CData/*0:0*/ test__DOT__write_enable_42;
    CData/*1:0*/ test__DOT__debug;
    CData/*4:0*/ test__DOT__rd_idx_34;
    CData/*4:0*/ test__DOT__s2__DOT__rs1_idx;
    CData/*4:0*/ test__DOT__s2__DOT__rs2_idx;
    CData/*0:0*/ test__DOT__s2__DOT__rs1_use_pc;
    CData/*0:0*/ test__DOT__s4__DOT__mem_read_enable;
    CData/*0:0*/ test__DOT__s4__DOT__mem_write_enable;
    CData/*0:0*/ test__DOT__s4__DOT__reg_write_enable;
    IData/*31:0*/ test__DOT__intruction;
    IData/*31:0*/ test__DOT__pc;
    IData/*31:0*/ test__DOT__jump_address;
    IData/*31:0*/ test__DOT__rs1_val;
    IData/*31:0*/ test__DOT__rs2_val;
    IData/*31:0*/ test__DOT__imm;
    IData/*31:0*/ test__DOT__write_data;
    IData/*31:0*/ test__DOT__alu_res_34;
    IData/*31:0*/ test__DOT__rs2_val_34;
    IData/*31:0*/ test__DOT__s1__DOT__address;
    IData/*31:0*/ test__DOT__s1__DOT__imem__DOT__fd;
    IData/*31:0*/ test__DOT__s2__DOT__decode__DOT__I_imm;
    IData/*31:0*/ test__DOT__s2__DOT__decode__DOT__B_imm;
    IData/*31:0*/ test__DOT__s2__DOT__decode__DOT__instruction;
    IData/*31:0*/ test__DOT__s1__DOT__imem__DOT__mem[129];
    IData/*31:0*/ test__DOT__s2__DOT__gpr__DOT__gp[32];
    IData/*31:0*/ test__DOT__s4__DOT__dmem__DOT__mem[129];
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __VinpClk__TOP__test__DOT__clk;
    CData/*0:0*/ __Vclklast__TOP____VinpClk__TOP__test__DOT__clk;
    CData/*0:0*/ __Vchglast__TOP__test__DOT__clk;
    IData/*31:0*/ test__DOT__s4__DOT__dmem__DOT____Vlvbound1;
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vtest_pipeline_cpu__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vtest_pipeline_cpu);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vtest_pipeline_cpu(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vtest_pipeline_cpu();
    
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
    static void _eval_initial_loop(Vtest_pipeline_cpu__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vtest_pipeline_cpu__Syms* symsp, bool first);
  private:
    static QData _change_request(Vtest_pipeline_cpu__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vtest_pipeline_cpu__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__2(Vtest_pipeline_cpu__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vtest_pipeline_cpu__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vtest_pipeline_cpu__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vtest_pipeline_cpu__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__1(Vtest_pipeline_cpu__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__3(Vtest_pipeline_cpu__Syms* __restrict vlSymsp);
    static void _settle__TOP__4(Vtest_pipeline_cpu__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
