// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_0033c1d0 @ 0x0033c1d0
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern unsigned int DAT_004d9968;

// Lua 5.0 str_dump
struct lua_State;
struct luaL_Buffer_33c1d0 {
    char* p;
    int lvl;
    lua_State* L;
    char buffer[0x200];
};

extern "C" void __cdecl FUN_00339d70(lua_State* L, int narg, int type);               // luaL_checktype
extern "C" void __cdecl FUN_00339630(lua_State* L, luaL_Buffer_33c1d0* B);                   // luaL_buffinit
extern "C" int __cdecl FUN_00213b60(lua_State* L, int (*writer)(), void* data);       // lua_dump
extern "C" int __cdecl FUN_0033c1b0();                                                // writer
extern "C" int __cdecl FUN_00338e20(lua_State* L, const char* msg);                   // luaL_error
extern "C" void __cdecl FUN_00339540(luaL_Buffer_33c1d0* B);                                 // luaL_pushresult

struct Frame_33c1d0 {
    luaL_Buffer_33c1d0 b;
    unsigned int cookie;
};

int FUN_0033c1d0(lua_State* L) {
    Frame_33c1d0 fr;
    fr.cookie = DAT_004d9968;
    FUN_00339d70(L, 1, 6);
    FUN_00339630(L, &fr.b);
    if (!FUN_00213b60(L, FUN_0033c1b0, &fr.b))
        FUN_00338e20(L, "unable to dump given function");
    FUN_00339540(&fr.b);
    __security_check_cookie(fr.cookie);
    return 1;
}
