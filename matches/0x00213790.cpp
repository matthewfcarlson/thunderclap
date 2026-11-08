// lua_setfield: t[k] = the top value for the table at idx (metamethods apply); pops it.
extern "C" unsigned int __cdecl strlen(const char*);
#include "decls/data/lua.h"

extern "C" LuaVMTObject* __fastcall FUN_00212bb0(int idx, LuaVMState* L);
extern "C" LuaVMString* __cdecl FUN_00219430(LuaVMState* L, const char* str, unsigned int l);
extern "C" void __cdecl FUN_00217980(LuaVMState* L, const LuaVMTObject* t, LuaVMTObject* key, LuaVMTObject* val);

extern "C" void __cdecl FUN_00213790(LuaVMState* L, int idx, const char* k) {
    LuaVMTObject* t = FUN_00212bb0(idx, L);
    LuaVMTObject key;
    key.value.gc = (LuaVMGCObject*)FUN_00219430(L, k, (unsigned int)strlen(k));
    key.tt = LUAVM_TSTRING;
    FUN_00217980(L, t, &key, L->top - 1);
    L->top--;
}
