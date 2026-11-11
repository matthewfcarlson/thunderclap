// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00089400..0x0008c570 (kind game, layer game, confidence high), dominant class CGameFlowManager
// (tree_prelude.h: not needed)


// 0x0008b400 Closure1<CGameFlowManager,const_char_*,const_char_*>::vfunc_0 (30 B): matches/0x0008b400.cpp [isolated: lost its match in the tree (a call became inline code (callee now defined in the same TU)); on include/gen/ and not mergeable]
// sym: ??_G?$Closure1@VCGameFlowManager@@PBDPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
#include "gen/global.h"

// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure1<CGameFlowManager, const char *, const char *>::~Closure1() {}

