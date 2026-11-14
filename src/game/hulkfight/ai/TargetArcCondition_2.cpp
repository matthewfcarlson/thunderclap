// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
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


// 0x00127ab0 fight::ParamFloatConstRange<hulkfight::ai::TargetArcCondition>::vfunc_0 (30 B): matches/0x00127ab0.cpp
// sym: ??_G?$ParamFloatConstRange@VTargetArcCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::ai::TargetArcCondition>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::ai::TargetArcCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x127ab0)
#endif


// 0x00127ad0 fight::ParamBool<hulkfight::ai::TargetArcCondition>::vfunc_0 (30 B): matches/0x00127ad0.cpp
// sym: ??_G?$ParamBool@VTargetArcCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::ai::TargetArcCondition>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::ai::TargetArcCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x127ad0)
#endif


// 0x00127af0 fight::ParamVector<hulkfight::ai::TargetArcCondition>::vfunc_0 (30 B): matches/0x00127af0.cpp
// sym: ??_G?$ParamVector@VTargetArcCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamVector<hulkfight::ai::TargetArcCondition>::~ParamVector() {}
#if defined(HULK_PTR64)
template class fight::ParamVector<hulkfight::ai::TargetArcCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x127af0)
#endif

