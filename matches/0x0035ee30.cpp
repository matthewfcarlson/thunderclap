#include "gen/owners.h"
#include "decls/data/game/global.h"
// data: g_resource = DAT_004e58b8

class Resource {
  public:
    Resource(const char*, int);
};
extern "C" void __cdecl FUN_003640e0();
extern "C" int __cdecl atexit(void(__cdecl*)());
void __cdecl initResource() {
    ((owners::String_23fc40 *)&DAT_004e58b8)->FUN_0023fc40("sound/rsd", (hulk_intptr)0);
    atexit(FUN_003640e0);
}