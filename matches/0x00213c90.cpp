// lua_concat: concatenate the n top values (n == 0 pushes ""); a GC step first when due.
#include "decls/data/lua.h"
#include "decls/data/game/global.h"

extern "C" void __cdecl FUN_00217440(LuaVMState* L);
extern "C" void __cdecl FUN_00217f20(LuaVMState* L, int total, int last);
extern "C" LuaVMString* __cdecl FUN_00219430(LuaVMState* L, const char* str, unsigned int l);

extern "C" void __cdecl FUN_00213c90(LuaVMState* L, int n) {
    LuaVMGlobal* g = L->l_G;
    if (g->totalbytes >= g->GCthreshold)
        FUN_00217440(L);
    if (n >= 2) {
        FUN_00217f20(L, n, (int)(L->top - L->base) - 1);
        L->top -= n - 1;
        return;
    }
    if (n == 0) {
        LuaVMTObject* o = L->top;
        o->value.gc = (LuaVMGCObject*)FUN_00219430(L, (const char*)&DAT_003f335c, 0);
        o->tt = LUAVM_TSTRING;
        L->top++;
    }
}
