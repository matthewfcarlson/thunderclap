#include "gen/owners.h"
#include "decls/data/game/Render.h"
// data: gSound = DAT_004e23b8

class Sound {
  public:
    Sound(const char*, int);
};
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl FUN_00364050();
void init() {
    ((owners::String_23fc40 *)&DAT_004e23b8)->FUN_0023fc40("sound/rsd", (hulk_intptr)0);
    atexit(FUN_00364050);
}