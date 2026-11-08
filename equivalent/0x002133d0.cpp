// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 6/6)
// lua_pushstring: push a copy of s (nil for NULL; a GC step first when due).
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_00217440(LuaVMState* L);
extern "C" LuaVMString* __cdecl FUN_00219430(LuaVMState* L, const char* str, unsigned int l);

extern "C" void __cdecl FUN_002133d0(LuaVMState* L, const char* s) {
    if (s == 0) {
        L->top->tt = LUAVM_TNIL;
        L->top++;
        return;
    }
    unsigned int len = 0;
    while (s[len] != 0)
        len++;
    if (L->l_G->totalbytes >= L->l_G->GCthreshold)
        FUN_00217440(L);
    LuaVMTObject* t = L->top;
    t->value.gc = (LuaVMGCObject*)FUN_00219430(L, s, len);
    t->tt = LUAVM_TSTRING;
    L->top++;
}
