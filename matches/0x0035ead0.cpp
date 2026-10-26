#include "decls/data/game/global.h"
// data: g_reg = DAT_004e2538

extern "C" int __cdecl atexit(void (*)(void));
class Reg {
  public:
    void Register(const char* name, int a);
};
void F2() {}
void RegF() {
    (*(Reg*)((char*)&DAT_004e2530 + 8)).Register("sound/rsd", 0);
    atexit(F2);
}
