// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00212bb0..0x00213f20 (kind game, layer engine, confidence high)
#include "tree_prelude.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/global.h"
#include "decls/data/lua.h"
#define TREE_TU_BEGIN namespace fn_f4ee33a9 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f4ee33a9 {} using namespace fn_f4ee33a9;
#include "engine/lua.h"

// ---- declarations shared by the functions below
namespace fn_f4ee33a9 {
extern "C" void __cdecl FUN_00215460(LuaVMState* L, int n);
extern "C" void __cdecl FUN_00217440(LuaVMState* L);
extern "C" LuaVMState* __cdecl FUN_00215010(LuaVMState* L);
extern "C" LuaVMTObject* __fastcall FUN_00212bb0(int idx, LuaVMState* L);
extern "C" const LuaVMTObject* __cdecl FUN_00217600(const LuaVMTObject* obj, LuaVMTObject* n);
extern "C" int __cdecl FUN_00215fa0(const LuaVMTObject* t1, const LuaVMTObject* t2);
extern "C" int __cdecl FUN_00217cf0(LuaVMState* L, const LuaVMTObject* l, const LuaVMTObject* r);
extern "C" int __cdecl FUN_00217640(LuaVMState* L, LuaVMTObject* obj);
extern "C" LuaVMString* __cdecl FUN_00219430(LuaVMState* L, const char* str, unsigned int l);
extern "C" const char* __cdecl FUN_002160c0(LuaVMState* L, const char* fmt, char* argp);
extern "C" LuaVMClosure* __cdecl FUN_00219520(LuaVMState* L, int nelems);
extern "C" void __cdecl FUN_00217830(LuaVMState* L, const LuaVMTObject* t, LuaVMTObject* key, LuaVMTObject* val);
extern "C" const LuaVMTObject* __cdecl FUN_00219e90(LuaVMTable* t, const LuaVMTObject* key);
extern "C" const LuaVMTObject* __cdecl FUN_00219dc0(LuaVMTable* t, int key);
extern "C" LuaVMTable* __cdecl FUN_00219cc0(LuaVMState* L, int narray, int lnhash);
extern "C" void __cdecl FUN_00217980(LuaVMState* L, const LuaVMTObject* t, LuaVMTObject* key, LuaVMTObject* val);
extern "C" LuaVMTObject* __cdecl FUN_00219ef0(LuaVMState* L, LuaVMTable* t, const LuaVMTObject* key);
extern "C" void __cdecl FUN_00217100(LuaVMState* L, LuaVMGCObject* o, LuaVMGCObject* v);
extern "C" LuaVMTObject* __cdecl FUN_00219f60(LuaVMState* L, LuaVMTable* t, int key);
extern "C" void __cdecl FUN_002159e0(LuaVMState* L, LuaVMTObject* func, int nresults);
extern "C" void __cdecl FUN_002139d0(LuaVMState* L, void* ud);
extern "C" int __cdecl FUN_00215de0(LuaVMState* L, void(__cdecl* f)(LuaVMState*, void*), void* u, int oldtop, int ef);
extern "C" void __cdecl FUN_00213a50(LuaVMState* L, void* ud);
extern "C" void __cdecl FUN_0021a5e0(LuaVMState* L, LuaVMZio* z, LuaVMReader reader, void* data);
extern "C" int __cdecl FUN_00215ee0(LuaVMState* L, LuaVMZio* z, const char* name);
extern "C" int __cdecl FUN_0021ad80(LuaVMState* L, LuaVMProto* f, LuaVMWriter w, void* data, int strip);
extern "C" void __cdecl FUN_00217490(LuaVMState* L);
extern "C" void __cdecl FUN_002149b0(LuaVMState* L);
extern "C" int __cdecl FUN_0021a020(LuaVMState* L, LuaVMTable* t, LuaVMTObject* key);
extern "C" void __cdecl FUN_00217f20(LuaVMState* L, int total, int last);
extern "C" LuaVMUdata* __cdecl FUN_002194d0(LuaVMState* L, unsigned int s);


// 0x00212bb0 FUN_00212bb0 (95 B): matches/0x00212bb0.cpp
// sym: @FUN_00212bb0@8
// index2adr: the stack slot, pseudo-index (registry, globals) or C upvalue an API index names.
extern "C" LuaVMTObject* __fastcall FUN_00212bb0(int idx, LuaVMState* L) {
    if (idx > 0) {
        LuaVMTObject* o = L->base + (idx - 1);
        if (o < L->top)
            return o;
        return LUAVM_NILOBJECT;
    }
    if (idx > -10000)
        return L->top + idx;
    if (idx != -10001) {
        if (idx != -10000) {
            LuaVMCClosure* func = (LuaVMCClosure*)(L->base - 1)->value.gc;
            int i = -10001 - idx;
            LuaVMTObject* o = &func->upvalue[i - 1];
            return i <= func->nupvalues ? o : LUAVM_NILOBJECT;
        }
        return &L->l_G->l_registry;
    }
    return &L->_gt;
}


// 0x00212c10 FUN_00212c10 (50 B): matches/0x00212c10.cpp
// sym: _FUN_00212c10
// luaA_pushobject: push a copy of o (setobj2s + incr_top).
extern "C" void __cdecl FUN_00212c10(LuaVMState* L, const LuaVMTObject* o) {
    LuaVMTObject* t = L->top;
    t->tt = o->tt;
    t->value = o->value;
    if ((char*)L->stack_last - (char*)L->top <= (int)sizeof(LuaVMTObject))
        FUN_00215460(L, 1);
    L->top++;
}


// 0x00212c50 FUN_00212c50 (90 B): matches/0x00212c50.cpp
// sym: _FUN_00212c50
// lua_checkstack: room for size more slots (at most 2048 in the frame); raises the frame's top.
extern "C" int __cdecl FUN_00212c50(LuaVMState* L, int size) {
    if ((L->top - L->base) + size > 0x800)
        return 0;
    if ((char*)L->stack_last - (char*)L->top <= size * (int)sizeof(LuaVMTObject))
        FUN_00215460(L, size);
    LuaVMTObject* t = L->top + size;
    if (L->ci->top < t)
        L->ci->top = t;
    return 1;
}


// 0x00212cb0 FUN_00212cb0 (87 B): matches/0x00212cb0.cpp
// sym: _FUN_00212cb0
// lua_xmove: move n values from the top of from's stack to to's.
extern "C" void __cdecl FUN_00212cb0(LuaVMState* from, LuaVMState* to, int n) {
    if (from == to)
        return;
    from->top -= n;
    for (int i = 0; i < n; ++i) {
        LUAVM_SETOBJ(to->top, from->top + i);
        ++to->top;
    }
}


// 0x00212d30 FUN_00212d30 (57 B): matches/0x00212d30.cpp
// sym: _FUN_00212d30
// lua_newthread: a new thread pushed on the stack (a GC step first when the debt is due).
extern "C" LuaVMState* __cdecl FUN_00212d30(LuaVMState* L) {
    if (L->l_G->totalbytes >= L->l_G->GCthreshold)
        FUN_00217440(L);
    LuaVMState* L1 = FUN_00215010(L);
    LuaVMTObject* o = L->top;
    o->value.gc = (LuaVMGCObject*)L1;
    o->tt = LUAVM_TTHREAD;
    L->top++;
    return L1;
}


// 0x00212d70 FUN_00212d70 (14 B): matches/0x00212d70.cpp
// sym: _FUN_00212d70
// lua_gettop: the number of values in the current frame.
extern "C" int __cdecl FUN_00212d70(LuaVMState* L) {
    return (int)(L->top - L->base);
}


// 0x00212d80 FUN_00212d80 (85 B): matches/0x00212d80.cpp
// sym: _FUN_00212d80
// lua_settop: idx >= 0 sets the top to base + idx (new slots nil); idx < 0 drops -idx - 1 values.
extern "C" void __cdecl FUN_00212d80(LuaVMState* L, int idx) {
    if (idx >= 0) {
        while (L->top < L->base + idx) {
            L->top->tt = LUAVM_TNIL;
            L->top++;
        }
        L->top = L->base + idx;
        return;
    }
    L->top += idx + 1;
}


// 0x00212de0 FUN_00212de0 (59 B): matches/0x00212de0.cpp
// sym: _FUN_00212de0
// lua_remove: remove the value at idx, shifting the ones above it down.
extern "C" void __cdecl FUN_00212de0(LuaVMState* L, int idx) {
    LuaVMTObject* p = FUN_00212bb0(idx, L);
    p++;
    while (p < L->top) {
        LuaVMTObject* q = p - 1;
        q->tt = p->tt;
        q->value = p->value;
        p++;
    }
    L->top--;
}


// 0x00212e20 FUN_00212e20 (56 B): matches/0x00212e20.cpp
// sym: _FUN_00212e20
// lua_insert: move the top value to idx, shifting the ones above idx up.
extern "C" void __cdecl FUN_00212e20(LuaVMState* L, int idx) {
    LuaVMTObject* p = FUN_00212bb0(idx, L);
    LuaVMTObject* q = L->top;
    while (q > p) {
        q->tt = (q - 1)->tt;
        q->value = (q - 1)->value;
        --q;
    }
    q = L->top;
    p->tt = q->tt;
    p->value = q->value;
}

} // namespace fn_f4ee33a9

// 0x00212e60 FUN_00212e60 (103 B): equivalent/0x00212e60.cpp [wrapped: code differs from its standalone build]
// sym: _FUN_00212e60 @376f153c3155 @w9e65b924284f
namespace fn_00212e60 {
// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 8/8)
// lua_replace: pop the top value into idx (the write barrier for a C upvalue).

extern "C++" __declspec(nothrow) LuaVMTObject* __fastcall FUN_00212bb0(int idx, LuaVMState* L);
extern "C++" __declspec(nothrow) void __cdecl FUN_00217100(LuaVMState* L, LuaVMGCObject* o, LuaVMGCObject* v);

extern "C" void __cdecl FUN_00212e60(LuaVMState* L, int idx) {
    LuaVMTObject* src = L->top - 1;
    LuaVMTObject* o = FUN_00212bb0(idx, L);
    *o = *src;
    if (idx < -10001) {
        if (L->top[-1].tt >= LUAVM_TSTRING) {
            LuaVMGCObject* v = L->top[-1].value.gc;
            if ((v->marked & 3) != 0) {
                LuaVMGCObject* f = L->base[-1].value.gc;
                if ((f->marked & 4) != 0)
                    FUN_00217100(L, f, v);
            }
        }
    }
    L->top--;
}
} // namespace fn_00212e60

namespace fn_f4ee33a9 {

// 0x00212ed0 FUN_00212ed0 (35 B): matches/0x00212ed0.cpp
// sym: _FUN_00212ed0
// lua_pushvalue: push a copy of the value at idx.
extern "C" void __cdecl FUN_00212ed0(LuaVMState* L, int idx) {
    LuaVMTObject* o = FUN_00212bb0(idx, L);
    *L->top = *o;
    L->top++;
}


// 0x00212f00 FUN_00212f00 (27 B): equivalent/0x00212f00.cpp
// sym: _FUN_00212f00 @af779f846ba2 @wf39dc8b2e0aa
// STATUS: equivalent (tools/equiv.py level 3: 3003 inputs, branch coverage 2/2)
// lua_type: the type tag of the value at idx (LUA_TNONE -1 when absent).
extern "C" int __cdecl FUN_00212f00(LuaVMState* L, int idx) {
    LuaVMTObject* o = FUN_00212bb0(idx, L);
    if (o == LUAVM_NILOBJECT)
        return -1;
    return o->tt;
}


// 0x00212f20 FUN_00212f20 (23 B): matches/0x00212f20.cpp
// sym: _FUN_00212f20
// lua_typename: the name of type tag t ("no value" for LUA_TNONE).
extern "C" const char* __cdecl FUN_00212f20(LuaVMState* L, int t) {
    if (t == -1)
        return DAT_004265fc;
    return DAT_00426948[t];
}


// 0x00212f40 FUN_00212f40 (37 B): matches/0x00212f40.cpp
// sym: _FUN_00212f40
// lua_iscfunction: the value at idx is a C closure.
extern "C" int __cdecl FUN_00212f40(LuaVMState* L, int idx) {
    int i = *(volatile int*)&idx;  // idx loaded first (ecx), as the original
    LuaVMTObject* o = FUN_00212bb0(i, L);
    if (o->tt == LUAVM_TFUNCTION && ((LuaVMClosure*)o->value.gc)->c.isC)
        return 1;
    return 0;
}


// 0x00212f70 FUN_00212f70 (51 B): equivalent/0x00212f70.cpp
// sym: _FUN_00212f70 @c029d65787d1 @web43671a6b44
// STATUS: equivalent (tools/equiv.py level 3: 3003 inputs, branch coverage 4/4)
// lua_isnumber: the value at idx is a number or converts to one.
extern "C" int __cdecl FUN_00212f70(LuaVMState* L, int idx) {
    LuaVMTObject n;
    LuaVMTObject* o = FUN_00212bb0(idx, L);
    if (o->tt != LUAVM_TNUMBER && FUN_00217600(o, &n) == 0)
        return 0;
    return 1;
}


// 0x00212fb0 FUN_00212fb0 (41 B): matches/0x00212fb0.cpp
// sym: _FUN_00212fb0
// lua_isstring: the value at idx is a string or a number.
extern "C" int __cdecl FUN_00212fb0(LuaVMState* L, int idx) {
    int i = *(volatile int*)&idx;  // idx loaded first (ecx), as the original
    LuaVMTObject* o = FUN_00212bb0(i, L);
    if (o == LUAVM_NILOBJECT)
        return 0;
    return o->tt == LUAVM_TSTRING || o->tt == LUAVM_TNUMBER;
}


// 0x00212fe0 FUN_00212fe0 (34 B): equivalent/0x00212fe0.cpp
// sym: _FUN_00212fe0 @44231d3f7dbf @w085a447c3bea
// STATUS: equivalent (tools/equiv.py level 3: 3004 inputs, branch coverage 4/4)
// lua_isuserdata: the value at idx is a full or light userdata.
extern "C" int __cdecl FUN_00212fe0(LuaVMState* L, int idx) {
    int t = FUN_00212bb0(idx, L)->tt;
    return t == LUAVM_TUSERDATA || t == LUAVM_TLIGHTUSERDATA;
}


// 0x00213010 FUN_00213010 (63 B): matches/0x00213010.cpp
// sym: _FUN_00213010
// lua_equal: the values at index1 and index2 are equal (primitive equality; 0 when either is absent).
extern "C" int __cdecl FUN_00213010(LuaVMState* L, int index1, int index2) {
    LuaVMTObject* o1 = FUN_00212bb0(index1, L);
    LuaVMTObject* o2 = FUN_00212bb0(index2, L);
    if (o1 != LUAVM_NILOBJECT && o2 != LUAVM_NILOBJECT)
        return FUN_00215fa0(o1, o2);
    return 0;
}


// 0x002130a0 FUN_002130a0 (64 B): matches/0x002130a0.cpp
// sym: _FUN_002130a0
// lua_lessthan: the value at index1 is less than the one at index2 (0 when either is absent).
extern "C" int __cdecl FUN_002130a0(LuaVMState* L, int index1, int index2) {
    LuaVMTObject* o1 = FUN_00212bb0(index1, L);
    LuaVMTObject* o2 = FUN_00212bb0(index2, L);
    if (o1 != LUAVM_NILOBJECT && o2 != LUAVM_NILOBJECT)
        return FUN_00217cf0(L, o1, o2);
    return 0;
}


// 0x002130e0 FUN_002130e0 (55 B): equivalent/0x002130e0.cpp
// sym: _FUN_002130e0 @9838312afc7e @wef758c084ba6
// STATUS: equivalent (tools/equiv.py level 3: 3005 inputs, branch coverage 4/4)
// lua_tonumber: the number at idx (converted from a string when it can be); 0 otherwise.
extern "C" float __cdecl FUN_002130e0(LuaVMState* L, int idx) {
    LuaVMTObject n;
    const LuaVMTObject* o = FUN_00212bb0(idx, L);
    if (o->tt != LUAVM_TNUMBER) {
        o = FUN_00217600(o, &n);
        if (!o)
            return DAT_003f32e0;
    }
    return o->value.n;
}


// 0x00213120 FUN_00213120 (54 B): equivalent/0x00213120.cpp
// sym: _FUN_00213120 @c5b1f05a3464 @wd84a9595004e
// STATUS: equivalent (tools/equiv.py level 3: 3005 inputs, branch coverage 4/4)
// lua_tointeger: the number at idx truncated to an integer (converted from a string when it can be); 0 otherwise.
extern "C" int __cdecl FUN_00213120(LuaVMState* L, int idx) {
    LuaVMTObject n;
    const LuaVMTObject* o = FUN_00212bb0(idx, L);
    if (o->tt == LUAVM_TNUMBER || (o = FUN_00217600(o, &n)) != 0)
        return (int)(__int64)o->value.n;
    return 0;
}


// 0x00213160 FUN_00213160 (40 B): matches/0x00213160.cpp
// sym: _FUN_00213160
// lua_toboolean: the value at idx is neither nil nor false.
extern "C" int __cdecl FUN_00213160(LuaVMState* L, int idx) {
    int i = *(volatile int*)&idx;  // idx loaded first (ecx), as the original
    LuaVMTObject* o = FUN_00212bb0(i, L);
    return o->tt != LUAVM_TNIL && (o->tt != LUAVM_TBOOLEAN || o->value.b != 0);
}


// 0x00213190 FUN_00213190 (82 B): matches/0x00213190.cpp
// sym: _FUN_00213190
// lua_tostring: the string at idx (a number is converted in place); NULL otherwise. A GC step when due.
extern "C" const char* __cdecl FUN_00213190(LuaVMState* L, int idx) {
    LuaVMTObject* o = FUN_00212bb0(idx, L);
    if (o->tt == LUAVM_TSTRING)
        return LUAVM_GETSTR(o->value.gc);
    const char* s = FUN_00217640(L, o) ? LUAVM_GETSTR(o->value.gc) : 0;
    LuaVMGlobal* g = L->l_G;
    if (g->totalbytes >= g->GCthreshold)
        FUN_00217440(L);
    return s;
}


// 0x002131f0 FUN_002131f0 (61 B): matches/0x002131f0.cpp
// sym: _FUN_002131f0
// lua_strlen: the length of the string at idx (a number is converted in place); 0 otherwise.
extern "C" unsigned int __cdecl FUN_002131f0(LuaVMState* L, int idx) {
    LuaVMTObject* o = FUN_00212bb0(idx, L);
    if (o->tt == LUAVM_TSTRING)
        return ((LuaVMString*)o->value.gc)->len;
    if (FUN_00217640(L, o))
        return ((LuaVMString*)o->value.gc)->len;
    return 0;
}


// 0x00213260 FUN_00213260 (39 B): equivalent/0x00213260.cpp
// sym: _FUN_00213260 @72cb92e3aaf6 @w94328e78c427
// STATUS: equivalent (tools/equiv.py level 3: 3004 inputs, branch coverage 4/4)
// lua_touserdata: the block of the full userdata or the light userdata at idx; NULL otherwise.
extern "C" void* __cdecl FUN_00213260(LuaVMState* L, int idx) {
    LuaVMTObject* o = FUN_00212bb0(idx, L);
    if (o->tt == LUAVM_TLIGHTUSERDATA)
        return o->value.p;
    if (o->tt == LUAVM_TUSERDATA)
        return (LuaVMUdata*)o->value.gc + 1;
    return 0;
}


// 0x00213290 FUN_00213290 (25 B): matches/0x00213290.cpp
// sym: _FUN_00213290
// lua_tothread: the thread at idx, or NULL.
extern "C" LuaVMState* __cdecl FUN_00213290(LuaVMState* L, int idx) {
    int i = *(volatile int*)&idx;  // idx loaded first (ecx), as the original
    LuaVMTObject* o = FUN_00212bb0(i, L);
    if (o->tt != LUAVM_TTHREAD)
        return 0;
    return (LuaVMState*)o->value.gc;
}


// 0x002132b0 FUN_002132b0 (77 B): equivalent/0x002132b0.cpp
// sym: _FUN_002132b0 @1b8d56fbfc68 @wa03ce85b7549
// STATUS: equivalent (tools/equiv.py level 3: 3024 inputs, branch coverage 13/13)
// lua_topointer: the address of the table, function, thread or userdata at idx; NULL otherwise.
extern "C" const void* __cdecl FUN_002132b0(LuaVMState* L, int idx) {
    LuaVMTObject* o = FUN_00212bb0(idx, L);
    switch (o->tt) {
    case LUAVM_TLIGHTUSERDATA:
    case LUAVM_TUSERDATA:
        o = FUN_00212bb0(idx, L);  // lua_touserdata inlined
        if (o->tt == LUAVM_TLIGHTUSERDATA)
            return o->value.p;
        if (o->tt == LUAVM_TUSERDATA)
            return (LuaVMUdata*)o->value.gc + 1;
        break;
    case LUAVM_TTABLE:
    case LUAVM_TFUNCTION:
    case LUAVM_TTHREAD:
        return o->value.gc;
    }
    return 0;
}


// 0x00213320 FUN_00213320 (18 B): matches/0x00213320.cpp
// sym: _FUN_00213320
// lua_pushnil.
extern "C" void __cdecl FUN_00213320(LuaVMState* L) {
    L->top->tt = LUAVM_TNIL;
    L->top++;
}


// 0x00213340 FUN_00213340 (25 B): matches/0x00213340.cpp
// sym: _FUN_00213340
// lua_pushnumber.
extern "C" void __cdecl FUN_00213340(LuaVMState* L, float n) {
    LuaVMTObject* o = L->top;
    o->value.n = n;
    o->tt = LUAVM_TNUMBER;
    L->top++;
}


// 0x00213360 FUN_00213360 (25 B): equivalent/0x00213360.cpp
// sym: _FUN_00213360 @5b1edf84b448 @weed379248c19
// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 0/0)
// lua_pushinteger.
extern "C" void __cdecl FUN_00213360(LuaVMState* L, int n) {
    LuaVMTObject* o = L->top;
    o->tt = LUAVM_TNUMBER;
    o->value.n = (float)n;
    L->top++;
}


// 0x00213380 FUN_00213380 (69 B): matches/0x00213380.cpp
// sym: _FUN_00213380
// lua_pushlstring: push a new string of len bytes (a GC step first when due).
extern "C" void __cdecl FUN_00213380(LuaVMState* L, const char* s, unsigned int len) {
    LuaVMGlobal* g = L->l_G;
    if (g->totalbytes >= g->GCthreshold)
        FUN_00217440(L);
    LuaVMTObject* o = L->top;
    o->value.gc = (LuaVMGCObject*)FUN_00219430(L, s, len);
    o->tt = LUAVM_TSTRING;
    L->top++;
}


// 0x002133d0 FUN_002133d0 (107 B): equivalent/0x002133d0.cpp
// sym: _FUN_002133d0 @2cc9a3e120b7 @w1431442576ef
// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 6/6)
// lua_pushstring: push a copy of s (nil for NULL; a GC step first when due).
extern "C" void __cdecl FUN_002133d0(LuaVMState* L, const char* s) {
    if (s == 0) {
        L->top->tt = LUAVM_TNIL;
        L->top++;
        return;
    }
    unsigned int len = 0;
    while (s[len] != 0)
        len++;
    if (L->l_G->totalbytes >= L->l_G->GCthreshold)
        FUN_00217440(L);
    LuaVMTObject* t = L->top;
    t->value.gc = (LuaVMGCObject*)FUN_00219430(L, s, len);
    t->tt = LUAVM_TSTRING;
    L->top++;
}


// 0x00213440 FUN_00213440 (46 B): matches/0x00213440.cpp
// sym: _FUN_00213440
// lua_pushvfstring: push the formatted string (a GC step first when due).
extern "C" const char* __cdecl FUN_00213440(LuaVMState* L, const char* fmt, char* argp) {
    LuaVMGlobal* g = L->l_G;
    if (g->totalbytes >= g->GCthreshold)
        FUN_00217440(L);
    return FUN_002160c0(L, fmt, argp);
}


// 0x00213470 FUN_00213470 (46 B): matches/0x00213470.cpp
// sym: _FUN_00213470
// lua_pushfstring: push the formatted string (a GC step first when due).
extern "C" const char* __cdecl FUN_00213470(LuaVMState* L, const char* fmt, ...) {
    LuaVMGlobal* g = L->l_G;
    if (g->totalbytes >= g->GCthreshold)
        FUN_00217440(L);
#if defined(HULK_PTR64)
    __builtin_va_list args;
    __builtin_va_start(args, fmt);
    return FUN_002160c0(L, fmt, args);
#else
    return FUN_002160c0(L, fmt, (char*)(&fmt + 1));
#endif
}


// 0x002134a0 FUN_002134a0 (125 B): equivalent/0x002134a0.cpp
// sym: _FUN_002134a0 @16f55e234ec0 @we24af1af666d
// STATUS: equivalent (tools/equiv.py level 3: 79 inputs, branch coverage 6/6)
// lua_pushcclosure: push a C closure of fn with the n top values as its upvalues (a GC step first when due).
extern "C" void __cdecl FUN_002134a0(LuaVMState* L, LuaVMCFunction fn, int n) {
    if (L->l_G->totalbytes >= L->l_G->GCthreshold)
        FUN_00217440(L);
    LuaVMClosure* cl = FUN_00219520(L, n);
    cl->c.f = fn;
    L->top -= n;
    while (n--)
        cl->c.upvalue[n] = L->top[n];
    L->top->value.gc = (LuaVMGCObject*)cl;
    L->top->tt = LUAVM_TFUNCTION;
    L->top++;
}


// 0x00213520 FUN_00213520 (34 B): matches/0x00213520.cpp
// sym: _FUN_00213520
// lua_pushboolean.
extern "C" void __cdecl FUN_00213520(LuaVMState* L, int b) {
    LuaVMTObject* o = L->top;
    o->tt = LUAVM_TBOOLEAN;
    o->value.b = (b != 0);
    L->top++;
}


// 0x00213550 FUN_00213550 (25 B): matches/0x00213550.cpp
// sym: _FUN_00213550
// lua_pushlightuserdata.
extern "C" void __cdecl FUN_00213550(LuaVMState* L, void* p) {
    LuaVMTObject* o = L->top;
    o->value.p = p;
    o->tt = LUAVM_TLIGHTUSERDATA;
    L->top++;
}

} // namespace fn_f4ee33a9

// 0x00213570 FUN_00213570 (36 B): equivalent/0x00213570.cpp [wrapped: code differs from its standalone build]
// sym: _FUN_00213570 @e468d440e1d0 @w5b9ef395bc04
namespace fn_00213570 {
// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 0/0)
// lua_gettable: replace the key on top with t[key] for the table at idx (metamethods apply).

extern "C++" __declspec(nothrow) LuaVMTObject* __fastcall FUN_00212bb0(int idx, LuaVMState* L);
extern "C++" __declspec(nothrow) void __cdecl FUN_00217830(LuaVMState* L, const LuaVMTObject* t, LuaVMTObject* key, LuaVMTObject* val);

extern "C" void __cdecl FUN_00213570(LuaVMState* L, int idx) {
    LuaVMTObject* key = L->top - 1;
    LuaVMTObject* t = FUN_00212bb0(idx, L);
    FUN_00217830(L, t, key, key);
}
} // namespace fn_00213570

namespace fn_f4ee33a9 {

// 0x002135a0 FUN_002135a0 (96 B): matches/0x002135a0.cpp
// sym: _FUN_002135a0
// lua_getfield: push t[k] for the table at idx (metamethods apply).
extern "C" void __cdecl FUN_002135a0(LuaVMState* L, int idx, const char* k) {
    LuaVMTObject key;
    LuaVMTObject* t = FUN_00212bb0(idx, L);
    key.value.gc = (LuaVMGCObject*)FUN_00219430(L, k, (unsigned int)strlen(k));
    key.tt = LUAVM_TSTRING;
    FUN_00217830(L, t, &key, L->top);
    L->top++;
}


// 0x00213600 FUN_00213600 (53 B): matches/0x00213600.cpp
// sym: _FUN_00213600
// lua_rawget: replace the key on top with t[key] for the table at idx (no metamethods).
extern "C" void __cdecl FUN_00213600(LuaVMState* L, int idx) {
    LuaVMTObject* t = FUN_00212bb0(idx, L);
    const LuaVMTObject* v = FUN_00219e90((LuaVMTable*)t->value.gc, L->top - 1);
    LuaVMTObject* o = L->top - 1;
    o->tt = v->tt;
    o->value = v->value;
}


// 0x00213640 FUN_00213640 (57 B): matches/0x00213640.cpp
// sym: _FUN_00213640
// lua_rawgeti: push t[n] for the table at idx (no metamethods).
extern "C" void __cdecl FUN_00213640(LuaVMState* L, int idx, int n) {
    LuaVMTObject* o = FUN_00212bb0(idx, L);
    const LuaVMTObject* v = FUN_00219dc0((LuaVMTable*)o->value.gc, n);
    LuaVMTObject* t = L->top;
    t->tt = v->tt;
    t->value = v->value;
    L->top++;
}


// 0x00213680 FUN_00213680 (76 B): matches/0x00213680.cpp
// sym: _FUN_00213680
// lua_createtable: push a new table with narray array slots and room for nrec hash entries.
extern "C" void __cdecl FUN_00213680(LuaVMState* L, int narray, int nrec) {
    LuaVMGlobal* g = L->l_G;
    if (g->totalbytes >= g->GCthreshold)
        FUN_00217440(L);
    LuaVMTObject* o = L->top;
    int lnhash = FUN_00215f70(nrec);
    o->value.gc = (LuaVMGCObject*)FUN_00219cc0(L, narray, lnhash + 1);
    o->tt = LUAVM_TTABLE;
    L->top++;
}


// 0x002136d0 FUN_002136d0 (73 B): matches/0x002136d0.cpp
// sym: _FUN_002136d0
// lua_getmetatable: push the metatable of the table or userdata at objindex; 0 when it has none.
extern "C" int __cdecl FUN_002136d0(LuaVMState* L, int objindex) {
    LuaVMTObject* obj = FUN_00212bb0(objindex, L);
    LuaVMTable* mt;
    switch (obj->tt) {
    case LUAVM_TTABLE:
        mt = ((LuaVMTable*)obj->value.gc)->metatable;
        break;
    case LUAVM_TUSERDATA:
        mt = ((LuaVMUdata*)obj->value.gc)->metatable;
        break;
    default:
        return 0;
    }
    if (mt == 0)
        return 0;
    LuaVMTObject* o = L->top;
    o->value.gc = (LuaVMGCObject*)mt;
    o->tt = LUAVM_TTABLE;
    L->top++;
    return 1;
}


// 0x00213720 FUN_00213720 (58 B): matches/0x00213720.cpp
// sym: _FUN_00213720
// lua_getfenv: push the globals of the Lua function at idx (the thread's globals otherwise).
extern "C" void __cdecl FUN_00213720(LuaVMState* L, int idx) {
    LuaVMTObject* o = FUN_00212bb0(idx, L);
    LuaVMTObject* src;
    if (o->tt == LUAVM_TFUNCTION && ((LuaVMClosure*)o->value.gc)->c.isC == 0)
        src = &((LuaVMClosure*)o->value.gc)->l.g;
    else
        src = &L->_gt;
    LuaVMTObject* dst = L->top;
    dst->tt = src->tt;
    dst->value = src->value;
    L->top++;
}


// 0x00213790 FUN_00213790 (99 B): matches/0x00213790.cpp
// sym: _FUN_00213790
// lua_setfield: t[k] = the top value for the table at idx (metamethods apply); pops it.
extern "C" void __cdecl FUN_00213790(LuaVMState* L, int idx, const char* k) {
    LuaVMTObject* t = FUN_00212bb0(idx, L);
    LuaVMTObject key;
    key.value.gc = (LuaVMGCObject*)FUN_00219430(L, k, (unsigned int)strlen(k));
    key.tt = LUAVM_TSTRING;
    FUN_00217980(L, t, &key, L->top - 1);
    L->top--;
}


// 0x00213800 FUN_00213800 (107 B): matches/0x00213800.cpp
// sym: _FUN_00213800
// lua_rawset: t[k] = v for the table at idx with k, v the two top values (no metamethods; the write barrier); pops both.
extern "C" void __cdecl FUN_00213800(LuaVMState* L, int idx) {
    LuaVMTObject* t = FUN_00212bb0(idx, L);
    LuaVMTObject* top = L->top;
    LuaVMTObject* slot = FUN_00219ef0(L, (LuaVMTable*)t->value.gc, top - 2);
    slot->tt = top[-1].tt;
    slot->value = top[-1].value;
    LuaVMTObject* r = L->top;
    if (r[-1].tt >= LUAVM_TSTRING && (r[-1].value.gc->marked & 3) && (t->value.gc->marked & 4))
        FUN_00217100(L, t->value.gc, r[-1].value.gc);
    L->top -= 2;
}


// 0x00213870 FUN_00213870 (110 B): equivalent/0x00213870.cpp
// sym: _FUN_00213870 @d7f68a7a9e7c @we4de6bcfba40
// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 6/6)
// lua_rawseti: t[n] = the top value for the table at idx (no metamethods; the write barrier); pops it.
extern "C" void __cdecl FUN_00213870(LuaVMState* L, int idx, int n) {
    LuaVMTObject* t = FUN_00212bb0(idx, L);
    LuaVMTObject* val = L->top - 1;
    LuaVMTObject* slot = FUN_00219f60(L, (LuaVMTable*)t->value.gc, n);
    *slot = *val;
    if (L->top[-1].tt >= LUAVM_TSTRING) {
        LuaVMGCObject* v = L->top[-1].value.gc;
        if ((v->marked & 3) != 0) {
            LuaVMGCObject* h = t->value.gc;
            if ((h->marked & 4) != 0)
                FUN_00217100(L, h, v);
        }
    }
    L->top--;
}


// 0x002138e0 FUN_002138e0 (112 B): equivalent/0x002138e0.cpp
// sym: _FUN_002138e0 @14740bac8878 @wa48d92b296d9
// STATUS: equivalent (tools/equiv.py level 3: 3017 inputs, branch coverage 12/12)
// lua_setmetatable: pop the top table (or nil) into the metatable of the table or userdata at objindex.
extern "C" int __cdecl FUN_002138e0(LuaVMState* L, int objindex) {
    LuaVMTObject* obj = FUN_00212bb0(objindex, L);
    LuaVMTable* mt = 0;
    if (L->top[-1].tt != LUAVM_TNIL)
        mt = (LuaVMTable*)L->top[-1].value.gc;
    if (obj->tt != LUAVM_TTABLE && obj->tt != LUAVM_TUSERDATA) {
        L->top--;
        return 0;
    }
    ((LuaVMTable*)obj->value.gc)->metatable = mt;  // Udata's metatable is at the same offset
    if (mt != 0 && (mt->marked & 3) != 0 && (obj->value.gc->marked & 4) != 0)
        FUN_00217100(L, obj->value.gc, (LuaVMGCObject*)mt);
    L->top--;
    return 1;
}


// 0x00213950 FUN_00213950 (71 B): matches/0x00213950.cpp
// sym: _FUN_00213950
// lua_setfenv: pop the top value into the globals of the Lua function at idx; 0 when idx is not one.
extern "C" int __cdecl FUN_00213950(LuaVMState* L, int idx) {
    int res = 0;
    LuaVMTObject* o = FUN_00212bb0(idx, L);
    L->top--;
    LuaVMTObject* v = L->top;
    if (o->tt == LUAVM_TFUNCTION) {
        LuaVMClosure* cl = (LuaVMClosure*)o->value.gc;
        if (0 == cl->c.isC) {
            res = 1;
            cl->l.g.tt = v->tt;
            cl->l.g.value = v->value;
        }
    }
    return res;
}


// 0x002139a0 FUN_002139a0 (33 B): equivalent/0x002139a0.cpp
// sym: _FUN_002139a0 @7a4b97860670 @w6f765692b60d
// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 0/0)
// lua_call: call the function below the nargs top values.
extern "C" void __cdecl FUN_002139a0(LuaVMState* L, int nargs, int nresults) {
    FUN_002159e0(L, L->top - (nargs + 1), nresults);
}


// 0x002139d0 FUN_002139d0 (25 B): matches/0x002139d0.cpp
// sym: _FUN_002139d0
// f_call: the protected body of lua_pcall (luaD_call with the CallS's function and result count).
extern "C" void __cdecl FUN_002139d0(LuaVMState* L, void* ud) {
    LuaVMCallS* c = (LuaVMCallS*)ud;
    FUN_002159e0(L, c->func, c->nresults);
}


// 0x002139f0 FUN_002139f0 (89 B): matches/0x002139f0.cpp
// sym: _FUN_002139f0
// lua_pcall: call the function below nargs arguments in protected mode; errfunc names the error handler (0: none).
extern "C" int __cdecl FUN_002139f0(LuaVMState* L, int nargs, int nresults, int errfunc) {
    int func;
    if (errfunc == 0)
        func = 0;
    else
        func = (int)((char*)FUN_00212bb0(errfunc, L) - (char*)L->stack);
    LuaVMCallS c;
    c.func = L->top - (nargs + 1);
    c.nresults = nresults;
    return FUN_00215de0(L, FUN_002139d0, &c, (int)((char*)c.func - (char*)L->stack), func);
}


// 0x00213a50 FUN_00213a50 (132 B): matches/0x00213a50.cpp
// sym: _FUN_00213a50
// f_Ccall: the protected body of lua_cpcall: push a C closure of the CCallS's function and its light userdata, call.
extern "C" void __cdecl FUN_00213a50(LuaVMState* L, void* ud) {
    LuaVMCCallS* c = (LuaVMCCallS*)ud;
    LuaVMClosure* cl = FUN_00219520(L, 0);
    cl->c.f = c->func;
    LuaVMTObject* o = L->top;
    o->value.gc = (LuaVMGCObject*)cl;
    o->tt = LUAVM_TFUNCTION;
    if ((char*)L->stack_last - (char*)L->top <= (int)sizeof(LuaVMTObject))
        FUN_00215460(L, 1);
    L->top++;
    o = L->top;
    o->value.p = c->ud;
    o->tt = LUAVM_TLIGHTUSERDATA;
    if ((char*)L->stack_last - (char*)L->top <= (int)sizeof(LuaVMTObject))
        FUN_00215460(L, 1);
    L->top++;
    FUN_002159e0(L, L->top - 2, 0);
}


// 0x00213ae0 FUN_00213ae0 (53 B): matches/0x00213ae0.cpp
// sym: _FUN_00213ae0
// lua_cpcall: call the C function func with ud in protected mode.
extern "C" int __cdecl FUN_00213ae0(LuaVMState* L, LuaVMCFunction func, void* ud) {
    LuaVMCCallS c;
    c.func = func;
    c.ud = ud;
    return FUN_00215de0(L, FUN_00213a50, &c, (int)((char*)L->top - (char*)L->stack), 0);
}


// 0x00213b20 FUN_00213b20 (64 B): matches/0x00213b20.cpp
// sym: _FUN_00213b20
// lua_load: load a chunk through reader (chunkname "?" when NULL).
extern "C" int __cdecl FUN_00213b20(LuaVMState* L, LuaVMReader reader, void* data, const char* chunkname) {
    LuaVMZio z;
    if (!chunkname)
        chunkname = DAT_00426608;
    FUN_0021a5e0(L, &z, reader, data);
    return FUN_00215ee0(L, &z, chunkname);
}


// 0x00213b60 FUN_00213b60 (57 B): matches/0x00213b60.cpp
// sym: _FUN_00213b60
// lua_dump: dump the Lua function on top through writer; 0 when it is not one.
extern "C" int __cdecl FUN_00213b60(LuaVMState* L, LuaVMWriter writer, void* data) {
    LuaVMTObject* o = L->top - 1;
    if (o->tt == LUAVM_TFUNCTION) {
        LuaVMClosure* cl = (LuaVMClosure*)o->value.gc;
        if (cl->c.isC == 0)
            return FUN_0021ad80(L, cl->l.p, writer, data, 0);
    }
    return 0;
}


// 0x00213ba0 FUN_00213ba0 (117 B): equivalent/0x00213ba0.cpp
// sym: _FUN_00213ba0 @8d29388af301 @w8e3d6befaf8b
// STATUS: equivalent (tools/equiv.py level 3: 3005 inputs, branch coverage 13/13)
// lua_gc: stop, restart, collect, count (KB) or step the collector.
extern "C" int __cdecl FUN_00213ba0(LuaVMState* L, int what, int data) {
    LuaVMGlobal* g = L->l_G;
    switch (what) {
    case 0:
        g->GCthreshold = 0x7fffffff;
        return 0;
    case 1:
        g->GCthreshold = g->totalbytes;
        return 0;
    case 2:
        FUN_00217490(L);
        return 0;
    case 3:
        return g->totalbytes >> 10;
    case 4:
        if (data > 0) {
            int n = data;
            do {
                if (g->totalbytes < g->GCthreshold)
                    g->GCthreshold = g->totalbytes;
                FUN_00217440(L);
                n--;
            } while (n != 0);
        }
        return 0;
    }
    return -1;
}


// 0x00213c40 FUN_00213c40 (16 B): matches/0x00213c40.cpp
// sym: _FUN_00213c40
// lua_error: raise the error on top of the stack (luaG_errormsg does not return).
extern "C" int __cdecl FUN_00213c40(LuaVMState* L) {
    FUN_002149b0(L);
    return 0;
}


// 0x00213c50 FUN_00213c50 (59 B): matches/0x00213c50.cpp
// sym: _FUN_00213c50
// lua_next: replace the key on top with the next key and value of the table at idx; pops it at the end.
extern "C" int __cdecl FUN_00213c50(LuaVMState* L, int idx) {
    LuaVMTObject* t = FUN_00212bb0(idx, L);
    int more = FUN_0021a020(L, (LuaVMTable*)t->value.gc, L->top - 1);
    if (more)
        L->top++;
    else
        L->top--;
    return more;
}


// 0x00213c90 FUN_00213c90 (125 B): matches/0x00213c90.cpp
// sym: _FUN_00213c90
// lua_concat: concatenate the n top values (n == 0 pushes ""); a GC step first when due.
extern "C" void __cdecl FUN_00213c90(LuaVMState* L, int n) {
    LuaVMGlobal* g = L->l_G;
    if (g->totalbytes >= g->GCthreshold)
        FUN_00217440(L);
    if (n >= 2) {
        FUN_00217f20(L, n, (int)(L->top - L->base) - 1);
        L->top -= n - 1;
        return;
    }
    if (n == 0) {
        LuaVMTObject* o = L->top;
        o->value.gc = (LuaVMGCObject*)FUN_00219430(L, (const char*)&DAT_003f335c, 0);
        o->tt = LUAVM_TSTRING;
        L->top++;
    }
}


// 0x00213d30 FUN_00213d30 (65 B): matches/0x00213d30.cpp
// sym: _FUN_00213d30
// lua_newuserdata: push a new full userdata of size bytes; returns its block (a GC step first when due).
extern "C" void* __cdecl FUN_00213d30(LuaVMState* L, unsigned int size) {
    LuaVMGlobal* g = L->l_G;
    if (g->totalbytes >= g->GCthreshold)
        FUN_00217440(L);
    LuaVMUdata* u = FUN_002194d0(L, size);
    LuaVMTObject* o = L->top;
    o->value.gc = (LuaVMGCObject*)u;
    o->tt = LUAVM_TUSERDATA;
    L->top++;
    return u + 1;
}


// 0x00213dd0 FUN_00213dd0 (115 B): matches/0x00213dd0.cpp
// sym: _FUN_00213dd0
// lua_getupvalue: push upvalue n of the function at funcindex; its name ("" for a C function) or NULL.
extern "C" const char* __cdecl FUN_00213dd0(LuaVMState* L, int funcindex, int n) {
    LuaVMTObject* fi = FUN_00212bb0(funcindex, L);
    if (fi->tt != LUAVM_TFUNCTION)
        return 0;
    LuaVMClosure* f = (LuaVMClosure*)fi->value.gc;
    LuaVMTObject* val;
    const char* name;
    if (f->c.isC) {
        if (n > f->c.nupvalues)
            return 0;
        val = &f->c.upvalue[n - 1];
        name = (const char*)&DAT_003f335c;
    } else {
        LuaVMProto* p = f->l.p;
        if (n > p->sizeupvalues)
            return 0;
        val = f->l.upvals[n - 1]->v;
        name = LUAVM_GETSTR(p->upvalues[n - 1]);
    }
    if (name) {
        LuaVMTObject* o = L->top;
        o->tt = val->tt;
        o->value = val->value;
        L->top++;
    }
    return name;
}


// 0x00213e50 FUN_00213e50 (157 B): equivalent/0x00213e50.cpp
// sym: _FUN_00213e50 @3dd27258316e @w278bd81994e2
// STATUS: equivalent (tools/equiv.py level 3: 3021 inputs, branch coverage 15/16, incomplete)
// lua_setupvalue: pop the top value into upvalue n of the function at funcindex (the write barrier); its name or NULL.
extern "C" const char* __cdecl FUN_00213e50(LuaVMState* L, int funcindex, int n) {
    LuaVMTObject* fi = FUN_00212bb0(funcindex, L);
    if (fi->tt != LUAVM_TFUNCTION)
        return 0;

    LuaVMClosure* f = (LuaVMClosure*)fi->value.gc;
    LuaVMTObject* val;
    const char* name;
    if (f->c.isC) {
        if (n > f->c.nupvalues)
            return 0;
        val = &f->c.upvalue[n - 1];
        name = (const char*)&DAT_003f335c;
    } else {
        LuaVMProto* p = f->l.p;
        if (n > p->sizeupvalues)
            return 0;
        name = LUAVM_GETSTR(p->upvalues[n - 1]);
        val = f->l.upvals[n - 1]->v;
        if (name == 0)
            return 0;
    }

    L->top--;
    *val = *L->top;
    if (L->top->tt >= LUAVM_TSTRING) {
        LuaVMGCObject* o = L->top->value.gc;
        if ((o->marked & 3) != 0 && (fi->value.gc->marked & 4) != 0)
            FUN_00217100(L, fi->value.gc, o);
    }
    return name;
}

} // namespace fn_f4ee33a9
