#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
// data: buffer = DAT_004e5950, counter = DAT_004e5a54

extern "C" int __cdecl snprintf(char*, unsigned int, const char*, ...);
char* FUN_00203740() {
    int n = (*(int*)&DAT_004e5a54)++;
    snprintf(((char*)((char*)&DAT_004e5948 + 8)), 256, "unique%d", n);
    return ((char*)((char*)&DAT_004e5948 + 8));
}