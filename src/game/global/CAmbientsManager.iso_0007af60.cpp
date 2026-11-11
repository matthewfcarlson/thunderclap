// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000788e0..0x00081340 (kind game, layer game, confidence high), dominant class CAmbientsManager
// (tree_prelude.h: not needed)


// 0x0007af60 CAmbientsManager::vfunc_0 (30 B): matches/0x0007af60.cpp [isolated: conflict: CAmbientsManager::~CAmbientsManager; on include/gen/ and not mergeable]
// sym: ??_GCAmbientsManager@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
#include "gen/global.h"

// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
CAmbientsManager::~CAmbientsManager() {}

