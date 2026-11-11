// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000be230..0x000c4ec0 (kind game, layer game, confidence high), dominant class CFEManager
// (tree_prelude.h: not needed)


// 0x000c0260 Closure2<CFEManager,void,const_char_*,int>::vfunc_0 (30 B): matches/0x000c0260.cpp [isolated: lost its match in the tree (a call became inline code (callee now defined in the same TU)); on include/gen/ and not mergeable]
// sym: ??_G?$Closure2@VCFEManager@@XPBDH@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
#include "gen/global.h"

// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure2<CFEManager, void, const char *, int>::~Closure2() {}

