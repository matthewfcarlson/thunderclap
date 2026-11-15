// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00153f40..0x00158f00 (kind game, layer game, confidence high), merged by D32: hulkfight/motion/InterruptAccumulatorCondition.cpp
// piece 0x00154000..0x00154080 (kind game, layer game, confidence high, dominant class hulkfight::motion::CollisionSourceForceMagnitudeCondition); was game/hulkfight/motion/CollisionSourceForceMagnitudeCondition.cpp until D46
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fcb542fc {
#define TREE_TU_END }
namespace fn_fcb542fc {} using namespace fn_fcb542fc;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_fcb542fc {
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
} // namespace fn_fcb542fc
namespace fight {
class ConditionFactoryCaster_154000 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class CollisionSourceForceMagnitudeCondition_154000 {};
} }
namespace fn_fcb542fc {
extern char DAT_004b1cc8;

} // namespace fn_fcb542fc

// 0x00154000 fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionSourceForceMagnitudeCondition>::vfunc_0 (36 B): matches/0x00154000.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCollisionSourceForceMagnitudeCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionSourceForceMagnitudeCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004b1cc8, 0) != 0;
}

