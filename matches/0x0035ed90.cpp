#include "decls/data/game/global.h"
// data: g_sub = DAT_004e36bc
#include "gen/owners.h"

class Sub {
  public:
};
void __cdecl Reg(void* f);
extern "C" void __cdecl FUN_003640a0();
void __cdecl InitSub() {
    ((owners::String_23fc40 *)&((*(Sub*)&DAT_004e36bc)))->FUN_0023fc40("sound/rsd", (hulk_intptr)0);
    Reg(FUN_003640a0);
}
