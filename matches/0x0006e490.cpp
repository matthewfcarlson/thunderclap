// cl-flags: /O2
#include "compat/ptr.h"
#include "gen/fight.h"
extern char DAT_0049850c;
extern char DAT_0049aad8;

class CSmartPropRemoveInstanceTrack_6e490;
int FUN_00344e74(hulk_intptr, int, void*, void*, int);
class TrackFactoryCaster_6e490 {
  public:
    virtual bool vfunc_0(int);
};

template <> bool fight::TrackFactoryCasterTemplate<CSmartPropRemoveInstanceTrack>::vfunc_0(void* __p0) { hulk_intptr param = (hulk_intptr)__p0;

    return !(FUN_00344e74(param, 0, (void*)&DAT_0049850c, (void*)&DAT_0049aad8, 0) == 0);
}
