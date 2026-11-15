// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0016a050..0x0016d360 (kind game, layer game, confidence high), merged by D32: hulkfight/motion/ChargeCondition_2.cpp
// piece 0x0016a7b0..0x0016a830 (kind game, layer game, confidence high, dominant class hulkfight::motion::GrappleHealthCondition); was game/hulkfight/motion/GrappleHealthCondition_2.cpp until D46
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f61ef722 {
#define TREE_TU_END }
namespace fn_f61ef722 {} using namespace fn_f61ef722;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f61ef722 {
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_004b71a0;

} // namespace fn_f61ef722

// 0x0016a7b0 fight::ConditionFactoryCasterTemplate<hulkfight::motion::GrappleHealthCondition>::vfunc_0 (36 B): matches/0x0016a7b0.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VGrappleHealthCondition@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::GrappleHealthCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004b71a0, 0) != 0;
}

