// STATUS: equivalent (tools/equiv.py level 3: 20001 inputs, branch coverage 8/8)
// FUN_0033ea00 @ 0x0033ea00
// cl-flags: /GS
struct lua_State;
lua_State* __cdecl FUN_00213290(lua_State* L, int idx);
void __cdecl FUN_00339c30(lua_State* L, int narg, const char* msg);
int __cdecl FUN_00213fc0(lua_State* L, int level, void* ar);
int __cdecl FUN_00212d70(lua_State* L);
void __cdecl FUN_00213380(lua_State* L, const char* s, unsigned int len);

// Lua coroutine.status
int __cdecl FUN_0033ea00(lua_State* L) {
    struct Frame {
        char ar[0x60];
    } fr;
    lua_State* co = FUN_00213290(L, 1);
    if (co == 0)
        FUN_00339c30(L, 1, "coroutine expected");
    if (L == co) {
        FUN_00213380(L, "running", 7);
    } else if (FUN_00213fc0(co, 0, fr.ar) == 0 && FUN_00212d70(co) == 0) {
        FUN_00213380(L, "dead", 4);
    } else {
        FUN_00213380(L, "suspended", 9);
    }
    return 1;
}
