#include "gen/fight.h"

extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_0049850c;
extern char DAT_004a5848;
namespace fight {
class TrackFactoryCaster_118b30 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace ai {
class MotionStopTrack_118b30;
}
} // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::ai::MotionStopTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004a5848, 0) != 0;
}
