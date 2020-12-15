// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef _VSTAGE_1_FETCH__SYMS_H_
#define _VSTAGE_1_FETCH__SYMS_H_  // guard

#include "verilated_heavy.h"

// INCLUDE MODULE CLASSES
#include "Vstage_1_fetch.h"

// SYMS CLASS
class Vstage_1_fetch__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vstage_1_fetch*                TOPp;
    
    // CREATORS
    Vstage_1_fetch__Syms(Vstage_1_fetch* topp, const char* namep);
    ~Vstage_1_fetch__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
