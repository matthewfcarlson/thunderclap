// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00127a80..0x00127b20 (kind game, layer game, confidence high), dominant class hulkfight::ai::TargetArcCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f0238603 {
#define TREE_TU_END }
namespace fn_f0238603 {} using namespace fn_f0238603;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_f0238603 {
extern hulk_intptr __cdecl FUN_00344e74(hulk_intptr, int, hulk_intptr, hulk_intptr, int);
extern int hulk_at_00491ca8;

} // namespace fn_f0238603

// 0x00127a80 fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetArcCondition>::vfunc_0 (36 B): matches/0x00127a80.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VTargetArcCondition@ai@hulkfight@@@fight@@UAE_NPAX@Z
// Same code shape as 0x000508c0 (propagated; names are from that function)
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetArcCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74((hulk_intptr)p, 0, (hulk_intptr)&hulk_at_00491ca8, (hulk_intptr)&gTypeB, 0) != 0;
}

