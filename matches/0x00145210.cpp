#include "gen/fight.h"

extern int __cdecl check(void*, int, void*, void*, int);
extern char DAT_0049850c;
extern char DAT_004adef0;
namespace fight {
class TrackFactoryCaster_145210 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class HitEffectTrack_145210;
}
} // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::HitEffectTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return check(p, 0, &DAT_0049850c, &DAT_004adef0, 0) != 0;
}
