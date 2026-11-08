// STATUS: equivalent (tools/equiv.py level 3: 576 inputs, branch coverage 7/7)
// DumpLocals: the local variables' count, then each one's name, startpc and endpc.
#include "decls/data/lua.h"

// equiv-conv: FUN_0021a830 esi stack
extern "C" void __cdecl FUN_0021a830(LuaVMDumpState* D, const LuaVMProto* f) {
    const int n = f->sizelocvars;
    int x = n;
    struct {
        int len;
        union {
            const char* str;
            int value;
        };
    } scratch;  // the original's slots: a string's size next to its characters' address, the integers in the second
    D->writer(D->L, &x, 4, D->data);
    if (n <= 0)
        return;
    int remaining = n;
    for (int i = 0; remaining; ++i, --remaining) {
        const LuaVMString* s = f->locvars[i].varname;
        if (s && LUAVM_GETSTR(s)) {
            scratch.str = LUAVM_GETSTR(s);
            const int len = s->len + 1;
            scratch.len = len;
            D->writer(D->L, &scratch.len, 4, D->data);
            D->writer(D->L, scratch.str, len, D->data);
        } else {
            scratch.value = 0;
            D->writer(D->L, &scratch.value, 4, D->data);
        }
        scratch.value = f->locvars[i].startpc;
        D->writer(D->L, &scratch.value, 4, D->data);
        scratch.value = f->locvars[i].endpc;
        D->writer(D->L, &scratch.value, 4, D->data);
    }
}
