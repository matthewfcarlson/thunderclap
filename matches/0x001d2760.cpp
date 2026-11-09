#include "decls/data/script.h"
extern "C" void __cdecl FUN_002151e0(LuaVMState* L);
struct Object_1d2760 : public ScriptHandlerFields {
    virtual void v0();
    void FUN_001d2760();
};
void Object_1d2760::FUN_001d2760() {
    if (ownsState) {
        if (L) {
            FUN_002151e0(L);
            L = 0;
        }
        ownsState = 0;
    }
}
