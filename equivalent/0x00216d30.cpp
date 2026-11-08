// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 9/9)
// freeobj: free a collectable object by its type.
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_00219730(LuaVMState* L, LuaVMProto* f);
extern "C" void __cdecl FUN_002197d0(LuaVMState* L, LuaVMClosure* c);
extern "C" void* __cdecl FUN_0021add0(LuaVMState* L, void* block, unsigned int osize, unsigned int nsize);
extern "C" void __cdecl FUN_00219d20(LuaVMState* L, LuaVMTable* t);
extern "C" void __cdecl FUN_00215090(LuaVMState* L, LuaVMState* L1);

// equiv-conv: FUN_00216d30 ecx eax
extern "C" void __cdecl FUN_00216d30(LuaVMState* L, LuaVMGCObject* o) {
    switch (o->tt) {
    case LUAVM_TSTRING:
        FUN_0021add0(L, o, ((LuaVMString*)o)->len + (unsigned int)sizeof(LuaVMString) + 1, 0);
        break;
    case LUAVM_TTABLE:
        FUN_00219d20(L, (LuaVMTable*)o);
        break;
    case LUAVM_TFUNCTION:
        FUN_002197d0(L, (LuaVMClosure*)o);
        break;
    case LUAVM_TUSERDATA:
        FUN_0021add0(L, o, ((LuaVMUdata*)o)->len + (unsigned int)sizeof(LuaVMUdata), 0);
        break;
    case LUAVM_TTHREAD:
        FUN_00215090(L, (LuaVMState*)o);
        break;
    case LUAVM_TPROTO:
        FUN_00219730(L, (LuaVMProto*)o);
        break;
    case LUAVM_TUPVAL:
        FUN_0021add0(L, o, sizeof(LuaVMUpVal), 0);
        break;
    }
}
