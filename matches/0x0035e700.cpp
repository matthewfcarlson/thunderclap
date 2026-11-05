#include "gen/owners.h"
#include "decls/data/game/global.h"
// data: gSound = DAT_004e2270

class Sound {
  public:
    Sound(const char*, int);
    ~Sound();
};
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl FUN_00364030();
void __cdecl FUN_0035e700() {
    ((owners::String_23fc40 *)((char*)&DAT_004e226c + 4))->FUN_0023fc40("sound/rsd", (hulk_intptr)0);
    atexit(FUN_00364030);
}