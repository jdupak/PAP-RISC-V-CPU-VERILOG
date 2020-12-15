// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vstage_2_decode.h for the primary calling header

#include "Vstage_2_decode.h"
#include "Vstage_2_decode__Syms.h"

//==========

void Vstage_2_decode::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vstage_2_decode::eval\n"); );
    Vstage_2_decode__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vstage_2_decode* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("pipeline/stage_2_decode.v", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vstage_2_decode::_eval_initial_loop(Vstage_2_decode__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("pipeline/stage_2_decode.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vstage_2_decode::_sequent__TOP__1(Vstage_2_decode__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstage_2_decode::_sequent__TOP__1\n"); );
    Vstage_2_decode* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*4:0*/ __Vdlyvdim0__Stage2Decode__DOT__gpr__DOT__gp__v0;
    CData/*0:0*/ __Vdlyvset__Stage2Decode__DOT__gpr__DOT__gp__v0;
    IData/*31:0*/ __Vdlyvval__Stage2Decode__DOT__gpr__DOT__gp__v0;
    // Body
    __Vdlyvset__Stage2Decode__DOT__gpr__DOT__gp__v0 = 0U;
    if (VL_UNLIKELY(vlTOPp->write_enable)) {
        VL_WRITEF("REG: r1=%x r2=%x w[%2#]=%x\n",32,
                  vlTOPp->Stage2Decode__DOT__gpr__DOT__gp
                  [1U],32,vlTOPp->Stage2Decode__DOT__gpr__DOT__gp
                  [2U],5,vlTOPp->write_idx,32,vlTOPp->write_data);
        if ((0U != (IData)(vlTOPp->write_idx))) {
            __Vdlyvval__Stage2Decode__DOT__gpr__DOT__gp__v0 
                = vlTOPp->write_data;
            __Vdlyvset__Stage2Decode__DOT__gpr__DOT__gp__v0 = 1U;
            __Vdlyvdim0__Stage2Decode__DOT__gpr__DOT__gp__v0 
                = vlTOPp->write_idx;
        }
    }
    if (__Vdlyvset__Stage2Decode__DOT__gpr__DOT__gp__v0) {
        vlTOPp->Stage2Decode__DOT__gpr__DOT__gp[__Vdlyvdim0__Stage2Decode__DOT__gpr__DOT__gp__v0] 
            = __Vdlyvval__Stage2Decode__DOT__gpr__DOT__gp__v0;
    }
}

VL_INLINE_OPT void Vstage_2_decode::_combo__TOP__2(Vstage_2_decode__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstage_2_decode::_combo__TOP__2\n"); );
    Vstage_2_decode* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->Stage2Decode__DOT__decode__DOT__instruction 
        = ((0xff000000U & (vlTOPp->instruction << 0x18U)) 
           | ((0xff0000U & (vlTOPp->instruction << 8U)) 
              | ((0xff00U & (vlTOPp->instruction >> 8U)) 
                 | (0xffU & (vlTOPp->instruction >> 0x18U)))));
    vlTOPp->Stage2Decode__DOT__decode__DOT__I_imm = 
        ((0xfffff000U & ((- (IData)((1U & (vlTOPp->Stage2Decode__DOT__decode__DOT__instruction 
                                           >> 0x1fU)))) 
                         << 0xcU)) | (0xfffU & (vlTOPp->Stage2Decode__DOT__decode__DOT__instruction 
                                                >> 0x14U)));
    vlTOPp->Stage2Decode__DOT__decode__DOT__B_imm = 
        ((0xfffff800U & ((- (IData)((1U & (vlTOPp->Stage2Decode__DOT__decode__DOT__instruction 
                                           >> 0x1fU)))) 
                         << 0xbU)) | ((0x400U & (vlTOPp->Stage2Decode__DOT__decode__DOT__instruction 
                                                 << 3U)) 
                                      | ((0x3f0U & 
                                          (vlTOPp->Stage2Decode__DOT__decode__DOT__instruction 
                                           >> 0x15U)) 
                                         | (0xfU & 
                                            (vlTOPp->Stage2Decode__DOT__decode__DOT__instruction 
                                             >> 8U)))));
    VL_WRITEF("Instruction: %b_%b_%b_%b_%b_%b\n",7,
              (0x7fU & (vlTOPp->Stage2Decode__DOT__decode__DOT__instruction 
                        >> 0x19U)),5,(0x1fU & (vlTOPp->Stage2Decode__DOT__decode__DOT__instruction 
                                               >> 0x14U)),
              5,(0x1fU & (vlTOPp->Stage2Decode__DOT__decode__DOT__instruction 
                          >> 0xfU)),3,(7U & (vlTOPp->Stage2Decode__DOT__decode__DOT__instruction 
                                             >> 0xcU)),
              5,(0x1fU & (vlTOPp->Stage2Decode__DOT__decode__DOT__instruction 
                          >> 7U)),7,(0x7fU & vlTOPp->Stage2Decode__DOT__decode__DOT__instruction));
    if (VL_UNLIKELY((0xcU == (0x1fU & (vlTOPp->Stage2Decode__DOT__decode__DOT__instruction 
                                       >> 2U))))) {
        VL_WRITEF("DEC: ALURegOp %x (%x <= %x %x)\n",
                  3,(7U & (vlTOPp->Stage2Decode__DOT__decode__DOT__instruction 
                           >> 0xcU)),5,(0x1fU & (vlTOPp->Stage2Decode__DOT__decode__DOT__instruction 
                                                 >> 7U)),
                  5,(0x1fU & (vlTOPp->Stage2Decode__DOT__decode__DOT__instruction 
                              >> 0xfU)),5,(0x1fU & 
                                           (vlTOPp->Stage2Decode__DOT__decode__DOT__instruction 
                                            >> 0x14U)));
        vlTOPp->Stage2Decode__DOT__rs1_idx = (0x1fU 
                                              & (vlTOPp->Stage2Decode__DOT__decode__DOT__instruction 
                                                 >> 0xfU));
        vlTOPp->Stage2Decode__DOT__rs2_idx = (0x1fU 
                                              & (vlTOPp->Stage2Decode__DOT__decode__DOT__instruction 
                                                 >> 0x14U));
        vlTOPp->rd_idx = (0x1fU & (vlTOPp->Stage2Decode__DOT__decode__DOT__instruction 
                                   >> 7U));
        vlTOPp->alu_op = (7U & (vlTOPp->Stage2Decode__DOT__decode__DOT__instruction 
                                >> 0xcU));
        vlTOPp->use_imm = 0U;
        vlTOPp->Stage2Decode__DOT__rs1_use_pc = 0U;
        vlTOPp->imm = 0U;
        vlTOPp->mem_load_enable = 0U;
        vlTOPp->mem_write_enable = 0U;
        vlTOPp->write_enable = 1U;
        vlTOPp->jump_enable = 0U;
        vlTOPp->debug = 0U;
    } else {
        if (VL_UNLIKELY((4U == (0x1fU & (vlTOPp->Stage2Decode__DOT__decode__DOT__instruction 
                                         >> 2U))))) {
            VL_WRITEF("DEC: ALUImmOp %x (%x <= %x %x)\n",
                      3,(7U & (vlTOPp->Stage2Decode__DOT__decode__DOT__instruction 
                               >> 0xcU)),5,(0x1fU & 
                                            (vlTOPp->Stage2Decode__DOT__decode__DOT__instruction 
                                             >> 7U)),
                      5,(0x1fU & (vlTOPp->Stage2Decode__DOT__decode__DOT__instruction 
                                  >> 0xfU)),32,vlTOPp->Stage2Decode__DOT__decode__DOT__I_imm);
            vlTOPp->Stage2Decode__DOT__rs1_idx = (0x1fU 
                                                  & (vlTOPp->Stage2Decode__DOT__decode__DOT__instruction 
                                                     >> 0xfU));
            vlTOPp->Stage2Decode__DOT__rs2_idx = 0U;
            vlTOPp->rd_idx = (0x1fU & (vlTOPp->Stage2Decode__DOT__decode__DOT__instruction 
                                       >> 7U));
            vlTOPp->alu_op = (7U & (vlTOPp->Stage2Decode__DOT__decode__DOT__instruction 
                                    >> 0xcU));
            vlTOPp->use_imm = 1U;
            vlTOPp->Stage2Decode__DOT__rs1_use_pc = 0U;
            vlTOPp->alu_res_neg = 0U;
            vlTOPp->imm = vlTOPp->Stage2Decode__DOT__decode__DOT__I_imm;
            vlTOPp->mem_load_enable = 0U;
            vlTOPp->mem_write_enable = 0U;
            vlTOPp->write_enable = 1U;
            vlTOPp->jump_enable = 0U;
            vlTOPp->debug = 0U;
        } else {
            if (VL_UNLIKELY((0U == (0x1fU & (vlTOPp->Stage2Decode__DOT__decode__DOT__instruction 
                                             >> 2U))))) {
                VL_WRITEF("DEC: Load %x => %x+%x\n",
                          5,(0x1fU & (vlTOPp->Stage2Decode__DOT__decode__DOT__instruction 
                                      >> 7U)),5,(0x1fU 
                                                 & (vlTOPp->Stage2Decode__DOT__decode__DOT__instruction 
                                                    >> 0xfU)),
                          32,vlTOPp->Stage2Decode__DOT__decode__DOT__I_imm);
                vlTOPp->Stage2Decode__DOT__rs1_idx 
                    = (0x1fU & (vlTOPp->Stage2Decode__DOT__decode__DOT__instruction 
                                >> 0xfU));
                vlTOPp->Stage2Decode__DOT__rs2_idx = 0U;
                vlTOPp->rd_idx = (0x1fU & (vlTOPp->Stage2Decode__DOT__decode__DOT__instruction 
                                           >> 7U));
                vlTOPp->alu_op = 0U;
                vlTOPp->use_imm = 1U;
                vlTOPp->Stage2Decode__DOT__rs1_use_pc = 0U;
                vlTOPp->alu_res_neg = 0U;
                vlTOPp->imm = vlTOPp->Stage2Decode__DOT__decode__DOT__I_imm;
                vlTOPp->mem_load_enable = 1U;
                vlTOPp->mem_write_enable = 0U;
                vlTOPp->write_enable = 1U;
                vlTOPp->jump_enable = 0U;
                vlTOPp->debug = 0U;
            } else {
                if (VL_UNLIKELY((8U == (0x1fU & (vlTOPp->Stage2Decode__DOT__decode__DOT__instruction 
                                                 >> 2U))))) {
                    VL_WRITEF("DEC: Store %x => %x+%x\n",
                              5,(0x1fU & (vlTOPp->Stage2Decode__DOT__decode__DOT__instruction 
                                          >> 0x14U)),
                              5,(0x1fU & (vlTOPp->Stage2Decode__DOT__decode__DOT__instruction 
                                          >> 0xfU)),
                              32,vlTOPp->Stage2Decode__DOT__decode__DOT__I_imm);
                    vlTOPp->Stage2Decode__DOT__rs1_idx 
                        = (0x1fU & (vlTOPp->Stage2Decode__DOT__decode__DOT__instruction 
                                    >> 0xfU));
                    vlTOPp->Stage2Decode__DOT__rs2_idx 
                        = (0x1fU & (vlTOPp->Stage2Decode__DOT__decode__DOT__instruction 
                                    >> 0x14U));
                    vlTOPp->rd_idx = (0x1fU & (vlTOPp->Stage2Decode__DOT__decode__DOT__instruction 
                                               >> 7U));
                    vlTOPp->alu_op = 0U;
                    vlTOPp->use_imm = 1U;
                    vlTOPp->Stage2Decode__DOT__rs1_use_pc = 0U;
                    vlTOPp->alu_res_neg = 0U;
                    vlTOPp->imm = ((0xfffff000U & (
                                                   (- (IData)(
                                                              (1U 
                                                               & (vlTOPp->Stage2Decode__DOT__decode__DOT__instruction 
                                                                  >> 0x1fU)))) 
                                                   << 0xcU)) 
                                   | ((0xfe0U & (vlTOPp->Stage2Decode__DOT__decode__DOT__instruction 
                                                 >> 0x14U)) 
                                      | (0x1fU & (vlTOPp->Stage2Decode__DOT__decode__DOT__instruction 
                                                  >> 7U))));
                    vlTOPp->mem_load_enable = 0U;
                    vlTOPp->mem_write_enable = 1U;
                    vlTOPp->write_enable = 0U;
                    vlTOPp->jump_enable = 0U;
                    vlTOPp->debug = 0U;
                } else {
                    if (VL_UNLIKELY((0x1bU == (0x1fU 
                                               & (vlTOPp->Stage2Decode__DOT__decode__DOT__instruction 
                                                  >> 2U))))) {
                        vlTOPp->imm = ((0xfff00000U 
                                        & ((- (IData)(
                                                      (1U 
                                                       & (vlTOPp->Stage2Decode__DOT__decode__DOT__instruction 
                                                          >> 0x1fU)))) 
                                           << 0x14U)) 
                                       | ((0xf8000U 
                                           & vlTOPp->Stage2Decode__DOT__decode__DOT__instruction) 
                                          | ((0x7000U 
                                              & vlTOPp->Stage2Decode__DOT__decode__DOT__instruction) 
                                             | ((0x800U 
                                                 & (vlTOPp->Stage2Decode__DOT__decode__DOT__instruction 
                                                    >> 9U)) 
                                                | (0x7feU 
                                                   & (vlTOPp->Stage2Decode__DOT__decode__DOT__instruction 
                                                      >> 0x14U))))));
                        vlTOPp->Stage2Decode__DOT__rs1_idx = 0U;
                        vlTOPp->Stage2Decode__DOT__rs2_idx = 0U;
                        vlTOPp->rd_idx = (0x1fU & (vlTOPp->Stage2Decode__DOT__decode__DOT__instruction 
                                                   >> 7U));
                        vlTOPp->alu_op = 4U;
                        vlTOPp->use_imm = 0U;
                        vlTOPp->Stage2Decode__DOT__rs1_use_pc = 1U;
                        vlTOPp->alu_res_neg = 0U;
                        vlTOPp->mem_load_enable = 0U;
                        vlTOPp->mem_write_enable = 0U;
                        vlTOPp->write_enable = 1U;
                        vlTOPp->jump_enable = 1U;
                        vlTOPp->debug = 0U;
                        VL_WRITEF("DEC: Jump %x, %11d\n",
                                  32,vlTOPp->imm,32,
                                  vlTOPp->imm);
                    } else {
                        if (VL_UNLIKELY((0x18U == (0x1fU 
                                                   & (vlTOPp->Stage2Decode__DOT__decode__DOT__instruction 
                                                      >> 2U))))) {
                            VL_WRITEF("DEC: Branch by %x\n",
                                      32,(vlTOPp->Stage2Decode__DOT__decode__DOT__B_imm 
                                          << 1U));
                            vlTOPp->Stage2Decode__DOT__rs1_idx 
                                = (0x1fU & (vlTOPp->Stage2Decode__DOT__decode__DOT__instruction 
                                            >> 0xfU));
                            vlTOPp->Stage2Decode__DOT__rs2_idx 
                                = (0x1fU & (vlTOPp->Stage2Decode__DOT__decode__DOT__instruction 
                                            >> 0x14U));
                            vlTOPp->rd_idx = 0U;
                            vlTOPp->alu_op = (3U & 
                                              (vlTOPp->Stage2Decode__DOT__decode__DOT__instruction 
                                               >> 0xdU));
                            vlTOPp->alu_res_neg = (1U 
                                                   & (vlTOPp->Stage2Decode__DOT__decode__DOT__instruction 
                                                      >> 0xcU));
                            vlTOPp->use_imm = 0U;
                            vlTOPp->Stage2Decode__DOT__rs1_use_pc = 0U;
                            vlTOPp->imm = (vlTOPp->Stage2Decode__DOT__decode__DOT__B_imm 
                                           << 1U);
                            vlTOPp->mem_load_enable = 0U;
                            vlTOPp->mem_write_enable = 0U;
                            vlTOPp->write_enable = 0U;
                            vlTOPp->jump_enable = 1U;
                            vlTOPp->debug = 0U;
                        } else {
                            if ((0x1cU == (0x1fU & 
                                           (vlTOPp->Stage2Decode__DOT__decode__DOT__instruction 
                                            >> 2U)))) {
                                VL_WRITEF("DEC: System instruction invoked\n");
                                vlTOPp->Stage2Decode__DOT__rs1_idx = 0U;
                                vlTOPp->Stage2Decode__DOT__rs2_idx = 0U;
                                vlTOPp->rd_idx = 0U;
                                vlTOPp->Stage2Decode__DOT__rs1_use_pc = 0U;
                                vlTOPp->alu_res_neg = 0U;
                                vlTOPp->write_enable = 0U;
                                vlTOPp->jump_enable = 0U;
                                vlTOPp->debug = ((0x2000U 
                                                  == 
                                                  (0x1ffffffU 
                                                   & (vlTOPp->Stage2Decode__DOT__decode__DOT__instruction 
                                                      >> 7U)))
                                                  ? 1U
                                                  : 2U);
                            } else {
                                VL_WRITEF("DEC: Unknown instruction\n");
                                vlTOPp->Stage2Decode__DOT__rs1_idx = 0U;
                                vlTOPp->Stage2Decode__DOT__rs2_idx = 0U;
                                vlTOPp->rd_idx = 0U;
                                vlTOPp->Stage2Decode__DOT__rs1_use_pc = 0U;
                                vlTOPp->alu_res_neg = 0U;
                                vlTOPp->write_enable = 0U;
                                vlTOPp->jump_enable = 0U;
                                vlTOPp->debug = 2U;
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->rs2_val = vlTOPp->Stage2Decode__DOT__gpr__DOT__gp
        [vlTOPp->Stage2Decode__DOT__rs2_idx];
    vlTOPp->rs1_val = ((IData)(vlTOPp->Stage2Decode__DOT__rs1_use_pc)
                        ? vlTOPp->pc : vlTOPp->Stage2Decode__DOT__gpr__DOT__gp
                       [vlTOPp->Stage2Decode__DOT__rs1_idx]);
}

void Vstage_2_decode::_eval(Vstage_2_decode__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstage_2_decode::_eval\n"); );
    Vstage_2_decode* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    vlTOPp->_combo__TOP__2(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

VL_INLINE_OPT QData Vstage_2_decode::_change_request(Vstage_2_decode__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstage_2_decode::_change_request\n"); );
    Vstage_2_decode* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vstage_2_decode::_change_request_1(Vstage_2_decode__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstage_2_decode::_change_request_1\n"); );
    Vstage_2_decode* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vstage_2_decode::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstage_2_decode::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((stall & 0xfeU))) {
        Verilated::overWidthError("stall");}
}
#endif  // VL_DEBUG
