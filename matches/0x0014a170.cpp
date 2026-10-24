#include "gen/fight.h"

class Track_14a170 {};
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
namespace fight {
class TrackFactoryCaster_14a170 {
  public:
    virtual bool vfunc_0(Track_14a170*);
    virtual void vfunc_1();
};
} // namespace fight
extern char DAT_0049850c;
extern char DAT_004af890;
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::CivilianAnimationTrack>::vfunc_0(void* __p0) { Track_14a170 * p = (Track_14a170 *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004af890, 0) != 0;
}
