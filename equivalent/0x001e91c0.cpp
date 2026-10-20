// STATUS: equivalent (tools/equiv.py level 3: 118 inputs, branch coverage 2/2)
// FUN_001e91c0 @ 0x001e91c0
#include "decls/data/game/global.h"

struct LevelKeys {
    unsigned __int64 keys[28];
};

void *FUN_0008d6d0(unsigned int size);
unsigned __int64 FUN_002672f0(const char *s, unsigned __int64 seed);

void FUN_001e91c0(void)
{
    LevelKeys *k = (LevelKeys *)FUN_0008d6d0(sizeof(LevelKeys));
    if (k != 0) {
        unsigned int *w = (unsigned int *)k;
        w[0] = 0;
        w[1] = 0;
        for (int i = 0; i < 0x36; i++) {
            w[i + 2] = w[i];
        }
    }
    (*(LevelKeys**)&DAT_004e2788) = k;
    (*(LevelKeys**)&DAT_004e2788)->keys[0] = FUN_002672f0("ghk", 0);
    (*(LevelKeys**)&DAT_004e2788)->keys[1] = FUN_002672f0("ghk_sidemissions", 0);
    (*(LevelKeys**)&DAT_004e2788)->keys[2] = FUN_002672f0("ghk_c0m1", 0);
    (*(LevelKeys**)&DAT_004e2788)->keys[3] = FUN_002672f0("ghk_c0m2", 0);
    (*(LevelKeys**)&DAT_004e2788)->keys[4] = FUN_002672f0("ghk_c1m1", 0);
    (*(LevelKeys**)&DAT_004e2788)->keys[5] = FUN_002672f0("ghk_c1m2", 0);
    (*(LevelKeys**)&DAT_004e2788)->keys[6] = FUN_002672f0("ghk_c1m3", 0);
    (*(LevelKeys**)&DAT_004e2788)->keys[7] = FUN_002672f0("ghk_c1m4", 0);
    (*(LevelKeys**)&DAT_004e2788)->keys[8] = FUN_002672f0("ghk_c1m5", 0);
    (*(LevelKeys**)&DAT_004e2788)->keys[9] = FUN_002672f0("ghk_c2m1", 0);
    (*(LevelKeys**)&DAT_004e2788)->keys[10] = FUN_002672f0("ghk_c2m2", 0);
    (*(LevelKeys**)&DAT_004e2788)->keys[11] = FUN_002672f0("ghk_c2m3", 0);
    (*(LevelKeys**)&DAT_004e2788)->keys[12] = FUN_002672f0("ghk_c2m4", 0);
    (*(LevelKeys**)&DAT_004e2788)->keys[13] = FUN_002672f0("ghk_c3m2", 0);
    (*(LevelKeys**)&DAT_004e2788)->keys[14] = FUN_002672f0("ghk_c3m3", 0);
    (*(LevelKeys**)&DAT_004e2788)->keys[15] = FUN_002672f0("ghk_c3m4", 0);
    (*(LevelKeys**)&DAT_004e2788)->keys[16] = FUN_002672f0("ghk_c4m1", 0);
    (*(LevelKeys**)&DAT_004e2788)->keys[17] = FUN_002672f0("ghk_c4m3", 0);
    (*(LevelKeys**)&DAT_004e2788)->keys[18] = FUN_002672f0("ghk_c4m4", 0);
    (*(LevelKeys**)&DAT_004e2788)->keys[19] = FUN_002672f0("ghk_c4m5", 0);
    (*(LevelKeys**)&DAT_004e2788)->keys[20] = FUN_002672f0("ghk_c5m1", 0);
    (*(LevelKeys**)&DAT_004e2788)->keys[21] = FUN_002672f0("ghk_c5m4", 0);
    (*(LevelKeys**)&DAT_004e2788)->keys[22] = FUN_002672f0("ghk_c6m1", 0);
    (*(LevelKeys**)&DAT_004e2788)->keys[23] = FUN_002672f0("ghk_c6m2", 0);
    (*(LevelKeys**)&DAT_004e2788)->keys[24] = FUN_002672f0("ghk_c6m3", 0);
    (*(LevelKeys**)&DAT_004e2788)->keys[25] = FUN_002672f0("ghk_c7m2", 0);
    (*(LevelKeys**)&DAT_004e2788)->keys[26] = FUN_002672f0("ghk_c7m3", 0);
    (*(LevelKeys**)&DAT_004e2788)->keys[27] = FUN_002672f0("ghk_c10m30", 0);
}
