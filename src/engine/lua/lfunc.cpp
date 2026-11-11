// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00219520..0x00219870 (kind game, layer engine, confidence high)
#include "tree_prelude.h"
#include "decls/data/lua.h"
#define TREE_TU_BEGIN namespace fn_fcbb1975 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fcbb1975 {} using namespace fn_fcbb1975;
#include "engine/lua.h"

// ---- declarations shared by the functions below
namespace fn_fcbb1975 {
extern "C" void* __cdecl FUN_0021add0(LuaVMState* L, void* block, unsigned int osize, unsigned int nsize);
extern "C" void __cdecl FUN_00217130(LuaVMState* L, LuaVMGCObject* o, unsigned char tt);
extern "C" void __cdecl FUN_00217160(LuaVMState* L, LuaVMGCObject* o);


// 0x00219520 FUN_00219520 (56 B): matches/0x00219520.cpp
// sym: _FUN_00219520
// luaF_newCclosure: a C closure with nelems upvalues.
extern "C" LuaVMClosure* __cdecl FUN_00219520(LuaVMState* L, int nelems) {
    LuaVMClosure* c = (LuaVMClosure*)FUN_0021add0(L, 0, 0, LUAVM_SIZECCLOSURE(nelems));
    FUN_00217130(L, (LuaVMGCObject*)c, LUAVM_TFUNCTION);
    c->c.nupvalues = (unsigned char)nelems;
    c->c.isC = 1;
    return c;
}


// 0x00219560 FUN_00219560 (99 B): matches/0x00219560.cpp
// sym: _FUN_00219560
// luaF_newLclosure: a Lua closure with nelems (cleared) upvalue pointers and the globals table e.
extern "C" LuaVMClosure* __cdecl FUN_00219560(LuaVMState* L, int nelems, const LuaVMTObject* e) {
    int size = LUAVM_SIZELCLOSURE(nelems);
    LuaVMClosure* c = (LuaVMClosure*)FUN_0021add0(L, 0, 0, size);
    FUN_00217130(L, (LuaVMGCObject*)c, LUAVM_TFUNCTION);
    c->l.isC = 0;
    LUAVM_SETOBJ(&c->l.g, e);
    c->l.nupvalues = (unsigned char)nelems;
    if (nelems != 0) {
        LuaVMUpVal** p = c->l.upvals + nelems;
        do {
            --p;
            --nelems;
            *p = 0;
        } while (nelems != 0);
    }
    return c;
}


// 0x002195d0 FUN_002195d0 (49 B): matches/0x002195d0.cpp
// sym: _FUN_002195d0
// luaF_newupval: a closed upvalue holding nil.
extern "C" LuaVMUpVal* __cdecl FUN_002195d0(LuaVMState* L) {
    LuaVMUpVal* uv = (LuaVMUpVal*)FUN_0021add0(L, 0, 0, sizeof(LuaVMUpVal));
    FUN_00217130(L, (LuaVMGCObject*)uv, LUAVM_TUPVAL);
    uv->v = &uv->value;
    uv->value.tt = LUAVM_TNIL;
    return uv;
}


// 0x00219610 FUN_00219610 (79 B): matches/0x00219610.cpp
// sym: _FUN_00219610
// luaF_findupval: the open upvalue for stack slot level (the list is ordered by level, highest first), made if absent.
extern "C" LuaVMUpVal* __cdecl FUN_00219610(LuaVMState* L, LuaVMTObject* level) {
    LuaVMUpVal* p = (LuaVMUpVal*)L->openupval;
    LuaVMGCObject** pp = &L->openupval;
    while (p != 0 && p->v >= level) {
        if (p->v == level)
            return p;
        pp = &p->next;
        p = (LuaVMUpVal*)p->next;
    }
    LuaVMUpVal* v = (LuaVMUpVal*)FUN_0021add0(L, 0, 0, sizeof(LuaVMUpVal));
    v->tt = LUAVM_TUPVAL;
    v->marked = (unsigned char)L->l_G->currentwhite;
    v->v = level;
    v->next = *pp;
    *pp = (LuaVMGCObject*)v;
    return v;
}


// 0x00219660 FUN_00219660 (102 B): matches/0x00219660.cpp
// sym: _FUN_00219660
// luaF_close: close the open upvalues at or above level (copy the slot into the upvalue; free the dead ones).
extern "C" void __cdecl FUN_00219660(LuaVMState* L, LuaVMTObject* level) {
    LuaVMGlobal* g = L->l_G;
    LuaVMUpVal* uv = (LuaVMUpVal*)L->openupval;
    while (uv && uv->v >= level) {
        L->openupval = uv->next;
        if (uv->marked & (g->currentwhite ^ 3)) {
            FUN_0021add0(L, uv, sizeof(LuaVMUpVal), 0);
        } else {
            LUAVM_SETOBJ(&uv->value, uv->v);
            uv->v = &uv->value;
            FUN_00217160(L, (LuaVMGCObject*)uv);
        }
        uv = (LuaVMUpVal*)L->openupval;
    }
}


// 0x002196d0 FUN_002196d0 (93 B): matches/0x002196d0.cpp
// sym: _FUN_002196d0
// luaF_newproto: an empty function prototype.
extern "C" LuaVMProto* __cdecl FUN_002196d0(LuaVMState* L) {
    LuaVMProto* f = (LuaVMProto*)FUN_0021add0(L, 0, 0, sizeof(LuaVMProto));
    FUN_00217130(L, (LuaVMGCObject*)f, LUAVM_TPROTO);
    f->k = 0;
    f->sizek = 0;
    f->p = 0;
    f->sizep = 0;
    f->code = 0;
    f->sizecode = 0;
    f->sizelineinfo = 0;
    f->sizeupvalues = 0;
    f->nups = 0;
    f->upvalues = 0;
    f->numparams = 0;
    f->is_vararg = 0;
    f->maxstacksize = 0;
    f->lineinfo = 0;
    f->sizelocvars = 0;
    f->locvars = 0;
    f->lineDefined = 0;
    f->source = 0;
    return f;
}


// 0x00219730 FUN_00219730 (147 B): matches/0x00219730.cpp
// sym: _FUN_00219730
// luaF_freeproto: free a prototype's arrays and the prototype.
extern "C" void __cdecl FUN_00219730(LuaVMState* L, LuaVMProto* f) {
    FUN_0021add0(L, f->code, f->sizecode * (unsigned int)sizeof(LuaVMInstruction), 0);
    FUN_0021add0(L, f->p, f->sizep * (unsigned int)sizeof(LuaVMProto*), 0);
    FUN_0021add0(L, f->k, f->sizek * (unsigned int)sizeof(LuaVMTObject), 0);
    FUN_0021add0(L, f->lineinfo, f->sizelineinfo * (unsigned int)sizeof(int), 0);
    FUN_0021add0(L, f->locvars, f->sizelocvars * (unsigned int)sizeof(LuaVMLocVar), 0);
    FUN_0021add0(L, f->upvalues, f->sizeupvalues * (unsigned int)sizeof(LuaVMString*), 0);
    FUN_0021add0(L, f, sizeof(LuaVMProto), 0);
}


// 0x002197d0 FUN_002197d0 (65 B): matches/0x002197d0.cpp
// sym: _FUN_002197d0
// luaF_freeclosure: free a C or Lua closure by its size.
extern "C" void __cdecl FUN_002197d0(LuaVMState* L, LuaVMClosure* c) {
    FUN_0021add0(L, c,
                 c->c.isC ? (unsigned int)LUAVM_SIZECCLOSURE(c->c.nupvalues)
                          : (unsigned int)LUAVM_SIZELCLOSURE(c->l.nupvalues),
                 0);
}


// 0x00219820 FUN_00219820 (71 B): matches/0x00219820.cpp
// sym: _FUN_00219820
// luaF_getlocalname: the name of the local_number-th local variable active at pc, or 0.
extern "C" const char* __cdecl FUN_00219820(const LuaVMProto* f, int local_number, int pc) {
    int i;
    for (i = 0; i < f->sizelocvars && f->locvars[i].startpc <= pc; i++) {
        if (pc < f->locvars[i].endpc) {
            local_number--;
            if (local_number == 0)
                return LUAVM_GETSTR(f->locvars[i].varname);
        }
    }
    return 0;
}

} // namespace fn_fcbb1975
