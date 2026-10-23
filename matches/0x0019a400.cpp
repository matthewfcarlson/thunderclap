#include "gen/fight.h"

extern "C" int __cdecl check(void*, int, void*, void*, int);
extern char DAT_0049850c;
extern char DAT_004c0e20;
namespace fight {
class TrackFactoryCaster_19a400 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class MissilePunchTrack_19a400 {};
} // namespace motion
} // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::MissilePunchTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return check(p, 0, &DAT_0049850c, &DAT_004c0e20, 0) != 0;
}
