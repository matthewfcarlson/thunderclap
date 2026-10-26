#include "decls/data/game/global.h"
// data: input = DAT_00400488, result = DAT_004e2290

extern "C" __int64 parse(const char*);
void FUN_0035e720() {
    (*(__int64*)&DAT_004e2290) = parse(((char*)&DAT_00400488));
}
