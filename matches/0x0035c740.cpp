#include "decls/data/game/unknown.h"

extern "C" __int64 __cdecl FUN_0027b020(const char*);
void FUN_0035c740() {
    unsigned long long h = FUN_0027b020("hulk");
    (*(unsigned long*)&DAT_004dc0e0) = (unsigned long)h;
    (*(unsigned long*)((char*)&DAT_004dc0e0 + 4)) = (unsigned long)(h >> 32);
}
