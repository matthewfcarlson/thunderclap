#include "gen/fight.h"

extern "C" int FindTrack(void*, int, void*, void*, int);
extern char DAT_0049850c;
extern char DAT_004a5b90;
namespace fight {
class TrackFactoryCaster_118d70 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace ai {
class MotionChaseTrack_118d70;
}
} // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::ai::MotionChaseTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FindTrack(p, 0, &DAT_0049850c, &DAT_004a5b90, 0) != 0;
}
