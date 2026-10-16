#include "gen/fight.h"

class Obj {};
class TrackFactoryCaster_137660 {
  public:
    virtual bool vfunc_0(Obj*);
    virtual void vfunc_1();
};
int __cdecl FUN_00344e74(Obj*, int, void*, void*, int);

template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::BounceTrack>::vfunc_0(void* __p0) { Obj * p = (Obj *)__p0;

    return (int)FUN_00344e74(p, 0, (void*)0x49850c, (void*)0x4abba8, 0) != 0;
}
