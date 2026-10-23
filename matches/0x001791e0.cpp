#include "gen/fight.h"

extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);
extern char DAT_0049850c;
extern char DAT_004ba2b0;
namespace fight {
class TrackFactoryCaster_1791e0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class MoveJointTrack_1791e0;
}
} // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::MoveJointTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return __RTDynamicCast(p, 0, &DAT_0049850c, &DAT_004ba2b0, 0) != 0;
}
