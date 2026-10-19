// Lua 5.0 luaD_throw
struct lua_State;
struct lua_longjmp {
    char pad[4];
    char b[0x40];       // jmp_buf at +4
    int status;         // +0x44
};
struct global_State {
    char pad[0x50];
    int (__cdecl *panic)(lua_State*);
};
struct lua_State {
    char pad0[0x10];
    global_State* l_G;
    char pad14[0x3c];
    lua_longjmp* errorJmp;
};

extern "C" __declspec(noreturn) void __cdecl _longjmp(void* env, int value);
__declspec(noreturn) void __cdecl FUN_003471a3(int code);

lua_State* __cdecl FUN_002152b0(lua_State* L, int errcode)
{
    if (L->errorJmp) {
        L->errorJmp->status = errcode;
        _longjmp(L->errorJmp->b, 1);
    }
    if (L->l_G->panic)
        L->l_G->panic(L);
    FUN_003471a3(1);
    return L;
}
