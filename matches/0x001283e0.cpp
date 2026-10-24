#include "gen/fight.h"

#include "compat/ptr.h"
extern "C" int FUN_00344e74(void*, int, void*, hulk_intptr, int);
extern char DAT_0049850c;
extern char DAT_004a8d20;
class TrackFactoryCaster_1283e0 {
  public:
    virtual int vfunc_0(int a);
    virtual int vfunc_1(int a);
};

template <> bool fight::TrackFactoryCasterTemplate<hulkfight::ai::AcquireTargetTrack>::vfunc_0(void* __p0) { int a = (int)__p0;

    return (FUN_00344e74((void*)a, 0, &DAT_0049850c, (hulk_intptr)&DAT_004a8d20, 0) != 0);
}
