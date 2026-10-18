// FUN_0033aef0 @ 0x0033aef0
struct lua_State;
void __cdecl FUN_00339d70(lua_State* L, int idx, int type);
int __cdecl FUN_003392c0(lua_State* L, int idx);
int __cdecl FUN_00339fe0(lua_State* L, int idx, int def);
void __cdecl FUN_00339270(lua_State* L, int idx, int n);
void __cdecl FUN_00213640(lua_State* L, int idx, int n);
void __cdecl FUN_00213870(lua_State* L, int idx, int n);
void __cdecl FUN_00213320(lua_State* L);
int tremove(lua_State* L) {
    FUN_00339d70(L, 1, 5);
    int n = FUN_003392c0(L, 1);
    int pos = FUN_00339fe0(L, 2, n);
    if (n <= 0) return 0;
    FUN_00339270(L, 1, n - 1);
    FUN_00213640(L, 1, pos);
    for (; pos < n; pos++) {
        FUN_00213640(L, 1, pos + 1);
        FUN_00213870(L, 1, pos);
    }
    FUN_00213320(L);
    FUN_00213870(L, 1, n);
    return 1;
}
