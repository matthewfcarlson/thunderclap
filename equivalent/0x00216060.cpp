// STATUS: equivalent (tools/equiv.py level 3: 2990 inputs, branch coverage 4/4)
// pushstr: push the string str (luaO_pushvfstring's helper).
#include "decls/data/lua.h"

extern "C" LuaVMString* __cdecl FUN_00219430(LuaVMState* L, const char* str, unsigned int l);
extern "C" void __cdecl FUN_00215460(LuaVMState* L, int n);

// equiv-conv: FUN_00216060 esi edx
extern "C" void __cdecl FUN_00216060(LuaVMState* L, const char* str) {
    const char* p = str;
    while (*p)
        ++p;
    LuaVMTObject* o = L->top;
    o->value.gc = (LuaVMGCObject*)FUN_00219430(L, str, (unsigned int)(p - str));
    o->tt = LUAVM_TSTRING;
    if ((char*)L->stack_last - (char*)L->top <= (int)sizeof(LuaVMTObject))
        FUN_00215460(L, 1);
    L->top++;
}
