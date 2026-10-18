// FUN_003393f0 @ 0x003393f0
// Lua 5.0 lauxlib adjuststack: concatenates the buffer's pending strings on the stack.
struct lua_State;
struct luaL_Buffer_3393f0 {
    char* p;
    int lvl;
    lua_State* L;
};

extern "C" unsigned int __cdecl FUN_002131f0(lua_State* L, int idx);   // lua_strlen
extern "C" void __cdecl FUN_00213c90(lua_State* L, int n);             // lua_concat

#define LIMIT 10

void FUN_003393f0(luaL_Buffer_3393f0* B) {
    if (B->lvl > 1) {
        lua_State* L = B->L;
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
