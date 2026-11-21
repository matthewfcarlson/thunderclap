// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0010c0d0..0x0010d080 (kind game, layer game, confidence low)
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x0010c9b0 FUN_0010c9b0 (82 B): equivalent/0x0010c9b0.cpp [isolated: conflict: FUN_0008d340; on include/gen/ and not mergeable]
// sym: ?FUN_0010c9b0@Obj_10c9b0@owners@@QAE_NPBD@Z @14db058cddd4 @w815d9010e969 @v3809cd2f35c8
// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_0010c9b0 @ 0x0010c9b0
#include "gen/owners.h"
void __cdecl operator delete[](void* p);   // (x64t21, D115) the game's 0x0008d340
extern "C" void* __cdecl FUN_0008d6d0(unsigned int);  bool owners::Obj_10c9b0::FUN_0010c9b0(const char* value) { ::operator delete[](text); if (!value) { text = 0; return true; } unsigned int length = 0; while (value[length]) ++length; char* allocated = (char*)FUN_0008d6d0(length + 1); text = allocated; char* dst = allocated; do { *dst++ = *value; } while (*value++); return true; }

