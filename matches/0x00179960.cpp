#include "gen/fight.h"

extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);
extern char DAT_0049850c;
extern char DAT_004bac38;
namespace fight {
class TrackFactoryCaster_179960 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class IntentionClearTrack_179960 {};
} // namespace motion
} // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::IntentionClearTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return __RTDynamicCast(p, 0, &DAT_0049850c, &DAT_004bac38, 0) != 0;
}
