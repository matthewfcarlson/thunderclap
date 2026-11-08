// STATUS: equivalent (tools/equiv.py level 3: 2935 inputs, branch coverage 2/2)
// fixjump: point the jump at pc to dest (the sBx field), with the "control structure too long" check.
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_0021b060(LuaVMLexState* ls, const char* msg);

// equiv-conv: FUN_002204e0 eax ecx ebx
extern "C" void __cdecl FUN_002204e0(int dest, int pc, LuaVMFuncState* fs) {
    unsigned int length = (unsigned int)dest - (unsigned int)pc - 1;
    int signedLength = (int)length;
    unsigned int magnitude = signedLength < 0 ? 0u - length : length;
    LuaVMInstruction* jmp = &fs->f->code[pc];
    if ((int)magnitude > 0x1ffff)
        FUN_0021b060(fs->ls, "control structure too long");
    LuaVMInstruction oldValue = *jmp;
    unsigned int bits = (length + 0x1ffff) << 6;
    *jmp = oldValue ^ ((bits ^ oldValue) & 0xffffc0);
}
