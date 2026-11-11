// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0010c0d0..0x0010d080 (kind game, layer game, confidence low)
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x0010c9b0 FUN_0010c9b0 (82 B): equivalent/0x0010c9b0.cpp [isolated: conflict: FUN_0008d340; on include/gen/ and not mergeable]
// sym: ?FUN_0010c9b0@Obj_10c9b0@owners@@QAEIPBD@Z
// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_0010c9b0 @ 0x0010c9b0
#include "gen/owners.h"
extern "C" unsigned int __cdecl FUN_0008d340(void*); extern "C" void* __cdecl FUN_0008d6d0(unsigned int);  unsigned int owners::Obj_10c9b0::FUN_0010c9b0(const char* value) { unsigned int oldResult = FUN_0008d340(text); if (!value) { text = 0; return (oldResult & ~255u) | 1u; } unsigned int length = 0; while (value[length]) ++length; char* allocated = (char*)FUN_0008d6d0(length + 1); text = allocated; char* dst = allocated; do { *dst++ = *value; } while (*value++); return ((hulk_uintptr)allocated & ~255u) | 1u; }

