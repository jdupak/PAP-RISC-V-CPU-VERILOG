// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtest_pipeline_cpu.h for the primary calling header

#include "Vtest_pipeline_cpu.h"
#include "Vtest_pipeline_cpu__Syms.h"

//==========

void Vtest_pipeline_cpu::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtest_pipeline_cpu::eval\n"); );
    Vtest_pipeline_cpu__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vtest_pipeline_cpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("test_pipeline_cpu.v", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vtest_pipeline_cpu::_eval_initial_loop(Vtest_pipeline_cpu__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("test_pipeline_cpu.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vtest_pipeline_cpu::_combo__TOP__2(Vtest_pipeline_cpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest_pipeline_cpu::_combo__TOP__2\n"); );
    Vtest_pipeline_cpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->test__DOT__clk = (1U & (~ (IData)(vlTOPp->test__DOT__clk)));
}

VL_INLINE_OPT void Vtest_pipeline_cpu::_sequent__TOP__3(Vtest_pipeline_cpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest_pipeline_cpu::_sequent__TOP__3\n"); );
    Vtest_pipeline_cpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*4:0*/ __Vdlyvdim0__test__DOT__s2__DOT__gpr__DOT__gp__v0;
    CData/*0:0*/ __Vdlyvset__test__DOT__s2__DOT__gpr__DOT__gp__v0;
    CData/*7:0*/ __Vdlyvdim0__test__DOT__s4__DOT__dmem__DOT__mem__v0;
    CData/*0:0*/ __Vdlyvset__test__DOT__s4__DOT__dmem__DOT__mem__v0;
    IData/*31:0*/ __Vdly__test__DOT__s1__DOT__address;
    IData/*31:0*/ __Vdlyvval__test__DOT__s2__DOT__gpr__DOT__gp__v0;
    IData/*31:0*/ __Vdlyvval__test__DOT__s4__DOT__dmem__DOT__mem__v0;
    // Body
    __Vdlyvset__test__DOT__s4__DOT__dmem__DOT__mem__v0 = 0U;
    __Vdlyvset__test__DOT__s2__DOT__gpr__DOT__gp__v0 = 0U;
    __Vdly__test__DOT__s1__DOT__address = vlTOPp->test__DOT__s1__DOT__address;
    VL_WRITEF("====================================================\n");
    VL_WRITEF("PC: 0x%x [jump=%x]\n",32,((IData)(vlTOPp->test__DOT__jump_enable)
                                          ? vlTOPp->test__DOT__jump_address
                                          : ((IData)(4U) 
                                             + vlTOPp->test__DOT__s1__DOT__address)),
              1,(IData)(vlTOPp->test__DOT__jump_enable));
    if (VL_UNLIKELY(vlTOPp->test__DOT__s4__DOT__mem_write_enable)) {
        vlTOPp->test__DOT__s4__DOT__dmem__DOT____Vlvbound1 
            = vlTOPp->test__DOT__rs2_val_34;
        VL_WRITEF("MEM: write [%x]=%x\n",32,vlTOPp->test__DOT__alu_res_34,
                  32,vlTOPp->test__DOT__rs2_val_34);
        if ((0x80U >= (0xffU & (vlTOPp->test__DOT__alu_res_34 
                                >> 2U)))) {
            __Vdlyvval__test__DOT__s4__DOT__dmem__DOT__mem__v0 
                = vlTOPp->test__DOT__s4__DOT__dmem__DOT____Vlvbound1;
            __Vdlyvset__test__DOT__s4__DOT__dmem__DOT__mem__v0 = 1U;
            __Vdlyvdim0__test__DOT__s4__DOT__dmem__DOT__mem__v0 
                = (0xffU & (vlTOPp->test__DOT__alu_res_34 
                            >> 2U));
        }
    }
    if (VL_UNLIKELY(vlTOPp->test__DOT__write_enable_42)) {
        VL_WRITEF("REG: r1=%x r2=%x w[%2#]=%x\n",32,
                  vlTOPp->test__DOT__s2__DOT__gpr__DOT__gp
                  [1U],32,vlTOPp->test__DOT__s2__DOT__gpr__DOT__gp
                  [2U],5,vlTOPp->test__DOT__write_idx,
                  32,vlTOPp->test__DOT__write_data);
        if ((0U != (IData)(vlTOPp->test__DOT__write_idx))) {
            __Vdlyvval__test__DOT__s2__DOT__gpr__DOT__gp__v0 
                = vlTOPp->test__DOT__write_data;
            __Vdlyvset__test__DOT__s2__DOT__gpr__DOT__gp__v0 = 1U;
            __Vdlyvdim0__test__DOT__s2__DOT__gpr__DOT__gp__v0 
                = vlTOPp->test__DOT__write_idx;
        }
    }
    vlTOPp->test__DOT__rs1_val = ((IData)(vlTOPp->test__DOT__s2__DOT__rs1_use_pc)
                                   ? ((IData)(4U) + vlTOPp->test__DOT__s1__DOT__address)
                                   : vlTOPp->test__DOT__s2__DOT__gpr__DOT__gp
                                  [vlTOPp->test__DOT__s2__DOT__rs1_idx]);
    __Vdly__test__DOT__s1__DOT__address = ((IData)(vlTOPp->test__DOT__jump_enable)
                                            ? vlTOPp->test__DOT__jump_address
                                            : vlTOPp->test__DOT__pc);
    if (__Vdlyvset__test__DOT__s2__DOT__gpr__DOT__gp__v0) {
        vlTOPp->test__DOT__s2__DOT__gpr__DOT__gp[__Vdlyvdim0__test__DOT__s2__DOT__gpr__DOT__gp__v0] 
            = __Vdlyvval__test__DOT__s2__DOT__gpr__DOT__gp__v0;
    }
    vlTOPp->test__DOT__rs2_val_34 = vlTOPp->test__DOT__rs2_val;
    vlTOPp->test__DOT__rs2_val_34 = vlTOPp->test__DOT__rs2_val;
    vlTOPp->test__DOT__write_enable_42 = vlTOPp->test__DOT__s4__DOT__reg_write_enable;
    vlTOPp->test__DOT__write_data = ((IData)(vlTOPp->test__DOT__s4__DOT__mem_read_enable)
                                      ? ((0x80U >= 
                                          (0xffU & 
                                           (vlTOPp->test__DOT__alu_res_34 
                                            >> 2U)))
                                          ? vlTOPp->test__DOT__s4__DOT__dmem__DOT__mem
                                         [(0xffU & 
                                           (vlTOPp->test__DOT__alu_res_34 
                                            >> 2U))]
                                          : 0U) : vlTOPp->test__DOT__alu_res_34);
    vlTOPp->test__DOT__write_idx = vlTOPp->test__DOT__rd_idx_34;
    vlTOPp->test__DOT__jump_address = ((IData)(4U) 
                                       + vlTOPp->test__DOT__s1__DOT__address);
    if (__Vdlyvset__test__DOT__s4__DOT__dmem__DOT__mem__v0) {
        vlTOPp->test__DOT__s4__DOT__dmem__DOT__mem[__Vdlyvdim0__test__DOT__s4__DOT__dmem__DOT__mem__v0] 
            = __Vdlyvval__test__DOT__s4__DOT__dmem__DOT__mem__v0;
    }
    vlTOPp->test__DOT__s1__DOT__address = __Vdly__test__DOT__s1__DOT__address;
    vlTOPp->test__DOT__rd_idx_34 = vlTOPp->test__DOT__rd_idx;
    vlTOPp->test__DOT__pc = ((IData)(4U) + vlTOPp->test__DOT__s1__DOT__address);
    vlTOPp->test__DOT__intruction = ((0x80U >= (0xffU 
                                                & (vlTOPp->test__DOT__s1__DOT__address 
                                                   >> 2U)))
                                      ? vlTOPp->test__DOT__s1__DOT__imem__DOT__mem
                                     [(0xffU & (vlTOPp->test__DOT__s1__DOT__address 
                                                >> 2U))]
                                      : 0U);
    vlTOPp->test__DOT__s2__DOT__decode__DOT__instruction 
        = ((0xff000000U & (vlTOPp->test__DOT__intruction 
                           << 0x18U)) | ((0xff0000U 
                                          & (vlTOPp->test__DOT__intruction 
                                             << 8U)) 
                                         | ((0xff00U 
                                             & (vlTOPp->test__DOT__intruction 
                                                >> 8U)) 
                                            | (0xffU 
                                               & (vlTOPp->test__DOT__intruction 
                                                  >> 0x18U)))));
    vlTOPp->test__DOT__s2__DOT__decode__DOT__I_imm 
        = ((0xfffff000U & ((- (IData)((1U & (vlTOPp->test__DOT__s2__DOT__decode__DOT__instruction 
                                             >> 0x1fU)))) 
                           << 0xcU)) | (0xfffU & (vlTOPp->test__DOT__s2__DOT__decode__DOT__instruction 
                                                  >> 0x14U)));
    vlTOPp->test__DOT__s2__DOT__decode__DOT__B_imm 
        = ((0xfffff800U & ((- (IData)((1U & (vlTOPp->test__DOT__s2__DOT__decode__DOT__instruction 
                                             >> 0x1fU)))) 
                           << 0xbU)) | ((0x400U & (vlTOPp->test__DOT__s2__DOT__decode__DOT__instruction 
                                                   << 3U)) 
                                        | ((0x3f0U 
                                            & (vlTOPp->test__DOT__s2__DOT__decode__DOT__instruction 
                                               >> 0x15U)) 
                                           | (0xfU 
                                              & (vlTOPp->test__DOT__s2__DOT__decode__DOT__instruction 
                                                 >> 8U)))));
    VL_WRITEF("Instruction: %b_%b_%b_%b_%b_%b\n",7,
              (0x7fU & (vlTOPp->test__DOT__s2__DOT__decode__DOT__instruction 
                        >> 0x19U)),5,(0x1fU & (vlTOPp->test__DOT__s2__DOT__decode__DOT__instruction 
                                               >> 0x14U)),
              5,(0x1fU & (vlTOPp->test__DOT__s2__DOT__decode__DOT__instruction 
                          >> 0xfU)),3,(7U & (vlTOPp->test__DOT__s2__DOT__decode__DOT__instruction 
                                             >> 0xcU)),
              5,(0x1fU & (vlTOPp->test__DOT__s2__DOT__decode__DOT__instruction 
                          >> 7U)),7,(0x7fU & vlTOPp->test__DOT__s2__DOT__decode__DOT__instruction));
    if (VL_UNLIKELY((0xcU == (0x1fU & (vlTOPp->test__DOT__s2__DOT__decode__DOT__instruction 
                                       >> 2U))))) {
        VL_WRITEF("DEC: ALURegOp %x (%x <= %x %x)\n",
                  3,(7U & (vlTOPp->test__DOT__s2__DOT__decode__DOT__instruction 
                           >> 0xcU)),5,(0x1fU & (vlTOPp->test__DOT__s2__DOT__decode__DOT__instruction 
                                                 >> 7U)),
                  5,(0x1fU & (vlTOPp->test__DOT__s2__DOT__decode__DOT__instruction 
                              >> 0xfU)),5,(0x1fU & 
                                           (vlTOPp->test__DOT__s2__DOT__decode__DOT__instruction 
                                            >> 0x14U)));
        vlTOPp->test__DOT__s2__DOT__rs1_idx = (0x1fU 
                                               & (vlTOPp->test__DOT__s2__DOT__decode__DOT__instruction 
                                                  >> 0xfU));
        vlTOPp->test__DOT__s2__DOT__rs2_idx = (0x1fU 
                                               & (vlTOPp->test__DOT__s2__DOT__decode__DOT__instruction 
                                                  >> 0x14U));
        vlTOPp->test__DOT__rd_idx = (0x1fU & (vlTOPp->test__DOT__s2__DOT__decode__DOT__instruction 
                                              >> 7U));
        vlTOPp->test__DOT__alu_op = (7U & (vlTOPp->test__DOT__s2__DOT__decode__DOT__instruction 
                                           >> 0xcU));
        vlTOPp->test__DOT__s2__DOT__rs1_use_pc = 0U;
        vlTOPp->test__DOT__imm = 0U;
        vlTOPp->test__DOT__jump_enable = 0U;
        vlTOPp->test__DOT__debug = 0U;
    } else {
        if (VL_UNLIKELY((4U == (0x1fU & (vlTOPp->test__DOT__s2__DOT__decode__DOT__instruction 
                                         >> 2U))))) {
            VL_WRITEF("DEC: ALUImmOp %x (%x <= %x %x)\n",
                      3,(7U & (vlTOPp->test__DOT__s2__DOT__decode__DOT__instruction 
                               >> 0xcU)),5,(0x1fU & 
                                            (vlTOPp->test__DOT__s2__DOT__decode__DOT__instruction 
                                             >> 7U)),
                      5,(0x1fU & (vlTOPp->test__DOT__s2__DOT__decode__DOT__instruction 
                                  >> 0xfU)),32,vlTOPp->test__DOT__s2__DOT__decode__DOT__I_imm);
            vlTOPp->test__DOT__s2__DOT__rs1_idx = (0x1fU 
                                                   & (vlTOPp->test__DOT__s2__DOT__decode__DOT__instruction 
                                                      >> 0xfU));
            vlTOPp->test__DOT__s2__DOT__rs2_idx = 0U;
            vlTOPp->test__DOT__rd_idx = (0x1fU & (vlTOPp->test__DOT__s2__DOT__decode__DOT__instruction 
                                                  >> 7U));
            vlTOPp->test__DOT__alu_op = (7U & (vlTOPp->test__DOT__s2__DOT__decode__DOT__instruction 
                                               >> 0xcU));
            vlTOPp->test__DOT__s2__DOT__rs1_use_pc = 0U;
            vlTOPp->test__DOT__alu_res_neg = 0U;
            vlTOPp->test__DOT__imm = vlTOPp->test__DOT__s2__DOT__decode__DOT__I_imm;
            vlTOPp->test__DOT__jump_enable = 0U;
            vlTOPp->test__DOT__debug = 0U;
        } else {
            if (VL_UNLIKELY((0U == (0x1fU & (vlTOPp->test__DOT__s2__DOT__decode__DOT__instruction 
                                             >> 2U))))) {
                VL_WRITEF("DEC: Load %x => %x+%x\n",
                          5,(0x1fU & (vlTOPp->test__DOT__s2__DOT__decode__DOT__instruction 
                                      >> 7U)),5,(0x1fU 
                                                 & (vlTOPp->test__DOT__s2__DOT__decode__DOT__instruction 
                                                    >> 0xfU)),
                          32,vlTOPp->test__DOT__s2__DOT__decode__DOT__I_imm);
                vlTOPp->test__DOT__s2__DOT__rs1_idx 
                    = (0x1fU & (vlTOPp->test__DOT__s2__DOT__decode__DOT__instruction 
                                >> 0xfU));
                vlTOPp->test__DOT__s2__DOT__rs2_idx = 0U;
                vlTOPp->test__DOT__rd_idx = (0x1fU 
                                             & (vlTOPp->test__DOT__s2__DOT__decode__DOT__instruction 
                                                >> 7U));
                vlTOPp->test__DOT__alu_op = 0U;
                vlTOPp->test__DOT__s2__DOT__rs1_use_pc = 0U;
                vlTOPp->test__DOT__alu_res_neg = 0U;
                vlTOPp->test__DOT__imm = vlTOPp->test__DOT__s2__DOT__decode__DOT__I_imm;
                vlTOPp->test__DOT__jump_enable = 0U;
                vlTOPp->test__DOT__debug = 0U;
            } else {
                if (VL_UNLIKELY((8U == (0x1fU & (vlTOPp->test__DOT__s2__DOT__decode__DOT__instruction 
                                                 >> 2U))))) {
                    VL_WRITEF("DEC: Store %x => %x+%x\n",
                              5,(0x1fU & (vlTOPp->test__DOT__s2__DOT__decode__DOT__instruction 
                                          >> 0x14U)),
                              5,(0x1fU & (vlTOPp->test__DOT__s2__DOT__decode__DOT__instruction 
                                          >> 0xfU)),
                              32,vlTOPp->test__DOT__s2__DOT__decode__DOT__I_imm);
                    vlTOPp->test__DOT__s2__DOT__rs1_idx 
                        = (0x1fU & (vlTOPp->test__DOT__s2__DOT__decode__DOT__instruction 
                                    >> 0xfU));
                    vlTOPp->test__DOT__s2__DOT__rs2_idx 
                        = (0x1fU & (vlTOPp->test__DOT__s2__DOT__decode__DOT__instruction 
                                    >> 0x14U));
                    vlTOPp->test__DOT__rd_idx = (0x1fU 
                                                 & (vlTOPp->test__DOT__s2__DOT__decode__DOT__instruction 
                                                    >> 7U));
                    vlTOPp->test__DOT__alu_op = 0U;
                    vlTOPp->test__DOT__s2__DOT__rs1_use_pc = 0U;
                    vlTOPp->test__DOT__alu_res_neg = 0U;
                    vlTOPp->test__DOT__imm = ((0xfffff000U 
                                               & ((- (IData)(
                                                             (1U 
                                                              & (vlTOPp->test__DOT__s2__DOT__decode__DOT__instruction 
                                                                 >> 0x1fU)))) 
                                                  << 0xcU)) 
                                              | ((0xfe0U 
                                                  & (vlTOPp->test__DOT__s2__DOT__decode__DOT__instruction 
                                                     >> 0x14U)) 
                                                 | (0x1fU 
                                                    & (vlTOPp->test__DOT__s2__DOT__decode__DOT__instruction 
                                                       >> 7U))));
                    vlTOPp->test__DOT__jump_enable = 0U;
                    vlTOPp->test__DOT__debug = 0U;
                } else {
                    if (VL_UNLIKELY((0x1bU == (0x1fU 
                                               & (vlTOPp->test__DOT__s2__DOT__decode__DOT__instruction 
                                                  >> 2U))))) {
                        vlTOPp->test__DOT__imm = ((0xfff00000U 
                                                   & ((- (IData)(
                                                                 (1U 
                                                                  & (vlTOPp->test__DOT__s2__DOT__decode__DOT__instruction 
                                                                     >> 0x1fU)))) 
                                                      << 0x14U)) 
                                                  | ((0xf8000U 
                                                      & vlTOPp->test__DOT__s2__DOT__decode__DOT__instruction) 
                                                     | ((0x7000U 
                                                         & vlTOPp->test__DOT__s2__DOT__decode__DOT__instruction) 
                                                        | ((0x800U 
                                                            & (vlTOPp->test__DOT__s2__DOT__decode__DOT__instruction 
                                                               >> 9U)) 
                                                           | (0x7feU 
                                                              & (vlTOPp->test__DOT__s2__DOT__decode__DOT__instruction 
                                                                 >> 0x14U))))));
                        vlTOPp->test__DOT__s2__DOT__rs1_idx = 0U;
                        vlTOPp->test__DOT__s2__DOT__rs2_idx = 0U;
                        vlTOPp->test__DOT__rd_idx = 
                            (0x1fU & (vlTOPp->test__DOT__s2__DOT__decode__DOT__instruction 
                                      >> 7U));
                        vlTOPp->test__DOT__alu_op = 4U;
                        vlTOPp->test__DOT__s2__DOT__rs1_use_pc = 1U;
                        vlTOPp->test__DOT__alu_res_neg = 0U;
                        vlTOPp->test__DOT__jump_enable = 1U;
                        vlTOPp->test__DOT__debug = 0U;
                        VL_WRITEF("DEC: Jump %x, %11d\n",
                                  32,vlTOPp->test__DOT__imm,
                                  32,vlTOPp->test__DOT__imm);
                    } else {
                        if (VL_UNLIKELY((0x18U == (0x1fU 
                                                   & (vlTOPp->test__DOT__s2__DOT__decode__DOT__instruction 
                                                      >> 2U))))) {
                            VL_WRITEF("DEC: Branch by %x\n",
                                      32,(vlTOPp->test__DOT__s2__DOT__decode__DOT__B_imm 
                                          << 1U));
                            vlTOPp->test__DOT__s2__DOT__rs1_idx 
                                = (0x1fU & (vlTOPp->test__DOT__s2__DOT__decode__DOT__instruction 
                                            >> 0xfU));
                            vlTOPp->test__DOT__s2__DOT__rs2_idx 
                                = (0x1fU & (vlTOPp->test__DOT__s2__DOT__decode__DOT__instruction 
                                            >> 0x14U));
                            vlTOPp->test__DOT__rd_idx = 0U;
                            vlTOPp->test__DOT__alu_op 
                                = (3U & (vlTOPp->test__DOT__s2__DOT__decode__DOT__instruction 
                                         >> 0xdU));
                            vlTOPp->test__DOT__alu_res_neg 
                                = (1U & (vlTOPp->test__DOT__s2__DOT__decode__DOT__instruction 
                                         >> 0xcU));
                            vlTOPp->test__DOT__s2__DOT__rs1_use_pc = 0U;
                            vlTOPp->test__DOT__imm 
                                = (vlTOPp->test__DOT__s2__DOT__decode__DOT__B_imm 
                                   << 1U);
                            vlTOPp->test__DOT__jump_enable = 1U;
                            vlTOPp->test__DOT__debug = 0U;
                        } else {
                            if ((0x1cU == (0x1fU & 
                                           (vlTOPp->test__DOT__s2__DOT__decode__DOT__instruction 
                                            >> 2U)))) {
                                VL_WRITEF("DEC: System instruction invoked\n");
                                vlTOPp->test__DOT__s2__DOT__rs1_idx = 0U;
                                vlTOPp->test__DOT__s2__DOT__rs2_idx = 0U;
                                vlTOPp->test__DOT__rd_idx = 0U;
                                vlTOPp->test__DOT__s2__DOT__rs1_use_pc = 0U;
                                vlTOPp->test__DOT__alu_res_neg = 0U;
                                vlTOPp->test__DOT__jump_enable = 0U;
                                vlTOPp->test__DOT__debug 
                                    = ((0x2000U == 
                                        (0x1ffffffU 
                                         & (vlTOPp->test__DOT__s2__DOT__decode__DOT__instruction 
                                            >> 7U)))
                                        ? 1U : 2U);
                            } else {
                                VL_WRITEF("DEC: Unknown instruction\n");
                                vlTOPp->test__DOT__s2__DOT__rs1_idx = 0U;
                                vlTOPp->test__DOT__s2__DOT__rs2_idx = 0U;
                                vlTOPp->test__DOT__rd_idx = 0U;
                                vlTOPp->test__DOT__s2__DOT__rs1_use_pc = 0U;
                                vlTOPp->test__DOT__alu_res_neg = 0U;
                                vlTOPp->test__DOT__jump_enable = 0U;
                                vlTOPp->test__DOT__debug = 2U;
                            }
                        }
                    }
                }
            }
        }
    }
    if (VL_UNLIKELY((1U == (IData)(vlTOPp->test__DOT__debug)))) {
        VL_WRITEF("Breakpoint reached\n");
        VL_FINISH_MT("test_pipeline_cpu.v", 113, "");
    } else {
        if (VL_UNLIKELY((2U == (IData)(vlTOPp->test__DOT__debug)))) {
            VL_WRITEF("Illegal instruction - teminating\n");
            VL_FINISH_MT("test_pipeline_cpu.v", 117, "");
        }
    }
    vlTOPp->test__DOT__rs2_val = vlTOPp->test__DOT__s2__DOT__gpr__DOT__gp
        [vlTOPp->test__DOT__s2__DOT__rs2_idx];
    if (((((((((0U == (IData)(vlTOPp->test__DOT__alu_op)) 
               | (1U == (IData)(vlTOPp->test__DOT__alu_op))) 
              | (2U == (IData)(vlTOPp->test__DOT__alu_op))) 
             | (3U == (IData)(vlTOPp->test__DOT__alu_op))) 
            | (4U == (IData)(vlTOPp->test__DOT__alu_op))) 
           | (5U == (IData)(vlTOPp->test__DOT__alu_op))) 
          | (6U == (IData)(vlTOPp->test__DOT__alu_op))) 
         | (7U == (IData)(vlTOPp->test__DOT__alu_op)))) {
        vlTOPp->test__DOT__alu_res_34 = ((0U == (IData)(vlTOPp->test__DOT__alu_op))
                                          ? (vlTOPp->test__DOT__rs1_val 
                                             + vlTOPp->test__DOT__imm)
                                          : ((1U == (IData)(vlTOPp->test__DOT__alu_op))
                                              ? ((0x1fU 
                                                  >= vlTOPp->test__DOT__imm)
                                                  ? 
                                                 (vlTOPp->test__DOT__rs1_val 
                                                  << vlTOPp->test__DOT__imm)
                                                  : 0U)
                                              : ((2U 
                                                  == (IData)(vlTOPp->test__DOT__alu_op))
                                                  ? 
                                                 VL_LTS_III(32,32,32, vlTOPp->test__DOT__rs1_val, vlTOPp->test__DOT__imm)
                                                  : 
                                                 ((3U 
                                                   == (IData)(vlTOPp->test__DOT__alu_op))
                                                   ? 
                                                  (vlTOPp->test__DOT__rs1_val 
                                                   < vlTOPp->test__DOT__imm)
                                                   : 
                                                  ((4U 
                                                    == (IData)(vlTOPp->test__DOT__alu_op))
                                                    ? 
                                                   (vlTOPp->test__DOT__rs1_val 
                                                    ^ vlTOPp->test__DOT__imm)
                                                    : 
                                                   ((5U 
                                                     == (IData)(vlTOPp->test__DOT__alu_op))
                                                     ? 
                                                    ((IData)(vlTOPp->test__DOT__alu_res_neg)
                                                      ? 
                                                     ((0x1fU 
                                                       >= vlTOPp->test__DOT__imm)
                                                       ? 
                                                      (vlTOPp->test__DOT__rs1_val 
                                                       >> vlTOPp->test__DOT__imm)
                                                       : 0U)
                                                      : 
                                                     ((0x1fU 
                                                       >= vlTOPp->test__DOT__imm)
                                                       ? 
                                                      (vlTOPp->test__DOT__rs1_val 
                                                       >> vlTOPp->test__DOT__imm)
                                                       : 0U))
                                                     : 
                                                    ((6U 
                                                      == (IData)(vlTOPp->test__DOT__alu_op))
                                                      ? 
                                                     (vlTOPp->test__DOT__rs1_val 
                                                      | vlTOPp->test__DOT__imm)
                                                      : 
                                                     (vlTOPp->test__DOT__rs1_val 
                                                      & vlTOPp->test__DOT__imm))))))));
    }
    VL_WRITEF("ALU: %x -> (%10# %11d) = %11d\n",3,vlTOPp->test__DOT__alu_op,
              32,vlTOPp->test__DOT__rs1_val,32,vlTOPp->test__DOT__imm,
              32,vlTOPp->test__DOT__alu_res_34);
}

void Vtest_pipeline_cpu::_eval(Vtest_pipeline_cpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest_pipeline_cpu::_eval\n"); );
    Vtest_pipeline_cpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__2(vlSymsp);
    if (((IData)(vlTOPp->__VinpClk__TOP__test__DOT__clk) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__test__DOT__clk)))) {
        vlTOPp->_sequent__TOP__3(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__test__DOT__clk 
        = vlTOPp->__VinpClk__TOP__test__DOT__clk;
    vlTOPp->__VinpClk__TOP__test__DOT__clk = vlTOPp->test__DOT__clk;
}

VL_INLINE_OPT QData Vtest_pipeline_cpu::_change_request(Vtest_pipeline_cpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest_pipeline_cpu::_change_request\n"); );
    Vtest_pipeline_cpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vtest_pipeline_cpu::_change_request_1(Vtest_pipeline_cpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest_pipeline_cpu::_change_request_1\n"); );
    Vtest_pipeline_cpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    __req |= ((vlTOPp->test__DOT__clk ^ vlTOPp->__Vchglast__TOP__test__DOT__clk));
    VL_DEBUG_IF( if(__req && ((vlTOPp->test__DOT__clk ^ vlTOPp->__Vchglast__TOP__test__DOT__clk))) VL_DBG_MSGF("        CHANGE: test_pipeline_cpu.v:2: test.clk\n"); );
    // Final
    vlTOPp->__Vchglast__TOP__test__DOT__clk = vlTOPp->test__DOT__clk;
    return __req;
}

#ifdef VL_DEBUG
void Vtest_pipeline_cpu::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest_pipeline_cpu::_eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG
