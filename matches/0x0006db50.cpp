#include "gen/fight.h"

extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_0049850c;
extern char DAT_00499620;
class TrackFactoryCaster_6db50 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
class CGrappleKeyPoseTrack_6db50;

template <> bool fight::TrackFactoryCasterTemplate<CGrappleKeyPoseTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_00499620, 0) != 0;
}
