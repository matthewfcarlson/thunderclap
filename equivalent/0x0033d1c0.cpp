// STATUS: equivalent (tools/equiv.py level 3: 151 inputs, branch coverage 19/19)
// FUN_0033d1c0 @ 0x0033d1c0
// lstrlib addquoted (format's %q)
#include "decls/data/lua.h"

extern "C" const char* __cdecl FUN_00339df0(LuaVMState* L, int narg, unsigned int* len);
extern "C" char* __cdecl FUN_00339470(LuaVMLBuffer* B);
extern "C" void __cdecl FUN_003394b0(LuaVMLBuffer* B, const char* s, unsigned int l);

// equiv-conv: FUN_0033d1c0 esi edx ecx
void FUN_0033d1c0(LuaVMLBuffer* b, LuaVMState* L, int arg) {
    unsigned l;
    const char* s = FUN_00339df0(L, arg, &l);
    char* end = b->buffer + LUAVM_BUFFERSIZE;
    if (b->p >= end) FUN_00339470(b);
    *b->p = '"';
    ++b->p;
    while (l) {
        --l;
        signed char ch = *s;
        if (ch == '"' || ch == '\\' || ch == '\n') {
            if (b->p >= end) FUN_00339470(b);
            *b->p = '\\';
            ++b->p;
            if (b->p >= end) FUN_00339470(b);
            *b->p = *s;
            ++b->p;
        } else if (ch == 0) {
            FUN_003394b0(b, "\\000", 4);
        } else {
            if (b->p >= end) FUN_00339470(b);
            *b->p = *s;
            ++b->p;
        }
        ++s;
    }
    if (b->p >= end) FUN_00339470(b);
    *b->p = '"';
    ++b->p;
}
