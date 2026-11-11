// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0027ca80..0x0027f2a0 (kind game, layer engine, confidence high), dominant class pure3d::prop::StateProp
// (tree_prelude.h: not needed)


// 0x0027e900 pure3d::prop::StateProp::vfunc_2 (30 B): matches/0x0027e900.cpp [isolated: conflict: pure3d::prop::StateProp::~StateProp; on include/gen/ and not mergeable]
// sym: ??_GStateProp@prop@pure3d@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
#include "gen/pure3d.h"

// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
pure3d::prop::StateProp::~StateProp() {}

