// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef _VPROGRAM_COUNTER__SYMS_H_
#define _VPROGRAM_COUNTER__SYMS_H_  // guard

#include "verilated_heavy.h"

// INCLUDE MODULE CLASSES
#include "Vprogram_counter.h"

// SYMS CLASS
class Vprogram_counter__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vprogram_counter*              TOPp;
    
    // CREATORS
    Vprogram_counter__Syms(Vprogram_counter* topp, const char* namep);
    ~Vprogram_counter__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
