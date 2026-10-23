#include "gen/fight.h"

class GrappleAnimationTrack_13bd60;
extern int __cdecl Check(GrappleAnimationTrack_13bd60*, int, void*, void*, int);
extern void* a;
extern void* b;
namespace fight {
class TrackFactoryCaster_13bd60 {
  public:
    virtual bool vfunc_0(GrappleAnimationTrack_13bd60*);
    virtual void vfunc_1();
};
} // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::GrappleAnimationTrack>::vfunc_0(void* __p0) { GrappleAnimationTrack_13bd60 * p = (GrappleAnimationTrack_13bd60 *)__p0;

    return Check(p, 0, &a, &b, 0) != 0;
}
