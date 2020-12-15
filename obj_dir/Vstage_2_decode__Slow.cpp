// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vstage_2_decode.h for the primary calling header

#include "Vstage_2_decode.h"
#include "Vstage_2_decode__Syms.h"

//==========

VL_CTOR_IMP(Vstage_2_decode) {
    Vstage_2_decode__Syms* __restrict vlSymsp = __VlSymsp = new Vstage_2_decode__Syms(this, name());
    Vstage_2_decode* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vstage_2_decode::__Vconfigure(Vstage_2_decode__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vstage_2_decode::~Vstage_2_decode() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = nullptr);
}

void Vstage_2_decode::_eval_initial(Vstage_2_decode__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstage_2_decode::_eval_initial\n"); );
    Vstage_2_decode* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

void Vstage_2_decode::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstage_2_decode::final\n"); );
    // Variables
    Vstage_2_decode__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vstage_2_decode* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vstage_2_decode::_eval_settle(Vstage_2_decode__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstage_2_decode::_eval_settle\n"); );
    Vstage_2_decode* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__2(vlSymsp);
}

void Vstage_2_decode::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstage_2_decode::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    stall = VL_RAND_RESET_I(1);
    instruction = VL_RAND_RESET_I(32);
    pc = VL_RAND_RESET_I(32);
    write_enable = VL_RAND_RESET_I(1);
    write_idx = VL_RAND_RESET_I(5);
    write_data = VL_RAND_RESET_I(32);
    alu_op = VL_RAND_RESET_I(3);
    rs1_val = VL_RAND_RESET_I(32);
    rs2_val = VL_RAND_RESET_I(32);
    imm = VL_RAND_RESET_I(32);
    use_imm = VL_RAND_RESET_I(1);
    rd_idx = VL_RAND_RESET_I(5);
    alu_rs2_neg = VL_RAND_RESET_I(1);
    alu_res_neg = VL_RAND_RESET_I(1);
    mem_load_enable = VL_RAND_RESET_I(1);
    mem_write_enable = VL_RAND_RESET_I(1);
    jump_enable = VL_RAND_RESET_I(1);
    debug = VL_RAND_RESET_I(2);
    Stage2Decode__DOT__rs1_idx = VL_RAND_RESET_I(5);
    Stage2Decode__DOT__rs2_idx = VL_RAND_RESET_I(5);
    Stage2Decode__DOT__rs1_use_pc = VL_RAND_RESET_I(1);
    Stage2Decode__DOT__decode__DOT__I_imm = VL_RAND_RESET_I(32);
    Stage2Decode__DOT__decode__DOT__B_imm = VL_RAND_RESET_I(32);
    Stage2Decode__DOT__decode__DOT__instruction = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<32; ++__Vi0) {
            Stage2Decode__DOT__gpr__DOT__gp[__Vi0] = VL_RAND_RESET_I(32);
    }}
}
