#include "gen/fight.h"

class CInvulnerableTrack_6df10;
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_0049850c;
extern char DAT_00499ec8;
namespace fight {
class TrackFactoryCaster_6df10 {
  public:
    virtual int vfunc_0(void*) = 0;
    virtual void vfunc_1() = 0;
};

} // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<CInvulnerableTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_00499ec8, 0) != 0;
}
