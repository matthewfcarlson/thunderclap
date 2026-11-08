// FUN_001d3bc0 @ 0x001d3bc0
// Register every script-visible object as a Lua global, then refresh the second list.
#include "decls/data/lua.h"
struct ScriptRefresh_1d3bc0;  // the refresh list's entries are pointers (0x001d2110's argument)

struct ScriptObject {
    char pad0[8];
    const char* name;
};

extern "C" int __cdecl FUN_001d22a0(LuaVMState* L);                                       // C function pushed as the closure
extern "C" void __cdecl FUN_00213550(LuaVMState* L, void* object);                // push the object (upvalue)
extern "C" void __cdecl FUN_002134a0(LuaVMState* L, LuaVMCFunction fn, int n); // lua_pushcclosure
extern "C" void __cdecl FUN_00213790(LuaVMState* L, int index, const char* name);         // lua_setfield

class ScriptRegistry {
public:
    char pad0[8];
    LuaVMState* L;
    ScriptObject* objects[0x400];
    int objectCount;
    ScriptRefresh_1d3bc0* refreshList[20];
    int refreshCount;

    void FUN_001d2110(ScriptRefresh_1d3bc0* entry);
    void FUN_001d3bc0();
};

void ScriptRegistry::FUN_001d3bc0()
{
    for (int i = 0; i < objectCount; i++) {
        ScriptObject* object = objects[i];
        LuaVMState* state = L;
        const char* name = object->name;
        FUN_00213550(state, object);
        FUN_002134a0(state, FUN_001d22a0, 1);
        FUN_00213790(state, -10001, name);
    }
    for (int i = 0; i < refreshCount; i++) {
        FUN_001d2110(refreshList[i]);
    }
}
