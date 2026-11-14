// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x000be230..0x000c4ec0 (kind game, layer game, confidence high), dominant class CFEManager
// (tree_prelude.h: not needed)


// 0x000c02e0 Closure0<CFEManager,int>::vfunc_0 (30 B): matches/0x000c02e0.cpp [isolated: lost its match in the tree (a call became inline code (callee now defined in the same TU)); on include/gen/ and not mergeable]
// sym: ??_G?$Closure0@VCFEManager@@H@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
#include "gen/global.h"

// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure0<CFEManager, int>::~Closure0() {}
#if defined(HULK_PTR64)
template class Closure0<CFEManager, int>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0xc02e0)
#endif

