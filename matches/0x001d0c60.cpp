#include "decls/data/game/global.h"
#include "decls/data/lua.h"
// data: gError = DAT_0042251c, gTostring = DAT_00422548

extern "C" int __cdecl FUN_00212d70(LuaVMState*);
extern "C" void __cdecl FUN_002135a0(LuaVMState*, int, const char*);
extern "C" void __cdecl FUN_00212ed0(LuaVMState*, int);
extern "C" void __cdecl FUN_002139a0(LuaVMState*, int, int);
extern "C" const char* __cdecl FUN_00213190(LuaVMState*, int);
extern "C" void __cdecl FUN_002133d0(LuaVMState*, const char*);
extern "C" void __cdecl FUN_00213c40(LuaVMState*);
extern "C" void __cdecl FUN_00212d80(LuaVMState*, int);
extern "C" int __cdecl FUN_001d0c60(LuaVMState* state) {
    int count = FUN_00212d70(state);
    FUN_002135a0(state, -10001, DAT_00422548);
    int i = 1;
    if (count >= i) {
        do {
            FUN_00212ed0(state, -1);
            FUN_00212ed0(state, i);
            FUN_002139a0(state, 1, 1);
            const char* ok = FUN_00213190(state, -1);
            if (!ok) {
                FUN_002133d0(state, DAT_0042251c);
                FUN_00213c40(state);
            }
            FUN_00212d80(state, -2);
            ++i;
        } while (i <= count);
    }
    FUN_00212d80(state, -2);
    return 0;
}
