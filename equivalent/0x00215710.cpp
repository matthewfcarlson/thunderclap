// STATUS: equivalent (tools/equiv.py level 3: 3011 inputs, branch coverage 8/8)
// FUN_00215710 @ 0x00215710
// Lua 5.0 tryfuncTM
#include "compat/ptr.h"
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
extern "C" void __cdecl FUN_00214c90(void *, const void *, const char *);
extern "C" void __cdecl FUN_00215460(void *, int);

// equiv-conv: FUN_00215710 esi edi
extern "C" void *__cdecl FUN_00215710(void *L, void * func_)
{
    TObject_215710 * func = (TObject_215710 *)func_;
    const TObject_215710 *tm = FUN_002175b0(((lua_State_215710 *)L), func, 14);
    hulk_intptr funcr = (char *)func - (char *)((lua_State_215710 *)L)->stack;
    if (tm->tt != 6)
        FUN_00214c90((lua_State_215710 *)((lua_State_215710 *)L), (const TObject_215710 *)func, "call");
    for (TObject_215710 *p = ((lua_State_215710 *)L)->top; p > func; p--)
        *p = *(p - 1);
    if ((char *)((lua_State_215710 *)L)->stack_last - (char *)((lua_State_215710 *)L)->top <= 8)
        FUN_00215460((lua_State_215710 *)((lua_State_215710 *)L), 1);
    ((lua_State_215710 *)L)->top++;
    func = (TObject_215710 *)((char *)((lua_State_215710 *)L)->stack + funcr);
    *func = *tm;
    return (TObject_215710 *)func;
}
