// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0016a050..0x0016d360 (kind game, layer game, confidence high), merged by D32: hulkfight/motion/ChargeCondition_2.cpp
// piece 0x0016a290..0x0016a310 (kind game, layer game, confidence high, dominant class hulkfight::motion::VelocityAnimatedXZCondition); was game/hulkfight/motion/VelocityAnimatedXZCondition.cpp until D46
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f9c24ea3 {
#define TREE_TU_END }
namespace fn_f9c24ea3 {} using namespace fn_f9c24ea3;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f9c24ea3 {
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_004b6920;
} // namespace fn_f9c24ea3
namespace fight {
class ConditionFactoryCaster_16a290 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class VelocityAnimatedXZCondition_16a290 {};
} }


// 0x0016a290 fight::ConditionFactoryCasterTemplate<hulkfight::motion::VelocityAnimatedXZCondition>::vfunc_0 (36 B): matches/0x0016a290.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VVelocityAnimatedXZCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::VelocityAnimatedXZCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004b6920, 0) != 0;
}

