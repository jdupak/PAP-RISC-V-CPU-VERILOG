// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vstage_4_mem.h for the primary calling header

#include "Vstage_4_mem.h"
#include "Vstage_4_mem__Syms.h"

//==========

void Vstage_4_mem::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vstage_4_mem::eval\n"); );
    Vstage_4_mem__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vstage_4_mem* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("pipeline/stage_4_mem.v", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vstage_4_mem::_eval_initial_loop(Vstage_4_mem__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("pipeline/stage_4_mem.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vstage_4_mem::_combo__TOP__1(Vstage_4_mem__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstage_4_mem::_combo__TOP__1\n"); );
    Vstage_4_mem* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->write_enable = vlTOPp->mem_write_enable;
    vlTOPp->write_idx = vlTOPp->rd_idx;
}

VL_INLINE_OPT void Vstage_4_mem::_sequent__TOP__3(Vstage_4_mem__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstage_4_mem::_sequent__TOP__3\n"); );
    Vstage_4_mem* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*7:0*/ __Vdlyvdim0__Stage4Mem__DOT__dmem__DOT__mem__v0;
    CData/*0:0*/ __Vdlyvset__Stage4Mem__DOT__dmem__DOT__mem__v0;
    IData/*31:0*/ __Vdlyvval__Stage4Mem__DOT__dmem__DOT__mem__v0;
    // Body
    __Vdlyvset__Stage4Mem__DOT__dmem__DOT__mem__v0 = 0U;
    if (VL_UNLIKELY(vlTOPp->mem_write_enable)) {
        vlTOPp->Stage4Mem__DOT__dmem__DOT____Vlvbound1 
            = vlTOPp->rs2_val;
        VL_WRITEF("MEM: write [%x]=%x\n",32,vlTOPp->alu_res,
                  32,vlTOPp->rs2_val);
        if ((0x80U >= (0xffU & (vlTOPp->alu_res >> 2U)))) {
            __Vdlyvval__Stage4Mem__DOT__dmem__DOT__mem__v0 
                = vlTOPp->Stage4Mem__DOT__dmem__DOT____Vlvbound1;
            __Vdlyvset__Stage4Mem__DOT__dmem__DOT__mem__v0 = 1U;
            __Vdlyvdim0__Stage4Mem__DOT__dmem__DOT__mem__v0 
                = (0xffU & (vlTOPp->alu_res >> 2U));
        }
    }
    if (__Vdlyvset__Stage4Mem__DOT__dmem__DOT__mem__v0) {
        vlTOPp->Stage4Mem__DOT__dmem__DOT__mem[__Vdlyvdim0__Stage4Mem__DOT__dmem__DOT__mem__v0] 
            = __Vdlyvval__Stage4Mem__DOT__dmem__DOT__mem__v0;
    }
}

VL_INLINE_OPT void Vstage_4_mem::_combo__TOP__4(Vstage_4_mem__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstage_4_mem::_combo__TOP__4\n"); );
    Vstage_4_mem* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->write_data = ((IData)(vlTOPp->mem_read_enable)
                           ? ((0x80U >= (0xffU & (vlTOPp->alu_res 
                                                  >> 2U)))
                               ? vlTOPp->Stage4Mem__DOT__dmem__DOT__mem
                              [(0xffU & (vlTOPp->alu_res 
                                         >> 2U))] : 0U)
                           : vlTOPp->alu_res);
}

void Vstage_4_mem::_eval(Vstage_4_mem__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstage_4_mem::_eval\n"); );
    Vstage_4_mem* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__3(vlSymsp);
    }
    vlTOPp->_combo__TOP__4(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

VL_INLINE_OPT QData Vstage_4_mem::_change_request(Vstage_4_mem__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstage_4_mem::_change_request\n"); );
    Vstage_4_mem* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vstage_4_mem::_change_request_1(Vstage_4_mem__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstage_4_mem::_change_request_1\n"); );
    Vstage_4_mem* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vstage_4_mem::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstage_4_mem::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((stall & 0xfeU))) {
        Verilated::overWidthError("stall");}
    if (VL_UNLIKELY((rd_idx & 0xe0U))) {
        Verilated::overWidthError("rd_idx");}
    if (VL_UNLIKELY((mem_read_enable & 0xfeU))) {
        Verilated::overWidthError("mem_read_enable");}
    if (VL_UNLIKELY((mem_write_enable & 0xfeU))) {
        Verilated::overWidthError("mem_write_enable");}
}
#endif  // VL_DEBUG
