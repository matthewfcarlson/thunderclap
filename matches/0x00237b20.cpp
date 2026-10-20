// Same code shape as 0x0006f850 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/fight.h"

typedef unsigned int u32_237b20;
struct Grapple_237b20 {
    hulk_uintptr ctor();
};
extern void* __cdecl Alloc(hulk_uintptr);

template <> void* fight::TrackFactoryTemplate<fight::OpportunityTrack>::vfunc_5() {
    Grapple_237b20* p = (Grapple_237b20*)Alloc(0x2c);
    if (p)
        return (void*)(p->ctor());
    return (void*)(0);
}
