// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002f90c0..0x002fa6b0 (kind game, layer engine, confidence low)
// (tree_prelude.h: not needed)


// 0x002fa080 FUN_002fa080 (94 B): equivalent/0x002fa080.cpp [isolated: conflict: FUN_002f9ff0; on include/gen/ and not mergeable]
// sym: ?FUN_002fa080@Buffer_2fa080@owners@@QAE_NIPAX@Z @b65edb39ee1a @wfad4de36d3c8
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_002fa080 @ 0x002fa080
#include "gen/owners.h"
extern "C" void* __cdecl FUN_0008d6d0(unsigned int); extern "C" void __cdecl FUN_002f9ff0(void*, unsigned int, void*);  bool owners::Buffer_2fa080::FUN_002fa080(unsigned int count, void* value) { if (start) return false; if (count) { start = (char*)FUN_0008d6d0(count * 80); if (start) { end = start + count * 80; FUN_002f9ff0(start, count, value); return true; } } start = 0; end = 0; return false; }

