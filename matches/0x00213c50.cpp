// lua_next: replace the key on top with the next key and value of the table at idx; pops it at the end.
#include "decls/data/lua.h"

extern "C" LuaVMTObject* __fastcall FUN_00212bb0(int idx, LuaVMState* L);
extern "C" int __cdecl FUN_0021a020(LuaVMState* L, LuaVMTable* t, LuaVMTObject* key);

extern "C" int __cdecl FUN_00213c50(LuaVMState* L, int idx) {
    LuaVMTObject* t = FUN_00212bb0(idx, L);
    int more = FUN_0021a020(L, (LuaVMTable*)t->value.gc, L->top - 1);
    if (more)
        L->top++;
    else
        L->top--;
    return more;
}
