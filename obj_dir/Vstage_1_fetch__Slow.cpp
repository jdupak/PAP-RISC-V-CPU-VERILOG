// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vstage_1_fetch.h for the primary calling header

#include "Vstage_1_fetch.h"
#include "Vstage_1_fetch__Syms.h"

//==========

VL_CTOR_IMP(Vstage_1_fetch) {
    Vstage_1_fetch__Syms* __restrict vlSymsp = __VlSymsp = new Vstage_1_fetch__Syms(this, name());
    Vstage_1_fetch* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vstage_1_fetch::__Vconfigure(Vstage_1_fetch__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vstage_1_fetch::~Vstage_1_fetch() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = nullptr);
}

void Vstage_1_fetch::_initial__TOP__1(Vstage_1_fetch__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstage_1_fetch::_initial__TOP__1\n"); );
    Vstage_1_fetch* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    IData/*31:0*/ Stage1Fetch__DOT__imem__DOT__i;
    // Body
    vlTOPp->Stage1Fetch__DOT__imem__DOT__fd = VL_FOPEN_NN(
                                                          std::string("gcd.bin")
                                                          , 
                                                          std::string("rb"));
    Stage1Fetch__DOT__imem__DOT__i = VL_FREAD_I(32,0
                                                ,129
                                                , vlTOPp->Stage1Fetch__DOT__imem__DOT__mem
                                                , vlTOPp->Stage1Fetch__DOT__imem__DOT__fd
                                                , 0
                                                , 129);
    ;
    VL_FCLOSE_I(vlTOPp->Stage1Fetch__DOT__imem__DOT__fd); vlTOPp->Stage1Fetch__DOT__imem__DOT__fd = 0;
    vlTOPp->Stage1Fetch__DOT__address = 0U;
    VL_WRITEF("PC: 0x00000000\n");
}

void Vstage_1_fetch::_settle__TOP__3(Vstage_1_fetch__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstage_1_fetch::_settle__TOP__3\n"); );
    Vstage_1_fetch* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->next_address = ((IData)(4U) + vlTOPp->Stage1Fetch__DOT__address);
    vlTOPp->instruction = ((0x80U >= (0xffU & (vlTOPp->Stage1Fetch__DOT__address 
                                               >> 2U)))
                            ? vlTOPp->Stage1Fetch__DOT__imem__DOT__mem
                           [(0xffU & (vlTOPp->Stage1Fetch__DOT__address 
                                      >> 2U))] : 0U);
}

void Vstage_1_fetch::_eval_initial(Vstage_1_fetch__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstage_1_fetch::_eval_initial\n"); );
    Vstage_1_fetch* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

void Vstage_1_fetch::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstage_1_fetch::final\n"); );
    // Variables
    Vstage_1_fetch__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vstage_1_fetch* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vstage_1_fetch::_eval_settle(Vstage_1_fetch__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstage_1_fetch::_eval_settle\n"); );
    Vstage_1_fetch* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__3(vlSymsp);
}

void Vstage_1_fetch::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstage_1_fetch::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    stall = VL_RAND_RESET_I(1);
    jump_enable = VL_RAND_RESET_I(1);
    jump_address = VL_RAND_RESET_I(32);
    instruction = VL_RAND_RESET_I(32);
    next_address = VL_RAND_RESET_I(32);
    Stage1Fetch__DOT__address = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<129; ++__Vi0) {
            Stage1Fetch__DOT__imem__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }}
    Stage1Fetch__DOT__imem__DOT__fd = 0;
}
