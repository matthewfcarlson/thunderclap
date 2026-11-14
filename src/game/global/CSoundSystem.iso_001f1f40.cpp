// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x001f0ab0..0x001f2db0 (kind game, layer game, confidence high), dominant class CSoundSystem
// (tree_prelude.h: not needed)


// 0x001f1f40 Closure4<CSoundSystem,void,char_*,char_*,float,float>::vfunc_0 (30 B): matches/0x001f1f40.cpp [isolated: lost its match in the tree (a call became inline code (callee now defined in the same TU)); on include/gen/ and not mergeable]
// sym: ??_G?$Closure4@VCSoundSystem@@XPADPADMM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
#include "gen/global.h"

// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure4<CSoundSystem, void, char *, char *, float, float>::~Closure4() {}
#if defined(HULK_PTR64)
template class Closure4<CSoundSystem, void, char *, char *, float, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1f1f40)
#endif

