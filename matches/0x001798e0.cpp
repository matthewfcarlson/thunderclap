#include "gen/fight.h"

extern char DAT_0049850c;
extern char DAT_004bab80;
extern "C" int __cdecl check(void*, int, const void*, const void*, int);
namespace fight {
class TrackFactoryCaster_1798e0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class TeleportRelativeTrack_1798e0;
}
} // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::TeleportRelativeTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return check(p, 0, &DAT_0049850c, &DAT_004bab80, 0) != 0;
}
