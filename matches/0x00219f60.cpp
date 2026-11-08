// luaH_setnum: the slot for an integer key, made by newkey when absent.
#include "decls/data/engine/unknown.h"
#include "decls/data/lua.h"

extern "C" LuaVMTObject* __cdecl FUN_00219dc0(LuaVMTable* t, int key);
extern "C" LuaVMTObject* __cdecl FUN_0021a3e0(LuaVMState* L, LuaVMTable* t, const LuaVMTObject* key);

extern "C" LuaVMTObject* __cdecl FUN_00219f60(LuaVMState* L, LuaVMTable* t, int key) {
    LuaVMTObject k;
    LuaVMTObject* p = FUN_00219dc0(t, key);
    if (p == LUAVM_NILOBJECT) {
        k.value.n = (float)key;
        k.tt = LUAVM_TNUMBER;
        return FUN_0021a3e0(L, t, &k);
    }
    return p;
}
