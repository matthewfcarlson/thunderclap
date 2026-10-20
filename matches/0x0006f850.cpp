#include "compat/ptr.h"
#include "gen/fight.h"

typedef unsigned int u32_6f850;
struct Grapple_6f850 {
    hulk_uintptr ctor();
};
extern void* __cdecl Alloc(hulk_uintptr);

template <> void* fight::TrackFactoryTemplate<CGrappleOpportunityTrack>::vfunc_5() {
    Grapple_6f850* p = (Grapple_6f850*)Alloc(0x2c);
    if (p)
        return (void*)(p->ctor());
    return (void*)(0);
}
