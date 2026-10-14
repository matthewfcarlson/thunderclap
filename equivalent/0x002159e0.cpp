// STATUS: equivalent (tools/equiv.py level 3: 3013 inputs, branch coverage 10/10)
// FUN_002159e0 @ 0x002159e0
// Lua 5.0 luaD_call
struct GlobalState_2159e0 { char pad0[0x48]; unsigned int GCthreshold; unsigned int nblocks; };
struct lua_State_2159e0 {
    char pad0[0x10];
    GlobalState_2159e0 *l_G;
    char pad14[0x1a];
    unsigned short nCcalls;
};
struct TObject;

void __cdecl FUN_00214a90(lua_State_2159e0 *L, const char *msg);
void __cdecl FUN_002152b0(lua_State_2159e0 *L, int errcode);
TObject *__cdecl FUN_00215790(lua_State_2159e0 *L, TObject *func);
TObject *__cdecl FUN_00218350(lua_State_2159e0 *L, int nresults);
void __cdecl FUN_00215970(lua_State_2159e0 *L, int nresults, TObject *first);
void __cdecl FUN_00217440(lua_State_2159e0 *L);

void FUN_002159e0(lua_State_2159e0 *L, TObject *func, int nResults)
{
    if (++L->nCcalls >= 200) {
        if (L->nCcalls == 200)
            FUN_00214a90(L, "C stack overflow");
        else if (L->nCcalls >= 225)
            FUN_002152b0(L, 5);
    }
    TObject *first = FUN_00215790(L, func);
    if (first == 0)
        first = FUN_00218350(L, 1);
    FUN_00215970(L, nResults, first);
    L->nCcalls--;
    if (L->l_G->nblocks >= L->l_G->GCthreshold)
        FUN_00217440(L);
}
