// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00051aa0..0x00051b10 (kind game, layer game, confidence high), dominant class CSmartPropDistanceCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f71e2877 {
#define TREE_TU_END }
namespace fn_f71e2877 {} using namespace fn_f71e2877;
#include "game/global.h"


// 0x00051aa0 fight::ParamEnumConstList<CSmartPropDistanceCondition>::vfunc_0 (30 B): matches/0x00051aa0.cpp
// sym: ??_G?$ParamEnumConstList@VCSmartPropDistanceCondition@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<CSmartPropDistanceCondition>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<CSmartPropDistanceCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x51aa0)
#endif


// 0x00051ac0 fight::ParamFloatConstRange<CSmartPropDistanceCondition>::vfunc_0 (30 B): matches/0x00051ac0.cpp
// sym: ??_G?$ParamFloatConstRange@VCSmartPropDistanceCondition@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<CSmartPropDistanceCondition>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<CSmartPropDistanceCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x51ac0)
#endif


// 0x00051af0 fight::ParamVector<CSmartPropDistanceCondition>::vfunc_0 (30 B): matches/0x00051af0.cpp
// sym: ??_G?$ParamVector@VCSmartPropDistanceCondition@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamVector<CSmartPropDistanceCondition>::~ParamVector() {}
#if defined(HULK_PTR64)
template class fight::ParamVector<CSmartPropDistanceCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x51af0)
#endif

