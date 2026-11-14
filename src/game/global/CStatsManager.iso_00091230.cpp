// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x0008ffb0..0x00091af0 (kind game, layer game, confidence high), dominant class CStatsManager
// (tree_prelude.h: not needed)


// 0x00091230 Closure3<CStatsManager,void,char_*,char_*,int>::vfunc_0 (30 B): matches/0x00091230.cpp [isolated: lost its match in the tree (a call became inline code (callee now defined in the same TU)); on include/gen/ and not mergeable]
// sym: ??_G?$Closure3@VCStatsManager@@XPADPADH@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
#include "gen/global.h"

// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure3<CStatsManager, void, char *, char *, int>::~Closure3() {}
#if defined(HULK_PTR64)
template class Closure3<CStatsManager, void, char *, char *, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x91230)
#endif

