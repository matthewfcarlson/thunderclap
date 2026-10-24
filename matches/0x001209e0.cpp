#include "gen/fight.h"

extern char DAT_0049850c;
extern char DAT_004a6a10;
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
namespace fight {
class TrackFactoryCaster_1209e0 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace ai {
class PathTrack_1209e0;
}
} // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::ai::PathTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004a6a10, 0) != 0;
}
