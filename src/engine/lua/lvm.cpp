// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00217600..0x002192c0 (kind game, layer engine, confidence high)
#include "tree_prelude.h"
#include "decls/data/lua.h"
#define TREE_TU_BEGIN namespace fn_fee536da {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fee536da {} using namespace fn_fee536da;
#include "engine/lua.h"

// ---- declarations shared by the functions below
namespace fn_fee536da {
extern "C" int __cdecl FUN_00215ff0(const char* s, float* result);
extern "C" void __cdecl FUN_00215520(LuaVMState* L, int event, int line);
extern "C" void __cdecl FUN_00215460(LuaVMState* L, int n);
extern "C" void __cdecl FUN_002159e0(LuaVMState* L, LuaVMTObject* func, int nresults);
extern "C" LuaVMTObject* __cdecl FUN_00219e90(LuaVMTable* t, const LuaVMTObject* key);
extern "C" const LuaVMTObject* __cdecl FUN_00217580(LuaVMTable* events, int event, LuaVMString* ename);
extern "C" const LuaVMTObject* __cdecl FUN_002175b0(LuaVMState* L, const LuaVMTObject* o, int event);
extern "C" void __cdecl FUN_00214c90(LuaVMState* L, const LuaVMTObject* o, const char* op);
extern "C" void __cdecl FUN_00214a90(LuaVMState* L, const char* fmt, ...);
extern "C" LuaVMTObject* __cdecl FUN_00219ef0(LuaVMState* L, LuaVMTable* t, const LuaVMTObject* key);
extern "C" void __cdecl FUN_00217100(LuaVMState* L, LuaVMGCObject* o, LuaVMGCObject* v);
extern "C" void __cdecl FUN_00217790(LuaVMState* L, LuaVMTObject* res);
extern "C" int __cdecl FUN_00215fa0(const LuaVMTObject* t1, const LuaVMTObject* t2);
extern "C" int __cdecl FUN_003473c6(const char* a, const char* b);
extern "C" int __cdecl FUN_00214d80(LuaVMState* L, const LuaVMTObject* p1, const LuaVMTObject* p2);
extern "C" int __cdecl FUN_00217be0(LuaVMState* L, const LuaVMTObject* p1, int event, const LuaVMTObject* p2);
extern "C" int __cdecl FUN_00217c80(const LuaVMString* ls, const LuaVMString* rs);
extern "C" const LuaVMTObject* __cdecl FUN_00217b60(LuaVMTable* mt1, int event, LuaVMTable* mt2, LuaVMState* L);
extern "C" void __cdecl FUN_00217750(LuaVMState* L, const LuaVMTObject* f, const LuaVMTObject* p1,
                                     const LuaVMTObject* p2);
extern "C" int __cdecl FUN_00217640(LuaVMState* L, LuaVMTObject* obj);
extern "C" void __cdecl FUN_00214d20(LuaVMState* L, LuaVMTObject* p1, LuaVMTObject* p2);
extern "C" char* __cdecl FUN_0021a6b0(LuaVMState* L, LuaVMBuffer* buff, unsigned int n);
extern "C" LuaVMString* __cdecl FUN_00219430(LuaVMState* L, const char* str, unsigned int l);
extern "C" LuaVMTObject* __cdecl FUN_00219e50(LuaVMTable* t, LuaVMString* key);
extern "C" int __cdecl FUN_00217af0(LuaVMState* L, const LuaVMTObject* p1, const LuaVMTObject* p2, LuaVMTObject* res,
                                    int event);
extern "C" void __cdecl FUN_00214d40(LuaVMState* L, const LuaVMTObject* p1, const LuaVMTObject* p2);


// 0x00217600 FUN_00217600 (61 B): matches/0x00217600.cpp
// sym: _FUN_00217600
// luaV_tonumber: obj itself when a number; a string converted into n; else 0.
extern "C" const LuaVMTObject* __cdecl FUN_00217600(const LuaVMTObject* obj, LuaVMTObject* n) {
    if (obj->tt == LUAVM_TNUMBER)
        return obj;
    if (obj->tt == LUAVM_TSTRING) {
        float num;
        if (FUN_00215ff0(LUAVM_GETSTR(obj->value.gc), &num)) {
            n->value.n = num;
            n->tt = LUAVM_TNUMBER;
            return n;
        }
    }
    return 0;
}


// 0x002176c0 FUN_002176c0 (129 B): equivalent/0x002176c0.cpp
// sym: _FUN_002176c0
// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 16/16)
// traceexec: save the pc and call the count hook or (on a new line or a jump back) the line hook.
// equiv-conv: FUN_002176c0 ebx edi
extern "C" void __cdecl FUN_002176c0(LuaVMState* L, const LuaVMInstruction* pc) {
    unsigned char mask = L->hookmask;
    LuaVMCallInfo* ci = L->ci;
    const LuaVMInstruction* oldpc = ci->savedpc;
    ci->savedpc = pc;

    if (mask > 4 && L->hookcount == 0) {
        L->hookcount = L->basehookcount;
        FUN_00215520(L, 3, -1);
        return;
    }

    if (mask & 4) {
        LuaVMProto* p = ((LuaVMLClosure*)ci->base[-1].value.gc)->p;
        int npc = (int)(pc - p->code) - 1;
        int newline = p->lineinfo ? p->lineinfo[npc] : 0;
        if (npc == 0 || pc <= oldpc || newline != (p->lineinfo ? p->lineinfo[(int)(oldpc - p->code) - 1] : 0))
            FUN_00215520(L, 2, newline);
    }
}


// 0x00217750 FUN_00217750 (59 B): equivalent/0x00217750.cpp
// sym: _FUN_00217750
// STATUS: equivalent (tools/equiv.py level 3: 2994 inputs, branch coverage 0/0)
// callTM's pushes: the metamethod f and its operands p1, p2 at the top of the stack (the caller moves top).
// equiv-conv: FUN_00217750 ecx stack eax edx
extern "C" void __cdecl FUN_00217750(LuaVMState* L, const LuaVMTObject* f, const LuaVMTObject* p1,
                                     const LuaVMTObject* p2) {
    L->top[0] = *f;
    L->top[1] = *p1;
    L->top[2] = *p2;
}


// 0x00217790 FUN_00217790 (88 B): equivalent/0x00217790.cpp
// sym: _FUN_00217790
// STATUS: equivalent (tools/equiv.py level 3: 2866 inputs, branch coverage 2/2)
// callTMres: call the metamethod pushed at the top (3 slots) for one result and store it in res.
// equiv-conv: FUN_00217790 ecx eax
extern "C" void __cdecl FUN_00217790(LuaVMState* L, LuaVMTObject* res) {
    hulk_intptr result = (char*)res - (char*)L->stack;  // savestack
    if ((char*)L->stack_last - (char*)L->top <= 3 * (int)sizeof(LuaVMTObject))
        FUN_00215460(L, 3);
    LuaVMTObject* func = L->top;
    L->top = func + 3;
    FUN_002159e0(L, func, 1);
    LuaVMTObject* src = L->top - 1;
    L->top = src;
    res = (LuaVMTObject*)((char*)L->stack + result);  // restorestack
    LUAVM_SETOBJ(res, src);
}


// 0x00217830 FUN_00217830 (331 B): equivalent/0x00217830.cpp
// sym: _FUN_00217830
// STATUS: equivalent (tools/equiv.py level 3: 2137 inputs, branch coverage 18/18)
// luaV_gettable: t[key] into val, following __index (a table or a function) up to 100 times.
extern "C" void __cdecl FUN_00217830(LuaVMState* L, const LuaVMTObject* t, LuaVMTObject* key, LuaVMTObject* val) {
    for (int loop = 0; loop < 100; ++loop) {
        const LuaVMTObject* tm = 0;
        if (t->tt == LUAVM_TTABLE) {
            LuaVMTable* h = (LuaVMTable*)t->value.gc;
            const LuaVMTObject* res = FUN_00219e90(h, key);
            if (res->tt == LUAVM_TNIL) {
                LuaVMTable* mt = h->metatable;
                if (mt && !(mt->flags & 1))
                    tm = FUN_00217580(mt, 0, L->l_G->tmname[0]);
            }
            if (!tm) {
                *val = *res;
                return;
            }
        } else {
            tm = FUN_002175b0(L, t, 0);
            if (tm->tt == LUAVM_TNIL)
                FUN_00214c90(L, t, "index");
        }

        if (tm->tt == LUAVM_TFUNCTION) {
            L->top[0] = *tm;
            L->top[1] = *t;
            L->top[2] = *key;
            hulk_intptr result = (char*)val - (char*)L->stack;  // callTMres, inlined
            if ((char*)L->stack_last - (char*)L->top <= 3 * (int)sizeof(LuaVMTObject))
                FUN_00215460(L, 3);
            L->top += 3;
            FUN_002159e0(L, L->top - 3, 1);
            L->top -= 1;
            LuaVMTObject* dst = (LuaVMTObject*)((char*)L->stack + result);
            *dst = *L->top;
            return;
        }
        t = tm;
    }
    FUN_00214a90(L, "loop in gettable");
}


// 0x00217980 FUN_00217980 (363 B): equivalent/0x00217980.cpp
// sym: _FUN_00217980
// STATUS: equivalent (tools/equiv.py level 3: 2124 inputs, branch coverage 24/24)
// luaV_settable: t[key] = val (with the barrier), following __newindex (a table or a function) up to 100 times.
extern "C" void __cdecl FUN_00217980(LuaVMState* L, const LuaVMTObject* t, LuaVMTObject* key, LuaVMTObject* val) {
    for (int loop = 0; loop < 100; loop++) {
        const LuaVMTObject* tm;
        if (t->tt == LUAVM_TTABLE) {
            LuaVMTable* h = (LuaVMTable*)t->value.gc;
            LuaVMTObject* oldval = FUN_00219ef0(L, h, key);
            LuaVMTable* mt;
            tm = 0;
            if (oldval->tt != LUAVM_TNIL || (mt = h->metatable) == 0 || (mt->flags & 2) != 0 ||
                (tm = FUN_00217580(mt, 1, L->l_G->tmname[1])) == 0) {
                *oldval = *val;
                if (val->tt >= LUAVM_TSTRING && (val->value.gc->marked & 3) != 0 && (h->marked & 4) != 0)
                    FUN_00217100(L, (LuaVMGCObject*)h, val->value.gc);
                return;
            }
        } else {
            tm = FUN_002175b0(L, t, 1);
            if (tm->tt == LUAVM_TNIL)
                FUN_00214c90(L, t, "index");
        }
        if (tm->tt == LUAVM_TFUNCTION) {
            L->top[0] = *tm;
            L->top[1] = *t;
            L->top[2] = *key;
            L->top[3] = *val;
            if ((char*)L->stack_last - (char*)L->top <= 4 * (int)sizeof(LuaVMTObject))
                FUN_00215460(L, 4);
            LuaVMTObject* func = L->top;
            L->top = func + 4;
            FUN_002159e0(L, func, 0);
            return;
        }
        t = tm;
    }
    FUN_00214a90(L, "loop in settable");
}


// 0x00217af0 FUN_00217af0 (107 B): equivalent/0x00217af0.cpp
// sym: _FUN_00217af0
// STATUS: equivalent (tools/equiv.py level 3: 3009 inputs, branch coverage 4/4)
// call_binTM: call the event's metamethod of p1 (else p2) on p1, p2 into res; 0 when there is none.
// equiv-conv: FUN_00217790 ecx eax
// equiv-conv: FUN_00217af0 esi ebx edi stack stack
extern "C" int __cdecl FUN_00217af0(LuaVMState* L, const LuaVMTObject* p1, const LuaVMTObject* p2, LuaVMTObject* res,
                                    int event) {
    const LuaVMTObject* tm = FUN_002175b0(L, p1, event);
    if (tm->tt == LUAVM_TNIL)
        tm = FUN_002175b0(L, p2, event);
    if (tm->tt != LUAVM_TFUNCTION)
        return 0;
    L->top->tt = LUAVM_TFUNCTION;
    L->top->value = tm->value;
    LUAVM_SETOBJ(L->top + 1, p1);
    LUAVM_SETOBJ(L->top + 2, p2);
    FUN_00217790(L, res);
    return 1;
}


// 0x00217b60 FUN_00217b60 (124 B): equivalent/0x00217b60.cpp
// sym: _FUN_00217b60
// STATUS: equivalent (tools/equiv.py level 3: 3009 inputs, branch coverage 14/14)
// get_compTM: the comparison metamethod shared by two metatables, or 0.
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


// 0x00217be0 FUN_00217be0 (158 B): equivalent/0x00217be0.cpp
// sym: _FUN_00217be0
// STATUS: equivalent (tools/equiv.py level 3: 3010 inputs, branch coverage 10/10)
// call_orderTM: the truth of an order metamethod shared by p1 and p2, or -1 when there is none.
// equiv-conv: FUN_00217790 ecx eax
// equiv-conv: FUN_00217be0 eax stack stack ebx
extern "C" int __cdecl FUN_00217be0(LuaVMState* L, const LuaVMTObject* p1, int event, const LuaVMTObject* p2) {
    const LuaVMTObject* tm1 = FUN_002175b0(L, p1, event);
    if (tm1->tt == LUAVM_TNIL)
        return -1;
    const LuaVMTObject* tm2 = FUN_002175b0(L, p2, event);
    if (!FUN_00215fa0(tm1, tm2))
        return -1;

    L->top[0] = *tm1;
    L->top[1] = *p1;
    L->top[2] = *p2;
    FUN_00217790(L, L->top);

    const LuaVMTObject* r = L->top;
    if (r->tt == LUAVM_TNIL)
        return 0;
    if (r->tt == LUAVM_TBOOLEAN && r->value.b == 0)
        return 0;
    return 1;
}


// 0x00217c80 FUN_00217c80 (104 B): equivalent/0x00217c80.cpp
// sym: _FUN_00217c80
// STATUS: equivalent (tools/equiv.py level 3: 3003 inputs, branch coverage 12/12)
// l_strcmp: compare two strings by strcoll, part by part across embedded NULs.
// equiv-conv: FUN_00217c80 ecx eax
extern "C" int __cdecl FUN_00217c80(const LuaVMString* ls, const LuaVMString* rs) {
    const char* l = LUAVM_GETSTR(ls);
    unsigned int ll = ls->len;
    const char* r = LUAVM_GETSTR(rs);
    unsigned int lr = rs->len;
    for (;;) {
        int temp = FUN_003473c6(l, r);
        if (temp != 0)
            return temp;
        unsigned int len = (unsigned int)strlen(l);
        if (len == lr)
            return len != ll;
        if (len == ll)
            return -1;
        len++;
        l += len;
        ll -= len;
        r += len;
        lr -= len;
    }
}


// 0x00217cf0 FUN_00217cf0 (133 B): equivalent/0x00217cf0.cpp
// sym: _FUN_00217cf0
// STATUS: equivalent (tools/equiv.py level 3: 3032 inputs, branch coverage 12/12)
// luaV_lessthan: l < r for numbers, strings or by __lt.
// equiv-conv: FUN_00217be0 eax stack stack ebx
// equiv-conv: FUN_00217c80 ecx eax
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


// 0x00217d80 FUN_00217d80 (147 B): equivalent/0x00217d80.cpp
// sym: _FUN_00217d80
// STATUS: equivalent (tools/equiv.py level 3: 3034 inputs, branch coverage 16/16)
// luaV_lessequal: l <= r for numbers, strings, by __le or by not (r < l).
// equiv-conv: FUN_00217be0 eax stack stack ebx
// equiv-conv: FUN_00217c80 ecx eax
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


// 0x00217e20 FUN_00217e20 (212 B): equivalent/0x00217e20.cpp
// sym: _FUN_00217e20
// STATUS: equivalent (tools/equiv.py level 3: 3035 inputs, branch coverage 22/22)
// luaV_equalval: t1 == t2 for two values of one type (tables and userdata by __eq).
// equiv-conv: FUN_00217b60 edi esi ebx stack
// equiv-conv: FUN_00217750 ecx stack eax edx
// equiv-conv: FUN_00217790 ecx eax
extern "C" int __cdecl FUN_00217e20(LuaVMState* L, const LuaVMTObject* t1, const LuaVMTObject* t2) {
    switch (t1->tt) {
    case LUAVM_TNIL:
        return 1;
    case LUAVM_TNUMBER:
        return t1->value.n == t2->value.n;
    case LUAVM_TTABLE:
    case LUAVM_TUSERDATA: {
        if (t1->value.gc == t2->value.gc)
            return 1;
        // a table's and a userdata's metatable (the original reads both at the one offset they share)
        LuaVMTable* mt1 = t1->tt == LUAVM_TTABLE ? ((LuaVMTable*)t1->value.gc)->metatable
                                                 : ((LuaVMUdata*)t1->value.gc)->metatable;
        LuaVMTable* mt2 = t1->tt == LUAVM_TTABLE ? ((LuaVMTable*)t2->value.gc)->metatable
                                                 : ((LuaVMUdata*)t2->value.gc)->metatable;
        const LuaVMTObject* tm = FUN_00217b60(mt1, 4, mt2, L);
        if (!tm)
            return 0;
        FUN_00217750(L, tm, t1, t2);
        FUN_00217790(L, L->top);
        const LuaVMTObject* res = L->top;
        return res->tt != LUAVM_TNIL && (res->tt != LUAVM_TBOOLEAN || res->value.b != 0);
    }
    case LUAVM_TBOOLEAN:
        return t1->value.b == t2->value.b;
    default:  // light userdata, strings, functions, threads: by the pointer (the original's 32-bit compare)
        return t1->value.p == t2->value.p;
    }
}


// 0x00217f20 FUN_00217f20 (590 B): equivalent/0x00217f20.cpp
// sym: _FUN_00217f20
// STATUS: equivalent (tools/equiv.py level 3: 399 inputs, branch coverage 31/32, incomplete)
// luaV_concat: concatenate the total values ending at base[last] (strings and numbers, else by __concat).
extern "C" void __cdecl FUN_00217f20(LuaVMState* L, int total, int last) {
    int n;
    do {
        LuaVMTObject* top = L->base + last + 1;
        n = 2;
        if ((top[-2].tt == LUAVM_TSTRING || FUN_00217640(L, top - 2)) &&
            (top[-1].tt == LUAVM_TSTRING || FUN_00217640(L, top - 1))) {
            LuaVMString* s1 = (LuaVMString*)top[-1].value.gc;
            if (s1->len != 0) {
                unsigned int tl = ((LuaVMString*)top[-2].value.gc)->len + s1->len;
                if (total > n) {
                    LuaVMTObject* p = top - 3;
                    do {
                        if (p->tt != LUAVM_TSTRING && !FUN_00217640(L, p))
                            break;
                        tl += ((LuaVMString*)p->value.gc)->len;
                        n++;
                        p--;
                    } while (n < total);
                }
                if (tl > 0xfffffffdu)
                    FUN_00214a90(L, "string size overflow");
                char* buffer = FUN_0021a6b0(L, &L->l_G->buff, tl);
                tl = 0;
                for (int i = n; i > 0; i--) {
                    LuaVMString* s = (LuaVMString*)top[-i].value.gc;
                    unsigned int len = s->len;
                    memcpy(buffer + tl, LUAVM_GETSTR(s), len);
                    tl += len;
                }
                top[-n].value.gc = (LuaVMGCObject*)FUN_00219430(L, buffer, tl);
                top[-n].tt = LUAVM_TSTRING;
            }
        } else {
            LuaVMTObject* p1 = top - 2;
            LuaVMTObject* p2 = top - 1;
            const LuaVMTObject* tm = FUN_002175b0(L, p1, 0xd);  // call_binTM(TM_CONCAT), inlined
            if (tm->tt == LUAVM_TNIL)
                tm = FUN_002175b0(L, p2, 0xd);
            if (tm->tt != LUAVM_TFUNCTION) {
                FUN_00214d20(L, p1, p2);
            } else {
                L->top->tt = LUAVM_TFUNCTION;
                L->top->value = tm->value;
                LUAVM_SETOBJ(L->top + 1, p1);
                LUAVM_SETOBJ(L->top + 2, p2);
                hulk_intptr result = (char*)(top - 2) - (char*)L->stack;
                if ((char*)L->stack_last - (char*)L->top <= 3 * (int)sizeof(LuaVMTObject))
                    FUN_00215460(L, 3);
                LuaVMTObject* func = L->top;
                L->top = func + 3;
                FUN_002159e0(L, func, 1);
                LuaVMTObject* res = L->top - 1;
                LuaVMTObject* stack = L->stack;
                L->top = res;
                LuaVMTObject* dst = (LuaVMTObject*)((char*)stack + result);
                LUAVM_SETOBJ(dst, res);
            }
        }
        total -= n - 1;
        last -= n - 1;
    } while (total > 1);
}


// 0x00218170 FUN_00218170 (448 B): equivalent/0x00218170.cpp
// sym: _FUN_00218170
// STATUS: equivalent (tools/equiv.py level 3: 3042 inputs, branch coverage 23/23)
// Arith: ra = rb op rc for numbers (and convertible strings), ^ by the global __pow, else by a metamethod;
// saves pc first and returns the (possibly moved) base.
// equiv-conv: FUN_00217750 ecx stack eax edx
// equiv-conv: FUN_00217790 ecx eax
// equiv-conv: FUN_00217af0 esi ebx edi stack stack
// equiv-conv: FUN_00218170 eax ecx edx stack stack stack
extern "C" LuaVMTObject* __cdecl FUN_00218170(const LuaVMTObject* rc, const LuaVMTObject* rb, const LuaVMInstruction* pc,
                                          LuaVMState* L, LuaVMTObject* ra, int op) {
    LuaVMValue num;  // luaO_str2d's result, copied by its bits
    LuaVMTObject tempc;
    LuaVMTObject tempb;
    const LuaVMTObject* b = rb;
    const LuaVMTObject* c = rc;
    L->ci->savedpc = pc;

    bool bnum = rb->tt == LUAVM_TNUMBER;
    if (rb->tt == LUAVM_TSTRING) {
        if (FUN_00215ff0(LUAVM_GETSTR(rb->value.gc), &num.n)) {
            tempb.value = num;
            tempb.tt = LUAVM_TNUMBER;
            b = &tempb;
            bnum = true;
        }
    }

    if (bnum) {
        bool cnum = rc->tt == LUAVM_TNUMBER;
        if (rc->tt == LUAVM_TSTRING) {
            if (FUN_00215ff0(LUAVM_GETSTR(rc->value.gc), &num.n)) {
                tempc.value = num;
                tempc.tt = LUAVM_TNUMBER;
                c = &tempc;
                cnum = true;
            }
        }
        if (cnum) {
            switch (op) {
            case 5: {  // TM_ADD
                float v = c->value.n + b->value.n;
                ra->tt = LUAVM_TNUMBER;
                ra->value.n = v;
                return L->base;
            }
            case 6: {  // TM_SUB
                float v = b->value.n - c->value.n;
                ra->tt = LUAVM_TNUMBER;
                ra->value.n = v;
                return L->base;
            }
            case 7: {  // TM_MUL
                float v = c->value.n * b->value.n;
                ra->tt = LUAVM_TNUMBER;
                ra->value.n = v;
                return L->base;
            }
            case 8: {  // TM_DIV
                float v = b->value.n / c->value.n;
                ra->tt = LUAVM_TNUMBER;
                ra->value.n = v;
                return L->base;
            }
            case 9: {  // TM_POW: the global __pow
                const LuaVMTObject* f = FUN_00219e50((LuaVMTable*)L->_gt.value.gc, L->l_G->tmname[9]);
                if (f->tt != LUAVM_TFUNCTION)
                    FUN_00214a90(L, "`__pow' (`^' operator) is not a function");
                FUN_00217750(L, f, b, c);
                FUN_00217790(L, ra);
                return L->base;
            }
            default:
                return L->base;
            }
        }
    }

    if (FUN_00217af0(L, rb, rc, ra, op) == 0)
        FUN_00214d40(L, rb, rc);
    return L->base;
}

} // namespace fn_fee536da

// 0x00218350 FUN_00218350 (3806 B): equivalent/0x00218350.cpp [wrapped: macros]
// sym: _FUN_00218350
namespace fn_00218350 {
// STATUS: equivalent (tools/equiv.py level 3: 958 inputs, branch coverage 228/230, incomplete)
// luaV_execute: the interpreter loop (calls and returns of Lua functions stay inside the loop, nexeccalls deep).

#define LUA_MASKCALL 1
#define LUA_MASKLINE 4
#define LUA_MASKCOUNT 8
#define MAXSTACK 250

#define GET_OPCODE(i) ((i) & 0x3f)
#define GETARG_A(i) ((int)((i) >> 24))
#define GETARG_B(i) ((int)(((i) >> 15) & 0x1ff))
#define GETARG_C(i) ((int)(((i) >> 6) & 0x1ff))
#define GETARG_Bx(i) ((int)(((i) >> 6) & 0x3ffff))
#define GETARG_sBx(i) (GETARG_Bx(i) - 0x1ffff)

#define RA(i) (base + GETARG_A(i))
#define RB(i) (base + GETARG_B(i))
#define RKB(i) ((GETARG_B(i) < MAXSTACK) ? base + GETARG_B(i) : k + GETARG_B(i) - MAXSTACK)
#define RKC(i) ((GETARG_C(i) < MAXSTACK) ? base + GETARG_C(i) : k + GETARG_C(i) - MAXSTACK)
#define KBx(i) (k + GETARG_Bx(i))

#define ttisnil(o) ((o)->tt == 0)
#define ttisnumber(o) ((o)->tt == 3)
#define ttisstring(o) ((o)->tt == 4)
#define ttistable(o) ((o)->tt == 5)
#define ttisfunction(o) ((o)->tt == 6)
#define l_isfalse(o) (ttisnil(o) || ((o)->tt == 1 && (o)->value.b == 0))

#define tonumber(o, tmp)                                                                                     \
    ((o)->tt == 3 || (((o) = ((o)->tt == 4 && FUN_00215ff0(LUAVM_GETSTR((o)->value.gc), &num_))        \
                                 ? (((tmp)->value.n = num_), ((tmp)->tt = 3), (tmp))                         \
                                 : 0) != 0))

#define luaC_checkGC(L)                                                                                      \
    {                                                                                                        \
        if ((L)->l_G->totalbytes >= (L)->l_G->GCthreshold)                                                      \
            FUN_00217440(L);                                                                                 \
    }

#define luaC_barrier(L, p, v)                                                                                \
    {                                                                                                        \
        if ((v)->tt >= 4 && ((v)->value.gc->marked & 3) && (((LuaVMGCObject*)(p))->marked & 4))              \
            FUN_00217100(L, (LuaVMGCObject*)(p), (v)->value.gc);                                             \
    }

#define Arith_inline(op, expr, tm)                                                                           \
    {                                                                                                        \
        LuaVMTObject* rb_ = RKB(i);                                                                                  \
        LuaVMTObject* rc_ = RKC(i);                                                                                  \
        if (ttisnumber(rb_) && ttisnumber(rc_)) {                                                            \
            ra->tt = 3;                                                                                      \
            ra->value.n = expr;                                                                              \
        } else                                                                                               \
            base = FUN_00218170(rc_, rb_, pc, L, ra, tm);                                                    \
    }

extern "C++" __declspec(nothrow) void __cdecl FUN_00215520(LuaVMState* L, int event, int line);
// equiv-conv: FUN_002176c0 ebx edi
extern "C++" __declspec(nothrow) void __cdecl FUN_002176c0(LuaVMState* L, const LuaVMInstruction* pc);
extern "C++" __declspec(nothrow) void __cdecl FUN_00217830(LuaVMState* L, const LuaVMTObject* t, LuaVMTObject* key, LuaVMTObject* val);
extern "C++" __declspec(nothrow) void __cdecl FUN_00217980(LuaVMState* L, const LuaVMTObject* t, LuaVMTObject* key, LuaVMTObject* val);
extern "C++" __declspec(nothrow) void __cdecl FUN_00217100(LuaVMState* L, LuaVMGCObject* o, LuaVMGCObject* v);
extern "C" LuaVMTable* __cdecl FUN_00219cc0(LuaVMState* L, int narray, int lnhash);
extern "C" void __cdecl FUN_00217440(LuaVMState* L);
// equiv-conv: FUN_00218170 eax ecx edx stack stack stack
extern "C++" __declspec(nothrow) LuaVMTObject* __cdecl FUN_00218170(const LuaVMTObject* rc, const LuaVMTObject* rb, const LuaVMInstruction* pc,
                                          LuaVMState* L, LuaVMTObject* ra, int op);
extern "C" int __cdecl FUN_00215ff0(const char* s, float* result);
extern "C++" __declspec(nothrow) const LuaVMTObject* __cdecl FUN_002175b0(LuaVMState* L, const LuaVMTObject* o, int event);
// equiv-conv: FUN_00217790 ecx eax
extern "C++" __declspec(nothrow) void __cdecl FUN_00217790(LuaVMState* L, LuaVMTObject* res);
extern "C++" __declspec(nothrow) void __cdecl FUN_00214d40(LuaVMState* L, const LuaVMTObject* p1, const LuaVMTObject* p2);
extern "C++" __declspec(nothrow) void __cdecl FUN_00217f20(LuaVMState* L, int total, int last);
extern "C++" __declspec(nothrow) int __cdecl FUN_00217e20(LuaVMState* L, const LuaVMTObject* t1, const LuaVMTObject* t2);
extern "C++" __declspec(nothrow) int __cdecl FUN_00217cf0(LuaVMState* L, const LuaVMTObject* l, const LuaVMTObject* r);
// equiv-conv: FUN_00217d80 edi esi stack
extern "C++" __declspec(nothrow) int __cdecl FUN_00217d80(const LuaVMTObject* l, const LuaVMTObject* r, LuaVMState* L);
extern "C" LuaVMTObject* __cdecl FUN_00215790(LuaVMState* L, LuaVMTObject* func);
extern "C" void __cdecl FUN_00215970(LuaVMState* L, int wanted, LuaVMTObject* firstResult);
extern "C++" __declspec(nothrow) void __cdecl FUN_00214a90(LuaVMState* L, const char* fmt, ...);
extern "C++" __declspec(nothrow) void __cdecl FUN_002159e0(LuaVMState* L, LuaVMTObject* func, int nresults);
extern "C++" __declspec(nothrow) LuaVMString* __cdecl FUN_00219430(LuaVMState* L, const char* str, unsigned int l);
extern "C++" __declspec(nothrow) LuaVMTObject* __cdecl FUN_00219e50(LuaVMTable* t, LuaVMString* key);
extern "C" LuaVMTObject* __cdecl FUN_00219f60(LuaVMState* L, LuaVMTable* t, int key);
extern "C" void __cdecl FUN_00219660(LuaVMState* L, LuaVMTObject* level);
extern "C" LuaVMClosure* __cdecl FUN_00219560(LuaVMState* L, int nelems, const LuaVMTObject* e);
extern "C" LuaVMUpVal* __cdecl FUN_00219610(LuaVMState* L, LuaVMTObject* level);

extern "C" LuaVMTObject* __cdecl FUN_00218350(LuaVMState* L, int nexeccalls) {
    // A call installs a new frame and runs its hook; a return resumes a frame
    // without running the call hook again.
    bool enteringCall = true;
    for (;;) {
        LuaVMLClosure* cl;
        LuaVMTObject* base;
        LuaVMTObject* k;
        const LuaVMInstruction* pc;
        bool switchFrame = false;

        if (enteringCall && (L->hookmask & LUA_MASKCALL))
            FUN_00215520(L, 0, -1);
        enteringCall = false;
        pc = L->ci->savedpc;
        cl = (LuaVMLClosure*)(L->base - 1)->value.gc;
        base = L->base;
        k = cl->p->k;

        while (!switchFrame) {
            const LuaVMInstruction i = *pc++;
            LuaVMTObject* ra;
            if ((L->hookmask & (LUA_MASKLINE | LUA_MASKCOUNT)) &&
                (--L->hookcount == 0 || L->hookmask & LUA_MASKLINE)) {
                FUN_002176c0(L, pc);
                if (L->status) {  // +0x32: the thread's status here (a hook yielded)
                    L->ci->savedpc = pc - 1;
                    return 0;
                }
                base = L->base;
            }
            ra = RA(i);
            switch (GET_OPCODE(i)) {
            case 0: { /* OP_MOVE */
                *ra = *RB(i);
                break;
            }
            case 1: { /* OP_LOADK */
                *ra = *KBx(i);
                break;
            }
            case 2: { /* OP_LOADBOOL */
                ra->value.b = GETARG_B(i);
                ra->tt = 1;
                if (GETARG_C(i))
                    pc++;
                break;
            }
            case 3: { /* OP_LOADNIL */
                LuaVMTObject* rb = RB(i);
                do {
                    (rb--)->tt = 0;
                } while (rb >= ra);
                break;
            }
            case 4: { /* OP_GETUPVAL */
                int b = GETARG_B(i);
                *ra = *cl->upvals[b]->v;
                break;
            }
            case 5: { /* OP_GETGLOBAL */
                L->ci->savedpc = pc;
                FUN_00217830(L, &cl->g, KBx(i), ra);
                base = L->base;
                break;
            }
            case 6: { /* OP_GETTABLE */
                L->ci->savedpc = pc;
                FUN_00217830(L, RB(i), RKC(i), ra);
                base = L->base;
                break;
            }
            case 7: { /* OP_SETGLOBAL */
                L->ci->savedpc = pc;
                FUN_00217980(L, &cl->g, KBx(i), ra);
                base = L->base;
                break;
            }
            case 8: { /* OP_SETUPVAL */
                LuaVMUpVal* uv = cl->upvals[GETARG_B(i)];
                *uv->v = *ra;
                luaC_barrier(L, uv, ra);
                break;
            }
            case 9: { /* OP_SETTABLE */
                L->ci->savedpc = pc;
                FUN_00217980(L, ra, RKB(i), RKC(i));
                base = L->base;
                break;
            }
            case 10: { /* OP_NEWTABLE */
                int b = GETARG_B(i);
                ra->value.gc = (LuaVMGCObject*)FUN_00219cc0(L, (b & 7) << (b >> 3), GETARG_C(i));
                ra->tt = 5;
                L->ci->savedpc = pc;
                luaC_checkGC(L);
                base = L->base;
                break;
            }
            case 11: { /* OP_SELF */
                LuaVMTObject* rb = RB(i);
                ra[1] = *rb;
                L->ci->savedpc = pc;
                FUN_00217830(L, rb, RKC(i), ra);
                base = L->base;
                break;
            }
            case 12: { /* OP_ADD */
                Arith_inline(+, rb_->value.n + rc_->value.n, 5) break;
            }
            case 13: { /* OP_SUB */
                Arith_inline(-, rb_->value.n - rc_->value.n, 6) break;
            }
            case 14: { /* OP_MUL */
                Arith_inline(*, rb_->value.n * rc_->value.n, 7) break;
            }
            case 15: { /* OP_DIV */
                Arith_inline(/, rb_->value.n / rc_->value.n, 8) break;
            }
            case 16: { /* OP_POW */
                base = FUN_00218170(RKC(i), RKB(i), pc, L, ra, 9);
                break;
            }
            case 17: { /* OP_UNM */
                LuaVMTObject* rb = RB(i);
                LuaVMTObject temp;
                float num_;
                if (tonumber(rb, &temp)) {
                    ra->tt = 3;
                    ra->value.n = -rb->value.n;
                } else {
                    const LuaVMTObject* tm;
                    temp.tt = 0;
                    L->ci->savedpc = pc;
                    tm = FUN_002175b0(L, RB(i), 10);
                    if (tm->tt == 0)
                        tm = FUN_002175b0(L, &temp, 10);
                    if (tm->tt == 6) {
                        *L->top = *tm;
                        L->top[1] = *RB(i);
                        L->top[2] = temp;
                        FUN_00217790(L, ra);
                    } else
                        FUN_00214d40(L, RB(i), &temp);
                    base = L->base;
                }
                break;
            }
            case 18: { /* OP_NOT */
                LuaVMTObject* rb = RB(i);
                ra->value.b = l_isfalse(rb) ? 1 : 0;
                ra->tt = 1;
                break;
            }
            case 19: { /* OP_CONCAT */
                int b = GETARG_B(i);
                int c = GETARG_C(i);
                L->ci->savedpc = pc;
                FUN_00217f20(L, c - b + 1, c);
                luaC_checkGC(L);
                base = L->base;
                *RA(i) = base[b];
                break;
            }
            case 20: { /* OP_JMP */
                pc += GETARG_sBx(i);
                break;
            }
            case 21: { /* OP_EQ */
                L->ci->savedpc = pc;
                if (((RKB(i)->tt == RKC(i)->tt) && FUN_00217e20(L, RKB(i), RKC(i))) != GETARG_A(i))
                    pc++;
                else
                    pc += GETARG_sBx(*pc) + 1;
                base = L->base;
                break;
            }
            case 22: { /* OP_LT */
                L->ci->savedpc = pc;
                if (FUN_00217cf0(L, RKB(i), RKC(i)) != GETARG_A(i))
                    pc++;
                else
                    pc += GETARG_sBx(*pc) + 1;
                base = L->base;
                break;
            }
            case 23: { /* OP_LE */
                L->ci->savedpc = pc;
                if (FUN_00217d80(RKB(i), RKC(i), L) != GETARG_A(i))
                    pc++;
                else
                    pc += GETARG_sBx(*pc) + 1;
                base = L->base;
                break;
            }
            case 24: { /* OP_TEST */
                LuaVMTObject* rb = RB(i);
                if (l_isfalse(rb) == GETARG_C(i))
                    pc++;
                else {
                    *ra = *rb;
                    pc += GETARG_sBx(*pc) + 1;
                }
                break;
            }
            case 25:   /* OP_CALL */
            case 26: { /* OP_TAILCALL */
                LuaVMTObject* firstResult;
                int b = GETARG_B(i);
                int nresults;
                if (b != 0)
                    L->top = ra + b;
                L->ci->savedpc = pc;
                firstResult = FUN_00215790(L, ra);
                if (firstResult) {
                    nresults = GETARG_C(i) - 1;
                    if (firstResult > L->top) {
                        (L->ci - 1)->savedpc = pc;
                        return 0;
                    }
                    FUN_00215970(L, nresults, firstResult);
                    if (nresults >= 0)
                        L->top = L->ci->top;
                    base = L->base;
                } else if (GET_OPCODE(i) == 25) {
                    nexeccalls++;
                    enteringCall = true;
                    switchFrame = true;
                } else {
                    // Re-read ci at each update: it may overlap the state itself.
                    int count;
                    base = (L->ci - 1)->base;
                    ra = RA(i);
                    if (L->openupval)
                        FUN_00219660(L, base);
                    for (count = 0; ra + count < L->top; count++)
                        (base - 1)[count] = ra[count];
                    LuaVMTObject* newTop = base + count;
                    L->top = newTop;
                    (L->ci - 1)->top = newTop;
                    (L->ci - 1)->savedpc = L->ci->savedpc;
                    (L->ci - 1)->tailcalls++;
                    L->ci = L->ci - 1;
                    L->base = L->ci->base;
                    enteringCall = true;
                    switchFrame = true;
                }
                break;
            }
            case 27: { /* OP_RETURN */
                LuaVMCallInfo* ci = L->ci - 1;
                int b = GETARG_B(i);
                int nresults;
                if (b != 0)
                    L->top = ra + b - 1;
                if (L->openupval)
                    FUN_00219660(L, base);
                L->ci->savedpc = pc;
                if (--nexeccalls == 0)
                    return ra;
                nresults = GETARG_C(ci->savedpc[-1]) - 1;
                FUN_00215970(L, nresults, ra);
                if (nresults >= 0)
                    L->top = L->ci->top;
                switchFrame = true;
                break;
            }
            case 28: { /* OP_FORLOOP */
                float limit = ra[1].value.n;
                volatile float idx = ra[2].value.n + ra->value.n;
                if (ra[2].value.n > 0 ? idx <= limit : idx >= limit) {
                    pc += GETARG_sBx(i);
                    ra->value.n = idx;
                    ra->tt = 3;
                    ra[3].value.n = idx;
                    ra[3].tt = 3;
                }
                break;
            }
            case 29: { /* OP_FORPREP */
                LuaVMTObject* init = ra;
                LuaVMTObject* plimit = ra + 1;
                LuaVMTObject* pstep = ra + 2;
                float num_;
                L->ci->savedpc = pc;
                if (!tonumber(init, ra))
                    FUN_00214a90(L, "`for' initial value must be a number");
                else if (!tonumber(plimit, ra + 1))
                    FUN_00214a90(L, "`for' limit must be a number");
                else if (!tonumber(pstep, ra + 2))
                    FUN_00214a90(L, "`for' step must be a number");
                ra->tt = 3;
                ra->value.n = ra->value.n - pstep->value.n;
                pc += GETARG_sBx(i);
                break;
            }
            case 30: { /* OP_TFORLOOP */
                LuaVMTObject* cb = ra + 3;
                cb[2] = ra[2];
                cb[1] = ra[1];
                cb[0] = ra[0];
                L->top = cb + 3;
                L->ci->savedpc = pc;
                FUN_002159e0(L, cb, GETARG_C(i));
                L->top = L->ci->top;
                base = L->base;
                cb = RA(i) + 3;
                if (cb->tt == 0)
                    pc++;
                else {
                    cb[-1] = *cb;
                    pc += GETARG_sBx(*pc) + 1;
                }
                break;
            }
            case 31: { /* OP_TFORPREP */
                if (ra->tt == 5) {
                    ra[1] = ra[0];
                    *ra = *FUN_00219e50((LuaVMTable*)L->_gt.value.gc, FUN_00219430(L, "next", 4));
                }
                pc += GETARG_sBx(i);
                break;
            }
            case 32:
            case 33: { /* OP_SETLIST, OP_SETLISTO */
                int bc;
                int n;
                LuaVMTable* h;
                if (ra->tt != 5)
                    return 0;
                h = (LuaVMTable*)ra->value.gc;
                bc = GETARG_Bx(i);
                if (GET_OPCODE(i) == 32)
                    n = (bc & 31) + 1;
                else {
                    n = (int)(L->top - ra) - 1;
                    L->top = L->ci->top;
                }
                bc &= ~31;
                for (; n > 0; n--) {
                    LuaVMTObject* o = FUN_00219f60(L, h, bc + n);
                    *o = ra[n];
                    luaC_barrier(L, h, &ra[n]);
                }
                break;
            }
            case 34: { /* OP_CLOSE */
                FUN_00219660(L, ra);
                break;
            }
            case 35: { /* OP_CLOSURE */
                LuaVMProto* p = cl->p->p[GETARG_Bx(i)];
                int nup = p->nups;
                LuaVMLClosure* ncl = &FUN_00219560(L, nup, &cl->g)->l;
                int j;
                ncl->p = p;
                for (j = 0; j < nup; j++, pc++) {
                    if (GET_OPCODE(*pc) == 4)
                        ncl->upvals[j] = cl->upvals[GETARG_B(*pc)];
                    else
                        ncl->upvals[j] = FUN_00219610(L, base + GETARG_B(*pc));
                }
                ra->value.gc = (LuaVMGCObject*)ncl;
                ra->tt = 6;
                L->ci->savedpc = pc;
                luaC_checkGC(L);
                base = L->base;
                break;
            }
            }
        }
    }
}
} // namespace fn_00218350
#undef Arith_inline
#undef GETARG_A
#undef GETARG_B
#undef GETARG_Bx
#undef GETARG_C
#undef GETARG_sBx
#undef GET_OPCODE
#undef KBx
#undef LUA_MASKCALL
#undef LUA_MASKCOUNT
#undef LUA_MASKLINE
#undef MAXSTACK
#undef RA
#undef RB
#undef RKB
#undef RKC
#undef l_isfalse
#undef luaC_barrier
#undef luaC_checkGC
#undef tonumber
#undef ttisfunction
#undef ttisnil
#undef ttisnumber
#undef ttisstring
#undef ttistable

