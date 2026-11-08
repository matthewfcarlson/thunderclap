// index2adr: the stack slot, pseudo-index (registry, globals) or C upvalue an API index names.
#include "decls/data/lua.h"
#include "decls/data/engine/unknown.h"

extern "C" LuaVMTObject* __fastcall FUN_00212bb0(int idx, LuaVMState* L) {
    if (idx > 0) {
        LuaVMTObject* o = L->base + (idx - 1);
        if (o < L->top)
            return o;
        return LUAVM_NILOBJECT;
    }
    if (idx > -10000)
        return L->top + idx;
    if (idx != -10001) {
        if (idx != -10000) {
            LuaVMCClosure* func = (LuaVMCClosure*)(L->base - 1)->value.gc;
            int i = -10001 - idx;
            LuaVMTObject* o = &func->upvalue[i - 1];
            return i <= func->nupvalues ? o : LUAVM_NILOBJECT;
        }
        return &L->l_G->l_registry;
    }
    return &L->_gt;
}
