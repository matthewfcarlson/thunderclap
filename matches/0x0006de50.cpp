#include "gen/fight.h"
extern char DAT_0049850c;
extern char DAT_00499d20;

extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
struct CIntangibleTrack_6de50;
class TrackFactoryCaster_6de50 {
  public:
    virtual int vfunc_0(void*);
};

template <> bool fight::TrackFactoryCasterTemplate<CIntangibleTrack>::vfunc_0(void* __p0) { void * a = (void *)__p0;

    return (FUN_00344e74(a, 0, (void*)&DAT_0049850c, (void*)&DAT_00499d20, 0) != 0);
}
