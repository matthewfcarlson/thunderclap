#include "compat/ptr.h"
extern "C" char DAT_003f6098[];
extern "C" char DAT_0042bdd0[];
extern "C" char DAT_0042bddc[];
struct V {
    virtual void A();
    virtual void B();
};
struct InstanceDrive_2766e0 {
    void** v;
    void** v4;
    int pad;
    V* p;
    void f();
};
void InstanceDrive_2766e0::f() {
    v = (void**)((hulk_intptr)DAT_0042bddc);
    v4 = (void**)((hulk_intptr)DAT_0042bdd0);
    p->B();
    v = (void**)((hulk_intptr)DAT_003f6098);
}