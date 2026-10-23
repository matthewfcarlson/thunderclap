#include "gen/fight.h"

namespace fight {
class TrackFactoryCaster_1870c0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class BallAndChainReturnTrack_1870c0 {};
} // namespace motion
} // namespace hulkfight
extern char DAT_0049850c;
extern char DAT_004be188;
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::BallAndChainReturnTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004be188, 0) != 0;
}
