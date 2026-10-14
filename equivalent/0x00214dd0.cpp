// STATUS: equivalent (tools/equiv.py level 3: 2976 inputs, branch coverage 0/0)
// FUN_00214dd0 @ 0x00214dd0
// stack_init (Lua 5.0): allocates the value stack and the CallInfo array of a new thread.
struct CallInfo {
    char *base;         // +0x00
    char *top;          // +0x04
    char pad08[8];
};

struct lua_State {
    char pad0[8];
    char *top;          // +0x08
    char *base;         // +0x0c
    char pad10[4];
    CallInfo *ci;       // +0x14
    char *stack_last;   // +0x18
    char *stack;        // +0x1c
    int stacksize;      // +0x20
    CallInfo *end_ci;   // +0x24
    CallInfo *base_ci;  // +0x28
    short size_ci;      // +0x2c
};

void *__cdecl FUN_0021add0(lua_State *L, void *block, unsigned int osize, unsigned int nsize);  // luaM_realloc

// equiv-conv: FUN_00214dd0 edi esi
void __cdecl FUN_00214dd0(lua_State *L, lua_State *L1) {
    char *stack = (char *)FUN_0021add0(L, 0, 0, 0x168);
    L1->stack = stack;
    L1->top = stack;
    L1->stacksize = 0x2d;
    L1->stack_last = stack + 0x138;
    CallInfo *ci = (CallInfo *)FUN_0021add0(L, 0, 0, 0x80);
    L1->ci = ci;
    L1->base_ci = ci;
    *(int *)L1->top = 0;
    L1->top += 8;
    L1->ci->base = L1->top;
    L1->base = L1->ci->base;
    L1->ci->top = L1->top + 0xa0;
    L1->end_ci = L1->base_ci + 8;
    L1->size_ci = 8;
}
