#include "gen/fight.h"

extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
namespace fight {
class TrackFactoryCaster_1a6d40 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace scenario {
class NISAnimationTrack_1a6d40 {};
} // namespace scenario
} // namespace hulkfight
extern char DAT_0049850c;
extern char DAT_004c2650;
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::scenario::NISAnimationTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004c2650, 0) != 0;
}
