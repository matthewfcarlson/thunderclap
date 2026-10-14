// STATUS: equivalent (tools/equiv.py level 3: 150 inputs, branch coverage 32/32)
// FUN_0033aa40 @ 0x0033aa40
extern unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int);

struct lua_State;

struct lua_Debug_33aa40 {
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

int __cdecl FUN_00212d70(lua_State* L);
int __cdecl FUN_00212f00(lua_State* L, int idx);
lua_State* __cdecl FUN_00213290(lua_State* L, int idx);
int __cdecl FUN_00212fb0(lua_State* L, int idx);
void __cdecl FUN_00213380(lua_State* L, const char* s, unsigned int len);
const char* __cdecl FUN_00213470(lua_State* L, const char* fmt, ...);
void __cdecl FUN_00213c90(lua_State* L, int n);
int __cdecl FUN_00213fc0(lua_State* L, int level, lua_Debug_33aa40* ar);
int __cdecl FUN_00214bd0(lua_State* L, const char* what, lua_Debug_33aa40* ar);

struct Frame_33aa40 {
    int arg;
    int firstpart;
    lua_Debug_33aa40 ar;
    unsigned int cookie;
};

// Lua 5.0 errorfb (stack traceback builder)
int FUN_0033aa40(lua_State* L)
{
    Frame_33aa40 f;
    int level = 1;
    lua_State* L1;

    f.cookie = DAT_004d9968;
    f.firstpart = 1;
    if (FUN_00212f00(L, 1) == 8) {
        f.arg = 1;
        L1 = FUN_00213290(L, 1);
    } else {
        f.arg = 0;
        L1 = L;
    }

    if (FUN_00212d70(L) == f.arg) {
        FUN_00213380(L, "", 0);
    } else {
        if (!FUN_00212fb0(L, f.arg + 1)) {
            __security_check_cookie(f.cookie);
            return 1;
        }
        FUN_00213380(L, "\n", 1);
    }
    FUN_00213380(L, "stack traceback:", 16);

    while (FUN_00213fc0(L1, level++, &f.ar)) {
        if (level > 12 && f.firstpart) {
            if (!FUN_00213fc0(L1, level + 10, &f.ar)) {
                level--;
            } else {
                FUN_00213380(L, "\n\t...", 5);
                while (FUN_00213fc0(L1, level + 10, &f.ar))
                    level++;
            }
            f.firstpart = 0;
            continue;
        }
        FUN_00213380(L, "\n\t", 2);
        FUN_00214bd0(L1, "Snl", &f.ar);
        FUN_00213470(L, "%s:", f.ar.short_src);
        if (f.ar.currentline > 0)
            FUN_00213470(L, "%d:", f.ar.currentline);
        switch (*f.ar.namewhat) {
        case 'f':
        case 'g':
        case 'l':
        case 'm':
            FUN_00213470(L, " in function `%s'", f.ar.name);
            break;
        default:
            if (*f.ar.what == 'm')
                FUN_00213470(L, " in main chunk");
            else if (*f.ar.what == 'C' || *f.ar.what == 't')
                FUN_00213380(L, " ?", 2);
            else
                FUN_00213470(L, " in function <%s:%d>", f.ar.short_src, f.ar.linedefined);
            break;
        }
        FUN_00213c90(L, FUN_00212d70(L) - f.arg);
    }
    FUN_00213c90(L, FUN_00212d70(L) - f.arg);
    __security_check_cookie(f.cookie);
    return 1;
}
