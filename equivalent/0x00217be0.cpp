// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 10/10)
// FUN_00217be0 @ 0x00217be0
// FUN_00217be0 @ 0x00217be0: Lua 5.0 call_orderTM (callTMres call-setup inlined)
struct TObject {
    int tt;
    int value;
};

struct lua_State {
    char pad[8];
    TObject *top;       // 0x8
};

const TObject *__cdecl FUN_002175b0(lua_State *L, const TObject *o, int event);
int __cdecl FUN_00215fa0(const TObject *a, const TObject *b);
// callTMres: ecx = L, eax = result slot
// equiv-conv: FUN_00217790 ecx eax
void FUN_00217790(lua_State *L, TObject *res);

// equiv-conv: FUN_00217be0 eax stack stack ebx
int __cdecl FUN_00217be0(lua_State *L, const TObject *p1, int event, const TObject *p2)
{
    const TObject *tm1 = FUN_002175b0(L, p1, event);
    if (tm1->tt == 0)
        return -1;
    const TObject *tm2 = FUN_002175b0(L, p2, event);
    if (!FUN_00215fa0(tm1, tm2))
        return -1;

    L->top[0] = *tm1;
    L->top[1] = *p1;
    L->top[2] = *p2;
    FUN_00217790(L, L->top);

    const TObject *r = L->top;
    if (r->tt == 0)
        return 0;
    if (r->tt == 1 && r->value == 0)
        return 0;
    return 1;
}
