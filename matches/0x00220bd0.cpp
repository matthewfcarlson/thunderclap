// luaK_codeABC.
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_00220b20(LuaVMFuncState* fs, LuaVMInstruction i, int line);

extern "C" int __cdecl FUN_00220bd0(LuaVMFuncState* fs, unsigned int o, int a, unsigned int b, unsigned int c) {
    return FUN_00220b20(fs, ((a << 9 | b) << 9 | c) << 6 | o, fs->ls->lastline);
}
