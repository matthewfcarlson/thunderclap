#include "decls/data/game/unknown.h"
// data: gHash_35c820 = DAT_004dc050

unsigned __int64 FUN_0027b020(const char* s);
void FUN_0035c820() {
    unsigned long long h = FUN_0027b020("harrier");
    ((unsigned int*)&DAT_004dc050)[0] = (unsigned int)h;
    ((unsigned int*)&DAT_004dc050)[1] = (unsigned int)(h >> 32);
}
