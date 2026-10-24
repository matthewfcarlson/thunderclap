#include "gen/fight.h"

namespace fight {
class TrackFactoryCaster_6e350 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
class CScrubberTrack_6e350;
} // namespace fight
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_0049850c;
extern char DAT_0049a7e4;
template <> bool fight::TrackFactoryCasterTemplate<CScrubberTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_0049a7e4, 0) != 0;
}
