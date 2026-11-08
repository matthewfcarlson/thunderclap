// luaB_print
#include "decls/data/lua.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/global.h"
// data: error = DAT_0042251c, tostring = DAT_00422548; zero_33d6e0 is the CRT's stdout (0x004d9a10)

extern "C" int __cdecl FUN_00212d70(LuaVMState* L);
extern "C" void __cdecl FUN_002135a0(LuaVMState* L, int idx, const char* k);
extern "C" void __cdecl FUN_00212ed0(LuaVMState* L, int idx);
extern "C" void __cdecl FUN_002139a0(LuaVMState* L, int nargs, int nresults);
extern "C" const char* __cdecl FUN_00213190(LuaVMState* L, int idx);
extern "C" void __cdecl FUN_00347eed(const void*, const void*);
extern "C" void __cdecl FUN_00212d80(LuaVMState* L, int idx);
extern "C" int __cdecl FUN_00338e20(LuaVMState* L, const char* fmt, ...);
extern float zero_33d6e0;

extern "C" int __cdecl FUN_0033d6e0(LuaVMState* L) {
    int n = FUN_00212d70(L);
    FUN_002135a0(L, -10001, DAT_00422548);
    for (int i = 1; i <= n; ++i) {
        FUN_00212ed0(L, -1);
        FUN_00212ed0(L, i);
        FUN_002139a0(L, 1, 1);
        const char* s = FUN_00213190(L, -1);
        if (!s)
            return FUN_00338e20(L, DAT_0042251c);
        if (i > 1)
            FUN_00347eed(DAT_00434f70, &zero_33d6e0);
        FUN_00347eed(s, &zero_33d6e0);
        FUN_00212d80(L, -2);
    }
    FUN_00347eed(DAT_00422518, &zero_33d6e0);
    return 0;
}
