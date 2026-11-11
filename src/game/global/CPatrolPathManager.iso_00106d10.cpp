// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001065b0..0x00107000 (kind game, layer game, confidence high), dominant class CPatrolPathManager
// (tree_prelude.h: not needed)


// 0x00106d10 Closure3<CPatrolPathManager,bool,const_char_*,int,math::Vector>::vfunc_0 (30 B): matches/0x00106d10.cpp [isolated: lost its match in the tree (a call became inline code (callee now defined in the same TU)); on include/gen/ and not mergeable]
// sym: ??_G?$Closure3@VCPatrolPathManager@@_NPBDHVVector@math@@@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
#include "gen/global.h"

// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure3<CPatrolPathManager, bool, const char *, int,math::Vector>::~Closure3() {}

