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
void FUN_00217750(lua_State* L, const TObject* f, const TObject* p1, const TObject* p2)
{
    L->top[0] = *f;
    L->top[1] = *p1;
    L->top[2] = *p2;
}
