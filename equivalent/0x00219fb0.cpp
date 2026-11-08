// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 6/6)
// luaH_index: the traversal index of a key for next (-1 for nil; array slots first, then the nodes).
#include "decls/data/engine/unknown.h"
#include "decls/data/lua.h"

// equiv-conv: FUN_00219980 esi stack
extern "C" int __cdecl FUN_00219980(const LuaVMTObject* key, float lim);
extern "C" LuaVMTObject* __cdecl FUN_00219e90(LuaVMTable* t, const LuaVMTObject* key);
extern "C" void __cdecl FUN_00214a90(LuaVMState* L, const char* fmt, ...);

// equiv-conv: FUN_00219fb0 eax edi stack
extern "C" int __cdecl FUN_00219fb0(const LuaVMTObject* key, LuaVMTable* t, LuaVMState* L) {
    if (key->tt == LUAVM_TNIL)
        return -1;
    int i = FUN_00219980(key, (float)t->sizearray);
    if (i >= 0)
        return i - 1;
    const LuaVMTObject* v = FUN_00219e90(t, key);
    if (v == LUAVM_NILOBJECT)
        FUN_00214a90(L, "invalid key for `next'");
    return (int)(((const char*)v - (const char*)&t->node[0].i_val) / sizeof(LuaVMNode)) + t->sizearray;
}
