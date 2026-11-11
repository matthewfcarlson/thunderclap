// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000788e0..0x00081340 (kind game, layer game, confidence high), dominant class CAmbientsManager
// (tree_prelude.h: not needed)


// 0x0007e490 Closure3<CAmbientsManager,void,const_char_*,unsigned_int,float>::vfunc_0 (30 B): matches/0x0007e490.cpp [isolated: lost its match in the tree (a call became inline code (callee now defined in the same TU)); on include/gen/ and not mergeable]
// sym: ??_G?$Closure3@VCAmbientsManager@@XPBDIM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
#include "gen/global.h"

// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure3<CAmbientsManager, void, const char *, unsigned int, float>::~Closure3() {}
#if defined(HULK_PTR64)
template class Closure3<CAmbientsManager, void, const char *, unsigned int, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x7e490)
#endif

