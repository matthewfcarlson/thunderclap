#include "decls/data/game/unknown.h"

class Obj {
  public:
    void Init(const char*, int);
};
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl Cleanup();
void __cdecl target() {
    (*(Obj*)((char*)&DAT_004e3748 + 4)).Init("sound/rsd", 0);
    atexit(Cleanup);
}