// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00186680..0x0018b4e0 (kind game, layer game, confidence high), merged by D32: hulkfight/motion/PropMissionCriticalCondition.cpp
// piece 0x001872a0..0x00187340 (kind game, layer game, confidence high, dominant class hulkfight::motion::BallAndChainSpinTrack); was game/hulkfight/motion/BallAndChainSpinTrack_3.cpp until D46
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f11b481b {
#define TREE_TU_END }
namespace fn_f11b481b {} using namespace fn_f11b481b;
#include "game/hulkfight/motion.h"
// (gfx2) __RTDynamicCast's own name (CRT, C linkage): the stand-ins below bound nothing natively
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

// ---- declarations shared by the functions below
namespace fight {
class TrackFactoryCaster_1872a0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class BallAndChainSpinTrack_1872a0 {};
} }
namespace fn_f11b481b {
extern char DAT_0049850c;
extern char DAT_004be3b0;

} // namespace fn_f11b481b

// 0x001872a0 fight::TrackFactoryCasterTemplate<hulkfight::motion::BallAndChainSpinTrack>::vfunc_0 (36 B): matches/0x001872a0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VBallAndChainSpinTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::BallAndChainSpinTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return ((int)(hulk_uintptr)__RTDynamicCast((void*)(hulk_uintptr)(p), 0, (void*)(hulk_uintptr)(&DAT_0049850c), (void*)(hulk_uintptr)(&DAT_004be3b0), 0)) != 0;
}

