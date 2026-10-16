#include "decls/data/game/global.h"

extern "C" char DAT_00400870[];
extern "C" void* __cdecl FUN_0008d690(unsigned int);
void FUN_0008e090() {
    if (DAT_004dd7e0 == 0) {
        char* p = (char*)FUN_0008d690(0xc);
        if (p != 0) {
            p[5] = 0;
            p[6] = 0;
            p[7] = 0;
            p[4] = 0;
            p[8] = 0;
            p[9] = 0;
            *(unsigned int*)p = ((int)DAT_00400870);
        } else {
            p = 0;
        }
        DAT_004dd7e0 = (unsigned int)p;
    }
}
