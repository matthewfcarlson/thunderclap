// lua_getfield: push t[k] for the table at idx (metamethods apply).
extern "C" unsigned int __cdecl strlen(const char*);
#include "decls/data/lua.h"

extern "C" LuaVMTObject* __fastcall FUN_00212bb0(int idx, LuaVMState* L);
extern "C" LuaVMString* __cdecl FUN_00219430(LuaVMState* L, const char* str, unsigned int l);
extern "C" void __cdecl FUN_00217830(LuaVMState* L, const LuaVMTObject* t, LuaVMTObject* key, LuaVMTObject* val);

extern "C" void __cdecl FUN_002135a0(LuaVMState* L, int idx, const char* k) {
    LuaVMTObject key;
    LuaVMTObject* t = FUN_00212bb0(idx, L);
    key.value.gc = (LuaVMGCObject*)FUN_00219430(L, k, (unsigned int)strlen(k));
    key.tt = LUAVM_TSTRING;
    FUN_00217830(L, t, &key, L->top);
    L->top++;
}
