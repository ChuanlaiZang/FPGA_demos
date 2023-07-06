// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vdual_control_switch__Syms.h"


void Vdual_control_switch___024root__traceInitSub0(Vdual_control_switch___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void Vdual_control_switch___024root__traceInitTop(Vdual_control_switch___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vdual_control_switch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        Vdual_control_switch___024root__traceInitSub0(vlSelf, tracep);
    }
}

void Vdual_control_switch___024root__traceInitSub0(Vdual_control_switch___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vdual_control_switch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+1,"a", false,-1);
        tracep->declBit(c+2,"b", false,-1);
        tracep->declBit(c+3,"f", false,-1);
        tracep->declBit(c+1,"dual_control_switch a", false,-1);
        tracep->declBit(c+2,"dual_control_switch b", false,-1);
        tracep->declBit(c+3,"dual_control_switch f", false,-1);
    }
}

void Vdual_control_switch___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) VL_ATTR_COLD;
void Vdual_control_switch___024root__traceChgTop0(void* voidSelf, VerilatedVcd* tracep);
void Vdual_control_switch___024root__traceCleanup(void* voidSelf, VerilatedVcd* /*unused*/);

void Vdual_control_switch___024root__traceRegister(Vdual_control_switch___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vdual_control_switch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        tracep->addFullCb(&Vdual_control_switch___024root__traceFullTop0, vlSelf);
        tracep->addChgCb(&Vdual_control_switch___024root__traceChgTop0, vlSelf);
        tracep->addCleanupCb(&Vdual_control_switch___024root__traceCleanup, vlSelf);
    }
}

void Vdual_control_switch___024root__traceFullSub0(Vdual_control_switch___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void Vdual_control_switch___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) {
    Vdual_control_switch___024root* const __restrict vlSelf = static_cast<Vdual_control_switch___024root*>(voidSelf);
    Vdual_control_switch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        Vdual_control_switch___024root__traceFullSub0((&vlSymsp->TOP), tracep);
    }
}

void Vdual_control_switch___024root__traceFullSub0(Vdual_control_switch___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vdual_control_switch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullBit(oldp+1,(vlSelf->a));
        tracep->fullBit(oldp+2,(vlSelf->b));
        tracep->fullBit(oldp+3,(vlSelf->f));
    }
}
