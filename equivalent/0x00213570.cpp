// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 0/0)
// lua_gettable: replace the key on top with t[key] for the table at idx (metamethods apply).
#include "decls/data/lua.h"

extern "C" LuaVMTObject* __fastcall FUN_00212bb0(int idx, LuaVMState* L);
extern "C" void __cdecl FUN_00217830(LuaVMState* L, const LuaVMTObject* t, LuaVMTObject* key, LuaVMTObject* val);

extern "C" void __cdecl FUN_00213570(LuaVMState* L, int idx) {
    LuaVMTObject* key = L->top - 1;
    LuaVMTObject* t = FUN_00212bb0(idx, L);
    FUN_00217830(L, t, key, key);
}
