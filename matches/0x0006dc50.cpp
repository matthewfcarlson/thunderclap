#include "gen/fight.h"

extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_0049850c;
extern char DAT_00499880;
namespace fight {
class TrackFactoryCaster_6dc50 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
class CGrappleSequenceTrack_6dc50 {};
template <> bool fight::TrackFactoryCasterTemplate<CGrappleSequenceTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_00499880, 0) != 0;
}
