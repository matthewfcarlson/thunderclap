#include "decls/data/lua.h"
extern "C" void __cdecl FUN_002151e0(LuaVMState* L);
class Obj_1d2700 {
    char pad[8];
    LuaVMState* mL;  // 0x08

  public:
    void FUN_001d2700();
};
void Obj_1d2700::FUN_001d2700() {
    if (mL) {
        FUN_002151e0(mL);
        mL = 0;
    }
}
