#include "decls/data/game/global.h"
// data: g_sub = DAT_004e36bc

class Sub {
  public:
    void Init(const char* path, int flag);
};
void __cdecl Reg(void* f);
extern "C" void __cdecl FUN_003640a0();
void __cdecl InitSub() {
    (*(Sub*)&DAT_004e36bc).Init("sound/rsd", 0);
    Reg(FUN_003640a0);
}
