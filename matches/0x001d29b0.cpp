// FUN_001d29b0 @ 0x001d29b0
#include "decls/data/game/global.h"
#include "gen/owners.h"

extern "C" {
void FUN_002133d0(int h, const char* v);
void FUN_00213600(int h, int v);
void FUN_00213640(int h, int idx, int v);
int FUN_00213290(int h, int idx);
void FUN_00212d80(int h, int v);
int FUN_00215d10(int a, int b);
void FUN_00213320(int h);
void FUN_00213870(int h, int idx, int v);
}


char owners::Runner_1d29b0::FUN_001d29b0(hulk_intptr arg, char *failed)
{
    if (((int)arg) == 0) {
        *failed = 1;
        return 0;
    }
    FUN_002133d0(handle, DAT_004c5cf8);
    FUN_00213600(handle, -10000);
    FUN_00213640(handle, -1, ((int)arg));
    int r = FUN_00213290(handle, -1);
    if (r == 0) {
        FUN_00212d80(handle, -3);
        *failed = 1;
        return 0;
    }
    if (FUN_001d17f0(handle) != 2) {
        FUN_00212d80(handle, -3);
        *failed = 1;
        return 0;
    }
    FUN_00212d80(handle, -3);
    if (FUN_00215d10(r, 0) != 0) {
        *failed = 1;
        FUN_00212d80(handle, 0);
        return 0;
    }
    FUN_002133d0(handle, DAT_004c5cf8);
    FUN_00213600(handle, -10000);
    FUN_00213640(handle, -1, ((int)arg));
    if (FUN_001d17f0(handle) == 3) {
        FUN_002133d0(handle, DAT_004c5cf8);
        FUN_00213600(handle, -10000);
        FUN_00213320(handle);
        FUN_00213870(handle, -2, ((int)arg));
        FUN_00212d80(handle, -4);
        return 0;
    }
    FUN_00212d80(handle, -3);
    return 1;
}
