#include "gen/fight.h"

extern char DAT_0049850c;
extern char DAT_004b3470;
extern "C" int __cdecl DoCast(void*, int, void*, void*, int);
namespace fight {
class TrackFactoryCaster_154e60 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::HealthTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return DoCast(p, 0, &DAT_0049850c, &DAT_004b3470, 0) != 0;
}
