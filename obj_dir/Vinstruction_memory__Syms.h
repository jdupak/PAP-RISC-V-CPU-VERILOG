// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef _VINSTRUCTION_MEMORY__SYMS_H_
#define _VINSTRUCTION_MEMORY__SYMS_H_  // guard

#include "verilated_heavy.h"

// INCLUDE MODULE CLASSES
#include "Vinstruction_memory.h"

// SYMS CLASS
class Vinstruction_memory__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vinstruction_memory*           TOPp;
    
    // CREATORS
    Vinstruction_memory__Syms(Vinstruction_memory* topp, const char* namep);
    ~Vinstruction_memory__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
