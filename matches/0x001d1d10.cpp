#include "decls/data/lua.h"
extern "C" void __cdecl FUN_00212d80(LuaVMState* L, int idx);
class Target_1d1d10 {
    char pad[8];
    LuaVMState* L;  // 0x08

  public:
    unsigned char FUN_001d1d10();
};
unsigned char Target_1d1d10::FUN_001d1d10() {
    FUN_00212d80(L, -3);
    return 1;
}
