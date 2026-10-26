#include "decls/data/game/Render.h"
// data: gSound = DAT_004e23b8

class Sound {
  public:
    Sound(const char*, int);
};
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl cleanup();
void init() {
    (*(Sound*)&DAT_004e23b8).Sound::Sound("sound/rsd", 0);
    atexit(cleanup);
}