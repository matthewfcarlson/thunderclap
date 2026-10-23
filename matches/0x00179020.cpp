#include "gen/fight.h"

extern int gA, gB;
extern "C" int __cdecl check(void*, int, const int*, const int*, int);
namespace fight {
class TrackFactoryCaster_179020 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class SyncToLocatorTrack_179020;
}
} // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::SyncToLocatorTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return check(p, 0, &gA, &gB, 0) != 0;
}
