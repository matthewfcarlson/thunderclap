// Same code shape as 0x00075d20 (propagated; names are from that function)
#include "gen/fight.h"

typedef unsigned int u32_122dc0;
struct CAutoTargetTrack_122dc0 {
    u32_122dc0 initialize();
};
extern void* __cdecl alloc(unsigned int);

template <> void* fight::TrackFactoryTemplate<hulkfight::ai::RoutTrack>::vfunc_5() {
    CAutoTargetTrack_122dc0* p = (CAutoTargetTrack_122dc0*)alloc(0x3c);
    if (p)
        return (void*)(p->initialize());
    return (void*)(0);
}
