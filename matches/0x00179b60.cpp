#include "gen/fight.h"

extern "C" int __cdecl check(void*, int, const void*, const void*, int);
extern char DAT_0049850c;
extern char DAT_004baef0;
namespace fight {
class TrackFactoryCaster_179b60 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class FootPivotTrack_179b60;
}
} // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::FootPivotTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return check(p, 0, &DAT_0049850c, &DAT_004baef0, 0) != 0;
}
