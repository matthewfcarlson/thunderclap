// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00110e60..0x001133f0 (kind game, layer game, confidence high), merged by D32: hulkfight/ai/OnBlockedTriangleCondition_2.cpp
// piece 0x00111160..0x001111e0 (kind game, layer game, confidence high, dominant class hulkfight::ai::HulkActionRecentCondition); was game/hulkfight/ai/HulkActionRecentCondition.cpp until D46
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_feefccae {
#define TREE_TU_END }
namespace fn_feefccae {} using namespace fn_feefccae;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_feefccae {
extern hulk_intptr __cdecl FUN_00344e74(hulk_intptr, int, hulk_intptr, hulk_intptr, int);
extern int hulk_at_00491ca8;

} // namespace fn_feefccae

// 0x00111160 fight::ConditionFactoryCasterTemplate<hulkfight::ai::HulkActionRecentCondition>::vfunc_0 (36 B): matches/0x00111160.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VHulkActionRecentCondition@ai@hulkfight@@@fight@@UAE_NPAX@Z
// Same code shape as 0x000508c0 (propagated; names are from that function)
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::HulkActionRecentCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74((hulk_intptr)p, 0, (hulk_intptr)&hulk_at_00491ca8, (hulk_intptr)&gTypeB, 0) != 0;
}

