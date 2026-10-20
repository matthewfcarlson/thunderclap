// Same code shape as 0x00075d20 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/fight.h"

typedef unsigned int u32_764d0;
struct CAutoTargetTrack_764d0 {
    hulk_uintptr initialize();
};
extern void* __cdecl alloc(hulk_uintptr);

template <> void* fight::TrackFactoryTemplate<CDropTrack>::vfunc_5() {
    CAutoTargetTrack_764d0* p = (CAutoTargetTrack_764d0*)alloc(0x3c);
    if (p)
        return (void*)(p->initialize());
    return (void*)(0);
}
