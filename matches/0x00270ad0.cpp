#include "decls/data/engine/unknown.h"

extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);
extern "C" char __cdecl FUN_00345b90(int);
extern "C" char __cdecl FUN_002771b0(char*);
extern "C" void __cdecl FUN_0026d850(void*);
extern "C" void __cdecl FUN_0026d840(void*);
extern "C" char __cdecl FUN_00270ad0(char* param) {
    char local[17];
    strncpy(local, param, 16);
    local[16] = 0;
    char* p = local;
    char c = *p;
    while (c) {
        *p = FUN_00345b90((int)*p);
        ++p;
        c = *p;
    }
    if (FUN_002771b0(local)) {
        FUN_0026d850(((char*)((char*)&DAT_0052842c + 7364)));
        strncpy(DAT_0052a10c, local, 16);
        (*(char*)&DAT_0052a11c) = 0;
        FUN_0026d840(((char*)((char*)&DAT_0052842c + 7364)));
        return 1;
    }
    return 0;
}