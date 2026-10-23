#include "gen/fight.h"

struct TypeInfo {
    int x;
};
extern TypeInfo a, b;
extern "C" int __cdecl match(void*, int, TypeInfo*, TypeInfo*, int);
namespace fight {
class TrackFactoryCaster_1374e0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class FlyingDashTrack_1374e0 {};
} // namespace motion
} // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::FlyingDashTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return match(p, 0, &a, &b, 0) != 0;
}
