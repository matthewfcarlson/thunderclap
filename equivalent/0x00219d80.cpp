// STATUS: equivalent (tools/equiv.py level 3: 3005 inputs, branch coverage 6/6)
// luaH_getany: the value under a key of any type (by raw equality along its chain), or luaO_nilobject.
#include "decls/data/engine/unknown.h"
#include "decls/data/lua.h"

extern "C" LuaVMNode* __cdecl FUN_002198b0(const LuaVMTable* t, const LuaVMTObject* key);
extern "C" int __cdecl FUN_00215fa0(const LuaVMTObject* t1, const LuaVMTObject* t2);

// equiv-conv: FUN_00219d80 edi stack
extern "C" LuaVMTObject* __cdecl FUN_00219d80(const LuaVMTObject* key, LuaVMTable* t) {
    if (key->tt != LUAVM_TNIL) {
        LuaVMNode* n = FUN_002198b0(t, key);
        do {
            if (FUN_00215fa0(&n->i_key, key) != 0)
                return &n->i_val;
            n = n->next;
        } while (n != 0);
    }
    return LUAVM_NILOBJECT;
}
