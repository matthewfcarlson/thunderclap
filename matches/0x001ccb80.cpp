#include "gen/owners.h"
void owners::C_1ccb80::FUN_001ccb80() {
    char* p = (char*)this + 0x214;
    int i = 0x10;
    do {
        *(int*)(p - 0x104) = (int)0xbf800000;
        *(char*)(p - 0x100) = 0;
        *(int*)p = -1;
        p += 0x108;
        --i;
    } while (i != 0);
    *(int*)((char*)this + 0x1190) = 0;
}