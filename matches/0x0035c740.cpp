#include "decls/data/game/unknown.h"

extern "C" unsigned long long __cdecl Hash(const char*) throw();
void FUN_0035c740() {
    unsigned long long h = Hash("hulk");
    (*(unsigned long*)&DAT_004dc0e0) = (unsigned long)h;
    (*(unsigned long*)((char*)&DAT_004dc0e0 + 4)) = (unsigned long)(h >> 32);
}
