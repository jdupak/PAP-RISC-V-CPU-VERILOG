// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdecode.h for the primary calling header

#include "Vdecode.h"
#include "Vdecode__Syms.h"

//==========

VL_CTOR_IMP(Vdecode) {
    Vdecode__Syms* __restrict vlSymsp = __VlSymsp = new Vdecode__Syms(this, name());
    Vdecode* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vdecode::__Vconfigure(Vdecode__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vdecode::~Vdecode() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = nullptr);
}

void Vdecode::_eval_initial(Vdecode__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecode::_eval_initial\n"); );
    Vdecode* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vdecode::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecode::final\n"); );
    // Variables
    Vdecode__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vdecode* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vdecode::_eval_settle(Vdecode__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecode::_eval_settle\n"); );
    Vdecode* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

void Vdecode::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecode::_ctor_var_reset\n"); );
    // Body
    _instruction = VL_RAND_RESET_I(32);
    alu_op = VL_RAND_RESET_I(3);
    alu_rs1 = VL_RAND_RESET_I(5);
    alu_rs2 = VL_RAND_RESET_I(5);
    alu_rd = VL_RAND_RESET_I(5);
    alu_use_imm = VL_RAND_RESET_I(1);
    alu_rs1_pc = VL_RAND_RESET_I(1);
    alu_rs2_neg = VL_RAND_RESET_I(1);
    alu_res_neg = VL_RAND_RESET_I(1);
    imm = VL_RAND_RESET_I(32);
    mem_load = VL_RAND_RESET_I(1);
    mem_store = VL_RAND_RESET_I(1);
    write_enable = VL_RAND_RESET_I(1);
    jump_enable = VL_RAND_RESET_I(1);
    debug = VL_RAND_RESET_I(2);
    Decode__DOT__I_imm = VL_RAND_RESET_I(32);
    Decode__DOT__B_imm = VL_RAND_RESET_I(32);
    Decode__DOT__instruction = VL_RAND_RESET_I(32);
}
