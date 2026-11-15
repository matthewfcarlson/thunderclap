// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00153f40..0x00158f00 (kind game, layer game, confidence high), merged by D32: hulkfight/motion/InterruptAccumulatorCondition.cpp
// piece 0x001545e0..0x00154680 (kind game, layer game, confidence high, dominant class hulkfight::motion::CollisionChargeCondition); was game/hulkfight/motion/CollisionChargeCondition_params_factory.cpp until D46
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_ffe42598 {
#define TREE_TU_END }
namespace fn_ffe42598 {} using namespace fn_ffe42598;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_ffe42598 {
class CollisionChargeCondition_1545e0;
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
} // namespace fn_ffe42598
namespace fight {
class ConditionFactoryCaster_1545e0 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fn_ffe42598 {
extern char DAT_004b27f0;

} // namespace fn_ffe42598

// 0x001545e0 fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionChargeCondition>::vfunc_0 (36 B): matches/0x001545e0.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCollisionChargeCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionChargeCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004b27f0, 0) != 0;
}

