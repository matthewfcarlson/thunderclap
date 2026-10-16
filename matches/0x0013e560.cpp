// Same code shape as 0x0006fa30 (propagated; names are from that function)
#include "gen/fight.h"

typedef unsigned int u32_13e560;
struct Grapple_13e560 {
    u32_13e560 BuildTrack();
};
extern void* operator new(unsigned int);

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::AnimationChargeTrack>::vfunc_5() {
    Grapple_13e560* p = (Grapple_13e560*)operator new(0x40);
    if (p)
        return (void*)(p->BuildTrack());
    return (void*)(0);
}
