// lua_getfenv: push the globals of the Lua function at idx (the thread's globals otherwise).
#include "decls/data/lua.h"

extern "C" LuaVMTObject* __fastcall FUN_00212bb0(int idx, LuaVMState* L);

extern "C" void __cdecl FUN_00213720(LuaVMState* L, int idx) {
    LuaVMTObject* o = FUN_00212bb0(idx, L);
    LuaVMTObject* src;
    if (o->tt == LUAVM_TFUNCTION && ((LuaVMClosure*)o->value.gc)->c.isC == 0)
        src = &((LuaVMClosure*)o->value.gc)->l.g;
    else
        src = &L->_gt;
    LuaVMTObject* dst = L->top;
    dst->tt = src->tt;
    dst->value = src->value;
    L->top++;
}
