// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001b7970..0x001b8690 (kind game, layer game, confidence high), dominant class CFMVManager
// (tree_prelude.h: not needed)


// 0x001b8280 Closure0<CFMVManager,bool>::vfunc_0 (30 B): matches/0x001b8280.cpp [isolated: lost its match in the tree (a call became inline code (callee now defined in the same TU)); on include/gen/ and not mergeable]
// sym: ??_G?$Closure0@VCFMVManager@@_N@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
#include "gen/global.h"

// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure0<CFMVManager, bool>::~Closure0() {}
#if defined(HULK_PTR64)
template class Closure0<CFMVManager, bool>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1b8280)
#endif

