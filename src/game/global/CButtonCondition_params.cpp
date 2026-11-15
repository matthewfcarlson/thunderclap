// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x000514f0..0x00051940 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f0ce3427 {
#define TREE_TU_END }
namespace fn_f0ce3427 {} using namespace fn_f0ce3427;
#include "game/global.h"


// 0x000517b0 fight::ParamEnumConstList<CNameFlagConditionBase>::vfunc_0 (30 B): matches/0x000517b0.cpp
// sym: ??_G?$ParamEnumConstList@VCNameFlagConditionBase@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<CNameFlagConditionBase>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<CNameFlagConditionBase>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x517b0)
#endif

