// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_0033e7f0 @ 0x0033e7f0
// Lua 5.0 coroutine auxresume: eax = number of arguments, esi = coroutine, edi = caller state.
// equiv-conv: FUN_0033e7f0 eax esi edi
struct lua_State;

extern "C" int __cdecl FUN_00212c50(lua_State* L, int n);                         // lua_checkstack
extern "C" void __cdecl FUN_00212cb0(lua_State* from, lua_State* to, int n);      // lua_xmove
extern "C" int __cdecl FUN_00215d10(lua_State* co, int narg);                     // lua_resume
extern "C" int __cdecl FUN_00212d70(lua_State* L);                                // lua_gettop
extern "C" int __cdecl FUN_00338e20(lua_State* L, const char* msg);               // luaL_error

int FUN_0033e7f0(int narg, lua_State* co, lua_State* L) {
    if (!FUN_00212c50(co, narg))
        FUN_00338e20(L, "too many arguments to resume");
    FUN_00212cb0(L, co, narg);
    int status = FUN_00215d10(co, narg);
    if (status == 0) {
        int nres = FUN_00212d70(co);
        if (!FUN_00212c50(L, nres))
            FUN_00338e20(L, "too many results to resume");
        FUN_00212cb0(co, L, nres);
        return nres;
    }
    FUN_00212cb0(co, L, 1);
    return -1;
}
