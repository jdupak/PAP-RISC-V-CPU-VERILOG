// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtest_pipeline_cpu__Syms.h"
#include "Vtest_pipeline_cpu.h"



// FUNCTIONS
Vtest_pipeline_cpu__Syms::Vtest_pipeline_cpu__Syms(Vtest_pipeline_cpu* topp, const char* namep)
    // Setup locals
    : __Vm_namep(namep)
    , __Vm_didInit(false)
    // Setup submodule names
{
    // Pointer to top level
    TOPp = topp;
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOPp->__Vconfigure(this, true);
}
