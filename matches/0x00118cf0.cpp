#include "gen/fight.h"

extern int __cdecl check(void*, int, const void*, const void*, int);
extern char DAT_0049850c;
extern char DAT_004a5ae8;
namespace fight {
class TrackFactoryCaster_118cf0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace ai {
class MotionTargetTrack_118cf0 {};
} // namespace ai
} // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::ai::MotionTargetTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return check(p, 0, &DAT_0049850c, &DAT_004a5ae8, 0) != 0;
}
