// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00215240..0x00215f50 (kind game, layer engine, confidence high)
#include "tree_prelude.h"
#include "decls/data/lua.h"
#define TREE_TU_BEGIN namespace fn_ffc5dd1e {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_ffc5dd1e {} using namespace fn_ffc5dd1e;
#include "engine/lua.h"

// ---- declarations shared by the functions below
namespace fn_ffc5dd1e {
extern "C" LuaVMString* __cdecl FUN_00219430(LuaVMState* L, const char* str, unsigned int l);
} // namespace fn_ffc5dd1e
extern "C" int __cdecl __setjmp3(void* environment, int count);
namespace fn_ffc5dd1e {
extern "C" void* __cdecl FUN_0021add0(LuaVMState* L, void* block, unsigned int osize, unsigned int nsize);
extern "C" void __cdecl FUN_00215350(LuaVMState* L, LuaVMTObject* oldstack);
extern "C++" LuaVMTObject* __cdecl FUN_00215710(LuaVMState* L, LuaVMTObject* func);
extern "C++" LuaVMTObject* __cdecl FUN_002155f0(LuaVMTObject* base, LuaVMState* L, int nfixargs);
extern "C++" void __cdecl FUN_002152b0(LuaVMState* L, int errcode);
extern "C" void __cdecl FUN_00215410(LuaVMState* L, int newsize);
extern "C" void __cdecl FUN_00214a90(LuaVMState* L, const char* fmt, ...);
extern "C" void __cdecl FUN_00215460(LuaVMState* L, int n);
extern "C" void __cdecl FUN_00215520(LuaVMState* L, int event, int line);
extern "C" LuaVMTObject* __cdecl FUN_00215910(LuaVMTObject* firstResult, LuaVMState* L);
extern "C" LuaVMTObject* __cdecl FUN_00215790(LuaVMState* L, LuaVMTObject* func);
extern "C" LuaVMTObject* __cdecl FUN_00218350(LuaVMState* L, int nexeccalls);
extern "C" void __cdecl FUN_00215970(LuaVMState* L, int wanted, LuaVMTObject* firstResult);
extern "C" void __cdecl FUN_00217440(LuaVMState* L);
extern "C" void __cdecl FUN_00215a60(LuaVMState* L, void* ud);
extern "C" int __cdecl FUN_00215b00(LuaVMState* L, const char* msg);
extern "C" int __cdecl FUN_002152f0(LuaVMState* L, void(__cdecl* f)(LuaVMState* L, void* ud), void* ud);
extern "C" void __cdecl FUN_00219660(LuaVMState* L, LuaVMStkId level);
extern "C" void __cdecl FUN_00215240(int errcode, LuaVMTObject* oldtop, LuaVMState* L);
extern "C" int __cdecl FUN_00215de0(LuaVMState* L, void(__cdecl* func)(LuaVMState* L, void* ud), void* u, int oldtop,
                                    int ef);
extern "C++" void __cdecl FUN_00215c00(LuaVMState* L, void* ud);


// 0x00215240 FUN_00215240 (83 B): equivalent/0x00215240.cpp
// sym: _FUN_00215240 @e1f3b8745205 @w0a814387aa19
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 7/7)
// seterrorobj: the error object of a failed protected call at oldtop (the message, or the fixed memory /
// error-handler messages), and the top just above it.
// equiv-conv: FUN_00215240 eax ecx edi
extern "C" void __cdecl FUN_00215240(int errcode, LuaVMTObject* oldtop, LuaVMState* L) {
    if (errcode == 1 || errcode == 3) {
        LUAVM_SETOBJ(oldtop, L->top - 1);
    } else if (errcode == 4) {
        oldtop->value.gc = (LuaVMGCObject*)FUN_00219430(L, "not enough memory", 0x11);
        oldtop->tt = LUAVM_TSTRING;
    } else if (errcode == 5) {
        oldtop->value.gc = (LuaVMGCObject*)FUN_00219430(L, "error in error handling", 0x17);
        oldtop->tt = LUAVM_TSTRING;
    }
    L->top = oldtop + 1;
}

} // namespace fn_ffc5dd1e

// 0x002152b0 FUN_002152b0 (55 B): matches/0x002152b0.cpp [wrapped: conflict: FUN_002152b0]
// sym: _FUN_002152b0
namespace fn_002152b0 {
// luaD_throw: long-jump to the innermost protected call, else the panic function and exit.

extern "C" __declspec(noreturn) void __cdecl _longjmp(void* env, int value);
__declspec(noreturn) void __cdecl FUN_003471a3(int code);

extern "C" LuaVMState* __cdecl FUN_002152b0(LuaVMState* L, int errcode) {
    if (L->errorJmp) {
        L->errorJmp->status = errcode;
        _longjmp(L->errorJmp->b, 1);
    }
    if (L->l_G->panic)
        L->l_G->panic(L);
    FUN_003471a3(1);
    return L;
}
} // namespace fn_002152b0

namespace fn_ffc5dd1e {

// 0x002152f0 FUN_002152f0 (92 B): equivalent/0x002152f0.cpp
// sym: _FUN_002152f0 @b519ecd5624c @wb273e3087e25
// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 2/2)
// luaD_rawrunprotected: run f(L, ud) with a longjmp record on the error chain; returns its status.
extern "C" int __cdecl FUN_002152f0(LuaVMState* L, void(__cdecl* f)(LuaVMState* L, void* ud), void* ud) {
    struct {
        LuaVMLongjmp lj;
#if defined(_MSC_VER) && !defined(__clang__)
        volatile int extra;  // MSVC 7.1 puts the frame 4 bytes lower without it (the stored address is compared)
#endif
    } frame;
    frame.lj.previous = L->errorJmp;
    L->errorJmp = &frame.lj;
    frame.lj.status = 0;
#if defined(_MSC_VER) && !defined(__clang__)
    frame.extra = 0;
#endif
    if (__setjmp3(frame.lj.b, 0) == 0)
        f(L, ud);
    L->errorJmp = frame.lj.previous;
#if defined(_MSC_VER) && !defined(__clang__)
    return frame.lj.status + frame.extra;
#else
    return frame.lj.status;
#endif
}


// 0x00215350 FUN_00215350 (117 B): equivalent/0x00215350.cpp
// sym: _FUN_00215350 @b69830f8c24d @wf1448dd45aea
// STATUS: equivalent (tools/equiv.py level 3: 102 inputs, branch coverage 8/8)
// correctstack: after the stack moved from oldstack, move top, the open upvalues and every CallInfo with it.
// equiv-conv: FUN_00215350 eax edx
extern "C" void __cdecl FUN_00215350(LuaVMState* L, LuaVMTObject* oldstack) {
    L->top = L->stack + (L->top - oldstack);
    for (LuaVMGCObject* up = L->openupval; up != 0; up = up->next)
        ((LuaVMUpVal*)up)->v = L->stack + (((LuaVMUpVal*)up)->v - oldstack);
    for (LuaVMCallInfo* ci = L->base_ci; ci <= L->ci; ci++) {
        ci->top = L->stack + (ci->top - oldstack);
        ci->base = L->stack + (ci->base - oldstack);
    }
    L->base = L->ci->base;
}


// 0x002153d0 FUN_002153d0 (64 B): equivalent/0x002153d0.cpp
// sym: _FUN_002153d0 @0a55f54bd8d9 @wcd684a87a74e
// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 0/0)
// luaD_reallocstack: resize the stack to newsize slots (EXTRA_STACK 5 above stack_last), then correctstack.
// equiv-conv: FUN_00215350 eax edx
extern "C" void __cdecl FUN_002153d0(LuaVMState* L, int newsize) {
    LuaVMTObject* oldstack = L->stack;
    LuaVMTObject* stack = (LuaVMTObject*)FUN_0021add0(L, oldstack, L->stacksize * (unsigned int)sizeof(LuaVMTObject),
                                                       newsize * (unsigned int)sizeof(LuaVMTObject));
    L->stack_last = stack + newsize - 6;
    L->stack = stack;
    L->stacksize = newsize;
    FUN_00215350(L, oldstack);
}


// 0x00215410 FUN_00215410 (76 B): matches/0x00215410.cpp
// sym: _FUN_00215410
// luaD_reallocCI: resize the CallInfo array and move ci / end_ci with it.
extern "C" void __cdecl FUN_00215410(LuaVMState* L, int newsize) {
    unsigned short c = (unsigned short)newsize;
    LuaVMCallInfo* oldci = L->base_ci;
    LuaVMCallInfo* n = (LuaVMCallInfo*)FUN_0021add0(L, oldci, (unsigned int)L->size_ci * (unsigned int)sizeof(LuaVMCallInfo),
                                                    (unsigned int)newsize * (unsigned int)sizeof(LuaVMCallInfo));
    L->size_ci = c;
    L->base_ci = n;
    L->ci = n + (L->ci - oldci);
    L->end_ci = n + c;
}


// 0x00215460 FUN_00215460 (123 B): equivalent/0x00215460.cpp
// sym: _FUN_00215460 @6c47e18f740a @we1d61c5f42eb
// STATUS: equivalent (tools/equiv.py level 3: 3003 inputs, branch coverage 2/2)
// luaD_growstack: grow the stack by at least n slots, then fix the pointers into it (correctstack).
// equiv-conv: FUN_00215350 eax edx
extern "C" void __cdecl FUN_00215460(LuaVMState* L, int n) {
    int newsize;
    if (n <= L->stacksize)
        newsize = 2 * L->stacksize;
    else
        newsize = L->stacksize + n + 5;
    LuaVMTObject* oldstack = L->stack;
    L->stack = (LuaVMTObject*)FUN_0021add0(L, oldstack, L->stacksize * (unsigned int)sizeof(LuaVMTObject),
                                           newsize * (unsigned int)sizeof(LuaVMTObject));
    L->stacksize = newsize;
    L->stack_last = L->stack + newsize - 6;  // EXTRA_STACK 5
    FUN_00215350(L, oldstack);
}

} // namespace fn_ffc5dd1e

// 0x002155f0 FUN_002155f0 (288 B): equivalent/0x002155f0.cpp [wrapped: code differs from its standalone build]
// sym: _FUN_002155f0 @5f7e00d0f20e @w329dec5f7aab
namespace fn_002155f0 {
// STATUS: equivalent (tools/equiv.py level 3: 56 inputs, branch coverage 12/12)
// adjust_varargs: pad missing fixed arguments with nil and move the extra ones into a new `arg' table (with the
// count in field `n'), pushed in their place.

extern "C++" void __cdecl FUN_00215460(LuaVMState* L, int n);
extern "C" LuaVMTable* __cdecl FUN_00219cc0(LuaVMState* L, int narray, int lnhash);
extern "C" LuaVMTObject* __cdecl FUN_00219f60(LuaVMState* L, LuaVMTable* t, int key);
extern "C++" LuaVMString* __cdecl FUN_00219430(LuaVMState* L, const char* str, unsigned int l);
extern "C" LuaVMTObject* __cdecl FUN_0021a500(LuaVMState* L, LuaVMTable* t, LuaVMString* key);

// equiv-conv: FUN_002155f0 edx esi stack
extern "C" LuaVMTObject* __cdecl FUN_002155f0(LuaVMTObject* base, LuaVMState* L, int nfixargs) {
    int actual = (int)(L->top - base);
    if (actual < nfixargs) {
        int missing = nfixargs - actual;
        if ((char*)L->stack_last - (char*)L->top <= missing * (int)sizeof(LuaVMTObject))
            FUN_00215460(L, missing);
        actual += missing;
        do {
            L->top->tt = LUAVM_TNIL;
            L->top++;
        } while (--missing);
    }
    actual -= nfixargs;

    LuaVMTable* htab = FUN_00219cc0(L, actual, 1);
    for (int i = 0; i < actual; i++) {
        LuaVMTObject* src = L->top - actual + i;
        LuaVMTObject* dst = FUN_00219f60(L, htab, i + 1);
        LUAVM_SETOBJ(dst, src);
    }
    LuaVMTObject* slot = FUN_0021a500(L, htab, FUN_00219430(L, "n", 1));
    slot->tt = LUAVM_TNUMBER;
    slot->value.n = (float)actual;
    L->top -= actual;
    L->top->value.gc = (LuaVMGCObject*)htab;
    L->top->tt = LUAVM_TTABLE;
    if ((char*)L->stack_last - (char*)L->top <= (int)sizeof(LuaVMTObject))
        FUN_00215460(L, 1);
    L->top++;
    return L->top;
}
} // namespace fn_002155f0


// 0x00215710 FUN_00215710 (119 B): equivalent/0x00215710.cpp [wrapped: code differs from its standalone build]
// sym: _FUN_00215710 @41a02d94df20 @w068e22ff28fe
namespace fn_00215710 {
// STATUS: equivalent (tools/equiv.py level 3: 3016 inputs, branch coverage 8/8)
// tryfuncTM: a non-function call goes through the value's __call metamethod (inserted below the arguments).

// equiv-conv: FUN_002175b0 stack stack stack
extern "C" const LuaVMTObject* __cdecl FUN_002175b0(LuaVMState* L, const LuaVMTObject* o, int event);
extern "C" void __cdecl FUN_00214c90(LuaVMState* L, const LuaVMTObject* o, const char* op);
extern "C++" void __cdecl FUN_00215460(LuaVMState* L, int n);

// equiv-conv: FUN_00215710 esi edi
extern "C" LuaVMTObject* __cdecl FUN_00215710(LuaVMState* L, LuaVMTObject* func) {
    const LuaVMTObject* tm = FUN_002175b0(L, func, 14);
    int funcr = (int)((char*)func - (char*)L->stack);
    if (tm->tt != LUAVM_TFUNCTION)
        FUN_00214c90(L, func, "call");
    for (LuaVMTObject* p = L->top; p > func; p--)
        LUAVM_SETOBJ(p, p - 1);
    if ((char*)L->stack_last - (char*)L->top <= (int)sizeof(LuaVMTObject))
        FUN_00215460(L, 1);
    L->top++;
    func = (LuaVMTObject*)((char*)L->stack + funcr);
    LUAVM_SETOBJ(func, tm);
    return func;
}
} // namespace fn_00215710

namespace fn_ffc5dd1e {

// 0x00215790 FUN_00215790 (381 B): equivalent/0x00215790.cpp
// sym: _FUN_00215790 @6ed0064414db @w7714deadb6dc
// STATUS: equivalent (tools/equiv.py level 3: 103 inputs, branch coverage 22/22)
// luaD_precall: enter a function call: a Lua function gets its frame (returns NULL for luaV_execute), a C
// function runs here (returns its first result).
// equiv-conv: FUN_00215710 esi edi
// equiv-conv: FUN_002155f0 edx esi stack
extern "C" LuaVMTObject* __cdecl FUN_00215790(LuaVMState* L, LuaVMTObject* func) {
    int funcr = (int)((char*)func - (char*)L->stack);
    if (func->tt != LUAVM_TFUNCTION)
        func = FUN_00215710(L, func);
    if (L->ci + 1 == L->end_ci) {
        unsigned short n = L->size_ci;
        if (n > 0x1000)
            FUN_002152b0(L, 5);
        FUN_00215410(L, (int)(n * 2));
        if (L->size_ci > 0x1000)
            FUN_00214a90(L, "stack overflow");
    }
    LuaVMClosure* cl = (LuaVMClosure*)func->value.gc;
    if (!cl->c.isC) {
        LuaVMProto* p = cl->l.p;
        if (p->is_vararg)
            FUN_002155f0(func + 1, L, p->numparams);
        int n = p->maxstacksize;
        if ((char*)L->stack_last - (char*)L->top <= n * (int)sizeof(LuaVMTObject))
            FUN_00215460(L, n);
        LuaVMCallInfo* ci = L->ci + 1;
        L->ci = ci;
        ci->base = (LuaVMTObject*)((char*)L->stack + funcr) + 1;
        L->base = L->ci->base;
        ci->top = L->base + p->maxstacksize;
        ci->savedpc = p->code;
        ci->tailcalls = 0;
        LuaVMTObject* t = L->top;
        while (t < ci->top) {
            t->tt = LUAVM_TNIL;
            t++;
        }
        L->top = ci->top;
        return 0;
    }
    if ((char*)L->stack_last - (char*)L->top <= 20 * (int)sizeof(LuaVMTObject))
        FUN_00215460(L, 20);
    LuaVMCallInfo* ci = L->ci + 1;
    L->ci = ci;
    ci->base = (LuaVMTObject*)((char*)L->stack + funcr) + 1;
    L->base = L->ci->base;
    ci->top = L->top + 20;
    if (L->hookmask & 1)
        FUN_00215520(L, 0, -1);
    LuaVMClosure* c = (LuaVMClosure*)L->base[-1].value.gc;
    int n = c->c.f(L);
    return L->top - n;
}


// 0x00215910 FUN_00215910 (94 B): equivalent/0x00215910.cpp
// sym: _FUN_00215910 @dd843a944a8c @w3c31f1771ec8
// STATUS: equivalent (tools/equiv.py level 3: 2981 inputs, branch coverage 6/6)
// callrethooks: the return hook (and one tail-return hook per tail call of a Lua function); the results may move.
// equiv-conv: FUN_00215910 eax esi
extern "C" LuaVMTObject* __cdecl FUN_00215910(LuaVMTObject* firstResult, LuaVMState* L) {
    int fr = (int)((char*)firstResult - (char*)L->stack);
    FUN_00215520(L, 1, -1);
    LuaVMClosure* cl = (LuaVMClosure*)(L->ci->base - 1)->value.gc;
    if (!cl->c.isC) {
        while (L->ci->tailcalls != 0) {
            --L->ci->tailcalls;
            FUN_00215520(L, 4, -1);
        }
        --L->ci->tailcalls;
    }
    return (LuaVMTObject*)((char*)L->stack + fr);
}


// 0x00215970 FUN_00215970 (105 B): equivalent/0x00215970.cpp
// sym: _FUN_00215970 @04bdd36fa0af @w2b2b8448f173
// STATUS: equivalent (tools/equiv.py level 3: 2578 inputs, branch coverage 12/12)
// luaD_poscall: leave the call: move up to wanted results down to the function's slot (nil-padded).
// equiv-conv: FUN_00215910 eax esi
extern "C" void __cdecl FUN_00215970(LuaVMState* L, int wanted, LuaVMTObject* firstResult) {
    if (L->hookmask & 2)
        firstResult = FUN_00215910(firstResult, L);
    LuaVMCallInfo* ci = L->ci - 1;
    LuaVMTObject* res = L->base - 1;
    L->ci = ci;
    L->base = ci->base;
    if (wanted != 0) {
        do {
            if (firstResult >= L->top)
                break;
            LUAVM_SETOBJ(res, firstResult);
            firstResult++;
            res++;
            wanted--;
        } while (wanted != 0);
        if (wanted > 0) {
            do {
                res->tt = LUAVM_TNIL;
                res++;
                wanted--;
            } while (wanted != 0);
        }
    }
    L->top = res;
}


// 0x002159e0 FUN_002159e0 (120 B): equivalent/0x002159e0.cpp
// sym: _FUN_002159e0 @85d26bca2596 @w26e24dbbe561
// STATUS: equivalent (tools/equiv.py level 3: 3019 inputs, branch coverage 10/10)
// luaD_call: call func with its arguments above it (C-stack depth checked), then the GC step.
extern "C" void __cdecl FUN_002159e0(LuaVMState* L, LuaVMTObject* func, int nResults) {
    if (++L->nCcalls >= 200) {
        if (L->nCcalls == 200)
            FUN_00214a90(L, "C stack overflow");
        else if (L->nCcalls >= 225)
            FUN_002152b0(L, 5);
    }
    LuaVMTObject* first = FUN_00215790(L, func);
    if (first == 0)
        first = FUN_00218350(L, 1);
    FUN_00215970(L, nResults, first);
    L->nCcalls--;
    if (L->l_G->totalbytes >= L->l_G->GCthreshold)
        FUN_00217440(L);
}


// 0x00215a60 FUN_00215a60 (150 B): equivalent/0x00215a60.cpp
// sym: _FUN_00215a60 @2c7a104ef79c @we28a45af337a
// STATUS: equivalent (tools/equiv.py level 3: 3010 inputs, branch coverage 8/8)
// resume: the protected body of lua_resume: start the coroutine's function, or finish the yielding call, then
// run the Lua code. The suspended flag is the byte at 0x32 (LuaVMState.status in the records).
extern "C" void __cdecl FUN_00215a60(LuaVMState* L, void* ud) {
    int nargs = *(int*)ud;
    if (!L->status) {
        FUN_00215790(L, L->top - (nargs + 1));
    } else if (((LuaVMClosure*)(L->ci->base - 1)->value.gc)->c.isC) {
        LuaVMInstruction inst = L->ci[-1].savedpc[-1];
        int nresults = (int)((inst >> 6) & 0x1ff) - 1;
        FUN_00215970(L, nresults, L->top - nargs);
        if (nresults >= 0)
            L->top = L->ci->top;
    }
    L->status = 0;
    LuaVMTObject* firstResult = FUN_00218350(L, (int)(L->ci - L->base_ci));
    if (firstResult)
        FUN_00215970(L, -1, firstResult);
}


// 0x00215b00 FUN_00215b00 (87 B): equivalent/0x00215b00.cpp
// sym: _FUN_00215b00 @b5865198ce60 @w6b970a52799a
// STATUS: equivalent (tools/equiv.py level 3: 2976 inputs, branch coverage 4/4)
// resume_error: the error message as lua_resume's only result.
// equiv-conv: FUN_00215b00 esi edx
extern "C" int __cdecl FUN_00215b00(LuaVMState* L, const char* msg) {
    LuaVMTObject* o = L->ci->base;
    L->top = o;
    const char* p = msg;
    while (*p)
        ++p;
    o->value.gc = (LuaVMGCObject*)FUN_00219430(L, msg, (unsigned int)(p - msg));
    o->tt = LUAVM_TSTRING;
    if ((char*)L->stack_last - (char*)L->top <= (int)sizeof(LuaVMTObject))
        FUN_00215460(L, 1);
    L->top++;
    return 1;
}


// 0x00215b60 FUN_00215b60 (148 B): equivalent/0x00215b60.cpp
// sym: _FUN_00215b60 @2d06878bbd5c @w841d263de6ff
// STATUS: equivalent (tools/equiv.py level 3: 2976 inputs, branch coverage 10/10)
// lua_yield: from a C function, keep only its nresults results; mark the thread suspended (the byte at 0x32,
// LuaVMState.status in the records).
extern "C" int __cdecl FUN_00215b60(LuaVMState* L, int nresults) {
    LuaVMCallInfo* ci = L->ci;
    if (L->nCcalls > 0)
        FUN_00214a90(L, "attempt to yield across metamethod/C-call boundary");
    if (((LuaVMClosure*)(ci->base - 1)->value.gc)->c.isC) {
        if (L->top - nresults > L->base) {
            for (int i = 0; i < nresults; i++)
                LUAVM_SETOBJ(L->base + i, L->top + (i - nresults));
            L->top = L->base + nresults;
        }
    }
    L->status = 1;
    return -1;
}

} // namespace fn_ffc5dd1e

// 0x00215c00 FUN_00215c00 (194 B): matches/0x00215c00.cpp [wrapped: lost its match in the tree (call sequence differs)]
// sym: _FUN_00215c00
namespace fn_00215c00 {
// f_parser: the protected body of luaD_protectedparser: undump a binary chunk or parse the source, then push
// its main function as a closure with fresh upvalues.

extern "C" int __cdecl FUN_0021a590(LuaVMZio* z);
extern "C++" void __cdecl FUN_00217440(LuaVMState* L);
extern "C" LuaVMProto* __cdecl FUN_00220480(LuaVMState* L, LuaVMZio* Z, LuaVMBuffer* buff, const char* name);
extern "C" LuaVMProto* __cdecl FUN_0021f710(LuaVMState* L, LuaVMZio* z, LuaVMBuffer* buff, const char* name);
extern "C" LuaVMClosure* __cdecl FUN_00219560(LuaVMState* L, int nelems, const LuaVMTObject* e);
extern "C" LuaVMUpVal* __cdecl FUN_002195d0(LuaVMState* L);
extern "C++" void __cdecl FUN_00215460(LuaVMState* L, int n);

extern "C" void __cdecl FUN_00215c00(LuaVMState* L, void* ud) {
    LuaVMSParser* p = (LuaVMSParser*)ud;
    unsigned int c = (unsigned int)FUN_0021a590(p->z);
    if (L->l_G->totalbytes >= L->l_G->GCthreshold)
        FUN_00217440(L);
    typedef LuaVMProto*(__cdecl * Loader)(LuaVMState*, LuaVMZio*, LuaVMBuffer*, const char*);
    Loader loader = c == 0x1b ? &FUN_00220480 : &FUN_0021f710;
    LuaVMProto* tf = loader(L, p->z, &p->buff, p->name);
    LuaVMClosure* cl = FUN_00219560(L, tf->nups, &L->_gt);
    cl->l.p = tf;
    for (int i = 0; i < tf->nups; ++i)
        cl->l.upvals[i] = FUN_002195d0(L);
    LuaVMTObject* o = L->top;
    o->value.gc = (LuaVMGCObject*)cl;
    o->tt = LUAVM_TFUNCTION;
    if ((int)((char*)L->stack_last - (char*)L->top) <= (int)sizeof(LuaVMTObject))
        FUN_00215460(L, 1);
    L->top = L->top + 1;
}
} // namespace fn_00215c00

namespace fn_ffc5dd1e {

// 0x00215d10 FUN_00215d10 (200 B): equivalent/0x00215d10.cpp
// sym: _FUN_00215d10 @7a9bc7ca46e8 @w30ae0e9b89c0
// STATUS: equivalent (tools/equiv.py level 3: 3007 inputs, branch coverage 12/12)
// lua_resume: resume a suspended coroutine (or start it); on an error the thread is reset to its base.
// The suspended flag is the byte at 0x32 (LuaVMState.status in the records).
// equiv-conv: FUN_00215b00 esi edx
// equiv-conv: FUN_00215240 eax ecx edi
extern "C" int __cdecl FUN_00215d10(LuaVMState* L, int nargs) {
    if (!L->status) {
        if (L->ci != L->base_ci)
            return FUN_00215b00(L, "cannot resume non-suspended coroutine");
        if (nargs >= L->top - L->base)
            return FUN_00215b00(L, "cannot resume dead coroutine");
    }
    unsigned char old_allowhooks = L->allowhook;
    int status = FUN_002152f0(L, FUN_00215a60, &nargs);
    if (status) {
        L->ci = L->base_ci;
        LuaVMStkId base = L->ci->base;
        L->base = base;
        L->nCcalls = 0;
        FUN_00219660(L, base);
        FUN_00215240(status, L->base, L);
        bool grow = L->size_ci > 0x1000;
        L->allowhook = old_allowhooks;
        L->stack_last = L->stack + L->stacksize - 1;
        if (grow && (L->ci - L->base_ci) + 1 < 0x1000)
            FUN_00215410(L, 0x1000);
    }
    return status;
}


// 0x00215de0 FUN_00215de0 (246 B): equivalent/0x00215de0.cpp
// sym: _FUN_00215de0 @8c39d0556e17 @wba3a70d91a5c
// STATUS: equivalent (tools/equiv.py level 3: 3003 inputs, branch coverage 6/6)
// luaD_pcall: call func(L, u) protected with error function ef; on an error restore the stack (to the byte
// offset oldtop), the call depth, the CallInfo and the hooks, and set the error object.
// equiv-conv: FUN_00215240 eax ecx edi
extern "C" int __cdecl FUN_00215de0(LuaVMState* L, void(__cdecl* func)(LuaVMState* L, void* ud), void* u, int oldtop,
                                    int ef) {
    unsigned short oldnCcalls = L->nCcalls;
    unsigned char old_allowhooks = L->allowhook;
    int old_ci = (int)((char*)L->ci - (char*)L->base_ci);
    int old_errfunc = L->errfunc;
    L->errfunc = ef;
    int status = FUN_002152f0(L, func, u);
    if (status) {
        LuaVMTObject* oldtopp = (LuaVMTObject*)((char*)L->stack + oldtop);
        FUN_00219660(L, oldtopp);
        FUN_00215240(status, oldtopp, L);
        bool large = L->size_ci > 0x1000;
        LuaVMCallInfo* base_ci = L->base_ci;
        LuaVMTObject* stack = L->stack;
        L->nCcalls = oldnCcalls;
        LuaVMCallInfo* ci = (LuaVMCallInfo*)((char*)base_ci + old_ci);
        L->ci = ci;
        L->base = ci->base;
        L->allowhook = old_allowhooks;
        L->stack_last = stack + L->stacksize - 1;
        if (large && (int)(ci - base_ci) + 1 < 0x1000)
            FUN_00215410(L, 0x1000);
    }
    L->errfunc = old_errfunc;
    return status;
}


// 0x00215ee0 FUN_00215ee0 (101 B): matches/0x00215ee0.cpp
// sym: _FUN_00215ee0
// luaD_protectedparser: run f_parser protected over an SParser on the stack, then free its buffer.
extern "C" int __cdecl FUN_00215ee0(LuaVMState* L, LuaVMZio* z, const char* name) {
    LuaVMSParser p;
    p.z = z;
    p.name = name;
    p.buff.buffer = 0;
    p.buff.buffsize = 0;
    int status = FUN_00215de0(L, FUN_00215c00, &p, (int)((char*)L->top - (char*)L->stack), L->errfunc);
    FUN_0021add0(L, p.buff.buffer, p.buff.buffsize, 0);
    return status;
}

} // namespace fn_ffc5dd1e
