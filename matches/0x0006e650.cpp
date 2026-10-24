#include "gen/fight.h"

namespace fight {
class TrackFactoryCaster_6e650 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
class CSoundTrack_6e650 {};
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_0049850c;
extern char DAT_0049aef8;
template <> bool fight::TrackFactoryCasterTemplate<CSoundTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_0049aef8, 0) != 0;
}
