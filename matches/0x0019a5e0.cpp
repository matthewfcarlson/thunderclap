#include "gen/fight.h"

extern int __cdecl Lookup(void*, int, void*, void*, int);
namespace fight {
class TrackFactoryCaster_19a5e0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class FireMissileTrack_19a5e0 {};
} // namespace motion
} // namespace hulkfight
extern char DAT_0049850c;
extern char DAT_004c1030;
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::FireMissileTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return Lookup(p, 0, &DAT_0049850c, &DAT_004c1030, 0) != 0;
}
