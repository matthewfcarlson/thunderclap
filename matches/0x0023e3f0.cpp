#include "compat/ptr.h"
extern "C" char DAT_00428d60[];
struct Temp_23e3f0 {
    void* vptr;
};
struct A_23e3f0 {
    void G(void*);
};
struct B_23e3f0 {};
extern "C" void* FUN_00236ac0(B_23e3f0*, Temp_23e3f0*);
extern "C" void FUN_0023e3f0(A_23e3f0* a, B_23e3f0* b) {
    Temp_23e3f0 t;
    t.vptr = (void*)((hulk_intptr)DAT_00428d60);
    void* r = FUN_00236ac0(b, &t);
    a->G(r);
}