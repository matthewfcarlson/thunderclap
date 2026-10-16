// Same code shape as 0x0006f2b0 (propagated; names are from that function)
#include "gen/fight.h"

class Effect_700c0 {
  public:
    int Init();
};
extern void* __cdecl operator_new(unsigned int);

template <> void* fight::TrackFactoryTemplate<CSmartPropEventTrack>::vfunc_5() {
    void* p = operator_new(0x18);
    if (p)
        return (void*)(((Effect_700c0*)p)->Init());
    return (void*)(0);
}
