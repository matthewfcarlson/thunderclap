#include "gen/fight.h"

extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_0049850c;
extern char DAT_00499048;
namespace fight {
class TrackFactoryCaster_6d8d0 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
class CGrappleAttachTrack_6d8d0;
} // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<CGrappleAttachTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_00499048, 0) != 0;
}
