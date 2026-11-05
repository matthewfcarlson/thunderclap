#include "decls/data/game/global.h"
// data: g_sub = DAT_004e36bc
#include "gen/owners.h"

class Sub {
  public:
};
extern "C" int __cdecl atexit(void(__cdecl*)());
void FUN_003640a0();
void __cdecl InitSub() {
    ((owners::String_23fc40 *)&((*(Sub*)&DAT_004e36bc)))->FUN_0023fc40("sound/rsd", (hulk_intptr)0);
    atexit(FUN_003640a0);
}
