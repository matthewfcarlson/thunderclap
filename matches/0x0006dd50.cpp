#include "gen/fight.h"

class CGrappleUninterruptibleTrack_6dd50;
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
namespace fight {
class TrackFactoryCaster_6dd50 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
extern char DAT_0049850c;
extern char DAT_00499ad8;
template <> bool fight::TrackFactoryCasterTemplate<CGrappleUninterruptibleTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_00499ad8, 0) != 0;
}
