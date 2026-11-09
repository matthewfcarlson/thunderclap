#include "decls/data/script.h"
extern "C" int __cdecl FUN_00212d70(LuaVMState* L);
extern "C" void __cdecl FUN_00212d80(LuaVMState* L, int idx);
class Obj_1d1c70 : public ScriptHandlerFields {
  public:
    virtual void v0();
    void FUN_001d1c70();
};
void Obj_1d1c70::FUN_001d1c70() {
    if (topIndex >= 0) {
        int v = FUN_00212d70(L);
        int x = tops[topIndex];
        if (v != x)
            FUN_00212d80(L, x);
        --topIndex;
    }
}
