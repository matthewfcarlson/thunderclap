#include "gen/fight.h"

namespace fight {
class TrackFactoryCaster_10bb50 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace ai {
class FaceTargetTrack_10bb50 {};
} // namespace ai
} // namespace hulkfight
extern "C" void* FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_0049850c;
extern char DAT_004a2128;
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::ai::FaceTargetTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004a2128, 0) != 0;
}
