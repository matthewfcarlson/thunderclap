#include "decls/data/engine/unknown.h"
// data: gCount = DAT_004dbf6c, gReady = DAT_0056f020, gValues = DAT_0056f000

void FUN_0035a660() {
    DAT_004dbf6c = 0x45;
    for (int i = 0; i < 8; ++i)
        ((int*)&DAT_0056f000)[i] = 0;
    (*(unsigned char*)&DAT_0056f020) = 1;
}