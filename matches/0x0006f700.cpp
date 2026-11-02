#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" void* __cdecl FUN_0008d690(unsigned int);
struct Grapple_6f700 {
    hulk_intptr Build();
};

template <> void* fight::TrackFactoryTemplate<CGrappleLocoStrafe4Track>::vfunc_5() {
    Grapple_6f700* p = (Grapple_6f700*)FUN_0008d690(0x80);
    if (p)
        return (void*)(p->Build());
    return (void*)(0);
}
