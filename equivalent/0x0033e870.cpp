// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_0033e870 @ 0x0033e870
// equiv-conv: FUN_0033e7f0 eax esi edi
struct lua_State;

lua_State *__cdecl FUN_00213290(lua_State *L, int idx);
void __cdecl FUN_00339c30(lua_State *L, int narg, const char *msg);
int __cdecl FUN_00212d70(lua_State *L);
int __cdecl FUN_0033e7f0(int narg, lua_State *co, lua_State *L);
void __cdecl FUN_00213520(lua_State *L, int b);
void __cdecl FUN_00212e20(lua_State *L, int idx);

// luaB_coresume
int __cdecl FUN_0033e870(lua_State *L)
{
    lua_State *co = FUN_00213290(L, 1);
    if (co == 0)
        FUN_00339c30(L, 1, "coroutine expected");
    int r = FUN_0033e7f0(FUN_00212d70(L) - 1, co, L);
    if (r < 0) {
        FUN_00213520(L, 0);
        FUN_00212e20(L, -2);
        return 2;
    }
    FUN_00213520(L, 1);
    FUN_00212e20(L, -(r + 1));
    return r + 1;
}
