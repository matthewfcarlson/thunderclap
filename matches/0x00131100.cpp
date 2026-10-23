#include "gen/fight.h"

class TrackFactoryCaster_131100 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
class DebugPrintTrack_131100 {};
extern char DAT_0049850c;
extern char DAT_004aace8;
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);

template <> bool fight::TrackFactoryCasterTemplate<hulkfight::DebugPrintTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004aace8, 0) != 0;
}
