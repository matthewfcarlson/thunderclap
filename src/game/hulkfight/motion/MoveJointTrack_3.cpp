// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001791e0..0x001792a0 (kind game, layer game, confidence high), dominant class hulkfight::motion::MoveJointTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f9a2856f {
#define TREE_TU_END }
namespace fn_f9a2856f {} using namespace fn_f9a2856f;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f9a2856f {
extern char DAT_0049850c;
extern char DAT_004ba2b0;
} // namespace fn_f9a2856f
namespace fight {
class TrackFactoryCaster_1791e0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class MoveJointTrack_1791e0;
} }


// 0x001791e0 fight::TrackFactoryCasterTemplate<hulkfight::motion::MoveJointTrack>::vfunc_0 (36 B): matches/0x001791e0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VMoveJointTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::MoveJointTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return __RTDynamicCast(p, 0, &DAT_0049850c, &DAT_004ba2b0, 0) != 0;
}

