// cl-flags: /O2
#include "gen/fight.h"

class CSmartPropRemoveInstanceTrack_6e490;
int FUN_00344e74(int, int, void*, int, int);
class TrackFactoryCaster_6e490 {
  public:
    virtual bool vfunc_0(int);
};

template <> bool fight::TrackFactoryCasterTemplate<CSmartPropRemoveInstanceTrack>::vfunc_0(void* __p0) { int param = (int)__p0;

    return !(FUN_00344e74(param, 0, (void*)0x49850c, 0x49aad8, 0) == 0);
}
