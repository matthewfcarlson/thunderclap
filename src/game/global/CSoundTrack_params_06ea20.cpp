// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x0006ea20..0x0006ea80 (kind game, layer game, confidence high), dominant class CSoundTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f0e00859 {
#define TREE_TU_END }
namespace fn_f0e00859 {} using namespace fn_f0e00859;
#include "game/global.h"


// 0x0006ea20 fight::ParamFloatConstRange<CSoundTrack>::vfunc_0 (30 B): matches/0x0006ea20.cpp
// sym: ??_G?$ParamFloatConstRange@VCSoundTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<CSoundTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<CSoundTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x6ea20)
#endif


// 0x0006ea40 fight::ParamString<CSoundTrack>::vfunc_0 (30 B): matches/0x0006ea40.cpp
// sym: ??_G?$ParamString@VCSoundTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamString<CSoundTrack>::~ParamString() {}
#if defined(HULK_PTR64)
template class fight::ParamString<CSoundTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x6ea40)
#endif


// 0x0006ea60 fight::ParamBool<CSoundTrack>::vfunc_0 (30 B): matches/0x0006ea60.cpp
// sym: ??_G?$ParamBool@VCSoundTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<CSoundTrack>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<CSoundTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x6ea60)
#endif

