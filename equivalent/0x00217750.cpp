// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 0/0)
// FUN_00217750 @ 0x00217750
// Lua 5.0 callTM prologue: push f, p1, p2 on the Lua stack
struct TObject {
    int tt;
    int value;
};

struct lua_State {
    char pad[8];
    TObject* top;
};

// equiv-conv: FUN_00217750 ecx stack eax edx
extern "C" void FUN_00217750(void * L, const void * f, const void * p1, const void * p2)
{
    ((lua_State *)L)->top[0] = *((const TObject *)f);
    ((lua_State *)L)->top[1] = *((const TObject *)p1);
    ((lua_State *)L)->top[2] = *((const TObject *)p2);
}
