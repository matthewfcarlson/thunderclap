// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0012dfe0..0x00132e00 (kind game, layer game, confidence high), dominant class hulkfight::GameStateCondition
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x0012ec80 FUN_0012ec80 (82 B): equivalent/0x0012ec80.cpp [isolated: conflict: FUN_0008d340; on include/gen/ and not mergeable]
// sym: ?FUN_0012ec80@Item_12ec80@owners@@QAE_NPBD@Z @d106ec912a91 @w7cb51f969019 @vb1c4409544aa
// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_0012ec80 @ 0x0012ec80
#include "gen/owners.h"
void __cdecl operator delete[](void* p);   // (x64t21, D115) the game's 0x0008d340

void * __cdecl FUN_0008d6d0(unsigned int);
bool owners::Item_12ec80::FUN_0012ec80(const char *source) {
    ::operator delete[](text);
    if (!source) {
        text = 0;
        return true;
    }
    const char *end = source;
    do { ++end; } while (end[-1]);
    char *dest = (char *)FUN_0008d6d0((unsigned int)(end - source));
    text = dest;
    char *allocated = dest;
    do { *dest++ = *source++; } while (source[-1]);
    return true;
}

