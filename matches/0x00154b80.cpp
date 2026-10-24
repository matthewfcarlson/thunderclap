#include "gen/fight.h"

#include "compat/ptr.h"
extern "C" int __cdecl FUN_00344e74(void*, int, int, int, int);
namespace fight {
class TrackFactoryCaster_154b80 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class HitWaitTrack_154b80;
}
} // namespace hulkfight
extern char DAT_0049850c;
extern char DAT_004b3030;
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::HitWaitTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, (hulk_intptr)&DAT_0049850c, (hulk_intptr)&DAT_004b3030, 0) != 0;
}
