// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 4/4)
// kname: the name of RK operand c when it is a string constant; "?" otherwise.
#include "decls/data/lua.h"
#include "decls/data/engine/unknown.h"

// equiv-conv: FUN_002146c0 eax ecx
extern "C" const char* FUN_002146c0(int c, const LuaVMProto* p) {
    int index = c - 250;
    if (index >= 0 && p->k[index].tt == LUAVM_TSTRING)
        return LUAVM_GETSTR(p->k[index].value.gc);
    return DAT_00426608;
}
