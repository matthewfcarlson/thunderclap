// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x001047b0..0x00106170 (kind game, layer game, confidence high), dominant class CPathAgent
// (tree_prelude.h: not needed)


// 0x00105e30 CPathAgent::vfunc_2 (30 B): matches/0x00105e30.cpp [isolated: conflict: CPathAgent::~CPathAgent; on include/gen/ and not mergeable]
// sym: ??_GCPathAgent@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
#include "gen/global.h"

// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
CPathAgent::~CPathAgent() {}

