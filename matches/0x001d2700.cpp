#include "decls/data/script.h"
extern "C" void __cdecl FUN_002151e0(LuaVMState* L);
class Obj_1d2700 : public ScriptHandlerFields {
  public:
    virtual void v0();
    void FUN_001d2700();
};
void Obj_1d2700::FUN_001d2700() {
    if (L) {
        FUN_002151e0(L);
        L = 0;
    }
}
