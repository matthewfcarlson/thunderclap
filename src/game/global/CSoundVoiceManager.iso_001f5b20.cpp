// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001f2e40..0x001f6bc0 (kind game, layer game, confidence high), dominant class CSoundVoiceManager
// (tree_prelude.h: not needed)


// 0x001f5b20 Closure4<CSoundVoiceManager,void,char_*,char_*,char_*,int>::vfunc_0 (30 B): matches/0x001f5b20.cpp [isolated: lost its match in the tree (a call became inline code (callee now defined in the same TU)); on include/gen/ and not mergeable]
// sym: ??_G?$Closure4@VCSoundVoiceManager@@XPADPADPADH@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
#include "gen/global.h"

// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure4<CSoundVoiceManager, void, char *, char *, char *, int>::~Closure4() {}

