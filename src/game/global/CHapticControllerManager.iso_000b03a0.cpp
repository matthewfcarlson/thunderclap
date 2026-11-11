// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000b0060..0x000b0440 (kind game, layer game, confidence high), dominant class CHapticControllerManager
// (tree_prelude.h: not needed)


// 0x000b03a0 Closure1<CHapticControllerManager,void,bool>::vfunc_0 (30 B): matches/0x000b03a0.cpp [isolated: lost its match in the tree (a call became inline code (callee now defined in the same TU)); on include/gen/ and not mergeable]
// sym: ??_G?$Closure1@VCHapticControllerManager@@X_N@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
#include "gen/global.h"

// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure1<CHapticControllerManager, void, bool>::~Closure1() {}

