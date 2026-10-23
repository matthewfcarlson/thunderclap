#include "gen/fight.h"

extern char DAT_0049850c;
extern char DAT_004ba6b8;
extern "C" void* __cdecl findThing(void*, int, void*, void*, int);
namespace fight {
class TrackFactoryCaster_179520 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class PushOutTrack_179520;
}
} // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::PushOutTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return findThing(p, 0, &DAT_0049850c, &DAT_004ba6b8, 0) != 0;
}
