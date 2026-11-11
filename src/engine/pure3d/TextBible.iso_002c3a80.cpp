// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002c3670..0x002c3aa0 (kind game, layer engine, confidence high), dominant class pure3d::TextBible
// (tree_prelude.h: not needed)


// 0x002c3a80 pure3d::TextBible::vfunc_2 (30 B): matches/0x002c3a80.cpp [isolated: conflict: pure3d::TextBible::~TextBible; on include/gen/ and not mergeable]
// sym: ??_GTextBible@pure3d@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
#include "gen/pure3d.h"

// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
pure3d::TextBible::~TextBible() {}

