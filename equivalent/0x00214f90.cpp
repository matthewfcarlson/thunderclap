// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 0/0)
// FUN_00214f90 @ 0x00214f90
// Lua 5.0 close_state tail: frees the stacks and the state itself
struct lua_State_214f90;

struct global_State_214f90 {
    char pad0[0xc];
    void* (__cdecl *realloc)(void* ud, void* block, unsigned int osize, unsigned int nsize);    // 0xc
    void* ud;           // 0x10
    char pad14[0x3c - 0x14];
    void* strhash;      // 0x3c
    char pad40[4];
    unsigned int strsize;   // 0x44
};

struct lua_State_214f90 {
    char pad0[0x10];
    global_State_214f90* l_G;      // 0x10
    char pad14[0x1c - 0x14];
    void* stack;            // 0x1c
    unsigned int stacksize; // 0x20
    char pad24[4];
    void* base_ci;          // 0x28
    unsigned short size_ci; // 0x2c
};

void __cdecl FUN_00219660(lua_State_214f90* L, void* stack);               // luaF_close
extern "C" void __cdecl FUN_002172c0(void *);                            // luaC_sweep(L, 1)
extern "C" void __cdecl FUN_002192c0(void *);                            // luaS_freeall
void* __cdecl FUN_0021add0(lua_State_214f90* L, void* block, unsigned int osize, unsigned int nsize);  // luaM_realloc

// equiv-conv: FUN_00214f90 esi
extern "C" void FUN_00214f90(void * L)
{
    global_State_214f90* g = ((lua_State_214f90 *)L)->l_G;
    FUN_00219660(((lua_State_214f90 *)L), ((lua_State_214f90 *)L)->stack);
    FUN_002172c0((lua_State_214f90 *)((lua_State_214f90 *)L));
    FUN_002192c0((lua_State_214f90 *)((lua_State_214f90 *)L));
    g->strhash = FUN_0021add0(((lua_State_214f90 *)L), g->strhash, g->strsize, 0);
    g->strsize = 0;
    FUN_0021add0(((lua_State_214f90 *)L), ((lua_State_214f90 *)L)->base_ci, ((lua_State_214f90 *)L)->size_ci * 16, 0);
    FUN_0021add0(((lua_State_214f90 *)L), ((lua_State_214f90 *)L)->stack, ((lua_State_214f90 *)L)->stacksize * 8, 0);
    g->realloc(g->ud, ((lua_State_214f90 *)L), 0x108, 0);
}
