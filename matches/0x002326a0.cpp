#include "gen/fight.h"
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

void fight::Action::FUN_002326a0() {
    *(void* volatile*)this = (void*)((hulk_intptr)DAT_004276ec);
    _ReadWriteBarrier();
    Ref_2326a0* m = *(Ref_2326a0**)((char*)this + 8);
    if (m) {
        m->Release();
        *(Ref_2326a0**)((char*)this + 8) = 0;
    }
    --DAT_004e5af0;
    *(void**)this = (void*)((hulk_intptr)DAT_003f6098);
}
