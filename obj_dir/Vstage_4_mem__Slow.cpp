// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vstage_4_mem.h for the primary calling header

#include "Vstage_4_mem.h"
#include "Vstage_4_mem__Syms.h"

//==========

VL_CTOR_IMP(Vstage_4_mem) {
    Vstage_4_mem__Syms* __restrict vlSymsp = __VlSymsp = new Vstage_4_mem__Syms(this, name());
    Vstage_4_mem* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vstage_4_mem::__Vconfigure(Vstage_4_mem__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vstage_4_mem::~Vstage_4_mem() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = nullptr);
}

void Vstage_4_mem::_settle__TOP__2(Vstage_4_mem__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstage_4_mem::_settle__TOP__2\n"); );
    Vstage_4_mem* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->write_enable = vlTOPp->mem_write_enable;
    vlTOPp->write_idx = vlTOPp->rd_idx;
    vlTOPp->write_data = ((IData)(vlTOPp->mem_read_enable)
                           ? ((0x80U >= (0xffU & (vlTOPp->alu_res 
                                                  >> 2U)))
                               ? vlTOPp->Stage4Mem__DOT__dmem__DOT__mem
                              [(0xffU & (vlTOPp->alu_res 
                                         >> 2U))] : 0U)
                           : vlTOPp->alu_res);
}

void Vstage_4_mem::_eval_initial(Vstage_4_mem__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstage_4_mem::_eval_initial\n"); );
    Vstage_4_mem* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

void Vstage_4_mem::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstage_4_mem::final\n"); );
    // Variables
    Vstage_4_mem__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vstage_4_mem* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vstage_4_mem::_eval_settle(Vstage_4_mem__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstage_4_mem::_eval_settle\n"); );
    Vstage_4_mem* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

void Vstage_4_mem::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstage_4_mem::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    stall = VL_RAND_RESET_I(1);
    alu_res = VL_RAND_RESET_I(32);
    rs2_val = VL_RAND_RESET_I(32);
    rd_idx = VL_RAND_RESET_I(5);
    mem_read_enable = VL_RAND_RESET_I(1);
    mem_write_enable = VL_RAND_RESET_I(1);
    write_enable = VL_RAND_RESET_I(1);
    write_idx = VL_RAND_RESET_I(5);
    write_data = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<129; ++__Vi0) {
            Stage4Mem__DOT__dmem__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }}
    Stage4Mem__DOT__dmem__DOT____Vlvbound1 = VL_RAND_RESET_I(32);
}
