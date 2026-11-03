#include "decls/data/game/global.h"
#include "gen/owners.h"

extern "C" void __cdecl FUN_00363fc0();
extern "C" int __cdecl atexit(void (*)());

struct Reg {
};


void Target() {
    ((owners::String_23fc40 *)&((*(Reg*)&DAT_004e1818)))->FUN_0023fc40("sound/rsd", (hulk_intptr)0);
    atexit(FUN_00363fc0);
}
