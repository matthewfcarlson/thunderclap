// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_001d2810 @ 0x001d2810
struct lua_State;

int __cdecl FUN_00212d70(lua_State *L);
int __cdecl FUN_00339a60(lua_State *L, const char *buf, int len, const char *name);
int __cdecl FUN_002139f0(lua_State *L, int nargs, int nresults, int errfunc);
void __cdecl FUN_00212d80(lua_State *L, int top);

class ScriptHandler {
public:
    char pad0[8];
    lua_State *main;
    int FUN_001d2810(lua_State *L, const char *buf, int len, const char *name);
};

int ScriptHandler::FUN_001d2810(lua_State *L, const char *buf, int len, const char *name)
{
    int top = FUN_00212d70(main);
    if (len == -1) {
        const char *e = buf;
        while (*e != 0)
            e++;
        len = e - buf;
    }
    if (name == 0)
        name = "=ScriptHandler::DoLuaBuffer";
    int r = FUN_00339a60(L, buf, len, name);
    if (r != 0 || (r = FUN_002139f0(L, 0, -1, 0)) != 0)
        FUN_00212d80(L, top);
    return r;
}
