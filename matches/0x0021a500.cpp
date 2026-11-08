// luaH_setstr: the slot for a string key, made by newkey when absent.
#include "decls/data/engine/unknown.h"
#include "decls/data/lua.h"

extern "C" LuaVMTObject* __cdecl FUN_00219e50(LuaVMTable* t, LuaVMString* key);
extern "C" LuaVMTObject* __cdecl FUN_0021a3e0(LuaVMState* L, LuaVMTable* t, const LuaVMTObject* key);

extern "C" LuaVMTObject* __cdecl FUN_0021a500(LuaVMState* L, LuaVMTable* t, LuaVMString* key) {
    LuaVMTObject k;
    LuaVMTObject* p = FUN_00219e50(t, key);
    if (p == LUAVM_NILOBJECT) {
        k.value.gc = (LuaVMGCObject*)key;
        k.tt = LUAVM_TSTRING;
        return FUN_0021a3e0(L, t, &k);
    }
    return p;
}
