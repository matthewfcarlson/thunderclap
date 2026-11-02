#include "decls/data/game/global.h"
// data: gSound = DAT_004e5a5c

class Sound {
  public:
    void Init(const char*, int);
};
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl FUN_00364120();
void __cdecl target() {
    (*(Sound*)((char*)&DAT_004e5a58 + 4)).Init("sound/rsd", 0);
    atexit(FUN_00364120);
}