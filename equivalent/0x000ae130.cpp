// STATUS: equivalent (tools/equiv.py level 3: 54 inputs, branch coverage 22/22)
// FUN_000ae130 @ 0x000ae130
#include "decls/data/game/global.h"

struct Block_ae130 {
    float v[17];
};

struct Item_ae130 {
    char pad0[0xd];
    char flag;
    void FUN_000b3510(Block_ae130 *a, Block_ae130 *b);
};

void __cdecl FUN_000addd0(Block_ae130 *dst, Block_ae130 *src);
void __cdecl FUN_000adf20(Block_ae130 *dst, Block_ae130 *src);


class Accumulator_ae130 {
public:
    char pad0[0x10];
    int count;
    Item_ae130 **items;
    Block_ae130 blockA;
    Block_ae130 blockB;
    int words[3];
    Block_ae130 blockC;
    Block_ae130 blockD;
    void FUN_000ae130();
};

void Accumulator_ae130::FUN_000ae130()
{
    int k;
    for (k = 0; k < 17; k++)
        blockA.v[k] = 0;
    for (k = 0; k < 17; k++)
        blockB.v[k] = 0;
    for (k = 0; k < 17; k++)
        blockC.v[k] = 0;
    for (k = 0; k < 17; k++)
        blockD.v[k] = 0;

    for (int i = 0; i < count; i++) {
        if (items[i] != 0) {
            Block_ae130 first;
            Block_ae130 second;
            for (k = 0; k < 17; k++)
                first.v[k] = 0;
            for (k = 0; k < 17; k++)
                second.v[k] = 0;
            items[i]->FUN_000b3510(&first, &second);
            if (items[i]->flag) {
                FUN_000addd0(&blockC, &first);
                FUN_000adf20(&blockD, &second);
            } else {
                FUN_000addd0(&blockA, &first);
                FUN_000adf20(&blockB, &second);
            }
        }
    }

    if (DAT_004e222c) {
        if (blockA.v[0] < 0.2f && blockA.v[1] < 0.2f && blockA.v[4] < 0.2f && blockA.v[6] < 0.2f)
            DAT_004e222c = 0;
        for (k = 0; k < 11; k++) {
            blockA.v[k] = 0;
            blockC.v[k] = 0;
        }
        for (k = 0; k < 13; k++) {
            blockB.v[k] = 0;
            blockC.v[k] = 0;
        }
        words[0] = 0;
        words[1] = 0;
        words[2] = 0;
    }
}
