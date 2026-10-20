#include "compat/ptr.h"
extern "C" char DAT_003f6098[];
extern "C" char DAT_0042af64[];
extern "C" char DAT_004342bc[];
extern "C" char DAT_004342c4[];
struct V {
    virtual void f();
    virtual void g();
};
struct X_3340b0 {
    void** v;
    int a;
    int b;
    char p0[4];
    V* p;
    char pad[0x20];
    V* q;
};
extern int global_3340b0;
void __fastcall FUN_003340b0(X_3340b0* x) {
    x->v = (void**)((hulk_intptr)DAT_004342c4);
    x->a = (int)((hulk_intptr)DAT_004342bc);
    if (x->p) {
        x->p->g();
        x->p = 0;
    }
    if (x->q) {
        x->q->g();
        x->q = 0;
    }
    global_3340b0 = x->b;
    x->a = (int)((hulk_intptr)DAT_0042af64);
    x->v = (void**)((hulk_intptr)DAT_003f6098);
}