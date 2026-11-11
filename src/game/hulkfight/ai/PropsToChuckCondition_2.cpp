// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001110e0..0x00111160 (kind game, layer game, confidence high), dominant class hulkfight::ai::PropsToChuckCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f28dcc5d {
#define TREE_TU_END }
namespace fn_f28dcc5d {} using namespace fn_f28dcc5d;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_f28dcc5d {
extern char DAT_00491ca8;
extern char DAT_004a3ce0;
extern "C" int FUN_00344e74(hulk_intptr a, int b, hulk_intptr c, hulk_intptr d, int e);

} // namespace fn_f28dcc5d

// 0x001110e0 fight::ConditionFactoryCasterTemplate<hulkfight::ai::PropsToChuckCondition>::vfunc_0 (36 B): matches/0x001110e0.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VPropsToChuckCondition@ai@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::PropsToChuckCondition>::vfunc_0(void* __p0) { int a = (int)__p0;

    return (FUN_00344e74(a, 0, (hulk_intptr)&DAT_00491ca8, (hulk_intptr)&DAT_004a3ce0, 0) != 0);
}


// 0x00111110 fight::ParamEnumConstList<hulkfight::ai::PropsToChuckCondition>::vfunc_0 (30 B): matches/0x00111110.cpp
// sym: ??_G?$ParamEnumConstList@VPropsToChuckCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::ai::PropsToChuckCondition>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::ai::PropsToChuckCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x111110)
#endif


// 0x00111130 fight::ParamIntConstRange<hulkfight::ai::PropsToChuckCondition>::vfunc_0 (30 B): matches/0x00111130.cpp
// sym: ??_G?$ParamIntConstRange@VPropsToChuckCondition@ai@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::ai::PropsToChuckCondition>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<hulkfight::ai::PropsToChuckCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x111130)
#endif

