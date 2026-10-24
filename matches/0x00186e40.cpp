#include "gen/fight.h"

class TrackFactoryCaster_186e40 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_0049850c;
extern char DAT_004bdec8;

template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::PropDropTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004bdec8, 0) != 0;
}
