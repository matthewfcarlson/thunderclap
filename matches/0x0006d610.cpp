#include "gen/fight.h"

namespace fight {
class TrackFactoryCaster_6d610 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
class CComboMessageTrack_6d610;
} // namespace fight
extern char DAT_0049850c;
extern char DAT_00498aa8;
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
template <> bool fight::TrackFactoryCasterTemplate<CComboMessageTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_00498aa8, 0) != 0;
}
