// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0012dfe0..0x00132e00 (kind game, layer game, confidence high), dominant class hulkfight::GameStateCondition
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x0012ef40 FUN_0012ef40 (82 B): equivalent/0x0012ef40.cpp [isolated: conflict: FUN_0008d340; on include/gen/ and not mergeable]
// sym: ?FUN_0012ef40@Object_12ef40@owners@@QAEIPBD@Z
// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_0012ef40 @ 0x0012ef40
#include "gen/owners.h"
extern "C" unsigned int __cdecl FUN_0008d340(void*); extern "C" void* __cdecl FUN_0008d6d0(unsigned int);  unsigned int owners::Object_12ef40::FUN_0012ef40(const char* text) { unsigned int result = FUN_0008d340(value); if (!text) { value = 0; return (result & ~255u) | 1; } unsigned int length = 0; while (text[length]) ++length; char* allocated = (char*)FUN_0008d6d0(length + 1); value = allocated; char* destination = allocated; do { *destination++ = *text; } while (*text++); return ((hulk_uintptr)allocated & ~255u) | 1; }

