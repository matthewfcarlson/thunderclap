// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 10/10)
// FUN_00217be0 @ 0x00217be0
// FUN_00217be0 @ 0x00217be0: Lua 5.0 call_orderTM (callTMres call-setup inlined)
struct TObject_217be0 {
    int tt;
    int value;
};

struct lua_State_217be0 {
    char pad[8];
    TObject_217be0 *top;       // 0x8
};

const TObject_217be0 *__cdecl FUN_002175b0(lua_State_217be0 *L, const TObject_217be0 *o, int event);
int __cdecl FUN_00215fa0(const TObject_217be0 *a, const TObject_217be0 *b);
// callTMres: ecx = L, eax = result slot
// equiv-conv: FUN_00217790 ecx eax
void FUN_00217790(lua_State_217be0 *L, TObject_217be0 *res);

// equiv-conv: FUN_00217be0 eax stack stack ebx
int __cdecl FUN_00217be0(lua_State_217be0 *L, const TObject_217be0 *p1, int event, const TObject_217be0 *p2)
{
    const TObject_217be0 *tm1 = FUN_002175b0(L, p1, event);
    if (tm1->tt == 0)
        return -1;
    const TObject_217be0 *tm2 = FUN_002175b0(L, p2, event);
    if (!FUN_00215fa0(tm1, tm2))
        return -1;

    L->top[0] = *tm1;
    L->top[1] = *p1;
    L->top[2] = *p2;
    FUN_00217790(L, L->top);

    const TObject_217be0 *r = L->top;
    if (r->tt == 0)
        return 0;
    if (r->tt == 1 && r->value == 0)
        return 0;
    return 1;
}
