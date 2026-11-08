// lua_remove: remove the value at idx, shifting the ones above it down.
#include "decls/data/lua.h"

extern "C" LuaVMTObject* __fastcall FUN_00212bb0(int idx, LuaVMState* L);

extern "C" void __cdecl FUN_00212de0(LuaVMState* L, int idx) {
    LuaVMTObject* p = FUN_00212bb0(idx, L);
    p++;
    while (p < L->top) {
        LuaVMTObject* q = p - 1;
        q->tt = p->tt;
        q->value = p->value;
        p++;
    }
    L->top--;
}
