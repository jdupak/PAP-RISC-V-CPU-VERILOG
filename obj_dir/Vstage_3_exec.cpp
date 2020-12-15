// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vstage_3_exec.h for the primary calling header

#include "Vstage_3_exec.h"
#include "Vstage_3_exec__Syms.h"

//==========

void Vstage_3_exec::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vstage_3_exec::eval\n"); );
    Vstage_3_exec__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vstage_3_exec* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("pipeline/stage_3_exec.v", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vstage_3_exec::_eval_initial_loop(Vstage_3_exec__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("pipeline/stage_3_exec.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vstage_3_exec::_combo__TOP__2(Vstage_3_exec__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstage_3_exec::_combo__TOP__2\n"); );
    Vstage_3_exec* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((((((((0U == (IData)(vlTOPp->alu_op)) | (1U 
                                                  == (IData)(vlTOPp->alu_op))) 
              | (2U == (IData)(vlTOPp->alu_op))) | 
             (3U == (IData)(vlTOPp->alu_op))) | (4U 
                                                 == (IData)(vlTOPp->alu_op))) 
           | (5U == (IData)(vlTOPp->alu_op))) | (6U 
                                                 == (IData)(vlTOPp->alu_op))) 
         | (7U == (IData)(vlTOPp->alu_op)))) {
        vlTOPp->alu_res = ((0U == (IData)(vlTOPp->alu_op))
                            ? (vlTOPp->rs1_val + vlTOPp->imm)
                            : ((1U == (IData)(vlTOPp->alu_op))
                                ? ((0x1fU >= vlTOPp->imm)
                                    ? (vlTOPp->rs1_val 
                                       << vlTOPp->imm)
                                    : 0U) : ((2U == (IData)(vlTOPp->alu_op))
                                              ? VL_LTS_III(32,32,32, vlTOPp->rs1_val, vlTOPp->imm)
                                              : ((3U 
                                                  == (IData)(vlTOPp->alu_op))
                                                  ? 
                                                 (vlTOPp->rs1_val 
                                                  < vlTOPp->imm)
                                                  : 
                                                 ((4U 
                                                   == (IData)(vlTOPp->alu_op))
                                                   ? 
                                                  (vlTOPp->rs1_val 
                                                   ^ vlTOPp->imm)
                                                   : 
                                                  ((5U 
                                                    == (IData)(vlTOPp->alu_op))
                                                    ? 
                                                   ((IData)(vlTOPp->alu_op_modified)
                                                     ? 
                                                    ((0x1fU 
                                                      >= vlTOPp->imm)
                                                      ? 
                                                     (vlTOPp->rs1_val 
                                                      >> vlTOPp->imm)
                                                      : 0U)
                                                     : 
                                                    ((0x1fU 
                                                      >= vlTOPp->imm)
                                                      ? 
                                                     (vlTOPp->rs1_val 
                                                      >> vlTOPp->imm)
                                                      : 0U))
                                                    : 
                                                   ((6U 
                                                     == (IData)(vlTOPp->alu_op))
                                                     ? 
                                                    (vlTOPp->rs1_val 
                                                     | vlTOPp->imm)
                                                     : 
                                                    (vlTOPp->rs1_val 
                                                     & vlTOPp->imm))))))));
    }
    VL_WRITEF("ALU: %x -> (%10# %11d) = %11d\n",3,vlTOPp->alu_op,
              32,vlTOPp->rs1_val,32,vlTOPp->imm,32,
              vlTOPp->alu_res);
}

VL_INLINE_OPT void Vstage_3_exec::_sequent__TOP__4(Vstage_3_exec__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstage_3_exec::_sequent__TOP__4\n"); );
    Vstage_3_exec* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->mem_write_enable_out = vlTOPp->mem_write_enable;
    vlTOPp->rd_idx_out = vlTOPp->rd_idx;
    vlTOPp->mem_read_enable_out = vlTOPp->mem_read_enable;
    vlTOPp->rs2_val_out = vlTOPp->rs2_val;
    vlTOPp->rs2_val_out = vlTOPp->rs2_val;
}

void Vstage_3_exec::_eval(Vstage_3_exec__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstage_3_exec::_eval\n"); );
    Vstage_3_exec* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__2(vlSymsp);
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__4(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

VL_INLINE_OPT QData Vstage_3_exec::_change_request(Vstage_3_exec__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstage_3_exec::_change_request\n"); );
    Vstage_3_exec* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vstage_3_exec::_change_request_1(Vstage_3_exec__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstage_3_exec::_change_request_1\n"); );
    Vstage_3_exec* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vstage_3_exec::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstage_3_exec::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((stall & 0xfeU))) {
        Verilated::overWidthError("stall");}
    if (VL_UNLIKELY((alu_op & 0xf8U))) {
        Verilated::overWidthError("alu_op");}
    if (VL_UNLIKELY((alu_op_modified & 0xfeU))) {
        Verilated::overWidthError("alu_op_modified");}
    if (VL_UNLIKELY((use_imm & 0xfeU))) {
        Verilated::overWidthError("use_imm");}
    if (VL_UNLIKELY((rd_idx & 0xe0U))) {
        Verilated::overWidthError("rd_idx");}
    if (VL_UNLIKELY((mem_write_enable & 0xfeU))) {
        Verilated::overWidthError("mem_write_enable");}
    if (VL_UNLIKELY((mem_read_enable & 0xfeU))) {
        Verilated::overWidthError("mem_read_enable");}
    if (VL_UNLIKELY((reg_write_enable & 0xfeU))) {
        Verilated::overWidthError("reg_write_enable");}
}
#endif  // VL_DEBUG
