#include "gen/fight.h"

class CWallSlideTrack_6e7d0;
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_0049850c;
extern char DAT_0049b224;
namespace fight {
class TrackFactoryCaster_6e7d0 {
  public:
    virtual bool vfunc_0(CWallSlideTrack_6e7d0*);
    virtual void vfunc_1();
};

} // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<CWallSlideTrack>::vfunc_0(void* __p0) { CWallSlideTrack_6e7d0 * p = (CWallSlideTrack_6e7d0 *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_0049b224, 0) != 0;
}
