// luaB_cocreate
#include "decls/data/lua.h"
#include "decls/data/engine/unknown.h"
// data: luaerr = DAT_00435268

extern "C" LuaVMState* __cdecl FUN_00212d30(LuaVMState* L);
extern "C" int __cdecl FUN_00212f00(LuaVMState* L, int idx);
extern "C" int __cdecl FUN_00212f40(LuaVMState* L, int idx);
extern "C" int __cdecl FUN_00339c30(LuaVMState* L, int narg, const char* extramsg);
extern "C" void __cdecl FUN_00212ed0(LuaVMState* L, int idx);
extern "C" void __cdecl FUN_00212cb0(LuaVMState* from, LuaVMState* to, int n);

extern "C" int __cdecl FUN_0033e950(LuaVMState* L) {
    LuaVMState* NL = FUN_00212d30(L);
    int t = FUN_00212f00(L, 1);
    if (t != LUAVM_TFUNCTION || FUN_00212f40(L, 1) != 0)
        FUN_00339c30(L, 1, DAT_00435268);
    FUN_00212ed0(L, 1);
    FUN_00212cb0(L, NL, 1);
    return 1;
}
