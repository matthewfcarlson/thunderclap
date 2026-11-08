// luaK_codeABx.
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_00220b20(LuaVMFuncState* fs, LuaVMInstruction i, int line);

extern "C" int __cdecl FUN_00220c10(LuaVMFuncState* fs, unsigned int o, int a, unsigned int bc) {
    return FUN_00220b20(fs, (a << 18 | bc) << 6 | o, fs->ls->lastline);
}
