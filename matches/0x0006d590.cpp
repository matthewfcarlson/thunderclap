#include "compat/ptr.h"
extern "C" int __cdecl FUN_00344e74(void*, int, hulk_intptr, hulk_intptr, int);

class TrackFactoryCaster {
  public:
    virtual int vfunc_0(int);
    virtual int vfunc_1();
};

class CClimbingTrack;

template <class T> class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    int vfunc_0(int a);
};

template <> int TrackFactoryCasterTemplate<CClimbingTrack>::vfunc_0(int a) {
    return (int)(FUN_00344e74((void*)a, 0, 0x49850c, 0x498994, 0) != 0);
}
