// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vdual_control_switch.h"
#include "Vdual_control_switch__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vdual_control_switch::Vdual_control_switch(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp{new Vdual_control_switch__Syms(_vcontextp__, _vcname__, this)}
    , a{vlSymsp->TOP.a}
    , b{vlSymsp->TOP.b}
    , f{vlSymsp->TOP.f}
    , rootp{&(vlSymsp->TOP)}
{
}

Vdual_control_switch::Vdual_control_switch(const char* _vcname__)
    : Vdual_control_switch(nullptr, _vcname__)
{
}

//============================================================
// Destructor

Vdual_control_switch::~Vdual_control_switch() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vdual_control_switch___024root___eval_initial(Vdual_control_switch___024root* vlSelf);
void Vdual_control_switch___024root___eval_settle(Vdual_control_switch___024root* vlSelf);
void Vdual_control_switch___024root___eval(Vdual_control_switch___024root* vlSelf);
QData Vdual_control_switch___024root___change_request(Vdual_control_switch___024root* vlSelf);
#ifdef VL_DEBUG
void Vdual_control_switch___024root___eval_debug_assertions(Vdual_control_switch___024root* vlSelf);
#endif  // VL_DEBUG
void Vdual_control_switch___024root___final(Vdual_control_switch___024root* vlSelf);

static void _eval_initial_loop(Vdual_control_switch__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vdual_control_switch___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vdual_control_switch___024root___eval_settle(&(vlSymsp->TOP));
        Vdual_control_switch___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = Vdual_control_switch___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("dual_control_switch.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = Vdual_control_switch___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vdual_control_switch::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vdual_control_switch::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vdual_control_switch___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vdual_control_switch___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = Vdual_control_switch___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("dual_control_switch.v", 1, "",
                "Verilated model didn't converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = Vdual_control_switch___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

//============================================================
// Invoke final blocks

void Vdual_control_switch::final() {
    Vdual_control_switch___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Utilities

VerilatedContext* Vdual_control_switch::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* Vdual_control_switch::name() const {
    return vlSymsp->name();
}

//============================================================
// Trace configuration

void Vdual_control_switch___024root__traceInitTop(Vdual_control_switch___024root* vlSelf, VerilatedVcd* tracep);

static void traceInit(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vdual_control_switch___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vdual_control_switch___024root*>(voidSelf);
    Vdual_control_switch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vdual_control_switch___024root__traceInitTop(vlSelf, tracep);
    tracep->scopeEscape('.');
}

void Vdual_control_switch___024root__traceRegister(Vdual_control_switch___024root* vlSelf, VerilatedVcd* tracep);

void Vdual_control_switch::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, &(vlSymsp->TOP));
    Vdual_control_switch___024root__traceRegister(&(vlSymsp->TOP), tfp->spTrace());
}
