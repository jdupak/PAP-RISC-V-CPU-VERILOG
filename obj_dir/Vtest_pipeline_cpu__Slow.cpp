// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtest_pipeline_cpu.h for the primary calling header

#include "Vtest_pipeline_cpu.h"
#include "Vtest_pipeline_cpu__Syms.h"

//==========

VL_CTOR_IMP(Vtest_pipeline_cpu) {
    Vtest_pipeline_cpu__Syms* __restrict vlSymsp = __VlSymsp = new Vtest_pipeline_cpu__Syms(this, name());
    Vtest_pipeline_cpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vtest_pipeline_cpu::__Vconfigure(Vtest_pipeline_cpu__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vtest_pipeline_cpu::~Vtest_pipeline_cpu() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = nullptr);
}

void Vtest_pipeline_cpu::_initial__TOP__1(Vtest_pipeline_cpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest_pipeline_cpu::_initial__TOP__1\n"); );
    Vtest_pipeline_cpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    IData/*31:0*/ test__DOT__s1__DOT__imem__DOT__i;
    // Body
    vlTOPp->test__DOT__s1__DOT__imem__DOT__fd = VL_FOPEN_NN(
                                                            std::string("gcd.bin")
                                                            , 
                                                            std::string("rb"));
    test__DOT__s1__DOT__imem__DOT__i = VL_FREAD_I(32
                                                  ,0
                                                  ,129
                                                  , vlTOPp->test__DOT__s1__DOT__imem__DOT__mem
                                                  , vlTOPp->test__DOT__s1__DOT__imem__DOT__fd
                                                  , 0
                                                  , 129);
    ;
    VL_FCLOSE_I(vlTOPp->test__DOT__s1__DOT__imem__DOT__fd); vlTOPp->test__DOT__s1__DOT__imem__DOT__fd = 0;
    vlTOPp->test__DOT__clk = 0U;
    vlTOPp->test__DOT__alu_res_34 = 0U;
    vlTOPp->test__DOT__s1__DOT__address = 0U;
    VL_WRITEF("PC: 0x00000000\n");
}

void Vtest_pipeline_cpu::_settle__TOP__4(Vtest_pipeline_cpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest_pipeline_cpu::_settle__TOP__4\n"); );
    Vtest_pipeline_cpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->test__DOT__clk = (1U & (~ (IData)(vlTOPp->test__DOT__clk)));
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

void Vtest_pipeline_cpu::_eval_initial(Vtest_pipeline_cpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest_pipeline_cpu::_eval_initial\n"); );
    Vtest_pipeline_cpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__test__DOT__clk 
        = vlTOPp->__VinpClk__TOP__test__DOT__clk;
}

void Vtest_pipeline_cpu::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest_pipeline_cpu::final\n"); );
    // Variables
    Vtest_pipeline_cpu__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vtest_pipeline_cpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vtest_pipeline_cpu::_eval_settle(Vtest_pipeline_cpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest_pipeline_cpu::_eval_settle\n"); );
    Vtest_pipeline_cpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__4(vlSymsp);
}

void Vtest_pipeline_cpu::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtest_pipeline_cpu::_ctor_var_reset\n"); );
    // Body
    test__DOT__clk = VL_RAND_RESET_I(1);
    test__DOT__intruction = VL_RAND_RESET_I(32);
    test__DOT__pc = VL_RAND_RESET_I(32);
    test__DOT__jump_address = VL_RAND_RESET_I(32);
    test__DOT__jump_enable = VL_RAND_RESET_I(1);
    test__DOT__rs1_val = VL_RAND_RESET_I(32);
    test__DOT__rs2_val = VL_RAND_RESET_I(32);
    test__DOT__imm = VL_RAND_RESET_I(32);
    test__DOT__rd_idx = VL_RAND_RESET_I(5);
    test__DOT__alu_op = VL_RAND_RESET_I(3);
    test__DOT__alu_res_neg = VL_RAND_RESET_I(1);
    test__DOT__write_data = VL_RAND_RESET_I(32);
    test__DOT__write_idx = VL_RAND_RESET_I(5);
    test__DOT__write_enable_42 = VL_RAND_RESET_I(1);
    test__DOT__debug = VL_RAND_RESET_I(2);
    test__DOT__alu_res_34 = VL_RAND_RESET_I(32);
    test__DOT__rs2_val_34 = VL_RAND_RESET_I(32);
    test__DOT__rd_idx_34 = VL_RAND_RESET_I(5);
    test__DOT__s1__DOT__address = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<129; ++__Vi0) {
            test__DOT__s1__DOT__imem__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }}
    test__DOT__s1__DOT__imem__DOT__fd = 0;
    test__DOT__s2__DOT__rs1_idx = VL_RAND_RESET_I(5);
    test__DOT__s2__DOT__rs2_idx = VL_RAND_RESET_I(5);
    test__DOT__s2__DOT__rs1_use_pc = VL_RAND_RESET_I(1);
    test__DOT__s2__DOT__decode__DOT__I_imm = VL_RAND_RESET_I(32);
    test__DOT__s2__DOT__decode__DOT__B_imm = VL_RAND_RESET_I(32);
    test__DOT__s2__DOT__decode__DOT__instruction = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<32; ++__Vi0) {
            test__DOT__s2__DOT__gpr__DOT__gp[__Vi0] = VL_RAND_RESET_I(32);
    }}
    test__DOT__s4__DOT__mem_read_enable = VL_RAND_RESET_I(1);
    test__DOT__s4__DOT__mem_write_enable = VL_RAND_RESET_I(1);
    test__DOT__s4__DOT__reg_write_enable = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<129; ++__Vi0) {
            test__DOT__s4__DOT__dmem__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }}
    test__DOT__s4__DOT__dmem__DOT____Vlvbound1 = VL_RAND_RESET_I(32);
    __VinpClk__TOP__test__DOT__clk = VL_RAND_RESET_I(1);
    __Vchglast__TOP__test__DOT__clk = VL_RAND_RESET_I(1);
}
