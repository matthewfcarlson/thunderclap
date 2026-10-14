// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_00215460 @ 0x00215460
// luaD_growstack
struct lua_State {
    char pad0[0x18];
    char *stack_last;
    char *stack;
    int stacksize;
};

void *__cdecl FUN_0021add0(lua_State *L, void *block, unsigned int osize, unsigned int nsize);  // luaM_realloc
// equiv-conv: FUN_00215350 eax edx
void __cdecl FUN_00215350(lua_State *L, char *oldstack);  // correctstack

void __cdecl FUN_00215460(lua_State *L, int n) {
    int newsize;
    if (n <= L->stacksize) {
        newsize = 2 * L->stacksize;
    } else {
        newsize = L->stacksize + n + 5;
    }
    char *oldstack = L->stack;
    L->stack = (char *)FUN_0021add0(L, oldstack, L->stacksize * 8, newsize * 8);
    L->stacksize = newsize;
    L->stack_last = L->stack + newsize * 8 - 0x30;
    FUN_00215350(L, oldstack);
}
