// STATUS: equivalent (tools/equiv.py level 3: 96 inputs, branch coverage 23/24, incomplete)
// FUN_0033a080 @ 0x0033a080
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern unsigned int DAT_004d9968;

struct lua_State;

struct lua_Debug_33a080 {
    int event;
    const char *name;
    const char *namewhat;
    const char *what;
    const char *source;
    int currentline;
    int nups;
    int linedefined;
    char short_src[60];
    int i_ci;
};

int FUN_00212f00(lua_State *L, int idx);
lua_State *FUN_00213290(lua_State *L, int idx);
const char *FUN_00339e60(lua_State *L, int narg, const char *def, unsigned int *len);
int FUN_00212f70(lua_State *L, int idx);
int FUN_00213120(lua_State *L, int idx);
int FUN_00213fc0(lua_State *L, int level, lua_Debug_33a080 *ar);
void FUN_00213320(lua_State *L);
const char *FUN_00213470(lua_State *L, const char *fmt, ...);
const char *FUN_00213190(lua_State *L, int idx);
void FUN_00212ed0(lua_State *L, int idx);
void FUN_00212cb0(lua_State *from, lua_State *to, int n);
int FUN_00214bd0(lua_State *L, const char *what, lua_Debug_33a080 *ar);
int FUN_00339c30(lua_State *L, int narg, const char *msg);
void FUN_00213680(lua_State *L, int narr, int nrec);
void FUN_002133d0(lua_State *L, const char *s);
void FUN_00213360(lua_State *L, int n);
void FUN_00213790(lua_State *L, int idx, const char *k);

int FUN_0033a080(lua_State *L)
{
    unsigned int cookie = DAT_004d9968;
    lua_Debug_33a080 ar;
    lua_State *L1;
    int arg;
    if (FUN_00212f00(L, 1) == 8) {
        arg = 1;
        L1 = FUN_00213290(L, 1);
    } else {
        arg = 0;
        L1 = L;
    }
    const char *options = FUN_00339e60(L, arg + 2, "flnSu", 0);
    if (FUN_00212f70(L, arg + 1)) {
        if (!FUN_00213fc0(L1, FUN_00213120(L, arg + 1), &ar)) {
            FUN_00213320(L);
            __security_check_cookie(cookie);
            return 1;
        }
    } else if (FUN_00212f00(L, arg + 1) == 6) {
        FUN_00213470(L, ">%s", options);
        options = FUN_00213190(L, -1);
        FUN_00212ed0(L, arg + 1);
        FUN_00212cb0(L, L1, 1);
    } else {
        int r = FUN_00339c30(L, arg + 1, "function or level expected");
        __security_check_cookie(cookie);
        return r;
    }
    if (!FUN_00214bd0(L1, options, &ar)) {
        int r = FUN_00339c30(L, arg + 2, "invalid option");
        __security_check_cookie(cookie);
        return r;
    }
    FUN_00213680(L, 0, 0);
    for (; *options; options++) {
        switch (*options) {
        case 'S':
            FUN_002133d0(L, ar.source);
            FUN_00213790(L, -2, "source");
            FUN_002133d0(L, ar.short_src);
            FUN_00213790(L, -2, "short_src");
            FUN_00213360(L, ar.linedefined);
            FUN_00213790(L, -2, "linedefined");
            FUN_002133d0(L, ar.what);
            FUN_00213790(L, -2, "what");
            break;
        case 'l':
            FUN_00213360(L, ar.currentline);
            FUN_00213790(L, -2, "currentline");
            break;
        case 'u':
            FUN_00213360(L, ar.nups);
            FUN_00213790(L, -2, "nups");
            break;
        case 'n':
            FUN_002133d0(L, ar.name);
            FUN_00213790(L, -2, "name");
            FUN_002133d0(L, ar.namewhat);
            FUN_00213790(L, -2, "namewhat");
            break;
        case 'f':
            if (L == L1)
                FUN_00212ed0(L, -2);
            else
                FUN_00212cb0(L1, L, 1);
            FUN_00213790(L, -2, "func");
            break;
        default:
            break;
        }
    }
    __security_check_cookie(cookie);
    return 1;
}
