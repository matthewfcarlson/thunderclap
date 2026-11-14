// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x0023a3f0..0x0023b540 (kind game, layer engine, confidence high), dominant class fight::ScriptReader
// (tree_prelude.h: not needed)


// 0x0023b4f0 fight::ScriptReader::vfunc_2 (30 B): matches/0x0023b4f0.cpp [isolated: lost its match in the tree (a call became inline code (callee now defined in the same TU)); on include/gen/ and not mergeable]
// sym: ??_GScriptReader@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
#include "gen/fight.h"

// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
fight::ScriptReader::~ScriptReader() {}

