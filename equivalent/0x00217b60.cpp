// STATUS: equivalent (tools/equiv.py level 3: 3009 inputs, branch coverage 14/14)
// get_compTM: the comparison metamethod shared by two metatables, or 0.
#include "decls/data/lua.h"

extern "C" const LuaVMTObject* __cdecl FUN_00217580(LuaVMTable* events, int event, LuaVMString* ename);
extern "C" int __cdecl FUN_00215fa0(const LuaVMTObject* t1, const LuaVMTObject* t2);

// equiv-conv: FUN_00217b60 edi esi ebx stack
extern "C" const LuaVMTObject* __cdecl FUN_00217b60(LuaVMTable* mt1, int event, LuaVMTable* mt2, LuaVMState* L) {
    if (mt1 == 0 || (mt1->flags & (1 << event)) != 0)
        return 0;
    const LuaVMTObject* tm1 = FUN_00217580(mt1, event, L->l_G->tmname[event]);
    if (tm1 == 0)
        return 0;
    if (mt1 == mt2)
        return tm1;
    if (mt2 == 0 || (mt2->flags & (1 << event)) != 0)
        return 0;
    const LuaVMTObject* tm2 = FUN_00217580(mt2, event, L->l_G->tmname[event]);
    if (tm2 == 0)
        return 0;
    if (FUN_00215fa0(tm1, tm2))
        return tm1;
    return 0;
}
