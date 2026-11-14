// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x001fc690..0x00201740 (kind game, layer game, confidence high), dominant class CTriggerVolumeManager
// (tree_prelude.h: not needed)


// 0x00200270 Closure4<CTriggerVolumeManager,bool,const_char_*,int,int,bool>::vfunc_0 (30 B): matches/0x00200270.cpp [isolated: lost its match in the tree (a call became inline code (callee now defined in the same TU)); on include/gen/ and not mergeable]
// sym: ??_G?$Closure4@VCTriggerVolumeManager@@_NPBDHH_N@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
#include "gen/global.h"

// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure4<CTriggerVolumeManager, bool, const char *, int, int, bool>::~Closure4() {}
#if defined(HULK_PTR64)
template class Closure4<CTriggerVolumeManager, bool, const char *, int, int, bool>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x200270)
#endif

