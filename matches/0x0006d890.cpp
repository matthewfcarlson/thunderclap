#include "gen/fight.h"

extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
namespace fight {
class TrackFactoryCaster_6d890 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
class CGrabTrack_6d890;

} // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<CGrabTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, (void*)0x49850c, (void*)0x498fc4, 0) != 0;
}
