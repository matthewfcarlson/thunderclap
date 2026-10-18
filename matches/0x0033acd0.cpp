// FUN_0033acd0 @ 0x0033acd0
struct lua_State;

void __cdecl FUN_00212d80(lua_State *L, int idx);
void __cdecl FUN_00212ed0(lua_State *L, int idx);
int __cdecl FUN_00212f00(lua_State *L, int idx);
void __cdecl FUN_00213360(lua_State *L, int n);
void __cdecl FUN_00213640(lua_State *L, int idx, int n);
void __cdecl FUN_002139a0(lua_State *L, int nargs, int nresults);
int __cdecl FUN_003392c0(lua_State *L, int idx);
void __cdecl FUN_00339d70(lua_State *L, int idx, int type);

// Calls the function in argument 2 on each element (index, value) of the table in argument 1
// and returns 1 as soon as it answers true, otherwise 0.
int FUN_0033acd0(lua_State *L)
{
    FUN_00339d70(L, 1, 5);
    int n = FUN_003392c0(L, 1);
    FUN_00339d70(L, 2, 6);
    for (int i = 1; i <= n; i++) {
        FUN_00212ed0(L, 2);
        FUN_00213360(L, i);
        FUN_00213640(L, 1, i);
        FUN_002139a0(L, 2, 1);
        if (FUN_00212f00(L, -1))
            return 1;
        FUN_00212d80(L, -2);
    }
    return 0;
}
