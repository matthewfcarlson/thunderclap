#include "decls/data/game/global.h"
// data: g_sub = DAT_004e36bc

class Sub {
  public:
    void Init(const char* path, int flag);
};
void __cdecl Reg(void* f);
void __cdecl Cleanup();
void __cdecl InitSub() {
    (*(Sub*)&DAT_004e36bc).Init("sound/rsd", 0);
    Reg(Cleanup);
}
