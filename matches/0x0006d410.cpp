#include "gen/fight.h"

extern char DAT_0049850c;
extern char DAT_00498640;
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
namespace fight {
class TrackFactoryCaster_6d410 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
class CAutoTargetTrack_6d410;

} // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<CAutoTargetTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_00498640, 0) != 0;
}
