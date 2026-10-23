#include "gen/fight.h"

namespace hulkfight {
namespace motion {
class MomentumXZAddTrack_179460;
}
} // namespace hulkfight
extern char DAT_0049850c;
extern char DAT_004ba560;
extern "C" void* __cdecl castTrack(void*, int, const void*, const void*, int);
namespace fight {
class TrackFactoryCaster_179460 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};

} // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::MomentumXZAddTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return castTrack(p, 0, &DAT_0049850c, &DAT_004ba560, 0) != 0;
}
