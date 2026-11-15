// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00186680..0x0018b4e0 (kind game, layer game, confidence high), merged by D32: hulkfight/motion/PropMissionCriticalCondition.cpp
// piece 0x00186fe0..0x001870c0 (kind game, layer game, confidence high, dominant class hulkfight::motion::PropThrowTrack); was game/hulkfight/motion/PropThrowTrack_3.cpp until D46
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f737fdd5 {
#define TREE_TU_END }
namespace fn_f737fdd5 {} using namespace fn_f737fdd5;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fight {
class TrackFactoryCaster_186fe0 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class PropThrowTrack_186fe0 {};
} }
namespace fn_f737fdd5 {
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_0049850c;
extern char DAT_004be0d8;

} // namespace fn_f737fdd5

// 0x00186fe0 fight::TrackFactoryCasterTemplate<hulkfight::motion::PropThrowTrack>::vfunc_0 (36 B): matches/0x00186fe0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VPropThrowTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::PropThrowTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004be0d8, 0) != 0;
}

