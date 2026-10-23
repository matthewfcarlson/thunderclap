#include "gen/fight.h"

extern char DAT_0049850c;
extern char DAT_004ba360;
extern "C" void* Find(void*, int, void*, void*, int);
namespace fight {
class TrackFactoryCaster_1792a0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class DriftToPositionTrack_1792a0;
}
} // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::DriftToPositionTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return Find(p, 0, &DAT_0049850c, &DAT_004ba360, 0) != 0;
}
