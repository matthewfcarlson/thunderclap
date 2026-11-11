// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001112e0..0x00111360 (kind game, layer game, confidence high), dominant class hulkfight::ai::FormationReadyCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fbbea641 {
#define TREE_TU_END }
namespace fn_fbbea641 {} using namespace fn_fbbea641;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_fbbea641 {
extern "C" int __cdecl helper(void*, int, void*, void*, int);
extern int a, b;

} // namespace fn_fbbea641

// 0x001112e0 fight::ConditionFactoryCasterTemplate<hulkfight::ai::FormationReadyCondition>::vfunc_0 (36 B): matches/0x001112e0.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VFormationReadyCondition@ai@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::FormationReadyCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return helper(p, 0, &a, &b, 0) != 0;
}


// 0x00111310 fight::ParamEnumConstList<hulkfight::ai::FormationReadyCondition>::vfunc_0 (30 B): matches/0x00111310.cpp
// sym: ??_G?$ParamEnumConstList@VFormationReadyCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::ai::FormationReadyCondition>::~ParamEnumConstList() {}


// 0x00111330 fight::ParamString<hulkfight::ai::FormationReadyCondition>::vfunc_0 (30 B): matches/0x00111330.cpp
// sym: ??_G?$ParamString@VFormationReadyCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamString<hulkfight::ai::FormationReadyCondition>::~ParamString() {}

