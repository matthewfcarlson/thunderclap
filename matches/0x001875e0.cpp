#include "gen/fight.h"

namespace fight {
class TrackFactoryCaster_1875e0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class PropDestroyTrack_1875e0 {};
} // namespace motion
} // namespace hulkfight
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_0049850c;
extern char DAT_004be7d0;
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::PropDestroyTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004be7d0, 0) != 0;
}
