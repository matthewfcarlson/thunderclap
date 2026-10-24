#include "gen/fight.h"

extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_0049850c;
extern char DAT_004b9f48;
namespace fight {
class TrackFactoryCaster_178f00 {
  public:
    virtual int vfunc_0(void*);
    virtual int vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class SnapToGroundTrack_178f00 {};
} // namespace motion
} // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::SnapToGroundTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004b9f48, 0) != 0;
}
