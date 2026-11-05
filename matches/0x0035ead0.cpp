#include "decls/data/game/global.h"
// data: g_reg = DAT_004e2538
#include "gen/owners.h"

extern "C" int __cdecl atexit(void (*)(void));
class Reg {
  public:
};
void FUN_00364060() {}
void RegF() {
    ((owners::String_23fc40 *)&((*(Reg*)((char*)&DAT_004e2530 + 8))))->FUN_0023fc40("sound/rsd", (hulk_intptr)0);
    atexit(FUN_00364060);
}
