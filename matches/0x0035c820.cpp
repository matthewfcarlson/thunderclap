#include "decls/data/game/unknown.h"
// data: gHash_35c820 = DAT_004dc050

extern "C" unsigned long long Hash(const char*);
void FUN_0035c820() {
    unsigned long long h = Hash("harrier");
    ((unsigned int*)&DAT_004dc050)[0] = (unsigned int)h;
    ((unsigned int*)&DAT_004dc050)[1] = (unsigned int)(h >> 32);
}
