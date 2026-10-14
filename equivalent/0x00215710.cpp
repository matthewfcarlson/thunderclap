// STATUS: equivalent (tools/equiv.py level 3: 3011 inputs, branch coverage 8/8)
// FUN_00215710 @ 0x00215710
// Lua 5.0 tryfuncTM
struct TObject_215710 { int tt; int value; };
struct lua_State_215710 {
    char pad0[8];
    TObject_215710 *top;
    char pad0c[0xc];
    TObject_215710 *stack_last;
    TObject_215710 *stack;
};

// equiv-conv: FUN_002175b0 stack stack stack
const TObject_215710 *__cdecl FUN_002175b0(lua_State_215710 *L, const TObject_215710 *o, int event);
void __cdecl FUN_00214c90(lua_State_215710 *L, const TObject_215710 *o, const char *op);
void __cdecl FUN_00215460(lua_State_215710 *L, int n);

// equiv-conv: FUN_00215710 esi edi
TObject_215710 *__cdecl FUN_00215710(lua_State_215710 *L, TObject_215710 *func)
{
    const TObject_215710 *tm = FUN_002175b0(L, func, 14);
    int funcr = (char *)func - (char *)L->stack;
    if (tm->tt != 6)
        FUN_00214c90(L, func, "call");
    for (TObject_215710 *p = L->top; p > func; p--)
        *p = *(p - 1);
    if ((char *)L->stack_last - (char *)L->top <= 8)
        FUN_00215460(L, 1);
    L->top++;
    func = (TObject_215710 *)((char *)L->stack + funcr);
    *func = *tm;
    return func;
}
