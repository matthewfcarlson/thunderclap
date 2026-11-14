// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x000989d0..0x0009f760 (kind game, layer game, confidence high), dominant class CCameraManager
// (tree_prelude.h: not needed)


// 0x0009ccd0 Closure6<CCameraManager,bool,float,float,float,float,float,float>::vfunc_0 (30 B): matches/0x0009ccd0.cpp [isolated: lost its match in the tree (a call became inline code (callee now defined in the same TU)); on include/gen/ and not mergeable]
// sym: ??_G?$Closure6@VCCameraManager@@_NMMMMMM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
#include "gen/global.h"

// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure6<CCameraManager, bool, float, float, float, float, float, float>::~Closure6() {}
#if defined(HULK_PTR64)
template class Closure6<CCameraManager, bool, float, float, float, float, float, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x9ccd0)
#endif

