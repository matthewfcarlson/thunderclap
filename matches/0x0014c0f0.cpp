// Same code shape as 0x0006fa30 (propagated; names are from that function)
#include "gen/fight.h"

typedef unsigned int u32_14c0f0;
struct Grapple_14c0f0 {
    u32_14c0f0 BuildTrack();
};
extern void* operator new(unsigned int);

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::CivilianThrowTrack>::vfunc_5() {
    Grapple_14c0f0* p = (Grapple_14c0f0*)operator new(0x40);
    if (p)
        return (void*)(p->BuildTrack());
    return (void*)(0);
}
