#include "gen/fight.h"

extern int gOne;
extern int gTwo;
extern "C" void* __cdecl Search(void*, int, int*, int*, int);
namespace fight {
class TrackFactoryCaster_154f40 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};

} // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::GroundSlideTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return Search(p, 0, &gOne, &gTwo, 0) != 0;
}
