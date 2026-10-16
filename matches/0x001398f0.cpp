// Same code shape as 0x00075d20 (propagated; names are from that function)
#include "gen/fight.h"

typedef unsigned int u32_1398f0;
struct CAutoTargetTrack_1398f0 {
    u32_1398f0 initialize();
};
extern void* __cdecl alloc(unsigned int);

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::FlyingAutoTargetTrack>::vfunc_5() {
    CAutoTargetTrack_1398f0* p = (CAutoTargetTrack_1398f0*)alloc(0x3c);
    if (p)
        return (void*)(p->initialize());
    return (void*)(0);
}
