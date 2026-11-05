#include "decls/data/game/global.h"

extern unsigned __int64 FUN_0027b020(const char* name);
void FUN_0035e620() {
    unsigned __int64 id = FUN_0027b020("ATGWorldCollision");
    DAT_004e2198 = (unsigned int)id;
    (*(unsigned int*)&DAT_004e219c) = (unsigned int)(id >> 32);
}
