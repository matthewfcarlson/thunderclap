// luaH_free: free a table's hash part (unless it is the dummy node), its array part and the table.
#include "decls/data/lua.h"

extern "C" void* __cdecl FUN_0021add0(LuaVMState* L, void* block, unsigned int osize, unsigned int nsize);

extern "C" void __cdecl FUN_00219d20(LuaVMState* L, LuaVMTable* t) {
    if (t->lsizenode)
        FUN_0021add0(L, t->node, (1 << t->lsizenode) * (unsigned int)sizeof(LuaVMNode), 0);
    FUN_0021add0(L, t->array, t->sizearray * (unsigned int)sizeof(LuaVMTObject), 0);
    FUN_0021add0(L, t, sizeof(LuaVMTable), 0);
}
