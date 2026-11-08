// STATUS: equivalent (tools/equiv.py level 3: 2976 inputs, branch coverage 4/4)
// resume_error: the error message as lua_resume's only result.
#include "decls/data/lua.h"

extern "C" LuaVMString* __cdecl FUN_00219430(LuaVMState* L, const char* str, unsigned int l);
extern "C" void __cdecl FUN_00215460(LuaVMState* L, int n);

// equiv-conv: FUN_00215b00 esi edx
extern "C" int __cdecl FUN_00215b00(LuaVMState* L, const char* msg) {
    LuaVMTObject* o = L->ci->base;
    L->top = o;
    const char* p = msg;
    while (*p)
        ++p;
    o->value.gc = (LuaVMGCObject*)FUN_00219430(L, msg, (unsigned int)(p - msg));
    o->tt = LUAVM_TSTRING;
    if ((char*)L->stack_last - (char*)L->top <= (int)sizeof(LuaVMTObject))
        FUN_00215460(L, 1);
    L->top++;
    return 1;
}
