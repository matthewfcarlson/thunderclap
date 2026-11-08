// STATUS: equivalent (tools/equiv.py level 3: 2993 inputs, branch coverage 0/0)
// luaH_new: a table with narray array slots and 2^lnhash nodes.
#include "decls/data/lua.h"

extern "C" void* __cdecl FUN_0021add0(LuaVMState* L, void* block, unsigned int osize, unsigned int nsize);
extern "C" void __cdecl FUN_00217130(LuaVMState* L, LuaVMGCObject* o, unsigned char tt);
// equiv-conv: FUN_00219be0 esi edi stack
extern "C" void __cdecl FUN_00219be0(LuaVMTable* t, int size, LuaVMState* L);
// equiv-conv: FUN_00219c30 ebx esi stack
extern "C" void __cdecl FUN_00219c30(LuaVMState* L, LuaVMTable* t, int lsize);

extern "C" LuaVMTable* __cdecl FUN_00219cc0(LuaVMState* L, int narray, int lnhash) {
    LuaVMTable* t = (LuaVMTable*)FUN_0021add0(L, 0, 0, sizeof(LuaVMTable));
    FUN_00217130(L, (LuaVMGCObject*)t, LUAVM_TTABLE);
    t->metatable = 0;
    t->flags = 0xff;
    t->array = 0;
    t->sizearray = 0;
    t->lsizenode = 0;
    t->node = 0;
    FUN_00219be0(t, narray, L);
    FUN_00219c30(L, t, lnhash);
    return t;
}
