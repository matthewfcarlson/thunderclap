#include "gen/fight.h"

extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_0049850c;
extern char DAT_0049b198;
namespace fight {
class TrackFactoryCaster_6e790 {
  public:
    virtual int Cast(void*);
    virtual void Other();
};
} // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<CUninterruptibleTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_0049b198, 0) != 0;
}
