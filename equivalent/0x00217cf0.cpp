// STATUS: equivalent (tools/equiv.py level 3: 3032 inputs, branch coverage 12/12)
// luaV_lessthan: l < r for numbers, strings or by __lt.
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_00214d80(LuaVMState* L, const LuaVMTObject* p1, const LuaVMTObject* p2);
// equiv-conv: FUN_00217be0 eax stack stack ebx
extern "C" int __cdecl FUN_00217be0(LuaVMState* L, const LuaVMTObject* p1, int event, const LuaVMTObject* p2);
// equiv-conv: FUN_00217c80 ecx eax
extern "C" int __cdecl FUN_00217c80(const LuaVMString* ls, const LuaVMString* rs);

extern "C" int __cdecl FUN_00217cf0(LuaVMState* L, const LuaVMTObject* l, const LuaVMTObject* r) {
    if (l->tt != r->tt)
        return FUN_00214d80(L, l, r);
    if (l->tt == LUAVM_TNUMBER)
        return l->value.n < r->value.n;
    if (l->tt == LUAVM_TSTRING)
        return FUN_00217c80((const LuaVMString*)l->value.gc, (const LuaVMString*)r->value.gc) < 0;
    int res = FUN_00217be0(L, l, 0xb, r);
    if (res == -1)
        return FUN_00214d80(L, l, r);
    return res;
}
