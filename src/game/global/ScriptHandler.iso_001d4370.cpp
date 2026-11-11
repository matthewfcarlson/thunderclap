// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001d0620..0x001d4d50 (kind game, layer game, confidence high), dominant class ScriptHandler
// (tree_prelude.h: not needed)


// 0x001d4370 Closure1<ScriptHandler,ScriptHandler::script_state,const_char_*>::vfunc_0 (30 B): matches/0x001d4370.cpp [isolated: lost its match in the tree (a call became inline code (callee now defined in the same TU)); on include/gen/ and not mergeable]
// sym: ??_G?$Closure1@VScriptHandler@@W4script_state@1@PBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
#include "gen/global.h"

// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure1<ScriptHandler,ScriptHandler::script_state, const char *>::~Closure1() {}

