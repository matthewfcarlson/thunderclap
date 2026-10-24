#include "gen/fight.h"

class CPropActorSetStateTrack_6e250;
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_0049850c;
extern char DAT_0049a5b8;
namespace fight {
class TrackFactoryCaster_6e250 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<CPropActorSetStateTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_0049a5b8, 0) != 0;
}
