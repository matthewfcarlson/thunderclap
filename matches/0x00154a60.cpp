#include "gen/fight.h"

typedef unsigned int size_t;
extern "C" void* __cdecl dynamic_cast_helper(void*, int, void*, void*, int);
namespace fight {
class TrackFactoryCaster_154a60 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class HitPauseTrack_154a60 {};
} // namespace motion
} // namespace hulkfight
extern char DAT_0049850c;
extern char DAT_004b2ee0;
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::HitPauseTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return dynamic_cast_helper(p, 0, &DAT_0049850c, &DAT_004b2ee0, 0) != 0;
}
