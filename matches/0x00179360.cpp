#include "gen/fight.h"

extern char DAT_0049850c;
extern char DAT_004ba410;
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
namespace hulkfight {
namespace motion {
class DriftToHulkTrack_179360;
}
} // namespace hulkfight
namespace fight {
class TrackFactoryCaster_179360 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};

} // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::DriftToHulkTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004ba410, 0) != 0;
}
