// luaK_fixline: the line of the last instruction.
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_00220b00(LuaVMFuncState* fs, int line) {
    fs->f->lineinfo[fs->pc - 1] = line;
}
