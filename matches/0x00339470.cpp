// luaL_prepbuffer: empties the buffer onto the stack and returns its start.
#include "decls/data/lua.h"
extern "C" void __cdecl FUN_00213380(LuaVMState* L, const char* s, unsigned int len);
extern "C" void __cdecl FUN_003393f0(LuaVMLBuffer* B);
extern "C" char* __cdecl FUN_00339470(LuaVMLBuffer* B) {
    unsigned int n = (unsigned int)(B->p - B->buffer);
    if (n != 0) {
        FUN_00213380(B->L, B->buffer, n);
        B->p = B->buffer;
        ++B->lvl;
        FUN_003393f0(B);
    }
    return B->buffer;
}
