// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0028dfc0..0x0028e0c0 (kind game, layer engine, confidence medium), dominant class pure3d::RotationChannel
// (tree_prelude.h: not needed)


// 0x0028e060 pure3d::Vector2DOFChannel::vfunc_0 (30 B): matches/0x0028e060.cpp [isolated: lost its match in the tree (a call became inline code (callee now defined in the same TU)); on include/gen/ and not mergeable]
// sym: ??_GVector2DOFChannel@pure3d@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
#include "gen/pure3d.h"

// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
pure3d::Vector2DOFChannel::~Vector2DOFChannel() {}

