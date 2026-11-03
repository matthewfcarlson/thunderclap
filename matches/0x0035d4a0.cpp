#include "gen/owners.h"
class Sound {
  public:
};
extern Sound gSound;
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl Shutdown();
void __cdecl FUN_0035d4a0() {
    ((owners::String_23fc40 *)&gSound)->FUN_0023fc40("sound/rsd", (hulk_intptr)0);
    atexit(Shutdown);
}