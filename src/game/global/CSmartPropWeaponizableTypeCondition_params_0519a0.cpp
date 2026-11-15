// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x000519a0..0x00051aa0 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f6a11b4b {
#define TREE_TU_END }
namespace fn_f6a11b4b {} using namespace fn_f6a11b4b;
#include "game/global.h"


// 0x00051a40 fight::ParamEnumConstList<CSmartPropNameCondition>::vfunc_0 (30 B): matches/0x00051a40.cpp
// sym: ??_G?$ParamEnumConstList@VCSmartPropNameCondition@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<CSmartPropNameCondition>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<CSmartPropNameCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x51a40)
#endif


// 0x00051a60 fight::ParamIntConstRange<CSmartPropNameCondition>::vfunc_0 (30 B): matches/0x00051a60.cpp
// sym: ??_G?$ParamIntConstRange@VCSmartPropNameCondition@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<CSmartPropNameCondition>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<CSmartPropNameCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x51a60)
#endif

