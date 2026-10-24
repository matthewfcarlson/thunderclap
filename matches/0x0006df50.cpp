#include "gen/fight.h"

extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_0049850c;
extern char DAT_00499f50;
namespace fight {
class TrackFactoryCaster_6df50 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
class CJointTrack_6df50 {};
template <> bool fight::TrackFactoryCasterTemplate<CJointTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_00499f50, 0) != 0;
}
