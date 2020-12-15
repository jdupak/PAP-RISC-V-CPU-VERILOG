// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vinstruction_memory.h for the primary calling header

#include "Vinstruction_memory.h"
#include "Vinstruction_memory__Syms.h"

//==========

void Vinstruction_memory::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vinstruction_memory::eval\n"); );
    Vinstruction_memory__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vinstruction_memory* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("memory/instruction_memory.v", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vinstruction_memory::_eval_initial_loop(Vinstruction_memory__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("memory/instruction_memory.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vinstruction_memory::_combo__TOP__2(Vinstruction_memory__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinstruction_memory::_combo__TOP__2\n"); );
    Vinstruction_memory* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->instruction = ((0x80U >= (0xffU & (vlTOPp->address 
                                               >> 2U)))
                            ? vlTOPp->InstructionMemory__DOT__mem
                           [(0xffU & (vlTOPp->address 
                                      >> 2U))] : 0U);
}

void Vinstruction_memory::_eval(Vinstruction_memory__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinstruction_memory::_eval\n"); );
    Vinstruction_memory* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__2(vlSymsp);
}

VL_INLINE_OPT QData Vinstruction_memory::_change_request(Vinstruction_memory__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinstruction_memory::_change_request\n"); );
    Vinstruction_memory* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vinstruction_memory::_change_request_1(Vinstruction_memory__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinstruction_memory::_change_request_1\n"); );
    Vinstruction_memory* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vinstruction_memory::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinstruction_memory::_eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG
