#include "decls/data/game/global.h"
#include "gen/owners.h"

extern "C" void __cdecl FUN_00364070();
extern "C" void _atexit(void (*)());
void __cdecl FUN_0023fc40(const char*, int);
struct G {
};
void __cdecl FUN_0035ed10() {
    ((owners::String_23fc40 *)&((*(G*)((char*)&DAT_004e2644 + 4))))->FUN_0023fc40("sound/rsd", (hulk_intptr)0);
    _atexit(FUN_00364070);
}
