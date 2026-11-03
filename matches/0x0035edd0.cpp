#include "decls/data/game/global.h"
// data: gSound = DAT_004e36f0
#include "gen/owners.h"

extern "C" void __cdecl FUN_003640c0();
extern "C" int __cdecl _atexit(void (*func)(void));
struct Sound {
};
void __cdecl FUN_0035edd0() {
    ((owners::String_23fc40 *)&((*(Sound*)&DAT_004e36f0)))->FUN_0023fc40("sound/rsd", (hulk_intptr)0);
    _atexit(FUN_003640c0);
}
