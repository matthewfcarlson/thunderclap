// Same code shape as 0x0006fa30 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/fight.h"

typedef unsigned int u32_139980;
struct Grapple_139980 {
    hulk_uintptr BuildTrack();
};
extern void* operator new(unsigned int);

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::FlyingAttackTrack>::vfunc_5() {
    Grapple_139980* p = (Grapple_139980*)operator new(0x40);
    if (p)
        return (void*)(p->BuildTrack());
    return (void*)(0);
}
