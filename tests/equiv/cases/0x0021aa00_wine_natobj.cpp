// STATUS: equivalent (tools/equiv.py level 3: 644 inputs, branch coverage 15/15)
// DumpConstants: the constants (a type byte, then a number's 4 bytes or a string) and the nested functions.
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_0021ab30(const LuaVMProto* f, const LuaVMString* p, LuaVMDumpState* D);

// equiv-conv: FUN_0021aa00 esi stack
extern "C" void __cdecl FUN_0021aa00(LuaVMDumpState* D, const LuaVMProto* f) {
    int n = f->sizek;
    int x = n;  // one scratch slot for every value written (a type byte goes out with stale upper bytes)
    D->writer(D->L, &x, 4, D->data);
    for (int i = 0; i < n; ++i) {
        const LuaVMTObject* o = &f->k[i];
        x = (x & ~255) | (o->tt & 255);
        D->writer(D->L, &x, 1, D->data);
        if (o->tt == LUAVM_TNUMBER) {
            int bits = o->value.b;  // the number's 4 bytes
            D->writer(D->L, &bits, 4, D->data);
        } else if (o->tt == LUAVM_TSTRING) {
            const LuaVMString* s = (const LuaVMString*)o->value.gc;
            if (s && LUAVM_GETSTR(s)) {
                const char* str = LUAVM_GETSTR(s);
                int len = s->len + 1;
                x = len;
                D->writer(D->L, &x, 4, D->data);
                D->writer(D->L, str, len, D->data);
            } else {
                x = 0;
                D->writer(D->L, &x, 4, D->data);
            }
        }
    }
    int np = f->sizep;
    x = np;
    D->writer(D->L, &x, 4, D->data);
    for (int j = 0; j < np; ++j)
        FUN_0021ab30(f->p[j], f->source, D);
}
