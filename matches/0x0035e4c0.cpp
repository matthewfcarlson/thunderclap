#include "decls/data/game/hulkfight/motion.h"
// data: sound = DAT_004e14f8

class Sound {
  public:
    Sound(const char*, int);
    ~Sound();
};
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl FUN_00363f80();
void init() {
    (*(Sound*)&DAT_004e14f8).Sound::Sound("sound/rsd", 0);
    atexit(FUN_00363f80);
}