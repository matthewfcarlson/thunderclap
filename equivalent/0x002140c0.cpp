// STATUS: equivalent (tools/equiv.py level 3: 3011 inputs, branch coverage 12/14, incomplete)
// FUN_002140c0 @ 0x002140c0
struct Proto_2140c0 { char pad0[0xc]; unsigned *code; };
struct Closure_2140c0 { char pad0[6]; unsigned char native; char pad1[5]; Proto_2140c0 *proto; };
struct Slot_2140c0 { unsigned type; Closure_2140c0 *closure; };
struct CallInfo_2140c0 { Slot_2140c0 *base; unsigned unused; unsigned *pc; unsigned tailcalls; };
struct lua_State_2140c0 {
    char pad0[8];
    Slot_2140c0 *top;
    char pad1[0x28 - 0xc];
    CallInfo_2140c0 *base_ci;
};
struct lua_Debug_2140c0 { char pad[0x5c]; int i_ci; };
extern const char *__cdecl FUN_00219820(Proto_2140c0 *p, int n, int pc);

// Lua 5.0 lua_setlocal.
const char *__cdecl FUN_002140c0(lua_State_2140c0 *L, lua_Debug_2140c0 *ar, int n)
{
    CallInfo_2140c0 *ci = L->base_ci + ar->i_ci;
    Slot_2140c0 *fn = ci->base - 1;
    Proto_2140c0 *p = 0;
    if (fn->type == 6 && fn->closure->native == 0)
        p = fn->closure->proto;
    L->top--;
    if (p == 0)
        return 0;
    int pc = -1;
    fn = ci->base - 1;
    if (fn->type == 6 && fn->closure->native == 0)
        pc = (int)(ci->pc - fn->closure->proto->code) - 1;
    const char *name = FUN_00219820(p, n, pc);
    if (name == 0 || name[0] == '(')
        return 0;
    ci->base[n - 1] = *L->top;
    return name;
}
