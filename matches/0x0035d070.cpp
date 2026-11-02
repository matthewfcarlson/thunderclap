#include "decls/data/game/global.h"
// data: gSound = DAT_004dd768

class Sound {
  public:
    Sound(const char*, int);
    ~Sound();
};
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl FUN_00363cb0();
void initSound() {
    (*(Sound*)&DAT_004dd768).Sound::Sound("sound/rsd", 0);
    atexit(FUN_00363cb0);
}
