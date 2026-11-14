// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x00051940..0x000519a0 (kind game, layer game, confidence high), dominant class CSmartPropAttachedCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f48d610f {
#define TREE_TU_END }
namespace fn_f48d610f {} using namespace fn_f48d610f;
#include "game/global.h"


// 0x00051940 fight::ParamBool<CSmartPropAttachedCondition>::vfunc_0 (30 B): matches/0x00051940.cpp
// sym: ??_G?$ParamBool@VCSmartPropAttachedCondition@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<CSmartPropAttachedCondition>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<CSmartPropAttachedCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x51940)
#endif


// 0x00051960 fight::ParamEnumConstList<CSmartPropAttachedCondition>::vfunc_0 (30 B): matches/0x00051960.cpp
// sym: ??_G?$ParamEnumConstList@VCSmartPropAttachedCondition@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<CSmartPropAttachedCondition>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<CSmartPropAttachedCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x51960)
#endif


// 0x00051980 fight::ParamIntConstRange<CSmartPropAttachedCondition>::vfunc_0 (30 B): matches/0x00051980.cpp
// sym: ??_G?$ParamIntConstRange@VCSmartPropAttachedCondition@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<CSmartPropAttachedCondition>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<CSmartPropAttachedCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x51980)
#endif

