#include "decls/data/lua.h"
extern "C" void __cdecl FUN_00212d80(LuaVMState* L, int idx);
class Target_1d1d30 {
  public:
    char pad[8];
    LuaVMState* L;  // 0x08
    unsigned char FUN_001d1d30();
};
unsigned char Target_1d1d30::FUN_001d1d30() {
    FUN_00212d80(L, -2);
    return 1;
}
