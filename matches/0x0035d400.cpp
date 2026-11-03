#include "decls/data/game/global.h"
#include "gen/owners.h"

extern "C" void __cdecl FUN_00363df0();
extern "C" int __cdecl _atexit(void(__cdecl*)(void));
struct Reg {
};
void __cdecl FUN_0035d400() {
    ((owners::String_23fc40 *)&((*(Reg*)&DAT_004ddbe4)))->FUN_0023fc40("sound/rsd", (hulk_intptr)0);
    _atexit(FUN_00363df0);
}
