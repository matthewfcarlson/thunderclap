// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x00051b10..0x00051c50 (kind game, layer game, confidence high), dominant class CLuaNumberCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fb4071e0 {
#define TREE_TU_END }
namespace fn_fb4071e0 {} using namespace fn_fb4071e0;
#include "game/global.h"


// 0x00051b10 fight::ParamEnumConstList<CSmartPropGrabbableNameCondition>::vfunc_0 (30 B): matches/0x00051b10.cpp
// sym: ??_G?$ParamEnumConstList@VCSmartPropGrabbableNameCondition@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<CSmartPropGrabbableNameCondition>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<CSmartPropGrabbableNameCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x51b10)
#endif

