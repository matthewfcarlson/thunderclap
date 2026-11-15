// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x0006e8c0..0x0006e960 (kind game, layer game, confidence high), dominant class CJumpTrack
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_ff8e3545 {
#define TREE_TU_END }
namespace fn_ff8e3545 {} using namespace fn_ff8e3545;
#include "game/global.h"


// 0x0006e8c0 fight::ParamFloat<CScrubberTrack>::vfunc_0 (30 B): matches/0x0006e8c0.cpp
// sym: ??_G?$ParamFloat@VCScrubberTrack@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloat<CScrubberTrack>::~ParamFloat() {}
#if defined(HULK_PTR64)
template class fight::ParamFloat<CScrubberTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x6e8c0)
#endif

