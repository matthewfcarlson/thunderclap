#include "decls/data/game/unknown.h"

class Obj {
  public:
    void Init(const char*, int);
};
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl FUN_003640d0();
void __cdecl target() {
    (*(Obj*)((char*)&DAT_004e3748 + 4)).Init("sound/rsd", 0);
    atexit(FUN_003640d0);
}