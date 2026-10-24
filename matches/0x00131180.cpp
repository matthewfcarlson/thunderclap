#include "gen/fight.h"

namespace fight {
class TrackFactoryCaster_131180 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
class StatEndTrialTrack_131180 {};
} // namespace hulkfight
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_0049850c;
extern char DAT_004aad80;
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::StatEndTrialTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004aad80, 0) != 0;
}
