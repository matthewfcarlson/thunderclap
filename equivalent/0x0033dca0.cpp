// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 8/8)
// FUN_0033dca0 @ 0x0033dca0
// luaB_collectgarbage
#include "decls/data/lua.h"
#include "decls/data/engine/unknown.h"
// data: the option names = DAT_004350b4 (const char*[]), their lua_gc codes = DAT_004350a4 (int[])

extern "C" int __cdecl FUN_00212f70(LuaVMState* L, int idx);
extern "C" int __cdecl FUN_00213120(LuaVMState* L, int idx);
extern "C" void __cdecl FUN_00212d80(LuaVMState* L, int idx);
extern "C" void __cdecl FUN_002133d0(LuaVMState* L, const char* s);
extern "C" const char* __cdecl FUN_00339e60(LuaVMState* L, int narg, const char* def, unsigned int* len);
extern "C" int __cdecl FUN_00338e50(const char* name, const char* const* list);
extern "C" int __cdecl FUN_00339fe0(LuaVMState* L, int narg, int def);
extern "C" int __cdecl FUN_00339c30(LuaVMState* L, int narg, const char* extramsg);
extern "C" int __cdecl FUN_00213ba0(LuaVMState* L, int what, int data);
extern "C" void __cdecl FUN_00213360(LuaVMState* L, int n);

extern "C" int __cdecl FUN_0033dca0(LuaVMState* L) {
    if (FUN_00212f70(L, 1)) {
        int value = FUN_00213120(L, 1);
        FUN_00212d80(L, 0);
        const char* option;
        if (value == 0) option = "collect";
        else if (value >= 10000) option = "stop";
        else option = "restart";
        FUN_002133d0(L, option);
    }
    const char* option = FUN_00339e60(L, 1, "collect", 0);
    int o = FUN_00338e50(option, (const char* const*)DAT_004350b4);
    int ex = FUN_00339fe0(L, 2, 0);
    if (o < 0) FUN_00339c30(L, 1, "invalid option");
    FUN_00213360(L, FUN_00213ba0(L, DAT_004350a4[o], ex));
    return 1;
}
