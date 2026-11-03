#include "decls/data/game/global.h"
// data: gSound = DAT_004e5a5c
#include "gen/owners.h"

class Sound {
  public:
};
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl FUN_00364120();
void __cdecl target() {
    ((owners::String_23fc40 *)&((*(Sound*)((char*)&DAT_004e5a58 + 4))))->FUN_0023fc40("sound/rsd", (hulk_intptr)0);
    atexit(FUN_00364120);
}