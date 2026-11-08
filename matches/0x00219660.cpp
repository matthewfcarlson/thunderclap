// luaF_close: close the open upvalues at or above level (copy the slot into the upvalue; free the dead ones).
#include "decls/data/lua.h"

extern "C" void* __cdecl FUN_0021add0(LuaVMState* L, void* block, unsigned int osize, unsigned int nsize);
extern "C" void __cdecl FUN_00217160(LuaVMState* L, LuaVMGCObject* o);

extern "C" void __cdecl FUN_00219660(LuaVMState* L, LuaVMTObject* level) {
    LuaVMGlobal* g = L->l_G;
    LuaVMUpVal* uv = (LuaVMUpVal*)L->openupval;
    while (uv && uv->v >= level) {
        L->openupval = uv->next;
        if (uv->marked & (g->currentwhite ^ 3)) {
            FUN_0021add0(L, uv, sizeof(LuaVMUpVal), 0);
        } else {
            LUAVM_SETOBJ(&uv->value, uv->v);
            uv->v = &uv->value;
            FUN_00217160(L, (LuaVMGCObject*)uv);
        }
        uv = (LuaVMUpVal*)L->openupval;
    }
}
