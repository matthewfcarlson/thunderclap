#include "decls/data/game/global.h"
// data: gSound = DAT_004e2270

class Sound {
  public:
    Sound(const char*, int);
    ~Sound();
};
extern "C" int __cdecl atexit(void(__cdecl*)());
extern void __cdecl cleanup();
void __cdecl FUN_0035e700() {
    (*(Sound*)((char*)&DAT_004e226c + 4)).Sound::Sound("sound/rsd", 0);
    atexit(cleanup);
}