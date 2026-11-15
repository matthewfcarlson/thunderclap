// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x00051c50..0x00051d70 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f19f4e34 {
#define TREE_TU_END }
namespace fn_f19f4e34 {} using namespace fn_f19f4e34;
#include "game/global.h"


// 0x00051c50 fight::ParamEnumConstList<CCharacterTemplateCondition>::vfunc_0 (30 B): matches/0x00051c50.cpp
// sym: ??_G?$ParamEnumConstList@VCCharacterTemplateCondition@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<CCharacterTemplateCondition>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<CCharacterTemplateCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x51c50)
#endif


// 0x00051c70 fight::ParamEnumConstList<CCharacterTemplateVariationCondition>::vfunc_0 (30 B): matches/0x00051c70.cpp
// sym: ??_G?$ParamEnumConstList@VCCharacterTemplateVariationCondition@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<CCharacterTemplateVariationCondition>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<CCharacterTemplateVariationCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x51c70)
#endif


// 0x00051c90 fight::ParamEnumConstList<CGrappleCharacterTemplateCondition>::vfunc_0 (30 B): matches/0x00051c90.cpp
// sym: ??_G?$ParamEnumConstList@VCGrappleCharacterTemplateCondition@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<CGrappleCharacterTemplateCondition>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<CGrappleCharacterTemplateCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x51c90)
#endif

