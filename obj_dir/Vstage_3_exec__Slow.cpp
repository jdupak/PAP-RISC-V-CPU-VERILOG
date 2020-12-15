// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vstage_3_exec.h for the primary calling header

#include "Vstage_3_exec.h"
#include "Vstage_3_exec__Syms.h"

//==========

VL_CTOR_IMP(Vstage_3_exec) {
    Vstage_3_exec__Syms* __restrict vlSymsp = __VlSymsp = new Vstage_3_exec__Syms(this, name());
    Vstage_3_exec* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vstage_3_exec::__Vconfigure(Vstage_3_exec__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vstage_3_exec::~Vstage_3_exec() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = nullptr);
}

void Vstage_3_exec::_initial__TOP__1(Vstage_3_exec__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstage_3_exec::_initial__TOP__1\n"); );
    Vstage_3_exec* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->alu_res = 0U;
}

void Vstage_3_exec::_eval_initial(Vstage_3_exec__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstage_3_exec::_eval_initial\n"); );
    Vstage_3_exec* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

void Vstage_3_exec::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstage_3_exec::final\n"); );
    // Variables
    Vstage_3_exec__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vstage_3_exec* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vstage_3_exec::_eval_settle(Vstage_3_exec__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstage_3_exec::_eval_settle\n"); );
    Vstage_3_exec* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__2(vlSymsp);
}

void Vstage_3_exec::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstage_3_exec::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    stall = VL_RAND_RESET_I(1);
    alu_op = VL_RAND_RESET_I(3);
    alu_op_modified = VL_RAND_RESET_I(1);
    rs1_val = VL_RAND_RESET_I(32);
    rs2_val = VL_RAND_RESET_I(32);
    imm = VL_RAND_RESET_I(32);
    use_imm = VL_RAND_RESET_I(1);
    rd_idx = VL_RAND_RESET_I(5);
    mem_write_enable = VL_RAND_RESET_I(1);
    mem_read_enable = VL_RAND_RESET_I(1);
    reg_write_enable = VL_RAND_RESET_I(1);
    alu_res = VL_RAND_RESET_I(32);
    rs2_val_out = VL_RAND_RESET_I(32);
    rd_idx_out = VL_RAND_RESET_I(5);
    mem_write_enable_out = VL_RAND_RESET_I(1);
    mem_read_enable_out = VL_RAND_RESET_I(1);
    reg_write_enable_out = VL_RAND_RESET_I(1);
}
