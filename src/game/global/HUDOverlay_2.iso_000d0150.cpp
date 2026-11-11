// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000cc7e0..0x000d40e0 (kind game, layer game, confidence high), dominant class HUDOverlay
// (tree_prelude.h: not needed)


// 0x000d0150 Closure5<HUDOverlay,int,int,const_char_*,math::Vector,math::Vector,math::Vector>::vfunc_0 (30 B): matches/0x000d0150.cpp [isolated: lost its match in the tree (a call became inline code (callee now defined in the same TU)); on include/gen/ and not mergeable]
// sym: ??_G?$Closure5@VHUDOverlay@@HHPBDVVector@math@@V23@V23@@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
#include "gen/global.h"

// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure5<HUDOverlay, int, int, const char *,math::Vector,math::Vector,math::Vector>::~Closure5() {}

