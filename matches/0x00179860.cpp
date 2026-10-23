#include "gen/fight.h"

namespace hulkfight {
namespace motion {
class SuckInPropsTrack_179860;
}
} // namespace hulkfight
extern char DAT_0049850c;
extern char DAT_004baad0;
extern "C" int __cdecl check(void*, int, const void*, const void*, int);
namespace fight {
class TrackFactoryCaster_179860 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};

} // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::SuckInPropsTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return check(p, 0, &DAT_0049850c, &DAT_004baad0, 0) != 0;
}
