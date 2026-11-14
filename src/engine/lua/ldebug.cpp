// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00213f20..0x00214dd0 (kind game, layer engine, confidence high)
#include "tree_prelude.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/global.h"
#include "decls/data/lua.h"
#define TREE_TU_BEGIN namespace fn_f9add754 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f9add754 {} using namespace fn_f9add754;
#include "engine/lua.h"

// ---- declarations shared by the functions below
namespace fn_f9add754 {
extern "C" const char* __cdecl FUN_00219820(const LuaVMProto* f, int local_number, int pc);
extern "C" void __cdecl FUN_00212c10(LuaVMState* L, const LuaVMTObject* o);
extern "C++" LuaVMInstruction __cdecl FUN_002142d0(const LuaVMProto* pt, int lastpc, int reg);
extern "C" const char* FUN_002146c0(int c, const LuaVMProto* p);
extern "C" const char* __cdecl FUN_002146f0(unsigned reg, LuaVMCallInfo* ci, const char** name);
extern "C" void __cdecl FUN_002152b0(LuaVMState* L, int errcode);
extern "C" LuaVMString* __cdecl FUN_00219430(LuaVMState* L, const char* str, unsigned int l);
extern "C" const LuaVMTObject* __cdecl FUN_00219e50(LuaVMTable* t, LuaVMString* key);
extern "C" void __cdecl FUN_00215460(LuaVMState* L, int n);
extern "C" void __cdecl FUN_002159e0(LuaVMState* L, LuaVMTObject* func, int nresults);
extern "C" const char* __cdecl FUN_002160c0(LuaVMState* L, const char* fmt, char* argp);
extern "C" void FUN_00214900(LuaVMState* L, const char* msg);
extern "C" void __cdecl FUN_002149b0(LuaVMState* L);
extern "C" void __cdecl FUN_00214a90(LuaVMState* L, const char* fmt, ...);
extern "C++" int __cdecl FUN_00214ac0(const char* what, LuaVMDebug* ar, LuaVMCallInfo* ci, LuaVMState* L, const LuaVMTObject* f);
extern "C" void __cdecl FUN_002141d0(LuaVMDebug* ar, LuaVMState* L);
extern "C++" void __cdecl FUN_00214c90(LuaVMState* L, const LuaVMTObject* o, const char* op);
extern "C" const LuaVMTObject* __cdecl FUN_00217600(const LuaVMTObject* obj, LuaVMTObject* n);


// 0x00213f20 FUN_00213f20 (51 B): matches/0x00213f20.cpp
// sym: @FUN_00213f20@8
// currentline: the source line ci's Lua function is at (-1 for a C function or before the first instruction).
extern "C" int __fastcall FUN_00213f20(LuaVMState* L, LuaVMCallInfo* ci) {
    LuaVMClosure* cl;
    LuaVMProto* p;
    int pc;
    if (ci->base[-1].tt != LUAVM_TFUNCTION)
        return -1;
    cl = (LuaVMClosure*)ci->base[-1].value.gc;
    if (cl->c.isC != 0)
        return -1;
    p = cl->l.p;
    pc = (int)(ci->savedpc - p->code);
    --pc;
    if (pc < 0)
        return -1;
    int* lineinfo = p->lineinfo;
    return lineinfo ? lineinfo[pc] : 0;
}


// 0x00213f60 FUN_00213f60 (46 B): matches/0x00213f60.cpp
// sym: _FUN_00213f60
// lua_sethook: install func for the events in mask (no hook when either is 0), count for the count hook.
extern "C" int __cdecl FUN_00213f60(LuaVMState* L, LuaVMHook func, int mask, int count) {
    if (func == 0 || mask == 0) {
        mask = 0;
        func = 0;
    }
    L->hook = func;
    L->basehookcount = count;
    L->hookcount = count;
    L->hookmask = (unsigned char)mask;
    return 1;
}


// 0x00213f90 FUN_00213f90 (8 B): matches/0x00213f90.cpp
// sym: _FUN_00213f90
// lua_gethook.
extern "C" LuaVMHook __cdecl FUN_00213f90(LuaVMState* L) {
    return L->hook;
}


// 0x00213fa0 FUN_00213fa0 (9 B): matches/0x00213fa0.cpp
// sym: _FUN_00213fa0
// lua_gethookmask.
extern "C" int __cdecl FUN_00213fa0(LuaVMState* L) {
    return L->hookmask;
}


// 0x00213fb0 FUN_00213fb0 (8 B): matches/0x00213fb0.cpp
// sym: _FUN_00213fb0
// lua_gethookcount.
extern "C" int __cdecl FUN_00213fb0(LuaVMState* L) {
    return L->basehookcount;
}


// 0x00213fc0 FUN_00213fc0 (107 B): equivalent/0x00213fc0.cpp
// sym: _FUN_00213fc0 @5e0efeb95cd4 @w4f6ec7648719
// STATUS: equivalent (tools/equiv.py level 3: 3030 inputs, branch coverage 13/14, incomplete)
// lua_getstack: find the activation level levels up (tail calls count) and store its CallInfo index in ar.
extern "C" int __cdecl FUN_00213fc0(LuaVMState* L, int level, LuaVMDebug* ar) {
    LuaVMCallInfo* ci = L->ci;
    if (level > 0) {
        do {
            if (ci <= L->base_ci) {
                if (level > 0)
                    return 0;
                break;
            }
            level--;
            if (((LuaVMClosure*)ci->base[-1].value.gc)->c.isC == 0)
                level -= ci->tailcalls;
            ci--;
        } while (level > 0);
    }
    if (ci == L->base_ci)
        return 0;
    if (level < 0) {
        ar->i_ci = 0;
        return 1;
    }
    ar->i_ci = (int)(ci - L->base_ci);
    return 1;
}


// 0x00214050 FUN_00214050 (107 B): matches/0x00214050.cpp
// sym: _FUN_00214050
// lua_getlocal: push local n of the activation ar names; its name or NULL.
extern "C" const char* __cdecl FUN_00214050(LuaVMState* L, LuaVMDebug* ar, int n) {
    const char* name = 0;
    LuaVMCallInfo* ci = &L->base_ci[ar->i_ci];
    if (ci->base[-1].tt == LUAVM_TFUNCTION) {
        LuaVMClosure* cl = (LuaVMClosure*)ci->base[-1].value.gc;
        if (cl->c.isC == 0) {
            LuaVMProto* p = cl->l.p;
            if (p) {
                int pc = (int)(ci->savedpc - p->code) - 1;
                name = FUN_00219820(p, n, pc);
                if (name)
                    FUN_00212c10(L, ci->base + (n - 1));
            }
        }
    }
    return name;
}


// 0x002140c0 FUN_002140c0 (154 B): equivalent/0x002140c0.cpp
// sym: _FUN_002140c0 @cb36267a24ff @w34d6e34c2e6c
// STATUS: equivalent (tools/equiv.py level 3: 3104 inputs, branch coverage 12/14, incomplete)
// lua_setlocal: pop the top value into local n of the activation ar names; its name or NULL.
extern "C" const char* __cdecl FUN_002140c0(LuaVMState* L, LuaVMDebug* ar, int n) {
    LuaVMCallInfo* ci = L->base_ci + ar->i_ci;
    LuaVMTObject* fn = ci->base - 1;
    LuaVMProto* p = 0;
    if (fn->tt == LUAVM_TFUNCTION && ((LuaVMClosure*)fn->value.gc)->c.isC == 0)
        p = ((LuaVMClosure*)fn->value.gc)->l.p;
    L->top--;
    if (p == 0)
        return 0;
    int pc = -1;
    fn = ci->base - 1;
    if (fn->tt == LUAVM_TFUNCTION && ((LuaVMClosure*)fn->value.gc)->c.isC == 0)
        pc = (int)(ci->savedpc - ((LuaVMClosure*)fn->value.gc)->l.p->code) - 1;
    const char* name = FUN_00219820(p, n, pc);
    if (name == 0 || name[0] == '(')
        return 0;
    ci->base[n - 1] = *L->top;
    return name;
}


// 0x00214160 FUN_00214160 (107 B): equivalent/0x00214160.cpp
// sym: _FUN_00214160 @168584b56f7c @wf21804a16bdb
// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 4/4)
// funcinfo: fill ar's source, linedefined, what and short_src from the function func.
// equiv-conv: FUN_00214160 ecx eax
extern "C" void FUN_00214160(LuaVMDebug* ar, const LuaVMTObject* func) {
    LuaVMClosure* cl = (LuaVMClosure*)func->value.gc;
    if (cl->c.isC) {
        ar->source = "=[C]";
        ar->linedefined = -1;
        ar->what = "C";
        FUN_00216340(ar->short_src, ar->source, 0x3c);
        return;
    }
    ar->source = LUAVM_GETSTR(cl->l.p->source);
    int line = cl->l.p->lineDefined;
    ar->linedefined = line;
    ar->what = (line != 0) ? "Lua" : "main";
    FUN_00216340(ar->short_src, ar->source, 0x3c);
}


// 0x002141d0 FUN_002141d0 (74 B): equivalent/0x002141d0.cpp
// sym: _FUN_002141d0 @d99053d1d493 @w17c2d3c84b19
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 0/0)
// info_tailcall: fill ar for a tail call's lost activation; push nil as its function.
// equiv-conv: FUN_002141d0 esi stack
extern "C" void __cdecl FUN_002141d0(LuaVMDebug* ar, LuaVMState* L) {
    ar->name = (const char*)&DAT_003f335c;
    ar->namewhat = (const char*)&DAT_003f335c;
    ar->currentline = -1;
    ar->linedefined = -1;
    ar->what = DAT_0042662c;
    ar->source = DAT_00426634;
    FUN_00216340(ar->short_src, DAT_00426634, 60);
    ar->nups = 0;
    L->top->tt = LUAVM_TNIL;
}


// 0x00214250 FUN_00214250 (47 B): equivalent/0x00214250.cpp
// sym: _FUN_00214250 @d6fe0c8a3631 @w4cb03f8cec0a
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// checkopenop: the instruction after pc takes an open register count (a call with B 0, or OP_SETLISTO).
// equiv-conv: FUN_00214250 eax edx
extern "C" int FUN_00214250(const LuaVMProto* pt, int pc) {
    LuaVMInstruction i = pt->code[pc + 1];
    unsigned int op = i & 0x3f;
    if (op >= 0x19 && op <= 0x1b)
        return (i & 0xff8000) == 0;
    return op == 0x21;
}


// 0x00214280 FUN_00214280 (66 B): equivalent/0x00214280.cpp
// sym: _FUN_00214280 @9464b30b1035 @wffade218ad93
// STATUS: equivalent (tools/equiv.py level 3: 3003 inputs, branch coverage 16/16)
// checkArgMode: operand r is valid for argument mode mode (0 unused, 2 register, 3 register or constant).
// equiv-conv: FUN_00214280 ecx edx eax
extern "C" int FUN_00214280(int r, const LuaVMProto* pt, int mode) {
    if (mode == 0) return r == 0 ? 1 : 0;
    if (mode == 2) return r < pt->maxstacksize ? 1 : 0;
    if (mode == 3 && r >= pt->maxstacksize) {
        if (r < 250 || r - 250 >= pt->sizek) return 0;
    }
    return 1;
}

} // namespace fn_f9add754

// 0x002142d0 FUN_002142d0 (878 B): equivalent/0x002142d0.cpp [wrapped: code differs from its standalone build]
// sym: _FUN_002142d0 @79878dfb2c04 @wf4fe0034f236
namespace fn_002142d0 {
// STATUS: equivalent (tools/equiv.py level 3: 4660 inputs, branch coverage 88/120, incomplete)
// symbexec (with precheck): check pt's code up to lastpc; the last instruction that wrote reg (the final one when
// reg is NO_REG 0xff); 0 when the code is invalid.

// equiv-conv: FUN_00214280 ecx edx eax
extern "C++" int FUN_00214280(int r, const LuaVMProto* pt, int mode);
// equiv-conv: FUN_00214250 eax edx
extern "C++" int FUN_00214250(const LuaVMProto* pt, int pc);

extern "C" LuaVMInstruction __cdecl FUN_002142d0(const LuaVMProto* pt, int lastpc, int reg)
{
    int sizecode = pt->sizecode;
    int last = sizecode - 1;
    unsigned char maxstack = pt->maxstacksize;
    int pc;

    if (maxstack > 250)
        return 0;
    if (pt->sizelineinfo != sizecode && pt->sizelineinfo != 0)
        return 0;
    const LuaVMInstruction* code = pt->code;
    if ((code[sizecode - 1] & 0x3f) != 0x1b)
        return 0;

    for (pc = 0; pc < lastpc; pc++) {
        unsigned int i = code[pc];
        int op = i & 0x3f;
        int a = i >> 24;
        int b = 0;
        int c = 0;
        int maxs;
        unsigned int m;

        if (op >= 0x24)
            return 0;
        maxs = maxstack;
        if (a >= maxs)
            return 0;
        m = ((const unsigned char*)DAT_00426ba4)[op];
        switch (m & 3) {
        case 0:
            b = (i >> 15) & 0x1ff;
            c = (i >> 6) & 0x1ff;
            if (!FUN_00214280(b, pt, (m >> 4) & 3))
                return 0;
            if (!FUN_00214280(c, pt, (m >> 2) & 3))
                return 0;
            break;
        case 1:
            b = (i >> 6) & 0x3ffff;
            if ((m & 0x30) == 0x30) {
                if (b >= pt->sizek)
                    return 0;
            }
            break;
        case 2:
            b = ((i >> 6) & 0x3ffff) - 0x1ffff;
            if ((m & 0x30) == 0x20) {
                int dest = b + pc + 1;
                if (dest < 0 || dest >= sizecode)
                    return 0;
            }
            break;
        }

        m = ((const unsigned char*)DAT_00426ba4)[op];
        if (m & 0x40) {
            if (a == reg)
                last = pc;
        }
        if (m & 0x80) {
            if (pc + 2 >= sizecode)
                return 0;
            if ((code[pc + 1] & 0x3f) != 0x14)
                return 0;
        }

        switch (op) {
        case 2:
            if (c != 0 && pc + 2 >= sizecode)
                return 0;
            break;
        case 3:
            if (a <= reg && reg <= b)
                last = pc;
            break;
        case 4:
        case 8:
            if (b >= pt->nups)
                return 0;
            break;
        case 5:
        case 7:
            if (pt->k[b].tt != 4)
                return 0;
            break;
        case 11:
            if (a + 1 >= maxs)
                return 0;
            if (reg == a + 1)
                last = pc;
            break;
        case 19:
            if (b >= c)
                return 0;
            break;
        case 30:
            if (a + 5 >= maxs)
                return 0;
            if (reg >= a)
                last = pc;
            break;
        case 28:
        case 29:
        case 31:
            if (a + 3 >= maxs)
                return 0;
            /* fall through */
        case 20: {
            int dest = pc + 1 + b;
            if (reg != 0xff && pc < dest && dest <= lastpc)
                pc += b;
            break;
        }
        case 25:
        case 26:
            if (b != 0) {
                if (a + b - 1 >= maxs)
                    return 0;
            }
            c--;
            if (c == -1) {
                if (!FUN_00214250(pt, pc))
                    return 0;
            } else if (c != 0) {
                if (a + c - 1 >= maxs)
                    return 0;
            }
            if (reg >= a)
                last = pc;
            break;
        case 27:
            b--;
            if (b > 0) {
                if (a + b - 1 >= maxs)
                    return 0;
            }
            break;
        case 32:
            b &= 0x1f;
            if (a + b + 1 >= maxs)
                return 0;
            break;
        case 35: {
            if (b >= pt->sizep)
                return 0;
            int nup = pt->p[b]->nups;
            if (pc + nup >= sizecode)
                return 0;
            for (; nup > 0; nup--) {
                unsigned int op1 = code[pc + nup] & 0x3f;
                if (op1 != 4 && op1 != 0)
                    return 0;
            }
            break;
        }
        default:
            break;
        }
    }
    return code[last];
}
} // namespace fn_002142d0

namespace fn_f9add754 {

// 0x002146a0 FUN_002146a0 (29 B): matches/0x002146a0.cpp
// sym: _FUN_002146a0
// luaG_checkcode: the whole of pt's code passes symbexec.
extern "C" int __cdecl FUN_002146a0(const LuaVMProto* pt) {
    return FUN_002142d0(pt, pt->sizecode, 0xff) != 0;
}


// 0x002146c0 FUN_002146c0 (34 B): equivalent/0x002146c0.cpp
// sym: _FUN_002146c0 @779c108b3ca6 @we22e645cc6c8
// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 4/4)
// kname: the name of RK operand c when it is a string constant; "?" otherwise.
// equiv-conv: FUN_002146c0 eax ecx
extern "C" const char* FUN_002146c0(int c, const LuaVMProto* p) {
    int index = c - 250;
    if (index >= 0 && p->k[index].tt == LUAVM_TSTRING)
        return LUAVM_GETSTR(p->k[index].value.gc);
    return DAT_00426608;
}


// 0x002146f0 FUN_002146f0 (285 B): equivalent/0x002146f0.cpp
// sym: _FUN_002146f0 @39e934151a03 @wc722c9cc9ac0
// STATUS: equivalent (tools/equiv.py level 3: 3053 inputs, branch coverage 19/20, incomplete)
// getobjname: what register reg of ci's Lua function holds ("local", "global", "field", "upvalue", "method") and its name.
// equiv-conv: FUN_002146c0 eax ecx
// equiv-conv: FUN_002146f0 eax stack stack
extern "C" const char* __cdecl FUN_002146f0(unsigned reg, LuaVMCallInfo* ci, const char** name) {
 for (;;) {
  LuaVMTObject* slot = ci->base - 1;
  if (slot->tt != LUAVM_TFUNCTION) return 0;
  LuaVMClosure* closure = (LuaVMClosure*)slot->value.gc;
  if (closure->c.isC) return 0;
  LuaVMProto* proto = closure->l.p;
  int pc = (int)(ci->savedpc - proto->code) - 1;
  const char* local = FUN_00219820(proto, reg + 1, pc);
  *name = local;
  if (local) return "local";
  unsigned instruction = FUN_002142d0(proto, pc, reg);
  switch (instruction & 63) {
   case 0: {
    unsigned source = (instruction >> 15) & 511;
    if (source >= (instruction >> 24)) return 0;
    reg = source;
    break;
   }
   case 5:
    *name = LUAVM_GETSTR(proto->k[(instruction >> 6) & 0x3ffff].value.gc);
    return "global";
   case 6:
    *name = FUN_002146c0((int)((instruction >> 6) & 511), proto);
    return "field";
   case 4:
    *name = LUAVM_GETSTR(proto->upvalues[(instruction >> 15) & 511]);
    return "upvalue";
   case 11:
    *name = FUN_002146c0((int)((instruction >> 6) & 511), proto);
    return "method";
   default: return 0;
  }
 }
}


// 0x00214840 FUN_00214840 (140 B): equivalent/0x00214840.cpp
// sym: _FUN_00214840 @3185bf46ae87 @wbb4ea622a0bb
// STATUS: equivalent (tools/equiv.py level 3: 3061 inputs, branch coverage 16/18, incomplete)
// getfuncname: name the function running in ci from the OP_CALL / OP_TAILCALL of its calling Lua function.
// equiv-conv: FUN_002146f0 eax stack stack
// equiv-conv: FUN_00214840 ecx stack
extern "C" const char* __cdecl FUN_00214840(LuaVMCallInfo* ci, const char** name)
{
    LuaVMTObject* func = ci->base - 1;
    if (func->tt == LUAVM_TFUNCTION && !((LuaVMClosure*)func->value.gc)->c.isC && ci->tailcalls > 0) {
        return 0;
    }

    LuaVMCallInfo* caller = ci - 1;
    LuaVMTObject* callerFunc = caller->base - 1;
    if (callerFunc->tt != LUAVM_TFUNCTION || ((LuaVMClosure*)callerFunc->value.gc)->c.isC) {
        return 0;
    }

    int pc;
    callerFunc = caller->base - 1;
    if (callerFunc->tt == LUAVM_TFUNCTION && !((LuaVMClosure*)callerFunc->value.gc)->c.isC) {
        pc = (int)(caller->savedpc - ((LuaVMClosure*)callerFunc->value.gc)->l.p->code) - 1;
    } else {
        pc = -1;
    }

    unsigned instruction = ((LuaVMClosure*)caller->base[-1].value.gc)->l.p->code[pc];
    unsigned op = instruction & 0x3f;
    if (op == 0x19 || op == 0x1a) {
        return FUN_002146f0(instruction >> 24, caller, name);
    }
    return 0;
}


// 0x002149b0 FUN_002149b0 (211 B): equivalent/0x002149b0.cpp
// sym: _FUN_002149b0 @49cb333b34e8 @w413b337655d4
// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 8/8)
// luaG_errormsg: call the error handler (errfunc, else the global _TRACEBACK) on the message on top; throws.
extern "C" void __cdecl FUN_002149b0(LuaVMState* L) {
    const LuaVMTObject* errfunc;
    if (L->errfunc)
        errfunc = (LuaVMTObject*)((char*)L->stack + L->errfunc);
    else {
        LuaVMString* key = FUN_00219430(L, "_TRACEBACK", 10);
        errfunc = FUN_00219e50((LuaVMTable*)L->_gt.value.gc, key);
    }
    if (errfunc->tt != LUAVM_TFUNCTION)
        FUN_002152b0(L, 5);
    LuaVMTObject* top = L->top;
    top->tt = top[-1].tt;
    top->value = top[-1].value;
    top = L->top - 1;
    top->tt = errfunc->tt;
    top->value = errfunc->value;
    if ((char*)L->stack_last - (char*)L->top <= (int)sizeof(LuaVMTObject))
        FUN_00215460(L, 1);
    L->top++;
    FUN_002159e0(L, L->top - 2, 1);
    FUN_002152b0(L, 1);
}


// 0x00214a90 FUN_00214a90 (38 B): equivalent/0x00214a90.cpp
// sym: _FUN_00214a90 @810d10770395 @w9f294ea29321
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// luaG_runerror: raise the formatted message with the "chunk:line:" prefix.
// equiv-conv: FUN_00214900 ebx stack
extern "C" void __cdecl FUN_00214a90(LuaVMState* L, const char* fmt, ...)
{
#if defined(HULK_PTR64)
    __builtin_va_list args;
    __builtin_va_start(args, fmt);
    const char* msg = FUN_002160c0(L, fmt, args);
#else
    const char* msg = FUN_002160c0(L, fmt, (char*)(&fmt + 1));
#endif
    FUN_00214900(L, msg);
    FUN_002149b0(L);
}

} // namespace fn_f9add754

// 0x00214ac0 FUN_00214ac0 (199 B): equivalent/0x00214ac0.cpp [wrapped: code differs from its standalone build]
// sym: _FUN_00214ac0 @dd828a793bde @wbb69f946c729
namespace fn_00214ac0 {
// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 18/18)
// auxgetinfo: fill ar according to the option letters in what for the function f (ci its activation or NULL).

// equiv-conv: FUN_00214160 ecx eax
extern "C++" void FUN_00214160(LuaVMDebug* ar, const LuaVMTObject* func);
extern "C++" int __fastcall FUN_00213f20(LuaVMState* L, LuaVMCallInfo* ci);
// equiv-conv: FUN_00214840 ecx stack
extern "C++" const char* __cdecl FUN_00214840(LuaVMCallInfo* ci, const char** name);

// equiv-conv: FUN_00214ac0 eax esi edi stack stack
extern "C" int __cdecl FUN_00214ac0(const char* what, LuaVMDebug* ar, LuaVMCallInfo* ci, LuaVMState* L, const LuaVMTObject* f)
{
    int status = 1;
    for (; *what; what++) {
        switch (*what) {
        case 'S':
            FUN_00214160(ar, f);
            break;
        case 'l':
            ar->currentline = ci ? FUN_00213f20(0, ci) : -1;
            break;
        case 'u':
            ar->nups = ((LuaVMClosure*)f->value.gc)->c.nupvalues;
            break;
        case 'n':
            ar->namewhat = ci ? FUN_00214840(ci, &ar->name) : 0;
            if (ar->namewhat == 0) {
                ar->namewhat = "";
                ar->name = 0;
            }
            break;
        case 'f':
            L->top->tt = f->tt;
            L->top->value = f->value;
            break;
        default:
            status = 0;
        }
    }
    return status;
}
} // namespace fn_00214ac0

namespace fn_f9add754 {

// 0x00214bd0 FUN_00214bd0 (183 B): equivalent/0x00214bd0.cpp
// sym: _FUN_00214bd0 @26e3a8deacf0 @wcc1c293968e7
// STATUS: equivalent (tools/equiv.py level 3: 3064 inputs, branch coverage 10/10)
// lua_getinfo: fill ar for the activation it names, or for the function on top when what starts with '>'.
// equiv-conv: FUN_00214ac0 eax esi edi stack stack
// equiv-conv: FUN_002141d0 esi stack
extern "C" int __cdecl FUN_00214bd0(LuaVMState* L, const char* what, LuaVMDebug* ar)
{
    int status = 1;
    if (*what == '>') {
        LuaVMTObject* f = L->top - 1;
        if (f->tt != LUAVM_TFUNCTION)
            FUN_00214a90(L, "value for `lua_getinfo' is not a function");
        status = FUN_00214ac0(what + 1, ar, 0, L, f);
        L->top -= 1;
    } else if (ar->i_ci != 0) {
        LuaVMCallInfo* ci = L->base_ci + ar->i_ci;
        status = FUN_00214ac0(what, ar, ci, L, ci->base - 1);
    } else {
        FUN_002141d0(ar, L);
    }
    if (strchr(what, 'f')) {
        if ((char*)L->stack_last - (char*)L->top <= (int)sizeof(LuaVMTObject))
            FUN_00215460(L, 1);
        L->top += 1;
    }
    return status;
}

} // namespace fn_f9add754

// 0x00214c90 FUN_00214c90 (141 B): equivalent/0x00214c90.cpp [wrapped: code differs from its standalone build]
// sym: _FUN_00214c90 @fedf11f99926 @wb8125cfc1ba4
namespace fn_00214c90 {
// STATUS: equivalent (tools/equiv.py level 3: 2951 inputs, branch coverage 8/8)
// luaG_typeerror: "attempt to <op> <kind> `<name>' (a <type> value)" when o is a named stack value, else the short form.

// equiv-conv: FUN_002146f0 eax stack stack
extern "C++" const char* __cdecl FUN_002146f0(unsigned reg, LuaVMCallInfo* ci, const char** name);
extern "C++" void __cdecl FUN_00214a90(LuaVMState* L, const char* fmt, ...);

extern "C" void __cdecl FUN_00214c90(LuaVMState* L, const LuaVMTObject* o, const char* op)
{
    const char* typeName = DAT_00426948[o->tt];
    const char* name = 0;

    for (const LuaVMTObject* p = L->ci->base; p < L->ci->top; ++p) {
        if (p == o) {
            const char* kind = FUN_002146f0((unsigned)(o - L->base), L->ci, &name);
            if (kind != 0) {
                FUN_00214a90(L, "attempt to %s %s `%s' (a %s value)", op, kind, name, typeName);
                return;
            }
            break;
        }
    }
    FUN_00214a90(L, "attempt to %s a %s value", op, typeName);
}
} // namespace fn_00214c90

namespace fn_f9add754 {

// 0x00214d20 FUN_00214d20 (30 B): matches/0x00214d20.cpp
// sym: _FUN_00214d20
// luaG_concaterror: the type error for a concatenation (names p2 when p1 is a string).
extern "C" void __cdecl FUN_00214d20(LuaVMState* L, const LuaVMTObject* p1, const LuaVMTObject* p2) {
    const LuaVMTObject* o = p1;
    if (p1->tt == LUAVM_TSTRING)
        o = p2;
    FUN_00214c90(L, o, "concatenate");
}


// 0x00214d40 FUN_00214d40 (56 B): matches/0x00214d40.cpp
// sym: _FUN_00214d40
// luaG_aritherror: the type error for arithmetic (names p1 when it does not convert to a number, else p2).
extern "C" void __cdecl FUN_00214d40(LuaVMState* L, const LuaVMTObject* p1, const LuaVMTObject* p2) {
    LuaVMTObject temp;
    const LuaVMTObject* o;
    if (FUN_00217600(p1, &temp) == 0)
        o = p1;
    else
        o = p2;
    FUN_00214c90(L, o, "perform arithmetic on");
}


// 0x00214d80 FUN_00214d80 (79 B): matches/0x00214d80.cpp
// sym: _FUN_00214d80
// luaG_ordererror: the error for comparing p1 with p2 (two values of one type, or of two types).
extern "C" int __cdecl FUN_00214d80(LuaVMState* L, const LuaVMTObject* p1, const LuaVMTObject* p2) {
    const char* t1 = DAT_00426948[p1->tt];
    const char* t2 = DAT_00426948[p2->tt];
    if (t1[2] == t2[2]) {
        FUN_00214a90(L, DAT_00426728, t1);
        return 0;
    }
    FUN_00214a90(L, DAT_00426708, t1, t2);
    return 0;
}

} // namespace fn_f9add754
