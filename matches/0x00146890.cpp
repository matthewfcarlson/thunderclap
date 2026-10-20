// Same code shape as 0x0006fa30 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/fight.h"

typedef unsigned int u32_146890;
struct Grapple_146890 {
    hulk_uintptr BuildTrack();
};
extern void* operator new(unsigned int);

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::WorldDamageTrack>::vfunc_5() {
    Grapple_146890* p = (Grapple_146890*)operator new(0x40);
    if (p)
        return (void*)(p->BuildTrack());
    return (void*)(0);
}
