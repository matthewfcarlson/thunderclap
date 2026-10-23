#include "gen/fight.h"

namespace fight {
class TrackFactoryCaster_154ee0 {
  public:
    virtual bool vfunc_0(const char*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class HitDamageTrack_154ee0 {};
} // namespace motion
} // namespace hulkfight
extern "C" int __cdecl FUN_00344e74(const char*, int, const void*, const void*, int);
extern char DAT_0049850c;
extern char DAT_004b3518;
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::HitDamageTrack>::vfunc_0(void* __p0) { const char * s = (const char *)__p0;

    return FUN_00344e74(s, 0, &DAT_0049850c, &DAT_004b3518, 0) != 0;
}
