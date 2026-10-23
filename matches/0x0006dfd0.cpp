#include "gen/fight.h"

class CJumpAttackTrack_6dfd0;
extern int __cdecl TryCast(void*, int, void*, void*, int);
namespace fight {
class TrackFactoryCaster_6dfd0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};

} // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<CJumpAttackTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return TryCast(p, 0, (void*)0x49850c, (void*)0x49a050, 0) != 0;
}
