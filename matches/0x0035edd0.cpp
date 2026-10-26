#include "decls/data/game/global.h"
// data: gSound = DAT_004e36f0

extern "C" void __cdecl FUN_003640c0();
extern "C" int __cdecl _atexit(void (*func)(void));
struct Sound {
    void Init(const char* path, int flag);
};
void __cdecl FUN_0035edd0() {
    (*(Sound*)&DAT_004e36f0).Init("sound/rsd", 0);
    _atexit(FUN_003640c0);
}
