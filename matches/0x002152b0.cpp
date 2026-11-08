// luaD_throw: long-jump to the innermost protected call, else the panic function and exit.
#include "decls/data/lua.h"

extern "C" __declspec(noreturn) void __cdecl _longjmp(void* env, int value);
__declspec(noreturn) void __cdecl FUN_003471a3(int code);

extern "C" LuaVMState* __cdecl FUN_002152b0(LuaVMState* L, int errcode) {
    if (L->errorJmp) {
        L->errorJmp->status = errcode;
        _longjmp(L->errorJmp->b, 1);
    }
    if (L->l_G->panic)
        L->l_G->panic(L);
    FUN_003471a3(1);
    return L;
}
