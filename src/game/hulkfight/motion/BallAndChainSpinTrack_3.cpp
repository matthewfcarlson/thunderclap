// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001872a0..0x00187340 (kind game, layer game, confidence high), dominant class hulkfight::motion::BallAndChainSpinTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f11b481b {
#define TREE_TU_END }
namespace fn_f11b481b {} using namespace fn_f11b481b;
#include "game/hulkfight/motion.h"

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
extern "C" int __cdecl helper(void*, int, void*, void*, int);
extern char DAT_0049850c;
extern char DAT_004be3b0;

} // namespace fn_f11b481b

// 0x001872a0 fight::TrackFactoryCasterTemplate<hulkfight::motion::BallAndChainSpinTrack>::vfunc_0 (36 B): matches/0x001872a0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VBallAndChainSpinTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::BallAndChainSpinTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return helper(p, 0, &DAT_0049850c, &DAT_004be3b0, 0) != 0;
}

