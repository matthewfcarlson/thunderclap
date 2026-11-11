// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001b3020..0x001b6800 (kind game, layer game, confidence high), dominant class CCollisionManager
// (tree_prelude.h: not needed)


// 0x001b3620 FUN_001b3620 (80 B): equivalent/0x001b3620.cpp [isolated: code differs from its standalone build; on include/gen/ and not mergeable]
// sym: ?FUN_001b3620@SampleTable_1b3620@owners@@QAEMM@Z
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 6/6)
// FUN_001b3620 @ 0x001b3620
// FUN_001b3620 @ 0x001b3620
#include "decls/data/game/global.h"
#include "gen/owners.h"

struct ThisCall_001b3250 {
};


float owners::SampleTable_1b3620::FUN_001b3620(float value) {
    int index = row;
    if (index < 0)
        return (*(float*)&DAT_003f32e0);
    if (value < (*(float*)&DAT_0041d97c))
        value = 0.02f;
    if (value >= limit)
        return (*(float*)&DAT_003f32e0);
    int column = ((owners::Object_1b3250 *)(((ThisCall_001b3250*)(this))))->FUN_001b3250(value);
    return ((float*)((char*)&DAT_004e1830 + 160))[column + index * 45];
}

