#include "decls/data/game/global.h"
// data: gClass = DAT_004e2430, gClassNext = DAT_004e2434

extern unsigned __int64 Find(const char*);
void FUN_0035ea90() {
    unsigned __int64 r = Find("mass_class");
    (*(unsigned int*)&DAT_004e2430) = (unsigned int)r;
    (*(unsigned int*)((char*)&DAT_004e2430 + 4)) = (unsigned int)((r >> 32));
}
