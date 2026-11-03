#include "decls/data/game/global.h"
// data: gRegistry = DAT_004e22fc
#include "gen/owners.h"

class Registry {
  public:
};
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl FUN_00364040();
void __cdecl target() {
    ((owners::String_23fc40 *)&((*(Registry*)&DAT_004e22fc)))->FUN_0023fc40("sound/rsd", (hulk_intptr)0);
    atexit(FUN_00364040);
}