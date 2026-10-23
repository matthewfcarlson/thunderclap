#include "gen/fight.h"

extern "C" int __cdecl check(void*, int, void*, void*, int);
namespace fight {
class TrackFactoryCaster_1377e0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class FallTrack_1377e0 {};
} // namespace motion
} // namespace hulkfight
extern char DAT_0049850c;
extern char DAT_004abda0;
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::FallTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return check(p, 0, &DAT_0049850c, &DAT_004abda0, 0) != 0;
}
