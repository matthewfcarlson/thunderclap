// luaK_jump: an unconditional jump, chained with the pending jumps.
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_00220b20(LuaVMFuncState* fs, LuaVMInstruction i, int line);
extern "C" void __cdecl FUN_002207c0(LuaVMFuncState* fs, int* l1, int l2);

extern "C" int __cdecl FUN_00220cd0(LuaVMFuncState* fs) {
    int old = fs->jpc;
    fs->jpc = -1;
    int result = FUN_00220b20(fs, 0x7fff94, fs->ls->lastline);
    FUN_002207c0(fs, &result, old);
    return result;
}
