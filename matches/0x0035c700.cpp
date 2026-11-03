#include "decls/data/game/global.h"
#include "gen/owners.h"

struct Reg {
};
void FnSound();
extern "C" void __cdecl FUN_00363af0();
extern "C" int __cdecl _atexit(void(__cdecl* f)());
void __cdecl FUN_0035c700() {
    ((owners::String_23fc40 *)&((*(Reg*)&DAT_004dc020)))->FUN_0023fc40("sound/rsd", (hulk_intptr)0);
    _atexit(FUN_00363af0);
}
