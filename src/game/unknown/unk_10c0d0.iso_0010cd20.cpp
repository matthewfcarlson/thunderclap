// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0010c0d0..0x0010d080 (kind game, layer game, confidence low)
// (tree_prelude.h: not needed)


// 0x0010cd20 FUN_0010cd20 (82 B): equivalent/0x0010cd20.cpp [isolated: conflict: FUN_0008d340; on include/gen/ and not mergeable]
// sym: ?FUN_0010cd20@Obj_10cd20@owners@@QAE_NPBD@Z
// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_0010cd20 @ 0x0010cd20
#include "gen/owners.h"
extern "C" void __cdecl FUN_0008d340(void*); extern "C" void* __cdecl FUN_0008d6d0(unsigned int);  bool owners::Obj_10cd20::FUN_0010cd20(const char* value) { FUN_0008d340(text); if (!value) { text = 0; return true; } unsigned int len = 0; while (value[len]) ++len; text = (char*)FUN_0008d6d0(len + 1); char* dst = text; do { *dst++ = *value; } while (*value++); return true; }

