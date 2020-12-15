// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdecode.h for the primary calling header

#include "Vdecode.h"
#include "Vdecode__Syms.h"

//==========

void Vdecode::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vdecode::eval\n"); );
    Vdecode__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vdecode* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("decode/decode.v", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vdecode::_eval_initial_loop(Vdecode__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("decode/decode.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vdecode::_combo__TOP__1(Vdecode__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecode::_combo__TOP__1\n"); );
    Vdecode* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->Decode__DOT__instruction = ((0xff000000U 
                                         & (vlTOPp->_instruction 
                                            << 0x18U)) 
                                        | ((0xff0000U 
                                            & (vlTOPp->_instruction 
                                               << 8U)) 
                                           | ((0xff00U 
                                               & (vlTOPp->_instruction 
                                                  >> 8U)) 
                                              | (0xffU 
                                                 & (vlTOPp->_instruction 
                                                    >> 0x18U)))));
    vlTOPp->Decode__DOT__I_imm = ((0xfffff000U & ((- (IData)(
                                                             (1U 
                                                              & (vlTOPp->Decode__DOT__instruction 
                                                                 >> 0x1fU)))) 
                                                  << 0xcU)) 
                                  | (0xfffU & (vlTOPp->Decode__DOT__instruction 
                                               >> 0x14U)));
    vlTOPp->Decode__DOT__B_imm = ((0xfffff800U & ((- (IData)(
                                                             (1U 
                                                              & (vlTOPp->Decode__DOT__instruction 
                                                                 >> 0x1fU)))) 
                                                  << 0xbU)) 
                                  | ((0x400U & (vlTOPp->Decode__DOT__instruction 
                                                << 3U)) 
                                     | ((0x3f0U & (vlTOPp->Decode__DOT__instruction 
                                                   >> 0x15U)) 
                                        | (0xfU & (vlTOPp->Decode__DOT__instruction 
                                                   >> 8U)))));
    VL_WRITEF("Instruction: %b_%b_%b_%b_%b_%b\n",7,
              (0x7fU & (vlTOPp->Decode__DOT__instruction 
                        >> 0x19U)),5,(0x1fU & (vlTOPp->Decode__DOT__instruction 
                                               >> 0x14U)),
              5,(0x1fU & (vlTOPp->Decode__DOT__instruction 
                          >> 0xfU)),3,(7U & (vlTOPp->Decode__DOT__instruction 
                                             >> 0xcU)),
              5,(0x1fU & (vlTOPp->Decode__DOT__instruction 
                          >> 7U)),7,(0x7fU & vlTOPp->Decode__DOT__instruction));
    if (VL_UNLIKELY((0xcU == (0x1fU & (vlTOPp->Decode__DOT__instruction 
                                       >> 2U))))) {
        VL_WRITEF("DEC: ALURegOp %x (%x <= %x %x)\n",
                  3,(7U & (vlTOPp->Decode__DOT__instruction 
                           >> 0xcU)),5,(0x1fU & (vlTOPp->Decode__DOT__instruction 
                                                 >> 7U)),
                  5,(0x1fU & (vlTOPp->Decode__DOT__instruction 
                              >> 0xfU)),5,(0x1fU & 
                                           (vlTOPp->Decode__DOT__instruction 
                                            >> 0x14U)));
        vlTOPp->alu_rs1 = (0x1fU & (vlTOPp->Decode__DOT__instruction 
                                    >> 0xfU));
        vlTOPp->alu_rs2 = (0x1fU & (vlTOPp->Decode__DOT__instruction 
                                    >> 0x14U));
        vlTOPp->alu_rd = (0x1fU & (vlTOPp->Decode__DOT__instruction 
                                   >> 7U));
        vlTOPp->alu_op = (7U & (vlTOPp->Decode__DOT__instruction 
                                >> 0xcU));
        vlTOPp->alu_use_imm = 0U;
        vlTOPp->alu_rs1_pc = 0U;
        vlTOPp->alu_rs2_neg = ((0U == (7U & (vlTOPp->Decode__DOT__instruction 
                                             >> 0xcU))) 
                               & (0x20U == (0x7fU & 
                                            (vlTOPp->Decode__DOT__instruction 
                                             >> 0x19U))));
        vlTOPp->imm = 0U;
        vlTOPp->mem_load = 0U;
        vlTOPp->mem_store = 0U;
        vlTOPp->write_enable = 1U;
        vlTOPp->jump_enable = 0U;
        vlTOPp->debug = 0U;
    } else {
        if (VL_UNLIKELY((4U == (0x1fU & (vlTOPp->Decode__DOT__instruction 
                                         >> 2U))))) {
            VL_WRITEF("DEC: ALUImmOp %x (%x <= %x %x)\n",
                      3,(7U & (vlTOPp->Decode__DOT__instruction 
                               >> 0xcU)),5,(0x1fU & 
                                            (vlTOPp->Decode__DOT__instruction 
                                             >> 7U)),
                      5,(0x1fU & (vlTOPp->Decode__DOT__instruction 
                                  >> 0xfU)),32,vlTOPp->Decode__DOT__I_imm);
            vlTOPp->alu_rs1 = (0x1fU & (vlTOPp->Decode__DOT__instruction 
                                        >> 0xfU));
            vlTOPp->alu_rs2 = 0U;
            vlTOPp->alu_rd = (0x1fU & (vlTOPp->Decode__DOT__instruction 
                                       >> 7U));
            vlTOPp->alu_op = (7U & (vlTOPp->Decode__DOT__instruction 
                                    >> 0xcU));
            vlTOPp->alu_use_imm = 1U;
            vlTOPp->alu_rs1_pc = 0U;
            vlTOPp->alu_rs2_neg = ((0U == (7U & (vlTOPp->Decode__DOT__instruction 
                                                 >> 0xcU))) 
                                   & (0x20U == (0x7fU 
                                                & (vlTOPp->Decode__DOT__instruction 
                                                   >> 0x19U))));
            vlTOPp->alu_res_neg = 0U;
            vlTOPp->imm = vlTOPp->Decode__DOT__I_imm;
            vlTOPp->mem_load = 0U;
            vlTOPp->mem_store = 0U;
            vlTOPp->write_enable = 1U;
            vlTOPp->jump_enable = 0U;
            vlTOPp->debug = 0U;
        } else {
            if (VL_UNLIKELY((0U == (0x1fU & (vlTOPp->Decode__DOT__instruction 
                                             >> 2U))))) {
                VL_WRITEF("DEC: Load %x => %x+%x\n",
                          5,(0x1fU & (vlTOPp->Decode__DOT__instruction 
                                      >> 7U)),5,(0x1fU 
                                                 & (vlTOPp->Decode__DOT__instruction 
                                                    >> 0xfU)),
                          32,vlTOPp->Decode__DOT__I_imm);
                vlTOPp->alu_rs1 = (0x1fU & (vlTOPp->Decode__DOT__instruction 
                                            >> 0xfU));
                vlTOPp->alu_rs2 = 0U;
                vlTOPp->alu_rd = (0x1fU & (vlTOPp->Decode__DOT__instruction 
                                           >> 7U));
                vlTOPp->alu_op = 0U;
                vlTOPp->alu_use_imm = 1U;
                vlTOPp->alu_rs1_pc = 0U;
                vlTOPp->alu_rs2_neg = 0U;
                vlTOPp->alu_res_neg = 0U;
                vlTOPp->imm = vlTOPp->Decode__DOT__I_imm;
                vlTOPp->mem_load = 1U;
                vlTOPp->mem_store = 0U;
                vlTOPp->write_enable = 1U;
                vlTOPp->jump_enable = 0U;
                vlTOPp->debug = 0U;
            } else {
                if (VL_UNLIKELY((8U == (0x1fU & (vlTOPp->Decode__DOT__instruction 
                                                 >> 2U))))) {
                    VL_WRITEF("DEC: Store %x => %x+%x\n",
                              5,(0x1fU & (vlTOPp->Decode__DOT__instruction 
                                          >> 0x14U)),
                              5,(0x1fU & (vlTOPp->Decode__DOT__instruction 
                                          >> 0xfU)),
                              32,vlTOPp->Decode__DOT__I_imm);
                    vlTOPp->alu_rs1 = (0x1fU & (vlTOPp->Decode__DOT__instruction 
                                                >> 0xfU));
                    vlTOPp->alu_rs2 = (0x1fU & (vlTOPp->Decode__DOT__instruction 
                                                >> 0x14U));
                    vlTOPp->alu_rd = (0x1fU & (vlTOPp->Decode__DOT__instruction 
                                               >> 7U));
                    vlTOPp->alu_op = 0U;
                    vlTOPp->alu_use_imm = 1U;
                    vlTOPp->alu_rs1_pc = 0U;
                    vlTOPp->alu_rs2_neg = 0U;
                    vlTOPp->alu_res_neg = 0U;
                    vlTOPp->imm = ((0xfffff000U & (
                                                   (- (IData)(
                                                              (1U 
                                                               & (vlTOPp->Decode__DOT__instruction 
                                                                  >> 0x1fU)))) 
                                                   << 0xcU)) 
                                   | ((0xfe0U & (vlTOPp->Decode__DOT__instruction 
                                                 >> 0x14U)) 
                                      | (0x1fU & (vlTOPp->Decode__DOT__instruction 
                                                  >> 7U))));
                    vlTOPp->mem_load = 0U;
                    vlTOPp->mem_store = 1U;
                    vlTOPp->write_enable = 0U;
                    vlTOPp->jump_enable = 0U;
                    vlTOPp->debug = 0U;
                } else {
                    if (VL_UNLIKELY((0x1bU == (0x1fU 
                                               & (vlTOPp->Decode__DOT__instruction 
                                                  >> 2U))))) {
                        vlTOPp->imm = ((0xfff00000U 
                                        & ((- (IData)(
                                                      (1U 
                                                       & (vlTOPp->Decode__DOT__instruction 
                                                          >> 0x1fU)))) 
                                           << 0x14U)) 
                                       | ((0xf8000U 
                                           & vlTOPp->Decode__DOT__instruction) 
                                          | ((0x7000U 
                                              & vlTOPp->Decode__DOT__instruction) 
                                             | ((0x800U 
                                                 & (vlTOPp->Decode__DOT__instruction 
                                                    >> 9U)) 
                                                | (0x7feU 
                                                   & (vlTOPp->Decode__DOT__instruction 
                                                      >> 0x14U))))));
                        vlTOPp->alu_rs1 = 0U;
                        vlTOPp->alu_rs2 = 0U;
                        vlTOPp->alu_rd = (0x1fU & (vlTOPp->Decode__DOT__instruction 
                                                   >> 7U));
                        vlTOPp->alu_op = 4U;
                        vlTOPp->alu_use_imm = 0U;
                        vlTOPp->alu_rs1_pc = 1U;
                        vlTOPp->alu_rs2_neg = 0U;
                        vlTOPp->alu_res_neg = 0U;
                        vlTOPp->mem_load = 0U;
                        vlTOPp->mem_store = 0U;
                        vlTOPp->write_enable = 1U;
                        vlTOPp->jump_enable = 1U;
                        vlTOPp->debug = 0U;
                        VL_WRITEF("DEC: Jump %x, %11d\n",
                                  32,vlTOPp->imm,32,
                                  vlTOPp->imm);
                    } else {
                        if (VL_UNLIKELY((0x18U == (0x1fU 
                                                   & (vlTOPp->Decode__DOT__instruction 
                                                      >> 2U))))) {
                            VL_WRITEF("DEC: Branch by %x\n",
                                      32,(vlTOPp->Decode__DOT__B_imm 
                                          << 1U));
                            vlTOPp->alu_rs1 = (0x1fU 
                                               & (vlTOPp->Decode__DOT__instruction 
                                                  >> 0xfU));
                            vlTOPp->alu_rs2 = (0x1fU 
                                               & (vlTOPp->Decode__DOT__instruction 
                                                  >> 0x14U));
                            vlTOPp->alu_rd = 0U;
                            vlTOPp->alu_op = (3U & 
                                              (vlTOPp->Decode__DOT__instruction 
                                               >> 0xdU));
                            vlTOPp->alu_rs2_neg = (1U 
                                                   & (~ 
                                                      (vlTOPp->Decode__DOT__instruction 
                                                       >> 0xeU)));
                            vlTOPp->alu_res_neg = (1U 
                                                   & (vlTOPp->Decode__DOT__instruction 
                                                      >> 0xcU));
                            vlTOPp->alu_use_imm = 0U;
                            vlTOPp->alu_rs1_pc = 0U;
                            vlTOPp->imm = (vlTOPp->Decode__DOT__B_imm 
                                           << 1U);
                            vlTOPp->mem_load = 0U;
                            vlTOPp->mem_store = 0U;
                            vlTOPp->write_enable = 0U;
                            vlTOPp->jump_enable = 1U;
                            vlTOPp->debug = 0U;
                        } else {
                            if ((0x1cU == (0x1fU & 
                                           (vlTOPp->Decode__DOT__instruction 
                                            >> 2U)))) {
                                VL_WRITEF("DEC: System instruction invoked\n");
                                vlTOPp->alu_rs1 = 0U;
                                vlTOPp->alu_rs2 = 0U;
                                vlTOPp->alu_rd = 0U;
                                vlTOPp->alu_rs1_pc = 0U;
                                vlTOPp->alu_res_neg = 0U;
                                vlTOPp->write_enable = 0U;
                                vlTOPp->jump_enable = 0U;
                                vlTOPp->debug = ((0x2000U 
                                                  == 
                                                  (0x1ffffffU 
                                                   & (vlTOPp->Decode__DOT__instruction 
                                                      >> 7U)))
                                                  ? 1U
                                                  : 2U);
                            } else {
                                VL_WRITEF("DEC: Unknown instruction\n");
                                vlTOPp->alu_rs1 = 0U;
                                vlTOPp->alu_rs2 = 0U;
                                vlTOPp->alu_rd = 0U;
                                vlTOPp->alu_rs1_pc = 0U;
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
}

void Vdecode::_eval(Vdecode__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecode::_eval\n"); );
    Vdecode* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

VL_INLINE_OPT QData Vdecode::_change_request(Vdecode__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecode::_change_request\n"); );
    Vdecode* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vdecode::_change_request_1(Vdecode__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecode::_change_request_1\n"); );
    Vdecode* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vdecode::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecode::_eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG
