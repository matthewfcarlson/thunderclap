// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x00284a10..0x002878b0 (kind game, layer engine, confidence high), dominant class pure3d::DefaultFrameControllerHandler
// (tree_prelude.h: not needed)


// 0x00286500 pure3d::BlendFrameController::vfunc_2 (30 B): matches/0x00286500.cpp [isolated: conflict: pure3d::BlendFrameController::~BlendFrameController; on include/gen/ and not mergeable]
// sym: ??_GBlendFrameController@pure3d@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
#include "gen/pure3d.h"

// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
pure3d::BlendFrameController::~BlendFrameController() {}

