#include "compat/ptr.h"
#include "gen/fight.h"

typedef unsigned int u32_6fa30;
struct Grapple_6fa30 {
    hulk_uintptr BuildTrack();
};
extern void* operator new(unsigned int);

template <> void* fight::TrackFactoryTemplate<CGrappleSwapTrack>::vfunc_5() {
    Grapple_6fa30* p = (Grapple_6fa30*)operator new(0x40);
    if (p)
        return (void*)(p->BuildTrack());
    return (void*)(0);
}
