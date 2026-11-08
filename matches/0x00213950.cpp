// lua_setfenv: pop the top value into the globals of the Lua function at idx; 0 when idx is not one.
#include "decls/data/lua.h"

extern "C" LuaVMTObject* __fastcall FUN_00212bb0(int idx, LuaVMState* L);

extern "C" int __cdecl FUN_00213950(LuaVMState* L, int idx) {
    int res = 0;
    LuaVMTObject* o = FUN_00212bb0(idx, L);
    L->top--;
    LuaVMTObject* v = L->top;
    if (o->tt == LUAVM_TFUNCTION) {
        LuaVMClosure* cl = (LuaVMClosure*)o->value.gc;
        if (0 == cl->c.isC) {
            res = 1;
            cl->l.g.tt = v->tt;
            cl->l.g.value = v->value;
        }
    }
    return res;
}
