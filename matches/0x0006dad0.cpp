#include "gen/fight.h"

class CGrappleInvincibleTrack_6dad0;
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_0049850c;
extern char DAT_004994f0;
namespace fight {
class TrackFactoryCaster_6dad0 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};

} // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<CGrappleInvincibleTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004994f0, 0) != 0;
}
