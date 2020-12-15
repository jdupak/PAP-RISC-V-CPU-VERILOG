// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef _VTEST_PIPELINE_CPU__SYMS_H_
#define _VTEST_PIPELINE_CPU__SYMS_H_  // guard

#include "verilated_heavy.h"

// INCLUDE MODULE CLASSES
#include "Vtest_pipeline_cpu.h"

// SYMS CLASS
class Vtest_pipeline_cpu__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vtest_pipeline_cpu*            TOPp;
    
    // CREATORS
    Vtest_pipeline_cpu__Syms(Vtest_pipeline_cpu* topp, const char* namep);
    ~Vtest_pipeline_cpu__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
