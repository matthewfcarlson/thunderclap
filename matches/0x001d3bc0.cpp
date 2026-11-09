// FUN_001d3bc0 @ 0x001d3bc0
// Register every script-visible object as a Lua global, then refresh the second list.
#include "decls/data/script.h"
struct ScriptRefresh_1d3bc0;  // the refresh list's entries are pointers (0x001d2110's argument)

extern "C" int __cdecl FUN_001d22a0(LuaVMState* L);                                       // C function pushed as the closure
extern "C" void __cdecl FUN_00213550(LuaVMState* L, void* object);                // push the object (upvalue)
extern "C" void __cdecl FUN_002134a0(LuaVMState* L, LuaVMCFunction fn, int n); // lua_pushcclosure
extern "C" void __cdecl FUN_00213790(LuaVMState* L, int index, const char* name);         // lua_setfield

// ScriptHandler (include/decls/data/script.h): its Functions and its refresh list.
class ScriptRegistry : public ScriptHandlerFields {
public:
    virtual void v0();
    void FUN_001d2110(ScriptRefresh_1d3bc0* entry);
    void FUN_001d3bc0();
};

void ScriptRegistry::FUN_001d3bc0()
{
    for (int i = 0; i < functions.count; i++) {
        ScriptFunctionView* object = (ScriptFunctionView*)functions.items[i];
        LuaVMState* state = L;
        const char* name = object->f.key;
        FUN_00213550(state, object);
        FUN_002134a0(state, FUN_001d22a0, 1);
        FUN_00213790(state, -10001, name);
    }
    for (int i = 0; i < refreshCount; i++) {
        FUN_001d2110((ScriptRefresh_1d3bc0*)refreshList[i]);
    }
}
