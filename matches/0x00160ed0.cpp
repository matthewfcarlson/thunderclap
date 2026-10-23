#include "gen/fight.h"

extern int __cdecl Check(void*, int, void*, void*, int);
extern char DAT_0049850c;
extern char DAT_004b4670;
namespace fight {
class TrackFactoryCaster_160ed0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class LocomotingTrack_160ed0;
}
} // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::LocomotingTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return Check(p, 0, &DAT_0049850c, &DAT_004b4670, 0) != 0;
}
