// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00110e60..0x001133f0 (kind game, layer game, confidence high), merged by D32: hulkfight/ai/OnBlockedTriangleCondition_2.cpp
// piece 0x001112e0..0x00111360 (kind game, layer game, confidence high, dominant class hulkfight::ai::FormationReadyCondition); was game/hulkfight/ai/FormationReadyCondition_3.cpp until D46
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fbbea641 {
#define TREE_TU_END }
namespace fn_fbbea641 {} using namespace fn_fbbea641;
#include "game/hulkfight/ai.h"
// (gfx2) __RTDynamicCast's own name (CRT, C linkage): the stand-ins below bound nothing natively
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

// ---- declarations shared by the functions below
namespace fn_fbbea641 {
extern int hulk_at_00491ca8, hulk_at_004a3fb8;

} // namespace fn_fbbea641

// 0x001112e0 fight::ConditionFactoryCasterTemplate<hulkfight::ai::FormationReadyCondition>::vfunc_0 (36 B): matches/0x001112e0.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VFormationReadyCondition@ai@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::FormationReadyCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return ((int)(hulk_uintptr)__RTDynamicCast((void*)(hulk_uintptr)(p), 0, (void*)(hulk_uintptr)(&hulk_at_00491ca8), (void*)(hulk_uintptr)(&hulk_at_004a3fb8), 0)) != 0;
}

