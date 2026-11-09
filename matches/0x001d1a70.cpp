#include "decls/data/script.h"
extern "C" int __cdecl FUN_00212f00(LuaVMState* L, int idx);
extern "C" float __cdecl FUN_002130e0(LuaVMState* L, int idx);
extern "C" void __cdecl FUN_00212d80(LuaVMState* L, int idx);
struct Owner_1d1a70 : public ScriptHandlerFields {
    virtual void v0();
    bool FUN_001d1a70(float*);
};
bool Owner_1d1a70::FUN_001d1a70(float* out) {
    bool result = true;
    int state = FUN_00212f00(L, -1);
    if (state != 3)
        result = false;
    else
        *out = FUN_002130e0(L, -1);
    FUN_00212d80(L, -2);
    return result;
}
