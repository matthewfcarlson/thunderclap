#include "decls/data/lua.h"
extern "C" int __cdecl FUN_00212d70(LuaVMState* L);
extern "C" void __cdecl FUN_00212d80(LuaVMState* L, int idx);
class Obj_1d1c70 {
  public:
    char pad0[8];
    LuaVMState* L;  // 0x08
    char pad1[0x5470 - 12];
    int items[8];  // 0x5470
    int index;     // 0x5490
    void FUN_001d1c70();
};
void Obj_1d1c70::FUN_001d1c70() {
    if (index >= 0) {
        int v = FUN_00212d70(L);
        int x = items[index];
        if (v != x)
            FUN_00212d80(L, x);
        --index;
    }
}
