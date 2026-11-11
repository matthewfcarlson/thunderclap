// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000d7af0..0x000dc230 (kind game, layer game, confidence high), dominant class FEMemCardControl
// (tree_prelude.h: not needed)


// 0x000d83f0 FEMemCardControl::vfunc_2 (30 B): matches/0x000d83f0.cpp [isolated: conflict: FEMemCardControl::~FEMemCardControl; on include/gen/ and not mergeable]
// sym: ??_GFEMemCardControl@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
#include "gen/global.h"

// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
FEMemCardControl::~FEMemCardControl() {}

