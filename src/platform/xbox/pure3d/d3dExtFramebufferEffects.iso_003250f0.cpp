// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x00320160..0x00325ee0 (kind game, layer platform/xbox, confidence high), dominant class pure3d::d3dExtFramebufferEffects
// (tree_prelude.h: not needed)


// 0x003250f0 pure3d::d3dContext::vfunc_3 (30 B): matches/0x003250f0.cpp [isolated: conflict: pure3d::d3dContext::~d3dContext; on include/gen/ and not mergeable]
// sym: ??_Gd3dContext@pure3d@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
#include "gen/pure3d.h"

// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
pure3d::d3dContext::~d3dContext() {}

