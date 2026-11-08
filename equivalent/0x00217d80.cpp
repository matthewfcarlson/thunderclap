// STATUS: equivalent (tools/equiv.py level 3: 3034 inputs, branch coverage 16/16)
// luaV_lessequal: l <= r for numbers, strings, by __le or by not (r < l).
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_00214d80(LuaVMState* L, const LuaVMTObject* p1, const LuaVMTObject* p2);
// equiv-conv: FUN_00217be0 eax stack stack ebx
extern "C" int __cdecl FUN_00217be0(LuaVMState* L, const LuaVMTObject* p1, int event, const LuaVMTObject* p2);
// equiv-conv: FUN_00217c80 ecx eax
extern "C" int __cdecl FUN_00217c80(const LuaVMString* ls, const LuaVMString* rs);

// equiv-conv: FUN_00217d80 edi esi stack
extern "C" int __cdecl FUN_00217d80(const LuaVMTObject* l, const LuaVMTObject* r, LuaVMState* L) {
    if (l->tt != r->tt)
        return FUN_00214d80(L, l, r);
    if (l->tt == LUAVM_TNUMBER)
        return l->value.n <= r->value.n;
    if (l->tt == LUAVM_TSTRING)
        return FUN_00217c80((const LuaVMString*)l->value.gc, (const LuaVMString*)r->value.gc) <= 0;
    int res = FUN_00217be0(L, l, 0xc, r);
    if (res != -1)
        return res;
    res = FUN_00217be0(L, r, 0xb, l);
    if (res != -1)
        return res == 0;
    return FUN_00214d80(L, l, r);
}
