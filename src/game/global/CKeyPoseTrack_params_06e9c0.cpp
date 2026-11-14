// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x0006e9c0..0x0006ea20 (kind game, layer game, confidence high), dominant class CKeyPoseTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f2b5273f {
#define TREE_TU_END }
namespace fn_f2b5273f {} using namespace fn_f2b5273f;
#include "game/global.h"


// 0x0006e9c0 fight::ParamFloatConstRange<CKeyPoseTrack>::vfunc_0 (30 B): matches/0x0006e9c0.cpp
// sym: ??_G?$ParamFloatConstRange@VCKeyPoseTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<CKeyPoseTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<CKeyPoseTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x6e9c0)
#endif


// 0x0006e9e0 fight::ParamBool<CKeyPoseTrack>::vfunc_0 (30 B): matches/0x0006e9e0.cpp
// sym: ??_G?$ParamBool@VCKeyPoseTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<CKeyPoseTrack>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<CKeyPoseTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x6e9e0)
#endif


// 0x0006ea00 fight::ParamIntConstRange<CKeyPoseTrack>::vfunc_0 (30 B): matches/0x0006ea00.cpp
// sym: ??_G?$ParamIntConstRange@VCKeyPoseTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<CKeyPoseTrack>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<CKeyPoseTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x6ea00)
#endif

