// Same code shape as 0x00075d20 (propagated; names are from that function)
#include "gen/fight.h"

typedef unsigned int u32_764d0;
struct CAutoTargetTrack_764d0 {
    u32_764d0 initialize();
};
extern void* __cdecl alloc(unsigned int);

template <> void* fight::TrackFactoryTemplate<CDropTrack>::vfunc_5() {
    CAutoTargetTrack_764d0* p = (CAutoTargetTrack_764d0*)alloc(0x3c);
    if (p)
        return (void*)(p->initialize());
    return (void*)(0);
}
