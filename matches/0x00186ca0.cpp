#include "gen/fight.h"

class Actor;
class Track_186ca0;
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
namespace fight {
class TrackFactoryCaster_186ca0 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class PropActorToPropTrack_186ca0 {};
} // namespace motion
} // namespace hulkfight
extern char DAT_0049850c;
extern char DAT_004bdca8;
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::PropActorToPropTrack>::vfunc_0(void* __p0) { void * x = (void *)__p0;

    return FUN_00344e74(x, 0, &DAT_0049850c, &DAT_004bdca8, 0) != 0;
}
