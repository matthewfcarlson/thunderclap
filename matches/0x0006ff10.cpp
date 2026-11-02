// Same code shape as 0x0006f220 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/fight.h"

typedef unsigned int u32_6ff10;
extern "C" void* __cdecl FUN_0008d690(hulk_uintptr);
struct InitObj_6ff10 {
    hulk_uintptr Init();
};

template <> void* fight::TrackFactoryTemplate<CSmartPropAttachTrack>::vfunc_5() {
    void* p = FUN_0008d690(0x60);
    if (p)
        return (void*)(((InitObj_6ff10*)p)->Init());
    return (void*)(0);
}
