#include "gen/fight.h"

struct Info {
    int x;
};
extern Info a, b;
extern "C" void* __cdecl lookup(void*, int, Info*, Info*, int);
namespace fight {
class TrackFactoryCaster_128480 {
  public:
    virtual bool Make(void*);
    virtual void Other();
};
} // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::ai::ClearProjectileDistanceTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return lookup(p, 0, &a, &b, 0) != 0;
}
