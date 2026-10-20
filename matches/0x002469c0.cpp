#include "compat/ptr.h"
extern "C" char DAT_00423f20[];
extern "C" char DAT_00429214[];
struct V {
    virtual void a();
    virtual void b();
};
struct X_2469c0 {
    void** vptr;
    char pad[0x18];
    V* m;
    void f();
};
void X_2469c0::f() {
    vptr = (void**)((hulk_intptr)DAT_00429214);
    m->b();
    vptr = (void**)((hulk_intptr)DAT_00423f20);
}