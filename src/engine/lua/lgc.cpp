// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002164b0..0x00217520 (kind game, layer engine, confidence high)
#include "tree_prelude.h"
#include "decls/data/lua.h"
#define TREE_TU_BEGIN namespace fn_f29d11ae {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f29d11ae {} using namespace fn_f29d11ae;
#include "engine/lua.h"

// ---- declarations shared by the functions below
namespace fn_f29d11ae {
extern "C" const LuaVMTObject* __cdecl FUN_00217580(LuaVMTable* events, int event, LuaVMString* ename);
extern "C" void __cdecl FUN_002164b0(LuaVMGlobal* g, LuaVMGCObject* o);
extern "C" void __cdecl FUN_00215410(LuaVMState* L, int newsize);
extern "C" void __cdecl FUN_002153d0(LuaVMState* L, int newsize);
extern "C" int __cdecl FUN_00216670(LuaVMTable* h, LuaVMGlobal* g);
extern "C" void __cdecl FUN_002168d0(LuaVMClosure* cl, LuaVMGlobal* g);
extern "C" void __cdecl FUN_002169e0(LuaVMState* L, LuaVMGlobal* g);
extern "C" void __cdecl FUN_00216810(LuaVMProto* f, LuaVMGlobal* g);
extern "C" void __cdecl FUN_00219730(LuaVMState* L, LuaVMProto* f);
extern "C" void __cdecl FUN_002197d0(LuaVMState* L, LuaVMClosure* c);
extern "C" void* __cdecl FUN_0021add0(LuaVMState* L, void* block, unsigned int osize, unsigned int nsize);
extern "C" void __cdecl FUN_00219d20(LuaVMState* L, LuaVMTable* t);
extern "C" void __cdecl FUN_00215090(LuaVMState* L, LuaVMState* L1);
extern "C" void __cdecl FUN_002192e0(LuaVMState* L, int newsize);
extern "C" void __cdecl FUN_002159e0(LuaVMState* L, LuaVMTObject* func, int nresults);
extern "C" void __cdecl FUN_00216ed0(LuaVMState* L);
extern "C" void __cdecl FUN_00216ff0(LuaVMGlobal* g);
extern "C" int __cdecl FUN_00216ac0(int lim, LuaVMGlobal* g);
extern "C" unsigned int __cdecl FUN_002165c0(LuaVMState* L, int all);
extern "C" void __cdecl FUN_00216c40(LuaVMGCObject* l);
extern "C" void __cdecl FUN_00217100(LuaVMState* L, LuaVMGCObject* o, LuaVMGCObject* v);
extern "C" void __cdecl FUN_00216d30(LuaVMState* L, LuaVMGCObject* o);
extern "C++" __declspec(nothrow) int __cdecl FUN_00216e10(int all, int lim, LuaVMState* L);
extern "C" LuaVMGCObject** __cdecl FUN_002171c0(LuaVMState* L, LuaVMGCObject** p, int all, int* lim, int* count);
extern "C" void __cdecl FUN_00217050(LuaVMState* L);
extern "C" void __cdecl FUN_00216e70(LuaVMState* L);
extern "C" void __cdecl FUN_00216f90(LuaVMState* L);
extern "C" int __cdecl FUN_00217350(LuaVMState* L, int lim);


// 0x002164b0 FUN_002164b0 (193 B): equivalent/0x002164b0.cpp
// sym: _FUN_002164b0
// STATUS: equivalent (tools/equiv.py level 3: 3026 inputs, branch coverage 21/21)
// reallymarkobject: make a white object gray (onto g->gray) or black (strings, userdata, closed upvalues).
extern "C" void __cdecl FUN_002164b0(LuaVMGlobal* g, LuaVMGCObject* o) {
    o->marked &= 0xfc;
    for (;;) {
        switch (o->tt) {
        case LUAVM_TUSERDATA: {
            unsigned char m = o->marked;
            LuaVMTable* mt = ((LuaVMUdata*)o)->metatable;
            o->marked = m | 4;
            if (!mt || !(mt->marked & 3))
                return;
            mt->marked &= 0xfc;
            o = (LuaVMGCObject*)mt;
            break;
        }
        case LUAVM_TUPVAL: {
            LuaVMUpVal* uv = (LuaVMUpVal*)o;
            LuaVMTObject* v = uv->v;
            if (v != &uv->value)
                return;
            if (v->tt >= LUAVM_TSTRING) {
                LuaVMGCObject* gc = v->value.gc;
                if (gc->marked & 3)
                    FUN_002164b0(g, gc);
            }
            o->marked |= 4;
            return;
        }
        case LUAVM_TFUNCTION:
            ((LuaVMCClosure*)o)->gclist = g->gray;
            g->gray = o;
            return;
        case LUAVM_TTABLE:
            ((LuaVMTable*)o)->gclist = g->gray;
            g->gray = o;
            return;
        case LUAVM_TTHREAD:
            ((LuaVMState*)o)->gclist = g->gray;
            g->gray = o;
            return;
        case LUAVM_TPROTO:
            ((LuaVMProto*)o)->gclist = g->gray;
            g->gray = o;
            return;
        default:
            return;
        }
    }
}


// 0x002165c0 FUN_002165c0 (164 B): equivalent/0x002165c0.cpp
// sym: _FUN_002165c0
// STATUS: equivalent (tools/equiv.py level 3: 3058 inputs, branch coverage 16/16)
// luaC_separateudata: move the dead (or, with all, every) userdata with a __gc metamethod onto g->tmudata; the bytes.
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


// 0x00216670 FUN_00216670 (414 B): equivalent/0x00216670.cpp
// sym: _FUN_00216670
// STATUS: equivalent (tools/equiv.py level 3: 77 inputs, branch coverage 44/54, incomplete)
// traversetable: mark a table's metatable, keys and values (weak tables by __mode go onto g->weak); 1 when weak.
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


// 0x00216810 FUN_00216810 (191 B): equivalent/0x00216810.cpp
// sym: _FUN_00216810
// STATUS: equivalent (tools/equiv.py level 3: 122 inputs, branch coverage 30/30)
// traverseproto: mark a prototype's source, constants, upvalue names, nested prototypes and local names.
// equiv-conv: FUN_00216810 esi stack
extern "C" void __cdecl FUN_00216810(LuaVMProto* f, LuaVMGlobal* g) {
    if (f->source)
        f->source->marked &= 0xfc;
    for (int i = 0; i < f->sizek; ++i) {
        LuaVMTObject* o = &f->k[i];
        if (o->tt >= LUAVM_TSTRING && (o->value.gc->marked & 3))
            FUN_002164b0(g, o->value.gc);
    }
    for (int i = 0; i < f->sizeupvalues; ++i) {
        LuaVMString* s = f->upvalues[i];
        if (s)
            s->marked &= 0xfc;
    }
    for (int i = 0; i < f->sizep; ++i) {
        LuaVMProto* p = f->p[i];
        if (p && (p->marked & 3))
            FUN_002164b0(g, (LuaVMGCObject*)p);
    }
    for (int i = 0; i < f->sizelocvars; ++i) {
        LuaVMString* s = f->locvars[i].varname;
        if (s)
            s->marked &= 0xfc;
    }
}


// 0x002168d0 FUN_002168d0 (172 B): equivalent/0x002168d0.cpp
// sym: _FUN_002168d0
// STATUS: equivalent (tools/equiv.py level 3: 3010 inputs, branch coverage 20/20)
// traverseclosure: mark a C closure's upvalues, or a Lua closure's globals table, prototype and upvalues.
// equiv-conv: FUN_002168d0 esi stack
extern "C" void __cdecl FUN_002168d0(LuaVMClosure* cl, LuaVMGlobal* g) {
    if (cl->c.isC) {
        for (int i = 0; i < cl->c.nupvalues; ++i) {
            LuaVMTObject* o = &cl->c.upvalue[i];
            if (o->tt >= LUAVM_TSTRING && (o->value.gc->marked & 3))
                FUN_002164b0(g, o->value.gc);
        }
    } else {
        LuaVMGCObject* o = cl->l.g.value.gc;
        if (o->marked & 3)
            FUN_002164b0(g, o);
        o = (LuaVMGCObject*)cl->l.p;
        if (o->marked & 3)
            FUN_002164b0(g, o);
        for (int i = 0; i < cl->l.nupvalues; ++i) {
            o = (LuaVMGCObject*)cl->l.upvals[i];
            if (o->marked & 3)
                FUN_002164b0(g, o);
        }
    }
}


// 0x002169e0 FUN_002169e0 (212 B): equivalent/0x002169e0.cpp
// sym: _FUN_002169e0
// STATUS: equivalent (tools/equiv.py level 3: 145 inputs, branch coverage 30/30)
// traversestack: mark a thread's globals and live stack, clear the slots above, and shrink the CallInfo array and
// the stack when little is used.
// equiv-conv: FUN_002169e0 edi stack
extern "C" void __cdecl FUN_002169e0(LuaVMState* L, LuaVMGlobal* g) {
    if (L->_gt.tt >= LUAVM_TSTRING && (L->_gt.value.gc->marked & 3))
        FUN_002164b0(g, L->_gt.value.gc);
    LuaVMTObject* top = L->top;
    LuaVMTObject* lim = top;
    for (LuaVMCallInfo* ci = L->base_ci; ci <= L->ci; ++ci)
        if (lim < ci->top)
            lim = ci->top;
    LuaVMTObject* o = L->stack;
    if (o < top) {
        do {
            if (o->tt >= LUAVM_TSTRING && (o->value.gc->marked & 3))
                FUN_002164b0(g, o->value.gc);
            ++o;
        } while (o < L->top);
    }
    for (; o <= lim; ++o)
        o->tt = LUAVM_TNIL;
    int ci_used = (int)(L->ci - L->base_ci) * 4;
    unsigned int size_ci = L->size_ci;
    if (ci_used < (int)size_ci && size_ci > 16)
        FUN_00215410(L, (int)(size_ci >> 1));
    int s_used = (int)(lim - L->stack) * 4;
    if (s_used < L->stacksize && L->stacksize > 90)
        FUN_002153d0(L, L->stacksize / 2);
}


// 0x00216ac0 FUN_00216ac0 (296 B): equivalent/0x00216ac0.cpp
// sym: _FUN_00216ac0
// STATUS: equivalent (tools/equiv.py level 3: 1088 inputs, branch coverage 17/17)
// propagatemarks: traverse gray objects (black afterwards; threads go onto grayagain) until lim bytes are done.
// equiv-conv: FUN_00216670 edi stack
// equiv-conv: FUN_002168d0 esi stack
// equiv-conv: FUN_002169e0 edi stack
// equiv-conv: FUN_00216810 esi stack
// equiv-conv: FUN_00216ac0 eax stack
extern "C" int __cdecl FUN_00216ac0(int lim, LuaVMGlobal* g) {
    LuaVMGCObject* o = g->gray;
    if (!o)
        return lim;
    do {
        o->marked |= 4;
        switch (o->tt) {
        case LUAVM_TTABLE: {
            LuaVMTable* h = (LuaVMTable*)o;
            g->gray = h->gclist;
            if (FUN_00216670(h, g))
                o->marked &= ~4;
            lim -= (int)sizeof(LuaVMTable) + (int)sizeof(LuaVMTObject) * h->sizearray +
                   (int)sizeof(LuaVMNode) * (1 << (h->lsizenode & 31));
            break;
        }
        case LUAVM_TFUNCTION: {
            LuaVMClosure* cl = (LuaVMClosure*)o;
            g->gray = cl->c.gclist;
            FUN_002168d0(cl, g);
            lim -= cl->c.isC ? LUAVM_SIZECCLOSURE(cl->c.nupvalues) : LUAVM_SIZELCLOSURE(cl->l.nupvalues);
            break;
        }
        case LUAVM_TTHREAD: {
            LuaVMState* th = (LuaVMState*)o;
            g->gray = th->gclist;
            th->gclist = g->grayagain;
            g->grayagain = o;
            o->marked &= ~4;
            FUN_002169e0(th, g);
            lim -= (int)sizeof(LuaVMState) + (int)sizeof(LuaVMTObject) * th->stacksize +
                   (int)sizeof(LuaVMCallInfo) * th->size_ci;
            break;
        }
        case LUAVM_TPROTO: {
            LuaVMProto* p = (LuaVMProto*)o;
            g->gray = p->gclist;
            FUN_00216810(p, g);
            lim -= (int)sizeof(LuaVMProto) + (int)sizeof(LuaVMInstruction) * p->sizecode +
                   (int)sizeof(LuaVMProto*) * p->sizep + (int)sizeof(LuaVMTObject) * p->sizek +
                   (int)sizeof(int) * p->sizelineinfo + (int)sizeof(LuaVMLocVar) * p->sizelocvars +
                   (int)sizeof(LuaVMString*) * p->sizeupvalues;
            break;
        }
        }
        if (lim <= 0)
            break;
        o = g->gray;
    } while (o);
    return lim;
}


// 0x00216c40 FUN_00216c40 (231 B): equivalent/0x00216c40.cpp
// sym: _FUN_00216c40
// STATUS: equivalent (tools/equiv.py level 3: 131 inputs, branch coverage 43/44, incomplete)
// cleartable: remove the collected keys and values from the weak tables on the list l (by gclist).
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


// 0x00216d30 FUN_00216d30 (118 B): equivalent/0x00216d30.cpp
// sym: _FUN_00216d30
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 9/9)
// freeobj: free a collectable object by its type.
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

} // namespace fn_f29d11ae

// 0x00216e10 FUN_00216e10 (96 B): equivalent/0x00216e10.cpp [wrapped: code differs from its standalone build]
// sym: _FUN_00216e10
namespace fn_00216e10 {
// STATUS: equivalent (tools/equiv.py level 3: 2989 inputs, branch coverage 8/8)
// sweepstrings: sweep the string table's buckets from g->sweepstrgc until lim bytes are done; the budget left.

extern "C++" __declspec(nothrow) LuaVMGCObject** __cdecl FUN_002171c0(LuaVMState* L, LuaVMGCObject** p, int all, int* lim, int* count);

// equiv-conv: FUN_00216e10 stack stack ebx
extern "C" int __cdecl FUN_00216e10(int all, int lim, LuaVMState* L) {
    LuaVMGlobal* g = L->l_G;
    int i = g->sweepstrgc;
    while (i < g->strt.size) {
        LuaVMGCObject** p = (LuaVMGCObject**)&L->l_G->strt.hash[i];
        int dead = 0x7fffffff;
        if (*p != 0)
            FUN_002171c0(L, p, all, &dead, (int*)&g->strt.nuse);
        lim += dead - 0x7fffffff;
        if (lim <= 0)
            break;
        ++i;
    }
    g->sweepstrgc = i + 1;
    return lim;
}
} // namespace fn_00216e10

namespace fn_f29d11ae {

// 0x00216e70 FUN_00216e70 (85 B): equivalent/0x00216e70.cpp
// sym: _FUN_00216e70
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// checkSizes: halve the string table when a quarter full and the concatenation buffer when over 64 bytes.
// equiv-conv: FUN_00216e70 ebx
extern "C" void __cdecl FUN_00216e70(LuaVMState* L) {
    LuaVMGlobal* g = L->l_G;
    if (g->strt.nuse < (unsigned int)(g->strt.size / 4) && g->strt.size > 0x4000)
        FUN_002192e0(L, g->strt.size / 2);
    unsigned int size = g->buff.buffsize;
    if (size > 0x40) {
        unsigned int newsize = size >> 1;
        char* buffer = (char*)FUN_0021add0(L, g->buff.buffer, size, newsize);
        g->buff.buffsize = newsize;
        g->buff.buffer = buffer;
    }
}


// 0x00216ed0 FUN_00216ed0 (139 B): equivalent/0x00216ed0.cpp
// sym: _FUN_00216ed0
// STATUS: equivalent (tools/equiv.py level 3: 2951 inputs, branch coverage 6/6)
// GCTM: take the next userdata awaiting finalization, put it back after the dummy udata (white) and call its __gc.
// equiv-conv: FUN_00216ed0 esi
extern "C" void __cdecl FUN_00216ed0(LuaVMState* L) {
    LuaVMGlobal* g = L->l_G;
    LuaVMGCObject* first = g->firstudata;
    LuaVMUdata* u = (LuaVMUdata*)g->tmudata;

    g->tmudata = u->next;
    u->next = first->next;
    L->l_G->firstudata->next = (LuaVMGCObject*)u;
    u->marked = (u->marked & 0xf8) | (unsigned char)g->currentwhite;

    LuaVMTable* mt = u->metatable;
    if (mt != 0 && (mt->flags & 4) == 0) {
        const LuaVMTObject* tm = FUN_00217580(mt, 2, L->l_G->tmname[2]);
        if (tm != 0) {
            unsigned char oldallow = L->allowhook;
            L->allowhook = 0;
            LUAVM_SETOBJ(L->top, tm);
            L->top[1].value.gc = (LuaVMGCObject*)u;
            L->top[1].tt = LUAVM_TUSERDATA;
            L->top += 2;
            FUN_002159e0(L, L->top - 2, 0);
            L->allowhook = oldallow;
        }
    }
}


// 0x00216f60 FUN_00216f60 (33 B): equivalent/0x00216f60.cpp
// sym: _FUN_00216f60
// STATUS: equivalent (tools/equiv.py level 3: 3005 inputs, branch coverage 4/4)
// luaC_callGCTM: run the pending finalizers.
// equiv-conv: FUN_00216ed0 esi
extern "C" void __cdecl FUN_00216f60(LuaVMState* L) {
    while (L->l_G->tmudata != 0)
        FUN_00216ed0(L);
}


// 0x00216f90 FUN_00216f90 (96 B): equivalent/0x00216f90.cpp
// sym: _FUN_00216f90
// STATUS: equivalent (tools/equiv.py level 3: 3009 inputs, branch coverage 10/10)
// markroot: start a collection: mark the main thread, its globals and the registry.
// equiv-conv: FUN_00216f90 edi
extern "C" void __cdecl FUN_00216f90(LuaVMState* L) {
    LuaVMGlobal* g = L->l_G;
    g->grayagain = 0;
    g->weak = 0;
    LuaVMGCObject* o = (LuaVMGCObject*)g->mainthread;
    if (o->marked & 3)
        FUN_002164b0(g, o);
    LuaVMState* th = g->mainthread;
    if (th->_gt.tt >= LUAVM_TSTRING) {
        o = th->_gt.value.gc;
        if (o->marked & 3)
            FUN_002164b0(g, o);
    }
    LuaVMGlobal* g2 = L->l_G;
    if (g2->l_registry.tt >= LUAVM_TSTRING) {
        o = g2->l_registry.value.gc;
        if (o->marked & 3)
            FUN_002164b0(g, o);
    }
    g->gcstate = 0;
}


// 0x00216ff0 FUN_00216ff0 (81 B): matches/0x00216ff0.cpp
// sym: _FUN_00216ff0
// remarkupvals: mark the values of the gray open upvalues of the white threads.
extern "C" void __cdecl FUN_00216ff0(LuaVMGlobal* g) {
    LuaVMGCObject* o = (LuaVMGCObject*)g->mainthread;
    while (o) {
        if (o->marked & 3) {
            LuaVMGCObject* curr = ((LuaVMState*)o)->openupval;
            while (curr) {
                if ((curr->marked & 7) == 0) {
                    LuaVMTObject* v = ((LuaVMUpVal*)curr)->v;
                    if (v->tt >= LUAVM_TSTRING) {
                        LuaVMGCObject* gc = v->value.gc;
                        if (gc->marked & 3)
                            FUN_002164b0(g, gc);
                    }
                }
                curr = curr->next;
            }
        }
        o = o->next;
    }
}


// 0x00217050 FUN_00217050 (170 B): equivalent/0x00217050.cpp
// sym: _FUN_00217050
// STATUS: equivalent (tools/equiv.py level 3: 2933 inputs, branch coverage 6/6)
// atomic: finish the mark phase (upvalues, weak tables, the running thread, grayagain, finalizable userdata), clear
// the weak tables, flip the white and start sweeping the strings.
// equiv-conv: FUN_00216ac0 eax stack
// equiv-conv: FUN_00216c40 eax
// equiv-conv: FUN_00217050 eax
extern "C" void __cdecl FUN_00217050(LuaVMState* L) {
    LuaVMGlobal* g = L->l_G;
    FUN_00216ff0(g);
    g->gray = g->weak;
    g->weak = 0;
    if (L->marked & 3)
        FUN_002164b0(g, (LuaVMGCObject*)L);
    FUN_00216ac0(0x7fffffff, g);
    g->gray = g->grayagain;
    g->grayagain = 0;
    FUN_00216ac0(0x7fffffff, g);
    FUN_002165c0(L, 0);
    for (LuaVMGCObject* o = g->tmudata; o; o = o->next) {
        o->marked = (o->marked & 0xf8) | (unsigned char)g->currentwhite;
        FUN_002164b0(g, o);
    }
    FUN_00216ac0(0x7fffffff, g);
    FUN_00216c40(g->weak);
    g->currentwhite ^= 3;
    g->gcstate = 1;
}


// 0x00217100 FUN_00217100 (38 B): matches/0x00217100.cpp
// sym: _FUN_00217100
// luaC_barrierf: a black object o now points at the white v: mark v while propagating, else make o not black.
extern "C" void __cdecl FUN_00217100(LuaVMState* L, LuaVMGCObject* o, LuaVMGCObject* v) {
    LuaVMGlobal* g = L->l_G;
    if (g->gcstate != 0) {
        o->marked &= 0xfb;
        return;
    }
    FUN_002164b0(g, v);
}


// 0x00217130 FUN_00217130 (33 B): matches/0x00217130.cpp
// sym: _FUN_00217130
// luaC_link: put a new object on the root list, white.
extern "C" void __cdecl FUN_00217130(LuaVMState* L, LuaVMGCObject* o, unsigned char tt) {
    LuaVMGlobal* g = L->l_G;
    o->next = g->rootgc;
    g->rootgc = o;
    o->marked = (unsigned char)g->currentwhite;
    o->tt = tt;
}


// 0x00217160 FUN_00217160 (91 B): matches/0x00217160.cpp
// sym: _FUN_00217160
// luaC_linkupval: put a closed upvalue on the root list; a gray one turns black (with the barrier) or white.
extern "C" void __cdecl FUN_00217160(LuaVMState* L, LuaVMUpVal* uv) {
    LuaVMGlobal* g = L->l_G;
    LuaVMGCObject* o = (LuaVMGCObject*)uv;
    o->next = g->rootgc;
    g->rootgc = o;
    unsigned char b = uv->marked;
    if ((b & 7) == 0) {
        if (g->gcstate == 0) {
            uv->marked = b | 4;
            LuaVMTObject* v = uv->v;
            if (v->tt >= LUAVM_TSTRING) {
                LuaVMGCObject* gc = v->value.gc;
                if ((gc->marked & 3) != 0 && (uv->marked & 4))
                    FUN_00217100(L, o, gc);
            }
        } else
            uv->marked = (b & 0xf8) | (unsigned char)g->currentwhite;
    }
}


// 0x002171c0 FUN_002171c0 (250 B): equivalent/0x002171c0.cpp
// sym: _FUN_002171c0
// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 18/18)
// sweeplist: free the dead objects of the list at p (re-whiten the live ones, sweep threads' open upvalues) until
// *lim bytes are done; the link reached.
// equiv-conv: FUN_00216d30 ecx eax
extern "C" LuaVMGCObject** __cdecl FUN_002171c0(LuaVMState* L, LuaVMGCObject** p, int all, int* lim, int* count) {
    LuaVMGlobal* g = L->l_G;
    unsigned int dead = g->currentwhite ^ 3;
    int l = *lim;
    if (all)
        dead |= 0x20;
    LuaVMGCObject* curr = *p;
    if (curr) {
        do {
            if ((((unsigned int)curr->marked ^ 0x20) & dead) != dead) {
                curr->marked = (unsigned char)((curr->marked & 0xf8) | (unsigned char)g->currentwhite);
                if (curr->tt == LUAVM_TTHREAD) {
                    int nested = 0x7fffffff;
                    if (((LuaVMState*)curr)->openupval)
                        FUN_002171c0(L, &((LuaVMState*)curr)->openupval, all, &nested, count);
                    l += nested - 0x7fffffff;
                }
                p = &curr->next;
                l -= 8;
            } else {
                *p = curr->next;
                if (curr == g->rootgc)
                    g->rootgc = curr->next;
                FUN_00216d30(L, curr);
                l -= 4;
                if (count)
                    --*count;
            }
            if (l <= 0)
                break;
            curr = *p;
        } while (curr);
    }
    *lim = l;
    return p;
}


// 0x002172c0 FUN_002172c0 (136 B): equivalent/0x002172c0.cpp
// sym: _FUN_002172c0
// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 2/2)
// luaC_sweepall: sweep everything twice (the second time with the other white), keeping the main thread.
// equiv-conv: FUN_00216e10 stack stack ebx
extern "C" void __cdecl FUN_002172c0(LuaVMState* L) {
    LuaVMGlobal* g = L->l_G;
    int lim = 0x7fffffff;
    FUN_00216e10(0, 0x7fffffff, L);
    FUN_002171c0(L, &g->rootgc, 0, &lim, 0);
    LuaVMGCObject* mainthread = (LuaVMGCObject*)g->mainthread;
    if (mainthread->marked & 3)
        FUN_002164b0(g, mainthread);
    g->currentwhite ^= 3;
    g->sweepgc = &g->rootgc;
    g->sweepstrgc = 0;
    FUN_00216e10(0, 0x7fffffff, L);
    FUN_002171c0(L, &g->rootgc, 0, &lim, 0);
}


// 0x00217350 FUN_00217350 (212 B): equivalent/0x00217350.cpp
// sym: _FUN_00217350
// STATUS: equivalent (tools/equiv.py level 3: 3010 inputs, branch coverage 14/14)
// singlestep: one step of the collector's state machine (propagate, sweep strings, sweep, finalize); the budget left.
// equiv-conv: FUN_00216ac0 eax stack
// equiv-conv: FUN_00217050 eax
// equiv-conv: FUN_00216e10 stack stack ebx
// equiv-conv: FUN_00216e70 ebx
// equiv-conv: FUN_00216ed0 esi
// equiv-conv: FUN_00216f90 edi
// equiv-conv: FUN_00217350 eax stack
extern "C" int __cdecl FUN_00217350(LuaVMState* L, int lim) {
    LuaVMGlobal* g = L->l_G;
    switch (g->gcstate) {
    case 0:
        if (g->gray)
            return FUN_00216ac0(lim, g);
        FUN_00217050(L);
        return 0;
    case 1: {
        int result = FUN_00216e10(1, lim, L);
        if (g->sweepstrgc >= g->strt.size) {
            g->sweepstrgc = 0;
            g->gcstate = 2;
        }
        return result;
    }
    case 2: {
        LuaVMGCObject** p = FUN_002171c0(L, g->sweepgc, 1, &lim, 0);
        g->sweepgc = p;
        if (*p == 0) {
            FUN_00216e70(L);
            g->sweepgc = &g->rootgc;
            g->gcstate = 3;
        }
        return lim;
    }
    case 3:
        if (g->tmudata) {
            FUN_00216ed0(L);
            return lim - 80;
        }
        FUN_00216f90(L);
        return 0;
    default:
        return lim;
    }
}


// 0x00217440 FUN_00217440 (78 B): equivalent/0x00217440.cpp
// sym: _FUN_00217440
// STATUS: equivalent (tools/equiv.py level 3: 2592 inputs, branch coverage 6/6)
// luaC_step: run collector steps for the bytes allocated past the threshold; set the next threshold.
// equiv-conv: FUN_00217350 eax stack
extern "C" void __cdecl FUN_00217440(LuaVMState* L) {
    LuaVMGlobal* g = L->l_G;
    int lim = (int)(g->totalbytes - g->GCthreshold) * 8 + 0xa00;
    do {
        lim = FUN_00217350(L, lim);
        if (g->gcstate == 3 && g->tmudata == 0)
            break;
    } while (lim > 0);
    g->GCthreshold = g->totalbytes - (lim / 8) + 0x140;
}


// 0x00217490 FUN_00217490 (131 B): equivalent/0x00217490.cpp
// sym: _FUN_00217490
// STATUS: equivalent (tools/equiv.py level 3: 8 inputs, branch coverage 11/12, incomplete)
// luaC_fullgc: finish the current cycle, run a whole one, set the threshold and call the finalizers.
// equiv-conv: FUN_00217350 eax stack
// equiv-conv: FUN_00216f90 edi
// equiv-conv: FUN_00216ed0 esi
extern "C" void __cdecl FUN_00217490(LuaVMState* L) {
    LuaVMGlobal* g = L->l_G;
    while (g->gcstate != 3)
        FUN_00217350(L, 0x7fffffff);
    FUN_00216f90(L);
    while (g->gcstate != 3)
        FUN_00217350(L, 0x7fffffff);
    g->GCthreshold = g->totalbytes + 0x140;
    while (L->l_G->tmudata != 0)
        FUN_00216ed0(L);
}

} // namespace fn_f29d11ae
