#include "gen/fight.h"

extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_0049850c;
extern char DAT_004a6820;
namespace fight {
class TrackFactoryCaster_1208a0 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace ai {
class StrafeLateralHBTrack_1208a0 {};
} // namespace ai
} // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::ai::StrafeLateralHBTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004a6820, 0) != 0;
}
