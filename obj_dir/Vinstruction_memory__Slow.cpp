// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vinstruction_memory.h for the primary calling header

#include "Vinstruction_memory.h"
#include "Vinstruction_memory__Syms.h"

//==========

VL_CTOR_IMP(Vinstruction_memory) {
    Vinstruction_memory__Syms* __restrict vlSymsp = __VlSymsp = new Vinstruction_memory__Syms(this, name());
    Vinstruction_memory* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vinstruction_memory::__Vconfigure(Vinstruction_memory__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vinstruction_memory::~Vinstruction_memory() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = nullptr);
}

void Vinstruction_memory::_initial__TOP__1(Vinstruction_memory__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinstruction_memory::_initial__TOP__1\n"); );
    Vinstruction_memory* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    IData/*31:0*/ InstructionMemory__DOT__i;
    // Body
    vlTOPp->InstructionMemory__DOT__fd = VL_FOPEN_NN(
                                                     std::string("gcd.bin")
                                                     , 
                                                     std::string("rb"));
    InstructionMemory__DOT__i = VL_FREAD_I(32,0,129
                                           , vlTOPp->InstructionMemory__DOT__mem
                                           , vlTOPp->InstructionMemory__DOT__fd
                                           , 0, 129);
    ;
    VL_FCLOSE_I(vlTOPp->InstructionMemory__DOT__fd); vlTOPp->InstructionMemory__DOT__fd = 0;
}

void Vinstruction_memory::_eval_initial(Vinstruction_memory__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinstruction_memory::_eval_initial\n"); );
    Vinstruction_memory* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
}

void Vinstruction_memory::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinstruction_memory::final\n"); );
    // Variables
    Vinstruction_memory__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vinstruction_memory* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vinstruction_memory::_eval_settle(Vinstruction_memory__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinstruction_memory::_eval_settle\n"); );
    Vinstruction_memory* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__2(vlSymsp);
}

void Vinstruction_memory::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinstruction_memory::_ctor_var_reset\n"); );
    // Body
    address = VL_RAND_RESET_I(32);
    instruction = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<129; ++__Vi0) {
            InstructionMemory__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }}
    InstructionMemory__DOT__fd = 0;
}
