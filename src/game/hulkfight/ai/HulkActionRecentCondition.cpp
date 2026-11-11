// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00111160..0x001111e0 (kind game, layer game, confidence high), dominant class hulkfight::ai::HulkActionRecentCondition
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


// 0x00111190 fight::ParamEnumConstList<hulkfight::ai::HulkActionRecentCondition>::vfunc_0 (30 B): matches/0x00111190.cpp
// sym: ??_G?$ParamEnumConstList@VHulkActionRecentCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::ai::HulkActionRecentCondition>::~ParamEnumConstList() {}


// 0x001111b0 fight::ParamString<hulkfight::ai::HulkActionRecentCondition>::vfunc_0 (30 B): matches/0x001111b0.cpp
// sym: ??_G?$ParamString@VHulkActionRecentCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamString<hulkfight::ai::HulkActionRecentCondition>::~ParamString() {}

