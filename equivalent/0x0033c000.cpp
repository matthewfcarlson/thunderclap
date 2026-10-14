// STATUS: equivalent (tools/equiv.py level 3: 114 inputs, branch coverage 4/4)
// FUN_0033c000 @ 0x0033c000
extern unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int);

struct lua_State;

struct luaL_Buffer {
    char *p;
    int lvl;
    lua_State *L;
    char buffer[0x200];
};

const char *__cdecl FUN_00339df0(lua_State *L, int narg, unsigned int *len);
int __cdecl FUN_00339f70(lua_State *L, int narg);
void __cdecl FUN_00339630(lua_State *L, luaL_Buffer *b);
void __cdecl FUN_003394b0(luaL_Buffer *b, const char *s, unsigned int l);
void __cdecl FUN_00339540(luaL_Buffer *b);

int FUN_0033c000(lua_State *L)
{
    unsigned int cookie = DAT_004d9968;
    unsigned int l;
    luaL_Buffer b;
    const char *s = FUN_00339df0(L, 1, &l);
    int n = FUN_00339f70(L, 2);
    FUN_00339630(L, &b);
    while (n > 0) {
        FUN_003394b0(&b, s, l);
        n--;
    }
    FUN_00339540(&b);
    __security_check_cookie(cookie);
    return 1;
}
