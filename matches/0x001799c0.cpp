#include "gen/fight.h"

namespace hulkfight {
namespace motion {
class TeleportToLocatorTrack_1799c0;
}
} // namespace hulkfight
extern int a, b;
extern "C" int __cdecl cast(void*, int, const int*, const int*, int);
namespace fight {
class TrackFactoryCaster_1799c0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};

} // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::TeleportToLocatorTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return cast(p, 0, &a, &b, 0) != 0;
}
