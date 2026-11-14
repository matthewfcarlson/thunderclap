// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x0006ee00..0x0006ee60 (kind game, layer game, confidence high), dominant class COrientTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f32cd57b {
#define TREE_TU_END }
namespace fn_f32cd57b {} using namespace fn_f32cd57b;
#include "game/global.h"


// 0x0006ee00 fight::ParamFloatConstRange<COrientTrack>::vfunc_0 (30 B): matches/0x0006ee00.cpp
// sym: ??_G?$ParamFloatConstRange@VCOrientTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<COrientTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<COrientTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x6ee00)
#endif


// 0x0006ee20 fight::ParamBool<COrientTrack>::vfunc_0 (30 B): matches/0x0006ee20.cpp
// sym: ??_G?$ParamBool@VCOrientTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<COrientTrack>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<COrientTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x6ee20)
#endif


// 0x0006ee40 fight::ParamIntConstRange<COrientTrack>::vfunc_0 (30 B): matches/0x0006ee40.cpp
// sym: ??_G?$ParamIntConstRange@VCOrientTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<COrientTrack>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<COrientTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x6ee40)
#endif

