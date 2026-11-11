// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00051d70..0x00051dd0 (kind game, layer game, confidence high), dominant class CGrappleTimerCondition
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fe90a4b8 {
#define TREE_TU_END }
namespace fn_fe90a4b8 {} using namespace fn_fe90a4b8;
#include "game/global.h"


// 0x00051d70 fight::ParamEnumConstList<CGrappleTimerCondition>::vfunc_0 (30 B): matches/0x00051d70.cpp
// sym: ??_G?$ParamEnumConstList@VCGrappleTimerCondition@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<CGrappleTimerCondition>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<CGrappleTimerCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x51d70)
#endif


// 0x00051d90 fight::ParamFloatConstRange<CGrappleTimerCondition>::vfunc_0 (30 B): matches/0x00051d90.cpp
// sym: ??_G?$ParamFloatConstRange@VCGrappleTimerCondition@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<CGrappleTimerCondition>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<CGrappleTimerCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x51d90)
#endif


// 0x00051db0 fight::ParamBool<CGrappleTimerCondition>::vfunc_0 (30 B): matches/0x00051db0.cpp
// sym: ??_G?$ParamBool@VCGrappleTimerCondition@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<CGrappleTimerCondition>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<CGrappleTimerCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x51db0)
#endif

