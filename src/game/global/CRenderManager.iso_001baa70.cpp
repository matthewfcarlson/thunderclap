// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x001b8690..0x001bc0c0 (kind game, layer game, confidence high), dominant class CRenderManager
// (tree_prelude.h: not needed)


// 0x001baa70 Closure1<CRenderManager,void,float>::vfunc_0 (30 B): matches/0x001baa70.cpp [isolated: lost its match in the tree (a call became inline code (callee now defined in the same TU)); on include/gen/ and not mergeable]
// sym: ??_G?$Closure1@VCRenderManager@@XM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
#include "gen/global.h"

// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure1<CRenderManager, void, float>::~Closure1() {}
#if defined(HULK_PTR64)
template class Closure1<CRenderManager, void, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1baa70)
#endif

