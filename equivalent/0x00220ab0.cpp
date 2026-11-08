// STATUS: equivalent (tools/equiv.py level 3: 2722 inputs, branch coverage 4/4)
// invertjump: flip the condition (A) of the jump's control instruction.
#include "decls/data/lua.h"
#include "decls/data/engine/unknown.h"

// equiv-conv: FUN_00220ab0 ecx eax
extern "C" void __cdecl FUN_00220ab0(LuaVMFuncState* fs, LuaVMExpDesc* e) {
    LuaVMInstruction* word = fs->f->code + e->info;
    if (e->info > 0 && ((signed char*)&DAT_00426ba4)[word[-1] & 63] < 0)
        --word;
    LuaVMInstruction value = *word;
    *word = (value & 0x00ffffff) | ((value & 0xff000000) == 0 ? 0x01000000 : 0);
}
