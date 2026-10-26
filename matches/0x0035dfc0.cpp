#include "decls/data/game/global.h"
// data: gHi_35dfc0 = DAT_004e09d0

typedef unsigned int uint;
extern unsigned long long hash(const char*);
void FUN_0035dfc0() {
    unsigned long long r = hash("$MACRO_INSERT");
    (*(uint*)&DAT_004e09d0) = (uint)r;
    (*(uint*)&DAT_004e09d4) = (uint)(r >> 32);
}
