#include "decls/data/game/unknown.h"
#include "gen/owners.h"

class Obj {
  public:
};
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl FUN_003640d0();
void __cdecl target() {
    ((owners::String_23fc40 *)&((*(Obj*)((char*)&DAT_004e3748 + 4))))->FUN_0023fc40("sound/rsd", (hulk_intptr)0);
    atexit(FUN_003640d0);
}