// STATUS: equivalent (tools/equiv.py level 3: 3004 inputs, branch coverage 0/0)
// condjump: emit op A B C, then a jump; returns the jump.
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_00220b20(LuaVMFuncState* fs, LuaVMInstruction i, int line);
extern "C" void __cdecl FUN_002207c0(LuaVMFuncState* fs, int* l1, int l2);

// equiv-conv: FUN_00220d10 eax esi stack stack stack
extern "C" unsigned int __cdecl FUN_00220d10(unsigned int a, LuaVMFuncState* fs, unsigned int op, unsigned int b,
                                             unsigned int c) {
    unsigned int code = ((((a << 9) | b) << 9 | c) << 6) | op;
    FUN_00220b20(fs, code, fs->ls->lastline);
    int previous = fs->jpc;
    fs->jpc = -1;
    unsigned int result = FUN_00220b20(fs, 0x7fff94, fs->ls->lastline);
    b = result;
    FUN_002207c0(fs, (int*)&b, previous);
    return b;
}
