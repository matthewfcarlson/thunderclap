#include "compat/ptr.h"
#include "gen/fight.h"

class Effect_6f2b0 {
  public:
    hulk_intptr Init();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);

template <> void* fight::TrackFactoryTemplate<CEffectStopTrack>::vfunc_5() {
    void* p = FUN_0008d690(0x18);
    if (p)
        return (void*)(((Effect_6f2b0*)p)->Init());
    return (void*)(0);
}
