#include "gen/fight.h"

class CMoveTrack_6e0d0;
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
namespace fight {
class TrackFactoryCaster_6e0d0 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
extern char DAT_0049850c;
extern char DAT_0049a278;
template <> bool fight::TrackFactoryCasterTemplate<CMoveTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74((CMoveTrack_6e0d0*)p, 0, &DAT_0049850c, &DAT_0049a278, 0) != 0;
}
