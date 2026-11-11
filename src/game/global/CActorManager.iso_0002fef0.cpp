// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0002c4f0..0x00034400 (kind game, layer game, confidence high), dominant class CActorManager
// (tree_prelude.h: not needed)


// 0x0002fef0 Closure2<CActorManager,math::Vector,math::Vector,float>::vfunc_0 (30 B): matches/0x0002fef0.cpp [isolated: lost its match in the tree (a call became inline code (callee now defined in the same TU)); on include/gen/ and not mergeable]
// sym: ??_G?$Closure2@VCActorManager@@VVector@math@@V23@M@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
#include "gen/global.h"

// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure2<CActorManager,math::Vector,math::Vector, float>::~Closure2() {}
#if defined(HULK_PTR64)
template class Closure2<CActorManager,math::Vector,math::Vector, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2fef0)
#endif

