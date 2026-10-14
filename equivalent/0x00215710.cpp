// STATUS: equivalent (tools/equiv.py level 3: 3011 inputs, branch coverage 8/8)
// FUN_00215710 @ 0x00215710
// Lua 5.0 tryfuncTM
struct TObject { int tt; int value; };
struct lua_State {
    char pad0[8];
    TObject *top;
    char pad0c[0xc];
    TObject *stack_last;
    TObject *stack;
};

// equiv-conv: FUN_002175b0 stack stack stack
const TObject *__cdecl FUN_002175b0(lua_State *L, const TObject *o, int event);
void __cdecl FUN_00214c90(lua_State *L, const TObject *o, const char *op);
void __cdecl FUN_00215460(lua_State *L, int n);

// equiv-conv: FUN_00215710 esi edi
TObject *__cdecl FUN_00215710(lua_State *L, TObject *func)
{
    const TObject *tm = FUN_002175b0(L, func, 14);
    int funcr = (char *)func - (char *)L->stack;
    if (tm->tt != 6)
        FUN_00214c90(L, func, "call");
    for (TObject *p = L->top; p > func; p--)
        *p = *(p - 1);
    if ((char *)L->stack_last - (char *)L->top <= 8)
        FUN_00215460(L, 1);
    L->top++;
    func = (TObject *)((char *)L->stack + funcr);
    *func = *tm;
    return func;
}
