// STATUS: equivalent (tools/equiv.py level 3: 1321 inputs, branch coverage 7/7)
// DumpUpvalues: the upvalue names' count, then each name.
#include "decls/data/lua.h"

// equiv-conv: FUN_0021a960 esi stack
extern "C" void __cdecl FUN_0021a960(LuaVMDumpState* D, const LuaVMProto* f) {
    int n = f->sizeupvalues;
    int x = n;
    D->writer(D->L, &x, 4, D->data);
    for (int i = 0; i < n; i++) {
        const LuaVMString* s = f->upvalues[i];
        if (s != 0) {
            int len = s->len + 1;
            x = len;
            D->writer(D->L, &x, 4, D->data);
            D->writer(D->L, LUAVM_GETSTR(s), len, D->data);
        } else {
            x = 0;
            D->writer(D->L, &x, 4, D->data);
        }
    }
}
