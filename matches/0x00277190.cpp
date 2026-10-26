#include "decls/data/platform/xbox/core.h"
// data: gDrive = DAT_0042b50c

extern "C" void FUN_00277190(char* p) {
    unsigned short v = *(volatile unsigned short*)((volatile char*)&DAT_0042b50c);
    *(unsigned short*)p = v;
    p[2] = ((volatile char*)&DAT_0042b50c)[2];
}