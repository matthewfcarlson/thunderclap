#include "decls/data/engine/unknown.h"
// data: gData_271070 = DAT_00528418, gFinal = DAT_0052a0f0, gFlag_271070 = DAT_004cdc04

extern "C" bool __cdecl FUN_00270f90(const char *);
extern "C" void __cdecl FUN_00273510();
extern "C" void __cdecl FUN_00276340();
extern "C" void __cdecl FUN_00277050();
extern "C" void __cdecl FUN_00274af0();
extern "C" void __cdecl FUN_0026d830(void*);
void __cdecl FUN_00271070() {
    if (DAT_004cdc04) {
        char* p = ((char*)&DAT_00528418);
        int n = 0x1a;
        do {
            if (*(int*)(p + 0x14) != 0)
                FUN_00270f90((const char *)(void *)p);
            p += 0x11c;
            --n;
        } while (n != 0);
    }
    FUN_00273510();
    FUN_00276340();
    FUN_00277050();
    FUN_00274af0();
    FUN_0026d830(((char*)((char*)&DAT_0052842c + 7364)));
    ((char*)((char*)&DAT_0052842c + 7364))[0x2d] = 0;
}