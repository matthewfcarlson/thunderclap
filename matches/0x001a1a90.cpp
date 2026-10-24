#include "gen/fight.h"

namespace fight {
class TrackFactoryCaster_1a1a90 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace scenario {
class LuaTrack_1a1a90 {};
} // namespace scenario
} // namespace hulkfight
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_0049850c;
extern char DAT_004c1600;
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::scenario::LuaTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004c1600, 0) != 0;
}
