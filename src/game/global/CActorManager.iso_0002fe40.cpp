// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0002c4f0..0x00034400 (kind game, layer game, confidence high), dominant class CActorManager
// (tree_prelude.h: not needed)


// 0x0002fe40 Closure0<CActorManager,float>::vfunc_0 (30 B): matches/0x0002fe40.cpp [isolated: lost its match in the tree (a call became inline code (callee now defined in the same TU)); on include/gen/ and not mergeable]
// sym: ??_G?$Closure0@VCActorManager@@M@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
#include "gen/global.h"

// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure0<CActorManager, float>::~Closure0() {}
#if defined(HULK_PTR64)
template class Closure0<CActorManager, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2fe40)
#endif

