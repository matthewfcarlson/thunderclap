// STATUS: equivalent (tools/equiv.py level 3: 3058 inputs, branch coverage 16/16)
// luaC_separateudata: move the dead (or, with all, every) userdata with a __gc metamethod onto g->tmudata; the bytes.
#include "decls/data/lua.h"

extern "C" const LuaVMTObject* __cdecl FUN_00217580(LuaVMTable* events, int event, LuaVMString* ename);

extern "C" unsigned int __cdecl FUN_002165c0(LuaVMState* L, int all) {
    unsigned int deadmem = 0;
    LuaVMGCObject** p = &L->l_G->firstudata;
    LuaVMGCObject* curr = *p;
    LuaVMGCObject* collected = 0;
    LuaVMGCObject** lastcollected = &collected;
    while (curr->tt == LUAVM_TUSERDATA) {
        unsigned char m = curr->marked;
        if (((m & 3) == 0 && all == 0) || (m & 8)) {
            p = &curr->next;
        } else {
            LuaVMTable* mt = ((LuaVMUdata*)curr)->metatable;
            if (mt == 0 || (mt->flags & 4) != 0 || FUN_00217580(mt, 2, L->l_G->tmname[2]) == 0) {
                curr->marked |= 8;
                p = &curr->next;
            } else {
                deadmem += ((LuaVMUdata*)curr)->len + (unsigned int)sizeof(LuaVMUdata);
                LuaVMGCObject* next = curr->next;
                curr->marked |= 8;
                *p = next;
                curr->next = 0;
                *lastcollected = curr;
                lastcollected = &curr->next;
            }
        }
        curr = *p;
    }
    *lastcollected = L->l_G->tmudata;
    L->l_G->tmudata = collected;
    return deadmem;
}
