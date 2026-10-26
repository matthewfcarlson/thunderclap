#include "decls/data/game/global.h"

extern unsigned __int64 GetId(const char* name);
void FUN_0035e620() {
    unsigned __int64 id = GetId("ATGWorldCollision");
    DAT_004e2198 = (unsigned int)id;
    (*(unsigned int*)&DAT_004e219c) = (unsigned int)(id >> 32);
}
