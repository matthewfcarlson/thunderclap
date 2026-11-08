// STATUS: equivalent (tools/equiv.py level 3: 131 inputs, branch coverage 43/44, incomplete)
// cleartable: remove the collected keys and values from the weak tables on the list l (by gclist).
#include "decls/data/lua.h"

// equiv-conv: FUN_00216c40 eax
extern "C" void __cdecl FUN_00216c40(LuaVMGCObject* l) {
    while (l) {
        LuaVMTable* h = (LuaVMTable*)l;
        if (h->marked & 0x10) {
            unsigned int i = (unsigned int)h->sizearray;
            while (i) {
                LuaVMTObject* o = &h->array[--i];
                if (o->tt == LUAVM_TSTRING)
                    o->value.gc->marked &= 0xfc;
                else if (o->tt > LUAVM_TSTRING) {
                    unsigned char m = o->value.gc->marked;
                    if ((m & 3) || (o->tt == LUAVM_TUSERDATA && (m & 8)))
                        o->tt = LUAVM_TNIL;
                }
            }
        }
        unsigned int n = 1u << (h->lsizenode & 31);
        while (n) {
            LuaVMNode* nd = &h->node[--n];
            if (!nd->i_val.tt)
                continue;
            bool remove = false;
            if (nd->i_key.tt == LUAVM_TSTRING)
                nd->i_key.value.gc->marked &= 0xfc;
            else if (nd->i_key.tt > LUAVM_TSTRING && (nd->i_key.value.gc->marked & 3))
                remove = true;
            if (!remove) {
                if (nd->i_val.tt == LUAVM_TSTRING)
                    nd->i_val.value.gc->marked &= 0xfc;
                else if (nd->i_val.tt > LUAVM_TSTRING) {
                    unsigned char m = nd->i_val.value.gc->marked;
                    if ((m & 3) || (nd->i_val.tt == LUAVM_TUSERDATA && (m & 8)))
                        remove = true;
                }
            }
            if (remove) {
                nd->i_val.tt = LUAVM_TNIL;
                if (nd->i_key.tt >= LUAVM_TSTRING)
                    nd->i_key.tt = -1;
            }
        }
        l = h->gclist;
    }
}
