// FUN_003393f0 @ 0x003393f0
// Lua 5.0 lauxlib adjuststack: concatenates the buffer's pending strings on the stack.
#include "decls/data/lua.h"

extern "C" unsigned int __cdecl FUN_002131f0(LuaVMState* L, int idx);   // lua_strlen
extern "C" void __cdecl FUN_00213c90(LuaVMState* L, int n);             // lua_concat

#define LIMIT 10

extern "C" void __cdecl FUN_003393f0(LuaVMLBuffer* B) {
    if (B->lvl > 1) {
        LuaVMState* L = B->L;
        int toget = 1;
        unsigned int toplen = FUN_002131f0(L, -1);
        do {
            unsigned int l = FUN_002131f0(L, -(toget + 1));
            if (B->lvl - toget + 1 >= LIMIT || toplen > l) {
                toplen += l;
                toget++;
            } else {
                break;
            }
        } while (toget < B->lvl);
        FUN_00213c90(L, toget);
        B->lvl = B->lvl - toget + 1;
    }
}
