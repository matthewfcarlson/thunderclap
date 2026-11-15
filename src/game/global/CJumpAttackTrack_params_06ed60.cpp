// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x0006ed60..0x0006ee00 (kind game, layer game, confidence high), dominant class CJumpAttackTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f7596310 {
#define TREE_TU_END }
namespace fn_f7596310 {} using namespace fn_f7596310;
#include "game/global.h"


// 0x0006ed60 fight::ParamFloatConstRange<CCameraHintTrack>::vfunc_0 (30 B): matches/0x0006ed60.cpp
// sym: ??_G?$ParamFloatConstRange@VCCameraHintTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<CCameraHintTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<CCameraHintTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x6ed60)
#endif


// 0x0006ed80 fight::ParamEnumConstList<CCameraHintTrack>::vfunc_0 (30 B): matches/0x0006ed80.cpp
// sym: ??_G?$ParamEnumConstList@VCCameraHintTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<CCameraHintTrack>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<CCameraHintTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x6ed80)
#endif


// 0x0006eda0 fight::ParamFloatConstRange<CJumpAttackTrack>::vfunc_0 (30 B): matches/0x0006eda0.cpp
// sym: ??_G?$ParamFloatConstRange@VCJumpAttackTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<CJumpAttackTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<CJumpAttackTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x6eda0)
#endif


// 0x0006edc0 fight::ParamVector<CJumpAttackTrack>::vfunc_0 (30 B): matches/0x0006edc0.cpp
// sym: ??_G?$ParamVector@VCJumpAttackTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamVector<CJumpAttackTrack>::~ParamVector() {}
#if defined(HULK_PTR64)
template class fight::ParamVector<CJumpAttackTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x6edc0)
#endif


// 0x0006ede0 fight::ParamIntConstRange<CJumpAttackTrack>::vfunc_0 (30 B): matches/0x0006ede0.cpp
// sym: ??_G?$ParamIntConstRange@VCJumpAttackTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<CJumpAttackTrack>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<CJumpAttackTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x6ede0)
#endif

