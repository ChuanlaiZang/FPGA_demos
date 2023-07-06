// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vdual_control_switch.h for the primary calling header

#ifndef VERILATED_VDUAL_CONTROL_SWITCH___024ROOT_H_
#define VERILATED_VDUAL_CONTROL_SWITCH___024ROOT_H_  // guard

#include "verilated_heavy.h"

//==========

class Vdual_control_switch__Syms;
class Vdual_control_switch_VerilatedVcd;


//----------

VL_MODULE(Vdual_control_switch___024root) {
  public:

    // PORTS
    VL_IN8(a,0,0);
    VL_IN8(b,0,0);
    VL_OUT8(f,0,0);

    // INTERNAL VARIABLES
    Vdual_control_switch__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vdual_control_switch___024root);  ///< Copying not allowed
  public:
    Vdual_control_switch___024root(const char* name);
    ~Vdual_control_switch___024root();

    // INTERNAL METHODS
    void __Vconfigure(Vdual_control_switch__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
