// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_00215460 @ 0x00215460
// luaD_growstack
struct lua_State_215460 {
    char pad0[0x18];
    char *stack_last;
    char *stack;
    int stacksize;
};

void *__cdecl FUN_0021add0(lua_State_215460 *L, void *block, unsigned int osize, unsigned int nsize);  // luaM_realloc
// equiv-conv: FUN_00215350 eax edx
void __cdecl FUN_00215350(lua_State_215460 *L, char *oldstack);  // correctstack

extern "C" void __cdecl FUN_00215460(void *L, int n) {
    int newsize;
    if (n <= ((lua_State_215460 *)L)->stacksize) {
        newsize = 2 * ((lua_State_215460 *)L)->stacksize;
    } else {
        newsize = ((lua_State_215460 *)L)->stacksize + n + 5;
    }
    char *oldstack = ((lua_State_215460 *)L)->stack;
    ((lua_State_215460 *)L)->stack = (char *)FUN_0021add0(((lua_State_215460 *)L), oldstack, ((lua_State_215460 *)L)->stacksize * 8, newsize * 8);
    ((lua_State_215460 *)L)->stacksize = newsize;
    ((lua_State_215460 *)L)->stack_last = ((lua_State_215460 *)L)->stack + newsize * 8 - 0x30;
    FUN_00215350(((lua_State_215460 *)L), oldstack);
}
