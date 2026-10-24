#include "gen/fight.h"

#include "compat/ptr.h"
class CGrappleSoundTrack_6dc90;
extern "C" int __cdecl FUN_00344e74(void*, int, hulk_intptr, hulk_intptr, int);
namespace fight {
class TrackFactoryCaster_6dc90 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
extern char DAT_0049850c;
extern char DAT_00499910;
template <> bool fight::TrackFactoryCasterTemplate<CGrappleSoundTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, (hulk_intptr)&DAT_0049850c, (hulk_intptr)&DAT_00499910, 0) != 0;
}
