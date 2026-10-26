#include "decls/data/engine/fight.h"
// data: g_count_2326a0 = DAT_004e5af0

#include "compat/ptr.h"
extern "C" char DAT_003f6098[];
extern "C" char DAT_004276ec[];
extern "C" void _ReadWriteBarrier();
struct Ref_2326a0 {
    virtual void A();
    virtual void Release();
};
struct Action {
    void* vptr;
    int pad;
    Ref_2326a0* member;
    void Cleanup();
};
void Action::Cleanup() {
    *(void* volatile*)&vptr = (void*)((hulk_intptr)DAT_004276ec);
    _ReadWriteBarrier();
    Ref_2326a0* m = member;
    if (m) {
        m->Release();
        member = 0;
    }
    --DAT_004e5af0;
    vptr = (void*)((hulk_intptr)DAT_003f6098);
}
