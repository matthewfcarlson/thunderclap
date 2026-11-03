#include "gen/owners.h"
typedef unsigned int U_26e470;
extern "C" char* __cdecl strncpy(char*, const char*, U_26e470);
void owners::C_26e470::FUN_0026e470(hulk_uintptr a, char* s) {
    char b[0x108];
    *(U_26e470*)b = 1;
    *(U_26e470*)(b + 4) = ((U_26e470)a);
    strncpy(b + 8, s, 0x100);
    b[0x107] = 0;
    helper(b, 0x108);
}
