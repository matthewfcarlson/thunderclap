// STATUS: equivalent (tools/equiv.py level 3: 3003 inputs, branch coverage 12/12)
// l_strcmp: compare two strings by strcoll, part by part across embedded NULs.
extern "C" unsigned int __cdecl strlen(const char*);
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_003473c6(const char* a, const char* b);

// equiv-conv: FUN_00217c80 ecx eax
extern "C" int __cdecl FUN_00217c80(const LuaVMString* ls, const LuaVMString* rs) {
    const char* l = LUAVM_GETSTR(ls);
    unsigned int ll = ls->len;
    const char* r = LUAVM_GETSTR(rs);
    unsigned int lr = rs->len;
    for (;;) {
        int temp = FUN_003473c6(l, r);
        if (temp != 0)
            return temp;
        unsigned int len = (unsigned int)strlen(l);
        if (len == lr)
            return len != ll;
        if (len == ll)
            return -1;
        len++;
        l += len;
        ll -= len;
        r += len;
        lr -= len;
    }
}
