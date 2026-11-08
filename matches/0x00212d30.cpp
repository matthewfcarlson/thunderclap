// lua_newthread: a new thread pushed on the stack (a GC step first when the debt is due).
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_00217440(LuaVMState* L);
extern "C" LuaVMState* __cdecl FUN_00215010(LuaVMState* L);

extern "C" LuaVMState* __cdecl FUN_00212d30(LuaVMState* L) {
    if (L->l_G->totalbytes >= L->l_G->GCthreshold)
        FUN_00217440(L);
    LuaVMState* L1 = FUN_00215010(L);
    LuaVMTObject* o = L->top;
    o->value.gc = (LuaVMGCObject*)L1;
    o->tt = LUAVM_TTHREAD;
    L->top++;
    return L1;
}
