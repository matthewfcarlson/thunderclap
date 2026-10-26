#include "decls/data/game/global.h"
// data: gEntries = DAT_004e18b0

struct Entry {
    int a[4];
    int b[4];
    int c[37];
};
void __cdecl FUN_001b33d0(int row, int col, int a, int b, int c) {
    if (row >= 0 && row < 13 && col >= 0 && col < 4) {
        ((Entry*)((char*)&DAT_004e1830 + 128))[row].a[col] = a;
        ((Entry*)((char*)&DAT_004e1830 + 128))[row].b[col] = b;
        ((Entry*)((char*)&DAT_004e1830 + 128))[row].c[col] = c;
    }
}