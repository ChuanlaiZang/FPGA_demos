// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdual_control_switch.h for the primary calling header

#include "Vdual_control_switch___024root.h"
#include "Vdual_control_switch__Syms.h"

//==========

VL_INLINE_OPT void Vdual_control_switch___024root___combo__TOP__1(Vdual_control_switch___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdual_control_switch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdual_control_switch___024root___combo__TOP__1\n"); );
    // Body
    vlSelf->f = ((IData)(vlSelf->a) ^ (IData)(vlSelf->b));
}

void Vdual_control_switch___024root___eval(Vdual_control_switch___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdual_control_switch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdual_control_switch___024root___eval\n"); );
    // Body
    Vdual_control_switch___024root___combo__TOP__1(vlSelf);
}

QData Vdual_control_switch___024root___change_request_1(Vdual_control_switch___024root* vlSelf);

VL_INLINE_OPT QData Vdual_control_switch___024root___change_request(Vdual_control_switch___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdual_control_switch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdual_control_switch___024root___change_request\n"); );
    // Body
    return (Vdual_control_switch___024root___change_request_1(vlSelf));
}

VL_INLINE_OPT QData Vdual_control_switch___024root___change_request_1(Vdual_control_switch___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdual_control_switch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdual_control_switch___024root___change_request_1\n"); );
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vdual_control_switch___024root___eval_debug_assertions(Vdual_control_switch___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdual_control_switch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdual_control_switch___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->a & 0xfeU))) {
        Verilated::overWidthError("a");}
    if (VL_UNLIKELY((vlSelf->b & 0xfeU))) {
        Verilated::overWidthError("b");}
}
#endif  // VL_DEBUG
