// STATUS: equivalent (tools/equiv.py level 3: 1513 inputs, branch coverage 30/30)
// FUN_001d0a40 @ 0x001d0a40
// cl-flags: /GS
struct lua_State;

struct lua_Debug_1d0a40 {
    int event;
    const char* name;
    const char* namewhat;
    const char* what;
    const char* source;
    int currentline;
    int nups;
    int linedefined;
    char short_src[60];
    int i_ci;
};


int FUN_00212d70(lua_State* L);
int FUN_00212fb0(lua_State* L, int idx);
void FUN_00212e20(lua_State* L, int idx);
void FUN_00213380(lua_State* L, const char* s, int len);
const char* FUN_00213470(lua_State* L, const char* fmt, ...);
void FUN_00213c90(lua_State* L, int n);
int FUN_00213fc0(lua_State* L, int level, lua_Debug_1d0a40* ar);
int FUN_00214bd0(lua_State* L, const char* what, lua_Debug_1d0a40* ar);

// Lua error handler: pushes the "LUA SCRIPT ERROR" banner and a stack traceback.
int FUN_001d0a40(lua_State* L)
{
    lua_Debug_1d0a40 ar;
    int level = 1;
    int firstpart = 1;
    int proceed = 1;

    if (FUN_00212d70(L) == 0) {
        FUN_00213380(L, "", 0);
    } else if (FUN_00212fb0(L, 1) == 0) {
        proceed = 0;
    } else {
        FUN_00213380(L, "\n", 1);
    }

    if (proceed) {
        FUN_00213380(L, "\n***** LUA SCRIPT ERROR *****\n", 0x1e);
        FUN_00212e20(L, 1);
        FUN_00213380(L, "stack traceback:", 0x10);
        while (FUN_00213fc0(L, level, &ar)) {
            level++;
            if (level > 12 && firstpart) {
                if (!FUN_00213fc0(L, level + 10, &ar)) {
                    level--;
                } else {
                    FUN_00213380(L, "\n\t...", 5);
                    while (FUN_00213fc0(L, level + 10, &ar))
                        level++;
                }
                firstpart = 0;
                continue;
            }
            FUN_00213380(L, "\n\t", 2);
            FUN_00214bd0(L, "Snl", &ar);
            FUN_00213470(L, "%s:", ar.source);
            if (ar.currentline > 0)
                FUN_00213470(L, "%d:", ar.currentline);
            switch (*ar.namewhat) {
            case 'f':
            case 'g':
            case 'l':
            case 'm':
                FUN_00213470(L, " in function `%s'", ar.name);
                break;
            default:
                if (*ar.what == 'm') {
                    FUN_00213470(L, " in main chunk");
                } else if (*ar.what == 'C' || *ar.what == 't') {
                    FUN_00213380(L, " ?", 2);
                } else {
                    FUN_00213470(L, " in function <%s:%d>", ar.short_src, ar.linedefined);
                }
                break;
            }
            FUN_00213c90(L, FUN_00212d70(L));
        }
        FUN_00213c90(L, FUN_00212d70(L));
    }
    return 1;
}
