#include "gen/fight.h"

extern "C" int __cdecl CastHelper(void*, int, void*, void*, int);
extern char DAT_0049850c;
extern char DAT_004c0cc0;
namespace fight {
class TrackFactoryCaster_19a260 {
  public:
    virtual bool Cast(void*);
    virtual void Other();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class FireProjectileTrack_19a260 {};
} // namespace motion
} // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::FireProjectileTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return CastHelper(p, 0, &DAT_0049850c, &DAT_004c0cc0, 0) != 0;
}
