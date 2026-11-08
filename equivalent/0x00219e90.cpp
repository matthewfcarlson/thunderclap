// STATUS: equivalent (tools/equiv.py level 3: 3004 inputs, branch coverage 6/6)
// luaH_get: the value under a key (integers and strings by their fast paths), or luaO_nilobject.
#include "decls/data/lua.h"

extern "C" LuaVMTObject* __cdecl FUN_00219dc0(LuaVMTable* t, int key);
extern "C" LuaVMTObject* __cdecl FUN_00219e50(LuaVMTable* t, LuaVMString* key);
// equiv-conv: FUN_00219d80 edi stack
extern "C" LuaVMTObject* __cdecl FUN_00219d80(const LuaVMTObject* key, LuaVMTable* t);

extern "C" LuaVMTObject* __cdecl FUN_00219e90(LuaVMTable* t, const LuaVMTObject* key) {
    if (key->tt == LUAVM_TNUMBER) {
        int k = (int)key->value.n;
        if (key->value.n == (float)k)
            return FUN_00219dc0(t, k);
    } else if (key->tt == LUAVM_TSTRING) {
        return FUN_00219e50(t, (LuaVMString*)key->value.gc);
    }
    return FUN_00219d80(key, t);
}
