// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vstage_1_fetch.h for the primary calling header

#include "Vstage_1_fetch.h"
#include "Vstage_1_fetch__Syms.h"

//==========

void Vstage_1_fetch::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vstage_1_fetch::eval\n"); );
    Vstage_1_fetch__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vstage_1_fetch* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("pipeline/stage_1_fetch.v", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vstage_1_fetch::_eval_initial_loop(Vstage_1_fetch__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("pipeline/stage_1_fetch.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vstage_1_fetch::_sequent__TOP__2(Vstage_1_fetch__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstage_1_fetch::_sequent__TOP__2\n"); );
    Vstage_1_fetch* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    VL_WRITEF("====================================================\n");
    VL_WRITEF("PC: 0x%x [jump=%x]\n",32,((IData)(vlTOPp->jump_enable)
                                          ? vlTOPp->jump_address
                                          : vlTOPp->next_address),
              1,(IData)(vlTOPp->jump_enable));
    vlTOPp->Stage1Fetch__DOT__address = ((IData)(vlTOPp->jump_enable)
                                          ? vlTOPp->jump_address
                                          : vlTOPp->next_address);
    vlTOPp->next_address = ((IData)(4U) + vlTOPp->Stage1Fetch__DOT__address);
    vlTOPp->instruction = ((0x80U >= (0xffU & (vlTOPp->Stage1Fetch__DOT__address 
                                               >> 2U)))
                            ? vlTOPp->Stage1Fetch__DOT__imem__DOT__mem
                           [(0xffU & (vlTOPp->Stage1Fetch__DOT__address 
                                      >> 2U))] : 0U);
}

void Vstage_1_fetch::_eval(Vstage_1_fetch__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstage_1_fetch::_eval\n"); );
    Vstage_1_fetch* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

VL_INLINE_OPT QData Vstage_1_fetch::_change_request(Vstage_1_fetch__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstage_1_fetch::_change_request\n"); );
    Vstage_1_fetch* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vstage_1_fetch::_change_request_1(Vstage_1_fetch__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstage_1_fetch::_change_request_1\n"); );
    Vstage_1_fetch* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vstage_1_fetch::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstage_1_fetch::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((stall & 0xfeU))) {
        Verilated::overWidthError("stall");}
    if (VL_UNLIKELY((jump_enable & 0xfeU))) {
        Verilated::overWidthError("jump_enable");}
}
#endif  // VL_DEBUG
