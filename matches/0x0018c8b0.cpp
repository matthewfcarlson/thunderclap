#include "compat/ptr.h"
#include "gen/fight.h"

typedef unsigned int u32_18c8b0;
struct Prop_18c8b0 {
    hulk_uintptr init();
};
extern "C" void* __cdecl operator_new(unsigned int);

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::PropThrowTrack>::vfunc_5() {
    Prop_18c8b0* p = (Prop_18c8b0*)operator_new(0x88);
    if (p)
        return (void*)(p->init());
    return (void*)(0);
}
