#include "gen/fight.h"

namespace fight {
class TrackFactoryCaster_130fc0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
class NISSoundTrack_130fc0;
}
extern int g1, g2;
extern "C" int __cdecl cast(void*, int, int*, int*, int);
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::NISSoundTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return cast(p, 0, &g1, &g2, 0) != 0;
}
