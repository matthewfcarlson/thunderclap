// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000788e0..0x00081340 (kind game, layer game, confidence high), dominant class CAmbientsManager
// (tree_prelude.h: not needed)


// 0x0007e430 Closure4<CAmbientsManager,void,const_char_*,int,const_math::Vector,const_math::Vector>::vfunc_0 (30 B): matches/0x0007e430.cpp [isolated: lost its match in the tree (a call became inline code (callee now defined in the same TU)); on include/gen/ and not mergeable]
// sym: ??_G?$Closure4@VCAmbientsManager@@XPBDH$$CBVVector@math@@$$CBV23@@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
#include "gen/global.h"

// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure4<CAmbientsManager, void, const char *, int, const ::math::Vector, const ::math::Vector>::~Closure4() {}

