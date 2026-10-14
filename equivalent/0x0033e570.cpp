// STATUS: equivalent (tools/equiv.py level 3: 191 inputs, branch coverage 4/4)
// FUN_0033e570 @ 0x0033e570
struct lua_State;

extern "C" char *__cdecl strchr(const char *s, int c);

const char *__cdecl FUN_00213190(lua_State *L, int idx);
void __cdecl FUN_00338fe0(lua_State *L, int level, const char *msg);
void __cdecl FUN_00213380(lua_State *L, const char *s, unsigned int len);
void __cdecl FUN_00212ed0(lua_State *L, int n);
void __cdecl FUN_002133d0(lua_State *L, const char *s);
void __cdecl FUN_00213c90(lua_State *L, int n);

// equiv-conv: FUN_0033e570 ebx
void FUN_0033e570(lua_State *L)
{
    const char *s = FUN_00213190(L, -1);
    int pieces = 1;
    const char *mark = strchr(s, '?');
    while (mark != 0) {
        FUN_00338fe0(L, 3, "too many marks in a path component");
        FUN_00213380(L, s, mark - s);
        FUN_00212ed0(L, 1);
        s = mark + 1;
        pieces += 2;
        mark = strchr(s, '?');
    }
    FUN_002133d0(L, s);
    FUN_00213c90(L, pieces);
}
