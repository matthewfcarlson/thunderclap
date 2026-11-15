// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x00051480..0x00056af0 (kind game, layer game, confidence high), merged by D32: global/CStageCondition_params_factory.cpp
// piece 0x00051dd0..0x00051ed0 (kind game, layer game, confidence high, dominant class CFightNodePrevCondition); was game/global/CFightNodePrevCondition.cpp until D46
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f76a0ac6 {
#define TREE_TU_END }
namespace fn_f76a0ac6 {} using namespace fn_f76a0ac6;
#include "game/global.h"


// 0x00051e10 fight::ParamEnumConstList<CCharacterFloatCondition>::vfunc_0 (30 B): matches/0x00051e10.cpp
// sym: ??_G?$ParamEnumConstList@VCCharacterFloatCondition@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<CCharacterFloatCondition>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<CCharacterFloatCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x51e10)
#endif


// 0x00051e30 fight::ParamFloatConstRange<CCharacterFloatCondition>::vfunc_0 (30 B): matches/0x00051e30.cpp
// sym: ??_G?$ParamFloatConstRange@VCCharacterFloatCondition@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<CCharacterFloatCondition>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<CCharacterFloatCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x51e30)
#endif


// 0x00051e50 fight::ParamEnumConstList<CCharacterBoolCondition>::vfunc_0 (30 B): matches/0x00051e50.cpp
// sym: ??_G?$ParamEnumConstList@VCCharacterBoolCondition@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<CCharacterBoolCondition>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<CCharacterBoolCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x51e50)
#endif

