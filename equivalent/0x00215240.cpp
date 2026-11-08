// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 7/7)
// seterrorobj: the error object of a failed protected call at oldtop (the message, or the fixed memory /
// error-handler messages), and the top just above it.
#include "decls/data/lua.h"

extern "C" LuaVMString* __cdecl FUN_00219430(LuaVMState* L, const char* str, unsigned int l);

// equiv-conv: FUN_00215240 eax ecx edi
extern "C" void __cdecl FUN_00215240(int errcode, LuaVMTObject* oldtop, LuaVMState* L) {
    if (errcode == 1 || errcode == 3) {
        LUAVM_SETOBJ(oldtop, L->top - 1);
    } else if (errcode == 4) {
        oldtop->value.gc = (LuaVMGCObject*)FUN_00219430(L, "not enough memory", 0x11);
        oldtop->tt = LUAVM_TSTRING;
    } else if (errcode == 5) {
        oldtop->value.gc = (LuaVMGCObject*)FUN_00219430(L, "error in error handling", 0x17);
        oldtop->tt = LUAVM_TSTRING;
    }
    L->top = oldtop + 1;
}
