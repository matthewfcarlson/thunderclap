// STATUS: equivalent (tools/equiv.py level 3: 3012 inputs, branch coverage 3/3)
// DumpString: a string as its size (with the NUL; 0 for none) and its characters.
#include "decls/data/lua.h"

// equiv-conv: FUN_0021a790 eax esi
extern "C" void __cdecl FUN_0021a790(const LuaVMString* s, LuaVMDumpState* D) {
    unsigned int size = 0;  // the chunk's size_t: 4 bytes
    if (s && LUAVM_GETSTR(s)) {
        const unsigned int len = s->len + 1;
        size = len;
        D->writer(D->L, &size, 4, D->data);
        D->writer(D->L, LUAVM_GETSTR(s), len, D->data);
    } else {
        unsigned int* volatile address = &size;
        D->writer(D->L, address, 4, D->data);
    }
}
