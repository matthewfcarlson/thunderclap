#include "gen/fight.h"

namespace fight {
class TrackFactoryCaster_118ad0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace ai {
class MotionFleeTrack_118ad0;
}
} // namespace hulkfight
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_0049850c;
extern char DAT_004a57a0;
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::ai::MotionFleeTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004a57a0, 0) != 0;
}
