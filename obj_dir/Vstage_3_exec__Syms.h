// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef _VSTAGE_3_EXEC__SYMS_H_
#define _VSTAGE_3_EXEC__SYMS_H_  // guard

#include "verilated_heavy.h"

// INCLUDE MODULE CLASSES
#include "Vstage_3_exec.h"

// SYMS CLASS
class Vstage_3_exec__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vstage_3_exec*                 TOPp;
    
    // CREATORS
    Vstage_3_exec__Syms(Vstage_3_exec* topp, const char* namep);
    ~Vstage_3_exec__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
