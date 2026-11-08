// luaL_addlstring
#include "decls/data/lua.h"
extern "C" void __cdecl FUN_00213380(LuaVMState* L, const char* s, unsigned int len);
extern "C" void __cdecl FUN_003393f0(LuaVMLBuffer* B);
extern "C" void __cdecl FUN_003394b0(LuaVMLBuffer* b, const char* src, unsigned int n) {
    for (; n != 0; --n) {
        if (b->p >= b->buffer + LUAVM_BUFFERSIZE) {
            unsigned int len = (unsigned int)(b->p - b->buffer);
            if (len != 0) {
                FUN_00213380(b->L, b->buffer, len);
                b->p = b->buffer;
                ++b->lvl;
                FUN_003393f0(b);
            }
        }
        *b->p++ = *src++;
    }
}
