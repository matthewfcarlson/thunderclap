// STATUS: equivalent (tools/equiv.py level 3: 50 inputs, branch coverage 7/8, incomplete)
// luaK_concat: append the jump list l2 to the list *l1.
#include "decls/data/lua.h"

// equiv-conv: FUN_002204e0 eax ecx ebx
extern "C" void __cdecl FUN_002204e0(int dest, int pc, LuaVMFuncState* fs);

extern "C" void __cdecl FUN_002207c0(LuaVMFuncState* fs, int* l1, int l2) {
    if (l2 == -1)
        return;
    int list = *l1;
    if (list == -1) {
        *l1 = l2;
        return;
    }
    LuaVMInstruction* code = fs->f->code;
    for (;;) {
        int offset = ((code[list] >> 6) & 0x3ffff) - 0x1ffff;
        if (offset == -1)
            break;
        list += offset + 1;
        if (list == -1)
            break;
    }
    FUN_002204e0(l2, list, fs);
    volatile int barrier = 0;
    (void)barrier;
}
