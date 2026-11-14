// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x000d40e0..0x000d6e00 (kind game, layer game, confidence high), dominant class MessageOverlay
// (tree_prelude.h: not needed)


// 0x000d6350 Closure5<MessageOverlay,void,int,const_char_*,int,math::Vector,float>::vfunc_0 (30 B): matches/0x000d6350.cpp [isolated: lost its match in the tree (a call became inline code (callee now defined in the same TU)); on include/gen/ and not mergeable]
// sym: ??_G?$Closure5@VMessageOverlay@@XHPBDHVVector@math@@M@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
#include "gen/global.h"

// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure5<MessageOverlay, void, int, const char *, int,math::Vector, float>::~Closure5() {}
#if defined(HULK_PTR64)
template class Closure5<MessageOverlay, void, int, const char *, int,math::Vector, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0xd6350)
#endif

