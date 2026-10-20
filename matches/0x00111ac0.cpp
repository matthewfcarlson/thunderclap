#include "compat/ptr.h"
#include "gen/fight.h"

int Helper(int a, int b, void* c, void* d, int e);

class TrackFactoryCaster_111ac0 {
  public:
    virtual void AddRef();
    virtual void Release();
    virtual ~TrackFactoryCaster_111ac0();
};

template <> bool fight::TrackFactoryCasterTemplate<hulkfight::ai::SemaphoreWaitTrack>::vfunc_0(void* __p0) { hulk_intptr arg = (hulk_intptr)__p0;

    int x = Helper(arg, 0, (void*)0x49850c, (void*)0x4a49d0, 0);
    return (x != 0) ? 1 : 0;
}
