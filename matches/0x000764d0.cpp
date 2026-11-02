// Same code shape as 0x00075d20 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/fight.h"

typedef unsigned int u32_764d0;
struct CAutoTargetTrack_764d0 {
    hulk_uintptr initialize();
};
extern "C" void* __cdecl FUN_0008d690(hulk_uintptr);

template <> void* fight::TrackFactoryTemplate<CDropTrack>::vfunc_5() {
    CAutoTargetTrack_764d0* p = (CAutoTargetTrack_764d0*)FUN_0008d690(0x3c);
    if (p)
        return (void*)(p->initialize());
    return (void*)(0);
}
