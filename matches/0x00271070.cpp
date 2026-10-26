#include "decls/data/engine/unknown.h"
// data: gData_271070 = DAT_00528418, gFinal = DAT_0052a0f0, gFlag_271070 = DAT_004cdc04

void __cdecl CleanupOne(void*);
void __cdecl StepA();
void __cdecl StepB();
void __cdecl StepC();
void __cdecl StepD();
void __cdecl Finish(void*);
void __cdecl FUN_00271070() {
    if (DAT_004cdc04) {
        char* p = ((char*)&DAT_00528418);
        int n = 0x1a;
        do {
            if (*(int*)(p + 0x14) != 0)
                CleanupOne(p);
            p += 0x11c;
            --n;
        } while (n != 0);
    }
    StepA();
    StepB();
    StepC();
    StepD();
    Finish(((char*)((char*)&DAT_0052842c + 7364)));
    ((char*)((char*)&DAT_0052842c + 7364))[0x2d] = 0;
}