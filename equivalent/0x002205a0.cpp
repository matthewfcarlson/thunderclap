// STATUS: equivalent (tools/equiv.py level 3: 3009 inputs, branch coverage 13/14, incomplete)
// need_value: does any jump in the list need a value (its control is not a TEST with this condition)?
#include "decls/data/lua.h"
#include "decls/data/engine/unknown.h"

// equiv-conv: FUN_002205a0 ecx eax stack
extern "C" int __cdecl FUN_002205a0(int list, LuaVMFuncState* fs, int cond) {
    while (list != -1) {
        LuaVMInstruction* pi = &fs->f->code[list];
        LuaVMInstruction* control = pi;
        if (list >= 1 && (((unsigned char*)&DAT_00426ba4)[pi[-1] & 0x3f] & 0x80))
            control = pi - 1;
        LuaVMInstruction i = *control;
        if ((i & 0x3f) != 0x18 || (int)((i >> 6) & 0x1ff) != cond)
            return 1;
        int offset = (int)((*pi >> 6) & 0x3ffff) - 0x1ffff;
        if (offset == -1)
            break;
        list = list + offset + 1;
    }
    return 0;
}
