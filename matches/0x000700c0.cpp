// Same code shape as 0x0006f2b0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/fight.h"

class Effect_700c0 {
  public:
    hulk_intptr Init();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);

template <> void* fight::TrackFactoryTemplate<CSmartPropEventTrack>::vfunc_5() {
    void* p = FUN_0008d690(0x18);
    if (p)
        return (void*)(((Effect_700c0*)p)->Init());
    return (void*)(0);
}
