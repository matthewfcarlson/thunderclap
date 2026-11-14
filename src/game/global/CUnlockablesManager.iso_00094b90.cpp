// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x00093600..0x000964d0 (kind game, layer game, confidence high), dominant class CUnlockablesManager
// (tree_prelude.h: not needed)


// 0x00094b90 Closure4<CUnlockablesManager,void,const_char_*,int,const_char_*,const_char_*>::vfunc_0 (30 B): matches/0x00094b90.cpp [isolated: lost its match in the tree (a call became inline code (callee now defined in the same TU)); on include/gen/ and not mergeable]
// sym: ??_G?$Closure4@VCUnlockablesManager@@XPBDHPBDPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
#include "gen/global.h"

// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure4<CUnlockablesManager, void, const char *, int, const char *, const char *>::~Closure4() {}
#if defined(HULK_PTR64)
template class Closure4<CUnlockablesManager, void, const char *, int, const char *, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x94b90)
#endif

