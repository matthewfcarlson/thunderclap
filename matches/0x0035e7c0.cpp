#include "decls/data/game/global.h"
// data: gRegistry = DAT_004e22fc

class Registry {
  public:
    void Init(const char*, int);
};
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl FUN_00364040();
void __cdecl target() {
    (*(Registry*)&DAT_004e22fc).Init("sound/rsd", 0);
    atexit(FUN_00364040);
}