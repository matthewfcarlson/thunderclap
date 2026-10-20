#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_003fd044[];
typedef unsigned int u32_6f5b0;
void* __cdecl Allocate(unsigned int);
struct CGrappleEffectTrack_6f5b0 {
    virtual void a();
    void Init();
};

template <> void* fight::TrackFactoryTemplate<CGrappleEffectTrack>::vfunc_5() {
    CGrappleEffectTrack_6f5b0* p = (CGrappleEffectTrack_6f5b0*)Allocate(0x60);
    if (p != 0) {
        p->Init();
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_003fd044);
        return (void*)(p);
    }
    return (void*)(0);
}
