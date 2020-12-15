// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vprogram_counter.h for the primary calling header

#include "Vprogram_counter.h"
#include "Vprogram_counter__Syms.h"

//==========

VL_CTOR_IMP(Vprogram_counter) {
    Vprogram_counter__Syms* __restrict vlSymsp = __VlSymsp = new Vprogram_counter__Syms(this, name());
    Vprogram_counter* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vprogram_counter::__Vconfigure(Vprogram_counter__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vprogram_counter::~Vprogram_counter() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = nullptr);
}

void Vprogram_counter::_initial__TOP__1(Vprogram_counter__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprogram_counter::_initial__TOP__1\n"); );
    Vprogram_counter* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->address = 0U;
    VL_WRITEF("PC: 0x%x\n",32,vlTOPp->address);
}

void Vprogram_counter::_settle__TOP__3(Vprogram_counter__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprogram_counter::_settle__TOP__3\n"); );
    Vprogram_counter* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->next_address = ((IData)(4U) + vlTOPp->address);
}

void Vprogram_counter::_eval_initial(Vprogram_counter__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprogram_counter::_eval_initial\n"); );
    Vprogram_counter* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

void Vprogram_counter::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprogram_counter::final\n"); );
    // Variables
    Vprogram_counter__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vprogram_counter* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vprogram_counter::_eval_settle(Vprogram_counter__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprogram_counter::_eval_settle\n"); );
    Vprogram_counter* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__3(vlSymsp);
}

void Vprogram_counter::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprogram_counter::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    jump_enable = VL_RAND_RESET_I(1);
    jump_address = VL_RAND_RESET_I(32);
    address = VL_RAND_RESET_I(32);
    next_address = VL_RAND_RESET_I(32);
}
