// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0012dfe0..0x00132e00 (kind game, layer game, confidence high), dominant class hulkfight::GameStateCondition
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x0012ef40 FUN_0012ef40 (82 B): equivalent/0x0012ef40.cpp [isolated: conflict: FUN_0008d340; on include/gen/ and not mergeable]
// sym: ?FUN_0012ef40@Object_12ef40@owners@@QAE_NPBD@Z @14db058cddd4 @w815d9010e969 @vf17d10af75e1
// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_0012ef40 @ 0x0012ef40
#include "gen/owners.h"
void __cdecl operator delete[](void* p);   // (x64t21, D115) the game's 0x0008d340
extern "C" void* __cdecl FUN_0008d6d0(unsigned int);  bool owners::Object_12ef40::FUN_0012ef40(const char* text) { ::operator delete[](value); if (!text) { value = 0; return true; } unsigned int length = 0; while (text[length]) ++length; char* allocated = (char*)FUN_0008d6d0(length + 1); value = allocated; char* destination = allocated; do { *destination++ = *text; } while (*text++); return true; }

