#include "gen/fight.h"

namespace fight {
class TrackFactoryCaster_1872a0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class BallAndChainSpinTrack_1872a0 {};
} // namespace motion
} // namespace hulkfight
extern "C" int __cdecl helper(void*, int, void*, void*, int);
extern char DAT_0049850c;
extern char DAT_004be3b0;
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::BallAndChainSpinTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return helper(p, 0, &DAT_0049850c, &DAT_004be3b0, 0) != 0;
}
