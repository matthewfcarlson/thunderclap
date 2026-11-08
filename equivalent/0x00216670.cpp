// STATUS: equivalent (tools/equiv.py level 3: 77 inputs, branch coverage 44/54, incomplete)
// traversetable: mark a table's metatable, keys and values (weak tables by __mode go onto g->weak); 1 when weak.
extern "C" char* __cdecl strchr(const char*, int);
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_002164b0(LuaVMGlobal* g, LuaVMGCObject* o);
extern "C" const LuaVMTObject* __cdecl FUN_00217580(LuaVMTable* events, int event, LuaVMString* ename);

// equiv-conv: FUN_00216670 edi stack
extern "C" int __cdecl FUN_00216670(LuaVMTable* h, LuaVMGlobal* g) {
    int weakkey = 0;
    int weakvalue = 0;

    if (h->metatable && (h->metatable->marked & 3))
        FUN_002164b0(g, (LuaVMGCObject*)h->metatable);

    LuaVMTable* mt = h->metatable;
    if (mt && !(mt->flags & 8)) {
        const LuaVMTObject* mode = FUN_00217580(mt, 3, g->tmname[3]);
        if (mode && mode->tt == LUAVM_TSTRING) {
            weakkey = strchr(LUAVM_GETSTR(mode->value.gc), 'k') != 0;
            weakvalue = strchr(LUAVM_GETSTR(mode->value.gc), 'v') != 0;
            if (weakkey || weakvalue) {
                h->marked = (h->marked & 0xe7) | (((weakvalue << 1) | weakkey) << 3);
                h->gclist = g->weak;
                g->weak = (LuaVMGCObject*)h;
            }
            if (weakkey && weakvalue)
                return 1;
        }
    }

    if (!weakvalue) {
        int i = h->sizearray;
        while (i != 0) {
            i--;
            LuaVMTObject* v = &h->array[i];
            if (v->tt >= LUAVM_TSTRING && (v->value.gc->marked & 3))
                FUN_002164b0(g, v->value.gc);
        }
    }

    int n = 1 << h->lsizenode;
    while (n != 0) {
        n--;
        LuaVMNode* nd = &h->node[n];
        if (nd->i_val.tt == LUAVM_TNIL) {
            int keytt = nd->i_key.tt;
            nd->i_val.tt = LUAVM_TNIL;
            if (keytt >= LUAVM_TSTRING)
                nd->i_key.tt = -1;
        } else {
            if (!weakkey && nd->i_key.tt >= LUAVM_TSTRING && (nd->i_key.value.gc->marked & 3))
                FUN_002164b0(g, nd->i_key.value.gc);
            if (!weakvalue && nd->i_val.tt >= LUAVM_TSTRING && (nd->i_val.value.gc->marked & 3))
                FUN_002164b0(g, nd->i_val.value.gc);
        }
    }
    return weakkey || weakvalue;
}
