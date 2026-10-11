// STATUS: equivalent (tools/equiv.py level 3: 110 inputs, branch coverage 14/14)
// FUN_0033e250 @ 0x0033e250
extern "C" unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern "C" int sprintf(char* buf, const char* fmt, ...);

struct lua_State;
void FUN_00339dc0(lua_State* L, int idx);
int FUN_00339070(lua_State* L, int idx, const char* event);
int FUN_00212f00(lua_State* L, int idx);
const char* FUN_00213190(lua_State* L, int idx);
void FUN_002133d0(lua_State* L, const char* s);
void FUN_00212ed0(lua_State* L, int idx);
int FUN_00213160(lua_State* L, int idx);
void FUN_00213380(lua_State* L, const char* s, int len);
const void* FUN_002132b0(lua_State* L, int idx);
void* FUN_00213260(lua_State* L, int idx);
lua_State* FUN_00213290(lua_State* L, int idx);
const char* FUN_00213470(lua_State* L, const char* fmt, ...);

int FUN_0033e250(lua_State* L)
{
    unsigned int cookie = DAT_004d9968;
    char buff[20];
    const char* name = "";
    const void* ptr = 0;

    FUN_00339dc0(L, 1);
    if (FUN_00339070(L, 1, "__tostring") != 0) {
        __security_check_cookie(cookie);
        return 1;
    }
    switch (FUN_00212f00(L, 1)) {
    case 3:
        FUN_002133d0(L, FUN_00213190(L, 1));
        __security_check_cookie(cookie);
        return 1;
    case 4:
        FUN_00212ed0(L, 1);
        __security_check_cookie(cookie);
        return 1;
    case 1:
        FUN_002133d0(L, FUN_00213160(L, 1) != 0 ? "true" : "false");
        __security_check_cookie(cookie);
        return 1;
    case 0:
        FUN_00213380(L, "nil", 3);
        __security_check_cookie(cookie);
        return 1;
    case 5:
        ptr = FUN_002132b0(L, 1);
        name = "table";
        break;
    case 6:
        ptr = FUN_002132b0(L, 1);
        name = "function";
        break;
    case 2:
    case 7:
        ptr = FUN_00213260(L, 1);
        name = "userdata";
        break;
    case 8:
        ptr = FUN_00213290(L, 1);
        name = "thread";
        break;
    default:
        break;
    }
    sprintf(buff, "%p", ptr);
    FUN_00213470(L, "%s: %s", name, buff);
    __security_check_cookie(cookie);
    return 1;
}
