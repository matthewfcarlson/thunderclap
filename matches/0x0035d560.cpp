#include "decls/data/game/global.h"

extern "C" unsigned __int64 __cdecl hash(const char*);
void init() {
    (*(unsigned __int64*)&DAT_004dde90) = hash("golfBall_golfBall");
}