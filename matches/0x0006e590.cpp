#include "gen/fight.h"

class CSmartPropThrowingTrack_6e590;
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
namespace fight {
class TrackFactoryCaster_6e590 {
  public:
    virtual bool Cast(void*);
    virtual void Other();
};

} // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<CSmartPropThrowingTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, (void*)0x49850c, (void*)0x49ad40, 0) != 0;
}
