// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00111060..0x001110e0 (kind game, layer game, confidence high), dominant class hulkfight::ai::HulkActionLargestCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_ffd04358 {
#define TREE_TU_END }
namespace fn_ffd04358 {} using namespace fn_ffd04358;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_ffd04358 {
extern hulk_intptr __cdecl FUN_00344e74(hulk_intptr, int, hulk_intptr, hulk_intptr, int);
extern int gTypeA_111060;

} // namespace fn_ffd04358

// 0x00111060 fight::ConditionFactoryCasterTemplate<hulkfight::ai::HulkActionLargestCondition>::vfunc_0 (36 B): matches/0x00111060.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VHulkActionLargestCondition@ai@hulkfight@@@fight@@UAE_NPAX@Z
// Same code shape as 0x000508c0 (propagated; names are from that function)
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::HulkActionLargestCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74((hulk_intptr)p, 0, (hulk_intptr)&gTypeA_111060, (hulk_intptr)&gTypeB, 0) != 0;
}


// 0x00111090 fight::ParamEnumConstList<hulkfight::ai::HulkActionLargestCondition>::vfunc_0 (30 B): matches/0x00111090.cpp
// sym: ??_G?$ParamEnumConstList@VHulkActionLargestCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::ai::HulkActionLargestCondition>::~ParamEnumConstList() {}


// 0x001110b0 fight::ParamString<hulkfight::ai::HulkActionLargestCondition>::vfunc_0 (30 B): matches/0x001110b0.cpp
// sym: ??_G?$ParamString@VHulkActionLargestCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamString<hulkfight::ai::HulkActionLargestCondition>::~ParamString() {}

