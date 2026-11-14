// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x00203870..0x00208b9c (kind game, layer game, confidence high), dominant class CWorldStreamManager
// (tree_prelude.h: not needed)


// 0x002061a0 Closure3<CWorldStreamManager,void,const_char_*,int,bool>::vfunc_0 (30 B): matches/0x002061a0.cpp [isolated: lost its match in the tree (a call became inline code (callee now defined in the same TU)); on include/gen/ and not mergeable]
// sym: ??_G?$Closure3@VCWorldStreamManager@@XPBDH_N@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
#include "gen/global.h"

// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure3<CWorldStreamManager, void, const char *, int, bool>::~Closure3() {}
#if defined(HULK_PTR64)
template class Closure3<CWorldStreamManager, void, const char *, int, bool>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2061a0)
#endif

