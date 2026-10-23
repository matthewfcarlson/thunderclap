#include "gen/fight.h"

extern "C" int __cdecl FUN_00344e74(void*, int, const void*, const void*, int);
extern char DAT_0049850c;
extern char DAT_004be680;
namespace fight {
class TrackFactoryCaster_1874c0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class PropDamageTrack_1874c0 {};
} // namespace motion
} // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::PropDamageTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004be680, 0) != 0;
}
