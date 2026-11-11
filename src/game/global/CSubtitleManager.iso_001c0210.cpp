// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001be0e0..0x001c1200 (kind game, layer game, confidence high), dominant class CSubtitleManager
// (tree_prelude.h: not needed)


// 0x001c0210 Closure3<CSubtitleManager,void,const_char_*,const_char_*,float>::vfunc_0 (30 B): matches/0x001c0210.cpp [isolated: lost its match in the tree (a call became inline code (callee now defined in the same TU)); on include/gen/ and not mergeable]
// sym: ??_G?$Closure3@VCSubtitleManager@@XPBDPBDM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
#include "gen/global.h"

// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure3<CSubtitleManager, void, const char *, const char *, float>::~Closure3() {}

