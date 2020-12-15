// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef _VSTAGE_4_MEM__SYMS_H_
#define _VSTAGE_4_MEM__SYMS_H_  // guard

#include "verilated_heavy.h"

// INCLUDE MODULE CLASSES
#include "Vstage_4_mem.h"

// SYMS CLASS
class Vstage_4_mem__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vstage_4_mem*                  TOPp;
    
    // CREATORS
    Vstage_4_mem__Syms(Vstage_4_mem* topp, const char* namep);
    ~Vstage_4_mem__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
