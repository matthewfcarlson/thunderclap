// os.exit
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_0034773f(int status);
extern "C" int __cdecl FUN_00339f70(LuaVMState* L, int narg);

extern "C" int __cdecl FUN_0033bc80(LuaVMState* L) {
    int v = FUN_00339f70(L, 1);
    FUN_0034773f(v);
    return 0;
}
