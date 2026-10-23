#include "gen/fight.h"

extern "C" int __cdecl Check(void*, int, void*, void*, int);
namespace fight {
class TrackFactoryCaster_187440 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class PropAddToMissileCountTrack_187440 {};
} // namespace motion
} // namespace hulkfight
extern char DAT_0049850c;
extern char DAT_004be5c8;
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::PropAddToMissileCountTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return Check(p, 0, &DAT_0049850c, &DAT_004be5c8, 0) != 0;
}
