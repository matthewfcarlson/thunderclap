// STATUS: equivalent (tools/equiv.py level 3: 359 inputs, branch coverage 8/8)
// FUN_001d3bc0 @ 0x001d3bc0
// Register every script-visible object as a Lua global, then refresh the second list.
struct lua_State;

struct ScriptObject {
    char pad0[8];
    const char* name;
};

int __cdecl FUN_001d22a0(lua_State* L);                                       // C function pushed as the closure
void __cdecl FUN_00213550(lua_State* L, ScriptObject* object);                // push the object (upvalue)
void __cdecl FUN_002134a0(lua_State* L, int (__cdecl *fn)(lua_State*), int n); // lua_pushcclosure
void __cdecl FUN_00213790(lua_State* L, int index, const char* name);         // lua_setfield

class ScriptRegistry {
public:
    char pad0[8];
    lua_State* L;
    ScriptObject* objects[0x400];
    int objectCount;
    int refreshList[20];
    int refreshCount;

    void FUN_001d2110(int entry);
    void FUN_001d3bc0();
};

void ScriptRegistry::FUN_001d3bc0()
{
    for (int i = 0; i < objectCount; i++) {
        ScriptObject* object = objects[i];
        lua_State* state = L;
        const char* name = object->name;
        FUN_00213550(state, object);
        FUN_002134a0(state, FUN_001d22a0, 1);
        FUN_00213790(state, -10001, name);
    }
    for (int i = 0; i < refreshCount; i++) {
        FUN_001d2110(refreshList[i]);
    }
}
