// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00213120 @ 0x00213120
// Lua 5.0 lua_tointeger
struct lua_State;

struct TObject {
    int tt;
    float n;
};

const TObject* __fastcall FUN_00212bb0(int idx, lua_State* L);
const TObject* __cdecl FUN_00217600(const TObject* obj, TObject* n);

int FUN_00213120(lua_State* L, int idx)
{
    TObject n;
    const TObject* o = FUN_00212bb0(idx, L);
    if (o->tt == 3 || (o = FUN_00217600(o, &n)) != 0)
        return (int)o->n;
    return 0;
}
