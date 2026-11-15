// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00186680..0x0018b4e0 (kind game, layer game, confidence high), merged by D32: hulkfight/motion/PropMissionCriticalCondition.cpp
// piece 0x001871e0..0x001872a0 (kind game, layer game, confidence high, dominant class hulkfight::motion::BallAndChainShootTrack); was game/hulkfight/motion/BallAndChainShootTrack_3.cpp until D46
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f6adaa5c {
#define TREE_TU_END }
namespace fn_f6adaa5c {} using namespace fn_f6adaa5c;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f6adaa5c {
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_0049850c;
extern char DAT_004be2f8;
} // namespace fn_f6adaa5c
namespace fight {
class TrackFactoryCaster_1871e0 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class BallAndChainShootTrack_1871e0 {};
} }


// 0x001871e0 fight::TrackFactoryCasterTemplate<hulkfight::motion::BallAndChainShootTrack>::vfunc_0 (36 B): matches/0x001871e0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VBallAndChainShootTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::BallAndChainShootTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004be2f8, 0) != 0;
}

