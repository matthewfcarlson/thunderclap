#include "gen/owners.h"
class Sound {
  public:
};
extern Sound gSound;
extern "C" void __cdecl FUN_00363c90();
extern "C" int __cdecl atexit(void(__cdecl*)());
void __cdecl FUN_0035cfb0() {
    ((owners::String_23fc40 *)&gSound)->FUN_0023fc40("sound/rsd", (hulk_intptr)0);
    atexit(FUN_00363c90);
}