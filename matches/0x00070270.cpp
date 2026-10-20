// Same code shape as 0x0006fc10 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/fight.h"

typedef unsigned int u32_70270;
extern "C" void* __cdecl Allocate(unsigned int);
class Created_70270 {
  public:
    hulk_uintptr Initialize();
};

template <> void* fight::TrackFactoryTemplate<CSmartPropSpawnTrack>::vfunc_5() {
    Created_70270* p = (Created_70270*)Allocate(0xd0);
    if (p)
        return (void*)(p->Initialize());
    return (void*)(0);
}
