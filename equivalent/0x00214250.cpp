// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// checkopenop: the instruction after pc takes an open register count (a call with B 0, or OP_SETLISTO).
#include "decls/data/lua.h"

// equiv-conv: FUN_00214250 eax edx
extern "C" int FUN_00214250(const LuaVMProto* pt, int pc) {
    LuaVMInstruction i = pt->code[pc + 1];
    unsigned int op = i & 0x3f;
    if (op >= 0x19 && op <= 0x1b)
        return (i & 0xff8000) == 0;
    return op == 0x21;
}
