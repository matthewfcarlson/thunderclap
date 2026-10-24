#include "gen/fight.h"

extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_0049850c;
extern char DAT_00499458;
namespace fight {
class TrackFactoryCaster_6da90 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
class CGrappleIntangibleTrack_6da90 {};
template <> bool fight::TrackFactoryCasterTemplate<CGrappleIntangibleTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_00499458, 0) != 0;
}
