#include "compat/ptr.h"
#include "gen/fight.h"

typedef unsigned int u32_6fc10;
extern "C" void* __cdecl Allocate(unsigned int);
class Created_6fc10 {
  public:
    hulk_uintptr Initialize();
};

template <> void* fight::TrackFactoryTemplate<CMotionTrailTrack>::vfunc_5() {
    Created_6fc10* p = (Created_6fc10*)Allocate(0xd0);
    if (p)
        return (void*)(p->Initialize());
    return (void*)(0);
}
