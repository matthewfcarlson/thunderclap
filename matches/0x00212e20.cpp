// lua_insert: move the top value to idx, shifting the ones above idx up.
#include "decls/data/lua.h"

extern "C" LuaVMTObject* __fastcall FUN_00212bb0(int idx, LuaVMState* L);

extern "C" void __cdecl FUN_00212e20(LuaVMState* L, int idx) {
    LuaVMTObject* p = FUN_00212bb0(idx, L);
    LuaVMTObject* q = L->top;
    while (q > p) {
        q->tt = (q - 1)->tt;
        q->value = (q - 1)->value;
        --q;
    }
    q = L->top;
    p->tt = q->tt;
    p->value = q->value;
}
