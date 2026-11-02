#include "compat/ptr.h"
#include "gen/fight.h"

typedef unsigned int u32_6f220;
extern "C" void* __cdecl FUN_0008d690(hulk_uintptr);
struct InitObj_6f220 {
    hulk_uintptr Init();
};

template <> void* fight::TrackFactoryTemplate<CEffectTrack>::vfunc_5() {
    void* p = FUN_0008d690(0x60);
    if (p)
        return (void*)(((InitObj_6f220*)p)->Init());
    return (void*)(0);
}
