#include "gen/fight.h"

class Effect_6f2b0 {
  public:
    int Init();
};
extern void* __cdecl operator_new(unsigned int);

template <> void* fight::TrackFactoryTemplate<CEffectStopTrack>::vfunc_5() {
    void* p = operator_new(0x18);
    if (p)
        return (void*)(((Effect_6f2b0*)p)->Init());
    return (void*)(0);
}
