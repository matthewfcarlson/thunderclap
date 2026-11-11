// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000be230..0x000c4ec0 (kind game, layer game, confidence high), dominant class CFEManager
// (tree_prelude.h: not needed)


// 0x000c0100 Closure7<CFEManager,void,const_char_*,const_char_*,const_char_*,const_char_*,const_char_*,const_char_*,const_char_*>::vfunc_0 (30 B): matches/0x000c0100.cpp [isolated: lost its match in the tree (ambiguous); on include/gen/ and not mergeable]
// sym: ??_G?$Closure7@VCFEManager@@XPBDPBDPBDPBDPBDPBDPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
#include "gen/global.h"

// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure7<CFEManager, void, const char *, const char *, const char *, const char *, const char *, const char *, const char *>::~Closure7() {}
#if defined(HULK_PTR64)
template class Closure7<CFEManager, void, const char *, const char *, const char *, const char *, const char *, const char *, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0xc0100)
#endif

