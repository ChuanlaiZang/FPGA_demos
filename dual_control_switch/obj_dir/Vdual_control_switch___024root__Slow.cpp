// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdual_control_switch.h for the primary calling header

#include "Vdual_control_switch___024root.h"
#include "Vdual_control_switch__Syms.h"

//==========


void Vdual_control_switch___024root___ctor_var_reset(Vdual_control_switch___024root* vlSelf);

Vdual_control_switch___024root::Vdual_control_switch___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    Vdual_control_switch___024root___ctor_var_reset(this);
}

void Vdual_control_switch___024root::__Vconfigure(Vdual_control_switch__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

Vdual_control_switch___024root::~Vdual_control_switch___024root() {
}

void Vdual_control_switch___024root___eval_initial(Vdual_control_switch___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdual_control_switch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdual_control_switch___024root___eval_initial\n"); );
}

void Vdual_control_switch___024root___combo__TOP__1(Vdual_control_switch___024root* vlSelf);

void Vdual_control_switch___024root___eval_settle(Vdual_control_switch___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdual_control_switch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdual_control_switch___024root___eval_settle\n"); );
    // Body
    Vdual_control_switch___024root___combo__TOP__1(vlSelf);
}

void Vdual_control_switch___024root___final(Vdual_control_switch___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdual_control_switch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdual_control_switch___024root___final\n"); );
}

void Vdual_control_switch___024root___ctor_var_reset(Vdual_control_switch___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdual_control_switch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdual_control_switch___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->a = VL_RAND_RESET_I(1);
    vlSelf->b = VL_RAND_RESET_I(1);
    vlSelf->f = VL_RAND_RESET_I(1);
}
