#include "gen/fight.h"

extern char DAT_0049850c;
extern char DAT_004ba760;
extern "C" void* __cdecl Find(void*, void*, void*, void*, void*);
namespace fight {
class TrackFactoryCaster_1795c0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class TeleportTrack_1795c0;
}
} // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::TeleportTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return Find(p, 0, &DAT_0049850c, &DAT_004ba760, 0) != 0;
}
