#include "compat/ptr.h"
#include "gen/fight.h"

void* __cdecl Allocate(unsigned int);
struct Grapple_6f700 {
    hulk_intptr Build();
};

template <> void* fight::TrackFactoryTemplate<CGrappleLocoStrafe4Track>::vfunc_5() {
    Grapple_6f700* p = (Grapple_6f700*)Allocate(0x80);
    if (p)
        return (void*)(p->Build());
    return (void*)(0);
}
