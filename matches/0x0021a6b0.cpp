// luaZ_openspace: make the buffer at least n bytes (32 at least); its characters.
#include "decls/data/lua.h"

extern "C" void* __cdecl FUN_0021add0(LuaVMState* L, void* block, unsigned int osize, unsigned int nsize);

extern "C" char* __cdecl FUN_0021a6b0(LuaVMState* L, LuaVMBuffer* buff, unsigned int n) {
    if (n > buff->buffsize) {
        if (n < 32)
            n = 32;
        buff->buffer = (char*)FUN_0021add0(L, buff->buffer, buff->buffsize, n);
        buff->buffsize = n;
    }
    return buff->buffer;
}
