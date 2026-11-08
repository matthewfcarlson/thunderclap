// luaK_nil: merge consecutive OP_LOADNIL instructions.
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_00220b20(LuaVMFuncState* fs, LuaVMInstruction i, int line);

extern "C" void __cdecl FUN_00220c40(LuaVMFuncState* fs, int from, int n) {
    if (fs->pc > fs->lasttarget) {
        LuaVMInstruction* previous = &fs->f->code[fs->pc - 1];
        LuaVMInstruction ins = *previous;
        if ((ins & 0x3f) == 3) {  // OP_LOADNIL
            int pfrom = ins >> 24;
            int pto = (ins >> 15) & 0x1ff;
            if (pfrom <= from && from <= pto + 1) {
                if (from + n - 1 > pto)
                    *previous = (ins & ~0xff8000u) | (((from + n - 1) << 15) & 0xff8000u);
                return;
            }
        }
    }
    FUN_00220b20(fs, (((from + n - 1) | (from << 9)) << 15) | 3, fs->ls->lastline);
}
