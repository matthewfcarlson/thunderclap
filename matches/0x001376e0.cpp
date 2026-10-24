#include "gen/fight.h"

extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
namespace fight {
class TrackFactoryCaster_1376e0 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class AirToGroundTargetTrack_1376e0 {};
} // namespace motion
} // namespace hulkfight
extern char DAT_0049850c;
extern char DAT_004abc58;
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::AirToGroundTargetTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004abc58, 0) != 0;
}
