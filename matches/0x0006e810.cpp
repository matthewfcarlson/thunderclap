#include "gen/fight.h"

extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_0049850c;
extern char DAT_0049b2b8;
namespace fight {
class TrackFactoryCaster_6e810 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
class CWeaponCollisionTrack_6e810;
} // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<CWeaponCollisionTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_0049b2b8, 0) != 0;
}
