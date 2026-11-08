// luaH_set: the slot for key, made by newkey when absent (a nil or NaN key is an error); clears the metamethod cache.
#include "decls/data/engine/unknown.h"
#include "decls/data/lua.h"

extern "C" LuaVMTObject* __cdecl FUN_00219e90(LuaVMTable* t, const LuaVMTObject* key);
extern "C" void __cdecl FUN_00214a90(LuaVMState* L, const char* fmt, ...);
extern "C" LuaVMTObject* __cdecl FUN_0021a3e0(LuaVMState* L, LuaVMTable* t, const LuaVMTObject* key);

extern "C" LuaVMTObject* __cdecl FUN_00219ef0(LuaVMState* L, LuaVMTable* t, const LuaVMTObject* key) {
    LuaVMTObject* p = FUN_00219e90(t, key);
    t->flags = 0;
    if (p == LUAVM_NILOBJECT) {
        if (key->tt == LUAVM_TNIL) {
            FUN_00214a90(L, "table index is nil");
        } else if (key->tt == LUAVM_TNUMBER) {
            float x = key->value.n;
            if (x != x)
                FUN_00214a90(L, "table index is NaN");
        }
        return FUN_0021a3e0(L, t, key);
    }
    return p;
}
