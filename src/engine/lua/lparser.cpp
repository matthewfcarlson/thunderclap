// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0021c190..0x0021f800 (kind game, layer engine, confidence high)
#include "tree_prelude.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/lua.h"
#define TREE_TU_BEGIN namespace fn_f77c2fa8 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f77c2fa8 {} using namespace fn_f77c2fa8;
#include "engine/lua.h"

// ---- declarations shared by the functions below
namespace fn_f77c2fa8 {
extern "C" int __cdecl FUN_0021bbc0(LuaVMLexState* ls, LuaVMSemInfo* seminfo);
extern "C" const char* __cdecl FUN_00216320(LuaVMState* L, const char* fmt, ...);
extern "C" void __cdecl FUN_0021afd0(LuaVMLexState* ls, const char* msg, int token);
extern "C" const char* __cdecl FUN_0021af00(LuaVMLexState* ls, int token);
extern "C" void __cdecl FUN_0021b060(LuaVMLexState* ls, const char* msg);
extern "C" int __cdecl FUN_002209b0(LuaVMFuncState* fs, LuaVMString* s);
extern "C" void* __cdecl FUN_0021ae40(LuaVMState* L, void* block, int* size, int size_elem, int limit,
                                      const char* errormsg);
extern "C" void __cdecl FUN_00217100(LuaVMState* L, LuaVMGCObject* o, LuaVMGCObject* v);
extern "C" int FUN_0021c5f0(LuaVMFuncState* fs, LuaVMString* name, LuaVMExpDesc* v);
extern "C" void __cdecl FUN_00220a50(LuaVMFuncState* fs, LuaVMExpDesc* e,
                                     int nresults);
extern "C" void __cdecl FUN_00220850(LuaVMFuncState* fs, int n);
extern "C" void FUN_00221110(LuaVMFuncState* fs, LuaVMExpDesc* e);
extern "C" void __cdecl FUN_00220c40(LuaVMFuncState* fs, int from, int n);
extern "C" int __cdecl FUN_00220c10(LuaVMFuncState* fs, unsigned int o, int a, unsigned int bc);
extern "C" int __cdecl FUN_00220bd0(LuaVMFuncState* fs, unsigned int o, int a, unsigned int b,
                                    unsigned int c);
extern "C" LuaVMProto* __cdecl FUN_002196d0(LuaVMState* L);
extern "C" LuaVMTable* __cdecl FUN_00219cc0(LuaVMState* L, int narray, int lnhash);
extern "C" void __cdecl FUN_00215460(LuaVMState* L, int n);
extern "C" void FUN_0021c5b0(LuaVMLexState* ls, int tolevel);
extern "C" void* __cdecl FUN_0021add0(LuaVMState* L, void* block, unsigned int osize, unsigned int nsize);
extern "C" LuaVMString* __cdecl FUN_0021b080(LuaVMLexState* ls, const char* str, unsigned int l);
extern "C" int __cdecl FUN_00221190(LuaVMFuncState* fs, LuaVMExpDesc* e);
extern "C" LuaVMString* FUN_0021c3d0(LuaVMLexState* ls);
extern "C" void __cdecl FUN_002216e0(LuaVMFuncState* fs, LuaVMExpDesc* t, LuaVMExpDesc* k);
extern "C++" __declspec(nothrow) int __cdecl FUN_0021ded0(LuaVMLexState* ls, LuaVMExpDesc* v, unsigned int limit);
extern "C" void __cdecl FUN_002211e0(LuaVMFuncState* fs, LuaVMExpDesc* e);
extern "C" void FUN_0021c2e0(LuaVMLexState* ls, int c);
extern "C" void FUN_0021c240(LuaVMFuncState* fs, const char* what, int limit);
extern "C" void FUN_0021cd30(LuaVMLexState* ls, LuaVMExpDesc* v);
extern "C" int __cdecl FUN_00221200(LuaVMFuncState* fs, LuaVMExpDesc* e);
extern "C" {
unsigned int __cdecl FUN_00215f50(unsigned int x);
}
extern "C" {
void FUN_0021c340(int where, LuaVMLexState* ls, int what, int who);
}
extern "C" {
void FUN_0021cec0(LuaVMConsControl* cc, LuaVMFuncState* fs);
}
extern "C" {
int __cdecl FUN_0021cd90(LuaVMLexState* ls, LuaVMConsControl* cc);
}
static inline void Next(LuaVMLexState* ls) {
    ls->lastline = ls->linenumber;
    if (ls->lookahead.token != 0x11f) {
        ls->t.token = ls->lookahead.token;
        ls->t.seminfo = ls->lookahead.seminfo;
        ls->lookahead.token = 0x11f;
    } else {
        ls->t.token = FUN_0021bbc0(ls, &ls->t.seminfo);
    }
}
extern "C" int __cdecl FUN_0021c490(LuaVMLexState* ls, LuaVMString* varname);
extern "C" void FUN_0021c570(LuaVMLexState* ls, int nvars);
static inline void CheckLocalLimit(LuaVMFuncState* fs, int count) {
    if (fs->nactvar + count > LUAVM_MAXVARS) {
        int line = fs->f->lineDefined;
        const char* msg;
        if (line != 0)
            msg =
                FUN_00216320(fs->L, "function at line %d has more than %d %s", line, 200, "local variables");
        else
            msg = FUN_00216320(fs->L, "main function has more than %d %s", 200, "local variables");
        FUN_0021afd0(fs->ls, msg, 0);
    }
}
extern unsigned int DAT_004d9968;
extern "C" void FUN_0021cac0(LuaVMLexState* ls, LuaVMFuncState* fs);
extern "C" void FUN_0021d210(LuaVMLexState* ls);
extern "C++" __declspec(nothrow) void __cdecl FUN_0021f640(LuaVMLexState* ls);
extern "C" void __cdecl FUN_0021cb80(LuaVMLexState* ls);
extern "C" void __cdecl FUN_0021c9b0(LuaVMLexState* ls, LuaVMFuncState* func, LuaVMExpDesc* v);
extern "C" void FUN_0021c190(LuaVMLexState* ls);
extern "C" void FUN_0021cf70(LuaVMLexState* ls, LuaVMExpDesc* t);
extern "C" int FUN_0021d5c0(LuaVMLexState* ls, LuaVMExpDesc* v);
extern "C" void __cdecl FUN_00220b00(LuaVMFuncState* fs, int line);
extern "C" void __cdecl FUN_0021c790(LuaVMFuncState* fs, LuaVMString* n, LuaVMExpDesc* var,
                                     int base);
extern "C" void __cdecl FUN_00220d90(LuaVMFuncState* fs, LuaVMExpDesc* e);
extern "C" {
void __cdecl FUN_00221360(LuaVMFuncState* fs, LuaVMExpDesc* e, LuaVMExpDesc* key);
}
extern "C" {
void FUN_0021d790(LuaVMLexState* ls, LuaVMExpDesc* v);
}
extern "C" {
void FUN_0021ccb0(LuaVMLexState* ls, LuaVMExpDesc* v);
}
extern "C" {
void FUN_0021d630(LuaVMLexState* ls, LuaVMExpDesc* f);
}
extern "C" int __cdecl FUN_002209e0(LuaVMFuncState* fs, float r);
extern "C" void FUN_0021c440(LuaVMLexState* ls, LuaVMString* s, LuaVMExpDesc* e);
extern "C" void __cdecl FUN_0021d4b0(LuaVMLexState* ls, LuaVMExpDesc* e, int needself, int line);
extern "C" void FUN_0021d830(LuaVMExpDesc* v, LuaVMLexState* ls);
extern "C" void __cdecl FUN_00220d70(LuaVMFuncState* fs, int list);
extern "C" void FUN_0021e110(LuaVMLexState* ls, LuaVMLHSAssign* lh, LuaVMExpDesc* v);
extern "C" void FUN_0021c8b0(LuaVMLexState* ls, LuaVMExpDesc* e, int nexps, int nvars);
extern "C" void __cdecl FUN_00221280(LuaVMFuncState* fs, LuaVMExpDesc* var, LuaVMExpDesc* ex);
extern "C" void __cdecl FUN_002214b0(LuaVMFuncState* fs, LuaVMExpDesc* e);
extern "C" int __cdecl FUN_00220cd0(LuaVMFuncState* fs);
extern "C" int __cdecl FUN_00220530(LuaVMFuncState* fs);
extern "C" void __cdecl FUN_00221560(LuaVMFuncState* fs, LuaVMExpDesc* e);
extern "C" void __cdecl FUN_002207c0(LuaVMFuncState* fs, int* l1, int l2);
extern "C" void FUN_0021e080(LuaVMLexState* ls);
extern "C" void __cdecl FUN_00221ae0(LuaVMFuncState* fs, int list, int target);
extern "C" int __cdecl FUN_00220b20(LuaVMFuncState* fs, LuaVMInstruction i, int line);
extern "C++" __declspec(nothrow) void FUN_0021e700(LuaVMLexState* ls, int base, int line, int nvars, int isnum);
extern "C" void __cdecl FUN_00220810(LuaVMFuncState* fs, int n);
extern "C" void FUN_0021e860(LuaVMLexState* ls, LuaVMString* varname, int line);
extern "C" void FUN_0021ea60(LuaVMLexState* ls, LuaVMString* indexname);
extern "C" int FUN_0021ede0(LuaVMLexState* ls);
extern "C" int FUN_0021f220(LuaVMLexState* ls, LuaVMExpDesc* v);
extern "C" void __cdecl FUN_0021e170(LuaVMLexState* ls, LuaVMLHSAssign* lh, int nvars);
extern "C" int FUN_0021c290(LuaVMLexState* ls, int c);
extern "C" void __cdecl FUN_0021e300(LuaVMLexState* ls, int line);
extern "C" void FUN_0021e5b0(LuaVMLexState* ls, int line);
extern "C" void FUN_0021ecd0(LuaVMLexState* ls, int line);
extern "C" void FUN_0021ee70(LuaVMLexState* ls, int line);
extern "C" void FUN_0021ef60(LuaVMLexState* ls);
extern "C" void FUN_0021f0a0(LuaVMLexState* ls);
extern "C" void FUN_0021f280(LuaVMLexState* ls, int line);
extern "C" void FUN_0021f300(LuaVMLexState* ls);
extern "C" unsigned int FUN_0021f350(LuaVMLexState* ls);
extern "C" void FUN_0021f460(LuaVMLexState* ls);


// 0x0021c190 FUN_0021c190 (48 B): equivalent/0x0021c190.cpp
// sym: _FUN_0021c190
// STATUS: equivalent (tools/equiv.py level 3: 3010 inputs, branch coverage 2/2)
// next: advance to the lookahead token when there is one, else lex the next token.
// equiv-conv: FUN_0021c190 esi
extern "C" void FUN_0021c190(LuaVMLexState* ls) {
    ls->lastline = ls->linenumber;
    if (ls->lookahead.token != 0x11f) {
        ls->t.token = ls->lookahead.token;
        ls->t.seminfo = ls->lookahead.seminfo;
        ls->lookahead.token = 0x11f;
    } else {
        ls->t.token = FUN_0021bbc0(ls, &ls->t.seminfo);
    }
}


// 0x0021c240 FUN_0021c240 (78 B): equivalent/0x0021c240.cpp
// sym: _FUN_0021c240
// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 2/2)
// errorlimit: "main function has more than N what" / "function at line L has more than N what" as a lexer error.
// equiv-conv: FUN_0021c240 esi ecx edx
extern "C" void FUN_0021c240(LuaVMFuncState* fs, const char* what, int limit) {
    if (fs->f->lineDefined == 0) {
        const char* msg = FUN_00216320(fs->L, "main function has more than %d %s", limit, what);
        FUN_0021afd0(fs->ls, msg, 0);
    } else {
        const char* msg =
            FUN_00216320(fs->L, "function at line %d has more than %d %s", fs->f->lineDefined, limit, what);
        FUN_0021afd0(fs->ls, msg, 0);
    }
}


// 0x0021c290 FUN_0021c290 (70 B): equivalent/0x0021c290.cpp
// sym: _FUN_0021c290
// STATUS: equivalent (tools/equiv.py level 3: 3011 inputs, branch coverage 4/4)
// testnext: when the current token is c, advance and return 1; else 0.
// equiv-conv: FUN_0021c290 esi ecx
extern "C" int FUN_0021c290(LuaVMLexState* ls, int c) {
    if (ls->t.token != c)
        return 0;
    ls->lastline = ls->linenumber;
    if (ls->lookahead.token != 0x11f) {
        int token = ls->lookahead.token;
        ls->lookahead.token = 0x11f;
        ls->t.token = token;
        ls->t.seminfo = ls->lookahead.seminfo;
    } else {
        ls->t.token = FUN_0021bbc0(ls, &ls->t.seminfo);
    }
    return 1;
}


// 0x0021c2e0 FUN_0021c2e0 (86 B): equivalent/0x0021c2e0.cpp
// sym: _FUN_0021c2e0
// STATUS: equivalent (tools/equiv.py level 3: 3011 inputs, branch coverage 4/4)
// checknext: expect token c ("`c' expected" otherwise), then advance.
// equiv-conv: FUN_0021c2e0 esi eax
extern "C" void FUN_0021c2e0(LuaVMLexState* ls, int c) {
    if (ls->t.token != c) {
        const char* name = FUN_0021af00(ls, c);
        const char* msg = FUN_00216320(ls->L, "`%s' expected", name);
        FUN_0021b060(ls, msg);
        return;
    }
    ls->lastline = ls->linenumber;
    if (ls->lookahead.token != 0x11f) {
        ls->t.token = ls->lookahead.token;
        ls->t.seminfo = ls->lookahead.seminfo;
        ls->lookahead.token = 0x11f;
    } else {
        ls->t.token = FUN_0021bbc0(ls, &ls->t.seminfo);
    }
}


// 0x0021c340 FUN_0021c340 (143 B): equivalent/0x0021c340.cpp
// sym: _FUN_0021c340
// STATUS: equivalent (tools/equiv.py level 3: 3012 inputs, branch coverage 6/6)
// check_match: expect token what, else report an error (mentioning who and its line when it is another line).
         // luaX_syntaxerror
// equiv-conv: FUN_0021c340 eax esi edi stack
extern "C" void FUN_0021c340(int where, LuaVMLexState* ls, int what, int who) {
    if (ls->t.token == what) {
        ls->lastline = ls->linenumber;
        if (ls->lookahead.token != 287) {
            ls->t.token = ls->lookahead.token;
            ls->t.seminfo = ls->lookahead.seminfo;
            ls->lookahead.token = 287;
        } else {
            ls->t.token = FUN_0021bbc0(ls, &ls->t.seminfo);
        }
        return;
    }
    if (where == ls->linenumber) {
        FUN_0021b060(ls, FUN_00216320(ls->L, "`%s' expected", FUN_0021af00(ls, what)));
    } else {
        FUN_0021b060(ls, FUN_00216320(ls->L, "`%s' expected (to close `%s' at line %d)",
                                      FUN_0021af00(ls, what), FUN_0021af00(ls, who), where));
    }
}


// 0x0021c3d0 FUN_0021c3d0 (80 B): equivalent/0x0021c3d0.cpp
// sym: _FUN_0021c3d0
// STATUS: equivalent (tools/equiv.py level 3: 3011 inputs, branch coverage 4/4)
// str_checkname: expect a name token, return its string and advance.
// equiv-conv: FUN_0021c3d0 esi
extern "C" LuaVMString* FUN_0021c3d0(LuaVMLexState* ls) {
    if (ls->t.token != 0x116)
        FUN_0021b060(ls, "<name> expected");
    ls->lastline = ls->linenumber;
    LuaVMString* ts = ls->t.seminfo.ts;
    if (ls->lookahead.token != 0x11f) {
        ls->t.seminfo = ls->lookahead.seminfo;
        ls->t.token = ls->lookahead.token;
        ls->lookahead.token = 0x11f;
    } else {
        ls->t.token = FUN_0021bbc0(ls, &ls->t.seminfo);
    }
    return ts;
}


// 0x0021c440 FUN_0021c440 (32 B): equivalent/0x0021c440.cpp
// sym: _FUN_0021c440
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// codestring: e = a string constant (VK) of s.
// equiv-conv: FUN_0021c440 ecx eax esi
extern "C" void FUN_0021c440(LuaVMLexState* ls, LuaVMString* s, LuaVMExpDesc* e) {
    int info = FUN_002209b0(ls->fs, s);
    e->t = -1;
    e->f = -1;
    e->k = 4; // VK
    e->info = info;
}


// 0x0021c490 FUN_0021c490 (156 B): matches/0x0021c490.cpp
// sym: _FUN_0021c490
// registerlocalvar: add a local variable's name to the prototype's locvars (growing it) and return its index.
extern "C" int __cdecl FUN_0021c490(LuaVMLexState* ls, LuaVMString* varname) {
    LuaVMFuncState* fs = ls->fs;
    LuaVMProto* f = fs->f;
    int oldsize = f->sizelocvars;
    if (fs->nlocvars + 1 > oldsize)
        f->locvars = (LuaVMLocVar*)FUN_0021ae40(ls->L, f->locvars, &f->sizelocvars, (int)sizeof(LuaVMLocVar), 0xffff,
                                                "too many local variables");
    while (oldsize < f->sizelocvars)
        f->locvars[oldsize++].varname = 0;
    f->locvars[fs->nlocvars].varname = varname;
    if ((varname->marked & 3) && (f->marked & 4))
        FUN_00217100(ls->L, (LuaVMGCObject*)f, (LuaVMGCObject*)varname);
    return fs->nlocvars++;
}


// 0x0021c570 FUN_0021c570 (49 B): equivalent/0x0021c570.cpp
// sym: _FUN_0021c570
// STATUS: equivalent (tools/equiv.py level 3: 70 inputs, branch coverage 4/4)
// adjustlocalvars: activate the last nvars declared locals (their startpc is the current pc).
// equiv-conv: FUN_0021c570 eax edx
extern "C" void FUN_0021c570(LuaVMLexState* ls, int nvars) {
    LuaVMFuncState* fs = ls->fs;
    fs->nactvar = (unsigned char)(fs->nactvar + nvars);
    while (nvars != 0) {
        unsigned int index = (unsigned int)fs->nactvar - nvars;
        fs->f->locvars[fs->actvar[index]].startpc = fs->pc;
        --nvars;
    }
}


// 0x0021c5b0 FUN_0021c5b0 (58 B): equivalent/0x0021c5b0.cpp
// sym: _FUN_0021c5b0
// STATUS: equivalent (tools/equiv.py level 3: 125 inputs, branch coverage 4/4)
// removevars: close the scope of the active locals above tolevel (their endpc is the current pc).
// equiv-conv: FUN_0021c5b0 eax edx
extern "C" void FUN_0021c5b0(LuaVMLexState* ls, int tolevel) {
    LuaVMFuncState* fs = ls->fs;
    while (fs->nactvar > tolevel) {
        --fs->nactvar;
        fs->f->locvars[fs->actvar[fs->nactvar]].endpc = fs->pc;
    }
}


// 0x0021c5f0 FUN_0021c5f0 (324 B): equivalent/0x0021c5f0.cpp
// sym: _FUN_0021c5f0
// STATUS: equivalent (tools/equiv.py level 3: 2980 inputs, branch coverage 22/22)
// indexupvalue: the index of the upvalue v of the function (added, with its name, when new).
// fs arrives in edi, name and v on the stack.
// equiv-conv: FUN_0021c5f0 edi stack stack
extern "C" int FUN_0021c5f0(LuaVMFuncState* fs, LuaVMString* name, LuaVMExpDesc* v) {
    LuaVMProto* f = fs->f;
    int i;
    int oldsize;

    oldsize = f->sizeupvalues;
    for (i = 0; i < f->nups; i++) {
        if (fs->upvalues[i].k == v->k && fs->upvalues[i].info == v->info)
            return i;
    }

    if (f->nups + 1 > LUAVM_MAXUPVALUES) {
        const char* msg;
        if (f->lineDefined == 0)
            msg = FUN_00216320(fs->L, "main function has more than %d %s", 32, "upvalues");
        else
            msg = FUN_00216320(fs->L, "function at line %d has more than %d %s", f->lineDefined, 32,
                               "upvalues");
        FUN_0021afd0(fs->ls, msg, 0);
    }

    if (f->nups + 1 > f->sizeupvalues)
        f->upvalues = (LuaVMString**)FUN_0021ae40(fs->L, f->upvalues, &f->sizeupvalues, (int)sizeof(LuaVMString*),
                                                  0x7ffffffd, "");
    while (oldsize < f->sizeupvalues)
        f->upvalues[oldsize++] = 0;

    f->upvalues[f->nups] = name;
    if ((name->marked & 3) && (f->marked & 4))
        FUN_00217100(fs->L, (LuaVMGCObject*)f, (LuaVMGCObject*)name);
    fs->upvalues[f->nups].k = (unsigned char)v->k;
    fs->upvalues[f->nups].info = (unsigned char)v->info;
    return f->nups++;
}


// 0x0021c790 FUN_0021c790 (225 B): equivalent/0x0021c790.cpp
// sym: _FUN_0021c790
// STATUS: equivalent (tools/equiv.py level 3: 3114 inputs, branch coverage 21/22, incomplete)
// singlevaraux: resolve the name n as a local of fs (marking its block as having an upvalue unless base), an
// upvalue of an enclosing function, or a global (its name constant when base).
// equiv-conv: FUN_0021c5f0 edi stack stack
extern "C" void __cdecl FUN_0021c790(LuaVMFuncState* fs, LuaVMString* n, LuaVMExpDesc* var, int base) {
    if (!fs) {
        var->t = -1;
        var->f = -1;
        var->k = 7;      // VGLOBAL
        var->info = 255; // NO_REG
        return;
    }
    int i = (int)fs->nactvar - 1;
    for (; i >= 0; --i) {
        if (fs->f->locvars[fs->actvar[i]].varname == n)
            break;
    }
    if (i >= 0) {
        var->t = -1;
        var->f = -1;
        var->k = 5; // VLOCAL
        var->info = i;
        if (!base) {
            LuaVMBlockCnt* bl = fs->bl;
            while (bl) {
                if ((int)bl->nactvar <= i) {
                    bl->upval = 1;
                    break;
                }
                bl = bl->previous;
            }
        }
        return;
    }
    FUN_0021c790(fs->prev, n, var, 0);
    if (var->k == 7) {
        if (base)
            var->info = FUN_002209b0(fs, n);
    } else {
        int index = FUN_0021c5f0(fs, n, var);
        var->k = 6; // VUPVAL
        var->info = index;
    }
}


// 0x0021c8b0 FUN_0021c8b0 (114 B): equivalent/0x0021c8b0.cpp
// sym: _FUN_0021c8b0
// STATUS: equivalent (tools/equiv.py level 3: 3003 inputs, branch coverage 8/8)
// adjust_assign: match nexps values to nvars targets (a call's results adjusted, missing values set to nil).
 // luaK_nil
// equiv-conv: FUN_0021c8b0 eax ecx edx stack
extern "C" void FUN_0021c8b0(LuaVMLexState* ls, LuaVMExpDesc* e, int nexps, int nvars) {
    LuaVMFuncState* fs = ls->fs;
    int extra = nvars - nexps;
    if (e->k == 12) { // VCALL
        extra++;
        if (extra <= 0) {
            extra = 0;
            FUN_00220a50(fs, e, extra);
        } else {
            FUN_00220850(fs, extra - 1);
            FUN_00220a50(fs, e, extra);
        }
    } else {
        if (e->k != 0) // VVOID
            FUN_00221110(fs, e);
        if (extra > 0) {
            int reg = fs->freereg;
            FUN_00220850(fs, extra);
            FUN_00220c40(fs, reg, extra);
        }
    }
}


// 0x0021c9b0 FUN_0021c9b0 (261 B): equivalent/0x0021c9b0.cpp
// sym: _FUN_0021c9b0
// STATUS: equivalent (tools/equiv.py level 3: 2861 inputs, branch coverage 16/16)
// pushclosure: add the nested function's prototype to the parent's p, code its CLOSURE (v: VRELOCABLE) and one
// MOVE / GETUPVAL per upvalue.
extern "C" void __cdecl FUN_0021c9b0(LuaVMLexState* ls, LuaVMFuncState* func, LuaVMExpDesc* v) {
    LuaVMFuncState* fs = ls->fs;
    LuaVMProto* f = fs->f;
    int oldsize = f->sizep;
    if (fs->np + 1 > oldsize) {
        f->p = (LuaVMProto**)FUN_0021ae40(ls->L, f->p, &f->sizep, (int)sizeof(LuaVMProto*), 0x3ffff,
                                          "constant table overflow");
    }
    for (int i = oldsize; i < f->sizep; ++i)
        f->p[i] = 0;
    f->p[fs->np] = func->f;
    ++fs->np;
    if ((func->f->marked & 3) && (f->marked & 4))
        FUN_00217100(ls->L, (LuaVMGCObject*)f, (LuaVMGCObject*)func->f);
    int pc = FUN_00220c10(fs, 0x23, 0, (unsigned int)(fs->np - 1)); // OP_CLOSURE
    v->t = -1;
    v->f = -1;
    v->k = 10; // VRELOCABLE
    v->info = pc;
    for (int j = 0; j < func->f->nups; ++j) {
        // OP_MOVE for a local, OP_GETUPVAL for an upvalue
        FUN_00220bd0(fs, (unsigned int)(func->upvalues[j].k == 5 ? 0 : 4), 0,
                     (unsigned int)func->upvalues[j].info, 0);
    }
}


// 0x0021cac0 FUN_0021cac0 (179 B): equivalent/0x0021cac0.cpp
// sym: _FUN_0021cac0
// STATUS: equivalent (tools/equiv.py level 3: 2942 inputs, branch coverage 4/4)
// open_func: start a function: a new prototype and constant table, the FuncState linked on the lexer, both
// anchored on the stack.
// equiv-conv: FUN_0021cac0 ecx eax
extern "C" void FUN_0021cac0(LuaVMLexState* ls, LuaVMFuncState* fs) {
    LuaVMState* L = ls->L;
    LuaVMProto* f = FUN_002196d0(L);
    fs->f = f;
    fs->prev = ls->fs;
    fs->ls = ls;
    fs->L = L;
    ls->fs = fs;
    fs->pc = 0;
    fs->lasttarget = 0;
    fs->jpc = -1;
    fs->freereg = 0;
    fs->nk = 0;
    fs->np = 0;
    fs->nlocvars = 0;
    fs->nactvar = 0;
    fs->bl = 0;
    f->source = ls->source;
    f->maxstacksize = 2;
    LuaVMTable* h = FUN_00219cc0(L, 0, 0);
    fs->h = h;
    LuaVMTObject* o = L->top;
    o->value.gc = (LuaVMGCObject*)h;
    o->tt = LUAVM_TTABLE;
    if ((char*)L->stack_last - (char*)L->top <= (int)sizeof(LuaVMTObject))
        FUN_00215460(L, 1);
    o = L->top + 1;
    L->top = o;
    o->value.gc = (LuaVMGCObject*)f;
    o->tt = LUAVM_TPROTO;
    if ((char*)L->stack_last - (char*)L->top <= (int)sizeof(LuaVMTObject))
        FUN_00215460(L, 1);
    ++L->top;
}


// 0x0021cb80 FUN_0021cb80 (301 B): equivalent/0x0021cb80.cpp
// sym: _FUN_0021cb80
// STATUS: equivalent (tools/equiv.py level 3: 2971 inputs, branch coverage 4/4)
// close_func: finish a function: close its locals, code the final RETURN, shrink the prototype's vectors to their
// use, unlink the FuncState and pop its anchors (re-anchoring the current name or string token).
// equiv-conv: FUN_0021c5b0 eax edx
extern "C" void __cdecl FUN_0021cb80(LuaVMLexState* ls) {
    LuaVMState* L = ls->L;
    LuaVMFuncState* fs = ls->fs;
    LuaVMProto* f = fs->f;

    FUN_0021c5b0(ls, 0);
    FUN_00220bd0(fs, 0x1b, 0, 1, 0); // OP_RETURN 0 1

    f->code =
        (LuaVMInstruction*)FUN_0021add0(L, f->code, f->sizecode * (unsigned int)sizeof(LuaVMInstruction),
                                        fs->pc * (unsigned int)sizeof(LuaVMInstruction));
    f->sizecode = fs->pc;

    f->lineinfo = (int*)FUN_0021add0(L, f->lineinfo, f->sizelineinfo * (unsigned int)sizeof(int),
                                     fs->pc * (unsigned int)sizeof(int));
    f->sizelineinfo = fs->pc;

    f->k = (LuaVMTObject*)FUN_0021add0(L, f->k, f->sizek * (unsigned int)sizeof(LuaVMTObject),
                                       fs->nk * (unsigned int)sizeof(LuaVMTObject));
    f->sizek = fs->nk;

    f->p = (LuaVMProto**)FUN_0021add0(L, f->p, f->sizep * (unsigned int)sizeof(LuaVMProto*),
                                      fs->np * (unsigned int)sizeof(LuaVMProto*));
    f->sizep = fs->np;

    f->locvars = (LuaVMLocVar*)FUN_0021add0(L, f->locvars, f->sizelocvars * (unsigned int)sizeof(LuaVMLocVar),
                                            fs->nlocvars * (unsigned int)sizeof(LuaVMLocVar));
    f->sizelocvars = fs->nlocvars;

    f->upvalues =
        (LuaVMString**)FUN_0021add0(L, f->upvalues, f->sizeupvalues * (unsigned int)sizeof(LuaVMString*),
                                    f->nups * (unsigned int)sizeof(LuaVMString*));
    f->sizeupvalues = f->nups;

    ls->fs = fs->prev;
    L->top -= 2;

    if (ls->t.token == 0x116 || ls->t.token == 0x11e)
        FUN_0021b080(ls, LUAVM_GETSTR(ls->t.seminfo.ts), ls->t.seminfo.ts->len);
}


// 0x0021ccb0 FUN_0021ccb0 (127 B): equivalent/0x0021ccb0.cpp
// sym: _FUN_0021ccb0
// STATUS: equivalent (tools/equiv.py level 3: 3010 inputs, branch coverage 2/2)
// field: v.name (v into a register, the name as a string constant key, VINDEXED).
// equiv-conv: FUN_0021c3d0 esi
// equiv-conv: FUN_0021ccb0 eax ebx
extern "C" void FUN_0021ccb0(LuaVMLexState* ls, LuaVMExpDesc* v) {
    LuaVMFuncState* fs = ls->fs;
    FUN_00221190(fs, v);
    ls->lastline = ls->linenumber;
    if (ls->lookahead.token != 0x11f) {
        ls->t.token = ls->lookahead.token;
        ls->t.seminfo = ls->lookahead.seminfo;
        ls->lookahead.token = 0x11f;
    } else {
        ls->t.token = FUN_0021bbc0(ls, &ls->t.seminfo);
    }
    LuaVMExpDesc key;
    LuaVMString* name = FUN_0021c3d0(ls);
    key.info = FUN_002209b0(ls->fs, name);
    key.k = 4; // VK
    key.t = -1;
    key.f = -1;
    FUN_002216e0(fs, v, &key);
}


// 0x0021cd30 FUN_0021cd30 (85 B): equivalent/0x0021cd30.cpp
// sym: _FUN_0021cd30
// STATUS: equivalent (tools/equiv.py level 3: 3010 inputs, branch coverage 2/2)
// yindex: [ exp ] (the key as a value).
// equiv-conv: FUN_0021c2e0 esi eax
// equiv-conv: FUN_0021cd30 eax edi
extern "C" void FUN_0021cd30(LuaVMLexState* ls, LuaVMExpDesc* v) {
    ls->lastline = ls->linenumber;
    if (ls->lookahead.token == 0x11f) {
        ls->t.token = FUN_0021bbc0(ls, &ls->t.seminfo);
    } else {
        ls->t.token = ls->lookahead.token;
        ls->t.seminfo = ls->lookahead.seminfo;
        ls->lookahead.token = 0x11f;
    }
    FUN_0021ded0(ls, v, 0);
    FUN_002211e0(ls->fs, v);
    FUN_0021c2e0(ls, 0x5d);
}


// 0x0021cd90 FUN_0021cd90 (224 B): equivalent/0x0021cd90.cpp
// sym: _FUN_0021cd90
// STATUS: equivalent (tools/equiv.py level 3: 3004 inputs, branch coverage 4/4)
// recfield: name = exp or [exp] = exp in a table constructor (OP_SETTABLE); returns the instruction's pc.
// equiv-conv: FUN_0021c240 esi ecx edx
// equiv-conv: FUN_0021c3d0 esi
// equiv-conv: FUN_0021cd30 eax edi
// equiv-conv: FUN_0021c2e0 esi eax
extern "C" int __cdecl FUN_0021cd90(LuaVMLexState* ls, LuaVMConsControl* cc) {
    LuaVMFuncState* fs = ls->fs;
    int reg = fs->freereg;
    LuaVMExpDesc key, val;
    if (ls->t.token == 0x116) {
        if (cc->nh > 0x7ffffffd)
            FUN_0021c240(fs, "items in a constructor", 0x7ffffffd);
        ++cc->nh;
        LuaVMString* name = FUN_0021c3d0(ls);
        int info = FUN_002209b0(ls->fs, name);
        key.t = -1;
        key.f = -1;
        key.k = 4; // VK
        key.info = info;
    } else
        FUN_0021cd30(ls, &key);
    FUN_0021c2e0(ls, 0x3d);
    FUN_00221200(fs, &key);
    FUN_0021ded0(ls, &val, 0);
    int rkval = FUN_00221200(fs, &val);
    int rkkey = FUN_00221200(fs, &key);
    int pc = FUN_00220bd0(fs, 9, cc->t->info, (unsigned int)rkkey, (unsigned int)rkval); // OP_SETTABLE
    fs->freereg = reg;
    return pc;
}


// 0x0021cec0 FUN_0021cec0 (105 B): equivalent/0x0021cec0.cpp
// sym: _FUN_0021cec0
// STATUS: equivalent (tools/equiv.py level 3: 3009 inputs, branch coverage 6/6)
// lastlistfield: flush the constructor's pending array items (SETLISTO for an open call).
// cc arrives in esi, fs in edi.
// equiv-conv: FUN_0021cec0 esi edi
extern "C" void FUN_0021cec0(LuaVMConsControl* cc, LuaVMFuncState* fs) {
    if (cc->tostore == 0)
        return;
    if (cc->v.k == 12) { // VCALL
        FUN_00220a50(fs, &cc->v, -1);
        FUN_00220c10(fs, 0x21, cc->t->info, (unsigned int)(cc->na - 1)); // OP_SETLISTO
    } else {
        if (cc->v.k != 0)
            FUN_00221110(fs, &cc->v);
        FUN_00220c10(fs, 0x20, cc->t->info, (unsigned int)(cc->na - 1)); // OP_SETLIST
    }
    fs->freereg = cc->t->info + 1;
}


// 0x0021cf70 FUN_0021cf70 (664 B): equivalent/0x0021cf70.cpp
// sym: _FUN_0021cf70
// STATUS: equivalent (tools/equiv.py level 3: 2742 inputs, branch coverage 24/28, incomplete)
// constructor: a table constructor { ... } (NEWTABLE sized by the items read; list items flushed by SETLIST).
// equiv-conv: FUN_0021c2e0 esi eax
// equiv-conv: FUN_0021c340 eax esi edi stack
// equiv-conv: FUN_0021cec0 esi edi
// Lua 5.0 constructor(ls, t): ls arrives in ecx, t in eax.
// equiv-conv: FUN_0021cf70 ecx eax
extern "C" void FUN_0021cf70(LuaVMLexState* ls, LuaVMExpDesc* t) {
    LuaVMFuncState* fs = ls->fs;
    int line = ls->linenumber;
    int pc = FUN_00220bd0(fs, 0xa, 0, 0, 0);
    LuaVMConsControl cc;

    t->t = -1;
    t->f = -1;
    t->k = 0xa;
    t->info = pc;
    LuaVMFuncState* fs1 = ls->fs;
    cc.tostore = 0;
    cc.na = 0;
    cc.nh = 0;
    cc.t = t;
    cc.v.t = -1;
    cc.v.f = -1;
    cc.v.k = 0;
    cc.v.info = 0;
    FUN_00221110(fs1, t);
    FUN_0021c2e0(ls, 0x7b);

    for (;;) {
        if (ls->t.token == 0x3b)
            Next(ls);
        if (ls->t.token == 0x7d)
            break;

        if (cc.v.k != 0) {
            FUN_00221110(fs, &cc.v);
            cc.v.k = 0;
            if (cc.tostore == 0x20) {
                FUN_00220c10(fs, 0x20, cc.t->info, (unsigned int)(cc.na - 1));
                cc.tostore = 0;
                fs->freereg = cc.t->info + 1;
            }
        }

        bool rec = false;
        if (ls->t.token == '[') {
            rec = true;
        } else if (ls->t.token == 0x116) {
            ls->lookahead.token = FUN_0021bbc0(ls, &ls->lookahead.seminfo);
            rec = (ls->lookahead.token == '=');
        }
        if (rec) {
            FUN_0021cd90(ls, &cc);
        } else {
            FUN_0021ded0(ls, &cc.v, 0);
            if (cc.na > 0x3ffff) {
                LuaVMFuncState* f2 = ls->fs;
                const char* msg;
                int ld = f2->f->lineDefined;
                if (ld != 0)
                    msg = FUN_00216320(f2->L, "function at line %d has more than %d %s", ld, 0x3ffff,
                                       "items in a constructor");
                else
                    msg = FUN_00216320(f2->L, "main function has more than %d %s", 0x3ffff,
                                       "items in a constructor");
                FUN_0021afd0(f2->ls, msg, 0);
            }
            cc.na++;
            cc.tostore++;
        }

        if (ls->t.token == ',') {
            Next(ls);
        } else if (ls->t.token == ';') {
            Next(ls);
        } else {
            break;
        }
    }

    FUN_0021c340(line, ls, 0x7d, 0x7b);
    FUN_0021cec0((&cc), fs);
    LuaVMInstruction* ip = &fs->f->code[pc];
    int fb = ((int)FUN_00215f50(cc.na));
    unsigned int i = *ip;
    *ip = (i & ~0xff8000u) | (((unsigned int)fb << 15) & 0xff8000u);
    ip = &fs->f->code[pc];
    int lg = FUN_00215f70(cc.nh);
    i = *ip;
    *ip = (i & ~0x7fc0u) | (((unsigned int)(lg + 1) << 6) & 0x7fc0u);
}


// 0x0021d210 FUN_0021d210 (665 B): equivalent/0x0021d210.cpp
// sym: _FUN_0021d210
// STATUS: equivalent (tools/equiv.py level 3: 3026 inputs, branch coverage 22/28, incomplete)
// parlist: the parameter list (names, `...' as the vararg `arg'); numparams, is_vararg, the registers.
// equiv-conv: FUN_0021c2e0 esi eax
// equiv-conv: FUN_0021c570 eax edx
// ls arrives in eax.
// equiv-conv: FUN_0021d210 eax
extern "C" void FUN_0021d210(LuaVMLexState* ls) {
    LuaVMFuncState* fs0 = ls->fs;
    LuaVMFuncState* fs;
    LuaVMProto* f = fs0->f;
    int nparams = 0;

    f->is_vararg = 0;
    if (ls->t.token != ')') {
        for (;;) {
            if (ls->t.token == 0x116) {
                LuaVMString* name = ls->t.seminfo.ts;
                Next(ls);
                fs = ls->fs;
                CheckLocalLimit(fs, nparams + 1);
                fs->actvar[fs->nactvar + nparams] = (unsigned short)FUN_0021c490(ls, name);
                nparams++;
                if (ls->t.token == '=') {
                    Next(ls);
                    FUN_0021c2e0(ls, 0x118);
                    f->is_vararg = 1;
                    break;
                }
            } else if (ls->t.token == 0x118) {
                Next(ls);
                LuaVMString* name = FUN_0021b080(ls, "arg", 3);
                LuaVMFuncState* cur = ls->fs;
                CheckLocalLimit(cur, nparams + 1);
                cur->actvar[cur->nactvar + nparams] = (unsigned short)FUN_0021c490(ls, name);
                nparams++;
                f->is_vararg = 1;
                break;
            } else {
                FUN_0021b060(ls, "<name> or `...' expected");
            }

            if (f->is_vararg)
                break;
            if (ls->t.token != ',')
                break;
            Next(ls);
        }
    }

    FUN_0021c570(ls, nparams);
    f->numparams = (unsigned char)(fs0->nactvar - f->is_vararg);
    FUN_00220850(fs0, fs0->nactvar);
}


// 0x0021d4b0 FUN_0021d4b0 (263 B): equivalent/0x0021d4b0.cpp
// sym: _FUN_0021d4b0
// STATUS: equivalent (tools/equiv.py level 3: 2847 inputs, branch coverage 4/4)
// body: a function body ( parlist ) chunk end, compiled in a new FuncState (with `self' first when needself);
// e is the closure.
// equiv-conv: FUN_0021cac0 ecx eax
// equiv-conv: FUN_0021c2e0 esi eax
// equiv-conv: FUN_0021c240 esi ecx edx
// equiv-conv: FUN_0021d210 eax
// equiv-conv: FUN_0021c340 eax esi edi stack
// equiv-conv: FUN_0021d4b0 ebx stack stack stack
extern "C" void __cdecl FUN_0021d4b0(LuaVMLexState* ls, LuaVMExpDesc* e, int needself, int line) {
    unsigned int cookie = DAT_004d9968;
    LuaVMFuncState new_fs;
    FUN_0021cac0(ls, &new_fs);
    new_fs.f->lineDefined = line;
    FUN_0021c2e0(ls, 0x28);
    if (needself) {
        LuaVMString* name = FUN_0021b080(ls, "self", 4);
        LuaVMFuncState* fs = ls->fs;
        if ((int)fs->nactvar + 1 > LUAVM_MAXVARS)
            FUN_0021c240(fs, "local variables", 200);
        unsigned short index = (unsigned short)FUN_0021c490(ls, name);
        fs->actvar[fs->nactvar] = index;
        fs = ls->fs;
        fs->nactvar = (unsigned char)(fs->nactvar + 1);
        fs->f->locvars[fs->actvar[fs->nactvar - 1]].startpc = fs->pc;
    }
    FUN_0021d210(ls);
    FUN_0021c2e0(ls, 0x29);
    FUN_0021f640(ls);
    FUN_0021c340(line, ls, 0x106, 0x109); // TK_END, TK_FUNCTION
    FUN_0021cb80(ls);
    FUN_0021c9b0(ls, &new_fs, e);
    __security_check_cookie(cookie);
}


// 0x0021d5c0 FUN_0021d5c0 (105 B): equivalent/0x0021d5c0.cpp
// sym: _FUN_0021d5c0
// STATUS: equivalent (tools/equiv.py level 3: 3011 inputs, branch coverage 4/4)
// explist1: expr { , expr } (each but the last into the next register); returns the count.
// ls arrives in esi, v in edi.
// equiv-conv: FUN_0021d5c0 esi edi
extern "C" int FUN_0021d5c0(LuaVMLexState* ls, LuaVMExpDesc* v) {
    int n = 1;
    FUN_0021ded0(ls, v, 0);
    while (ls->t.token == ',') {
        ls->lastline = ls->linenumber;
        if (ls->lookahead.token != 0x11f) {
            ls->t.token = ls->lookahead.token;
            ls->t.seminfo = ls->lookahead.seminfo;
            ls->lookahead.token = 0x11f;
        } else {
            ls->t.token = FUN_0021bbc0(ls, &ls->t.seminfo);
        }
        FUN_00221110(ls->fs, v);
        FUN_0021ded0(ls, v, 0);
        n++;
    }
    return n;
}


// 0x0021d630 FUN_0021d630 (349 B): equivalent/0x0021d630.cpp
// sym: _FUN_0021d630
// STATUS: equivalent (tools/equiv.py level 3: 3039 inputs, branch coverage 15/16, incomplete)
// funcargs: a call's arguments: ( explist ), a table constructor or a string; f becomes the CALL (VCALL).
// equiv-conv: FUN_0021c190 esi
// equiv-conv: FUN_0021c340 eax esi edi stack
// equiv-conv: FUN_0021cf70 ecx eax
// equiv-conv: FUN_0021d5c0 esi edi
// ls arrives in eax, f on the stack.
// equiv-conv: FUN_0021d630 eax stack
extern "C" void FUN_0021d630(LuaVMLexState* ls, LuaVMExpDesc* f) {
    LuaVMFuncState* fs = ls->fs;
    LuaVMExpDesc args;
    int line = ls->linenumber;
    int nparams;
    int base;

    switch (ls->t.token) {
    case '(':
        if (line != ls->lastline)
            FUN_0021b060(ls, "ambiguous syntax (function call x new statement)");
        ls->lastline = ls->linenumber;
        if (ls->lookahead.token != 0x11f) {
            ls->t.token = ls->lookahead.token;
            ls->t.seminfo = ls->lookahead.seminfo;
            ls->lookahead.token = 0x11f;
        } else {
            ls->t.token = FUN_0021bbc0(ls, &ls->t.seminfo);
        }
        if (ls->t.token == ')') {
            args.k = 0; // VVOID
        } else {
            FUN_0021d5c0(ls, &args);
            FUN_00220a50(fs, &args, -1);
        }
        FUN_0021c340(line, ls, ')', '(');
        break;
    case '{':
        FUN_0021cf70(ls, &args);
        break;
    case 0x11e:     // TK_STRING
        args.k = 4; // VK
        args.info = FUN_002209b0(fs, ls->t.seminfo.ts);
        args.t = -1;
        args.f = -1;
        args.aux = -1;
        FUN_0021c190(ls);
        break;
    default:
        FUN_0021b060(ls, "function arguments expected");
        return;
    }

    base = f->info;
    if (args.k == 12) { // VCALL
        nparams = -1;
    } else {
        if (args.k != 0)
            FUN_00221110(fs, &args);
        nparams = fs->freereg - base - 1;
    }
    f->info = FUN_00220bd0(fs, 0x19, base, (unsigned int)(nparams + 1), 2); // OP_CALL
    f->t = -1;
    f->f = -1;
    f->k = 12;
    FUN_00220b00(fs, line);
    fs->freereg = base + 1;
}


// 0x0021d790 FUN_0021d790 (145 B): equivalent/0x0021d790.cpp
// sym: _FUN_0021d790
// STATUS: equivalent (tools/equiv.py level 3: 3015 inputs, branch coverage 6/6)
// prefixexp: a name or a parenthesized expression.
// equiv-conv: FUN_0021c340 eax esi edi stack
// equiv-conv: FUN_0021c3d0 esi
 // luaK_dischargevars
// equiv-conv: FUN_0021d790 eax ebx
extern "C" void FUN_0021d790(LuaVMLexState* ls, LuaVMExpDesc* v) {
    switch (ls->t.token) {
    case '(': {
        int line = ls->linenumber;
        // luaX_next(ls)
        ls->lastline = line;
        if (ls->lookahead.token != 0x11f) {
            ls->t = ls->lookahead;
            ls->lookahead.token = 0x11f;
        } else {
            ls->t.token = FUN_0021bbc0(ls, &ls->t.seminfo);
        }
        FUN_0021ded0(ls, v, 0);
        FUN_0021c340(line, ls, ')', '(');
        FUN_00220d90(ls->fs, v);
        return;
    }
    case 0x116:
        FUN_0021c790(ls->fs, FUN_0021c3d0(ls), v, 1);
        return;
    default:
        FUN_0021b060(ls, "unexpected symbol");
        return;
    }
}


// 0x0021d830 FUN_0021d830 (519 B): equivalent/0x0021d830.cpp
// sym: _FUN_0021d830
// STATUS: equivalent (tools/equiv.py level 3: 3039 inputs, branch coverage 18/21, incomplete)
// equiv-conv: FUN_0021d790 eax ebx
// equiv-conv: FUN_0021ccb0 eax ebx
// equiv-conv: FUN_0021d630 eax stack
// primaryexp: a prefix expression followed by any number of field,
// index, method-call and call suffixes. v arrives in eax, ls in esi.
// equiv-conv: FUN_0021d830 eax esi
extern "C" void FUN_0021d830(LuaVMExpDesc* v, LuaVMLexState* ls) {
    LuaVMExpDesc key;
    LuaVMExpDesc method;
    LuaVMFuncState* fs = ls->fs;

    FUN_0021d790(ls, v);
    for (;;) {
        switch (ls->t.token) {
        case '.':
            FUN_0021ccb0(ls, v);
            break;
        case '[':
            FUN_00221190(fs, v);
            ls->lastline = ls->linenumber;
            if (ls->lookahead.token != 0x11f) {
                ls->t.token = ls->lookahead.token;
                ls->t.seminfo = ls->lookahead.seminfo;
                ls->lookahead.token = 0x11f;
            } else {
                ls->t.token = FUN_0021bbc0(ls, &ls->t.seminfo);
            }
            FUN_0021ded0(ls, &key, 0);
            FUN_002211e0(ls->fs, &key);
            if (ls->t.token != ']')
                FUN_0021b060(ls, FUN_00216320(ls->L, "`%s' expected", FUN_0021af00(ls, ']')));
            ls->lastline = ls->linenumber;
            if (ls->lookahead.token != 0x11f) {
                ls->t.token = ls->lookahead.token;
                ls->t.seminfo = ls->lookahead.seminfo;
                ls->lookahead.token = 0x11f;
            } else {
                ls->t.token = FUN_0021bbc0(ls, &ls->t.seminfo);
            }
            FUN_002216e0(fs, v, &key);
            break;
        case ':': {
            ls->lastline = ls->linenumber;
            if (ls->lookahead.token != 0x11f) {
                ls->t.token = ls->lookahead.token;
                ls->t.seminfo = ls->lookahead.seminfo;
                ls->lookahead.token = 0x11f;
            } else {
                ls->t.token = FUN_0021bbc0(ls, &ls->t.seminfo);
            }
            if (ls->t.token != 0x116)
                FUN_0021b060(ls, "<name> expected");
            LuaVMString* name = ls->t.seminfo.ts;
            ls->lastline = ls->linenumber;
            if (ls->lookahead.token != 0x11f) {
                ls->t.token = ls->lookahead.token;
                ls->t.seminfo = ls->lookahead.seminfo;
                ls->lookahead.token = 0x11f;
            } else {
                ls->t.token = FUN_0021bbc0(ls, &ls->t.seminfo);
            }
            method.k = 4;
            method.info = FUN_002209b0(ls->fs, name);
            method.t = -1;
            method.f = -1;
            FUN_00221360(fs, v, &method);
            FUN_0021d630(ls, v);
            break;
        }
        case '(':
        case '{':
        case 0x11e:
            FUN_00221110(fs, v);
            FUN_0021d630(ls, v);
            break;
        default:
            return;
        }
    }
}


// 0x0021db50 FUN_0021db50 (245 B): equivalent/0x0021db50.cpp
// sym: _FUN_0021db50
// STATUS: equivalent (tools/equiv.py level 3: 3026 inputs, branch coverage 10/10)
// simpleexp: a number, string, nil, true, false, table constructor, function or primary expression.
// equiv-conv: FUN_0021c190 esi
// equiv-conv: FUN_0021c440 ecx eax esi
// equiv-conv: FUN_0021cf70 ecx eax
// equiv-conv: FUN_0021d4b0 ebx stack stack stack
// equiv-conv: FUN_0021d830 eax esi
// equiv-conv: FUN_0021db50 eax edi
extern "C" void FUN_0021db50(LuaVMLexState* ls, LuaVMExpDesc* v) {
    switch (ls->t.token) {
    case 0x11d: { // TK_NUMBER
        int info = FUN_002209e0(ls->fs, ls->t.seminfo.r);
        v->t = -1;
        v->f = -1;
        v->k = 4; // VK
        v->info = info;
        FUN_0021c190(ls);
        break;
    }
    case 0x11e: // TK_STRING
        FUN_0021c440(ls, ls->t.seminfo.ts, v);
        FUN_0021c190(ls);
        break;
    case 0x10d: // TK_NIL
    case 0x113: // TK_TRUE
    case 0x107: // TK_FALSE
        v->t = -1;
        v->f = -1;
        v->k = ls->t.token == 0x107 ? 3 : ls->t.token == 0x10d ? 1 : 2; // VFALSE, VNIL, VTRUE
        v->info = 0;
        FUN_0021c190(ls);
        break;
    case '{':
        FUN_0021cf70(ls, v);
        break;
    case 0x109: // TK_FUNCTION
        FUN_0021c190(ls);
        FUN_0021d4b0(ls, v, 0, ls->linenumber);
        break;
    default:
        FUN_0021d830(v, ls);
        break;
    }
}


// 0x0021dd30 FUN_0021dd30 (111 B): equivalent/0x0021dd30.cpp
// sym: _FUN_0021dd30
// STATUS: equivalent (tools/equiv.py level 3: 3038 inputs, branch coverage 17/17)
// FUN_0021dd30 @ 0x0021dd30
// equiv-conv: FUN_0021dd30 eax
extern "C" int FUN_0021dd30(int op) {
    switch (op) {
    case '+':
        return 0;
    case '-':
        return 1;
    case '*':
        return 2;
    case '/':
        return 3;
    case '^':
        return 4;
    case 0x117:
        return 5;
    case 0x11c:
        return 6;
    case 0x119:
        return 7;
    case '<':
        return 8;
    case 0x11b:
        return 9;
    case '>':
        return 10;
    case 0x11a:
        return 11;
    case 0x101:
        return 12;
    case 0x10f:
        return 13;
    }
    return 14;
}

} // namespace fn_f77c2fa8

// 0x0021ded0 FUN_0021ded0 (327 B): equivalent/0x0021ded0.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: _FUN_0021ded0
namespace fn_0021ded0 {
// STATUS: equivalent (tools/equiv.py level 3: 2751 inputs, branch coverage 16/16)
// subexpr: (simpleexp | unop subexpr) { binop subexpr } while the operator's left priority exceeds limit;
// returns the first operator not handled.
// data: priority = DAT_00426e00 ({left, right} per binary operator)

extern "C++" __declspec(nothrow) int __cdecl FUN_0021bbc0(LuaVMLexState* ls, LuaVMSemInfo* seminfo);
extern "C++" __declspec(nothrow) void __cdecl FUN_0021afd0(LuaVMLexState* ls, const char* msg, int token);
// equiv-conv: FUN_0021db50 eax edi
extern "C++" __declspec(nothrow) void FUN_0021db50(LuaVMLexState* ls, LuaVMExpDesc* v);
// equiv-conv: FUN_0021dd30 eax
extern "C++" __declspec(nothrow) int FUN_0021dd30(int op);
extern "C" void __cdecl FUN_00221700(LuaVMFuncState* fs, int op, LuaVMExpDesc* e);
extern "C" void __cdecl FUN_002217c0(LuaVMFuncState* fs, int op, LuaVMExpDesc* v);
extern "C" void __cdecl FUN_002218d0(LuaVMFuncState* fs, int op, LuaVMExpDesc* e1, LuaVMExpDesc* e2);

static void next(LuaVMLexState* ls) {
    ls->lastline = ls->linenumber;
    if (ls->lookahead.token != 0x11f) {
        ls->t.token = ls->lookahead.token;
        ls->t.seminfo = ls->lookahead.seminfo;
        ls->lookahead.token = 0x11f;
    } else {
        ls->t.token = FUN_0021bbc0(ls, &ls->t.seminfo);
    }
}

extern "C" int __cdecl FUN_0021ded0(LuaVMLexState* ls, LuaVMExpDesc* v, unsigned int limit) {
    LuaVMExpDesc v2;
    int op;

    ls->nestlevel++;
    if (ls->nestlevel > 200)
        FUN_0021afd0(ls, "chunk has too many syntax levels", 0);

    if (ls->t.token == '-' || ls->t.token == 0x10e) {
        int uop = (ls->t.token == 0x10e); // OPR_NOT : OPR_MINUS
        next(ls);
        FUN_0021ded0(ls, v, 8); // UNARY_PRIORITY
        FUN_00221700(ls->fs, uop, v);
    } else {
        FUN_0021db50(ls, v);
    }
    op = FUN_0021dd30(ls->t.token);
    while (op != 0xe && DAT_00426e00[op * 2] > limit) {
        next(ls);
        FUN_002217c0(ls->fs, op, v);
        int nextop = FUN_0021ded0(ls, &v2, DAT_00426e00[op * 2 + 1]);
        FUN_002218d0(ls->fs, op, v, &v2);
        op = nextop;
    }
    ls->nestlevel--;
    return op;
}
} // namespace fn_0021ded0

namespace fn_f77c2fa8 {

// 0x0021e080 FUN_0021e080 (129 B): equivalent/0x0021e080.cpp
// sym: _FUN_0021e080
// STATUS: equivalent (tools/equiv.py level 3: 2993 inputs, branch coverage 2/2)
// block: enter a block, parse the chunk, then leave the block (close its locals and upvalues, patch its breaks).
// equiv-conv: FUN_0021c5b0 eax edx
// equiv-conv: FUN_0021e080 eax
extern "C" void FUN_0021e080(LuaVMLexState* ls) {
    LuaVMFuncState* fs = ls->fs;
    LuaVMBlockCnt bl;

    bl.breaklist = -1;
    bl.isbreakable = 0;
    bl.nactvar = fs->nactvar;
    bl.upval = 0;
    bl.previous = fs->bl;
    fs->bl = &bl;

    FUN_0021f640(ls);

    LuaVMBlockCnt* b = fs->bl;
    fs->bl = b->previous;
    FUN_0021c5b0(fs->ls, b->nactvar);
    if (b->upval)
        FUN_00220bd0(fs, 0x22, b->nactvar, 0, 0); // OP_CLOSE
    fs->freereg = fs->nactvar;
    FUN_00220d70(fs, b->breaklist);
}


// 0x0021e110 FUN_0021e110 (95 B): equivalent/0x0021e110.cpp
// sym: _FUN_0021e110
// STATUS: equivalent (tools/equiv.py level 3: 3007 inputs, branch coverage 12/12)
// check_conflict: when an earlier target of the assignment indexes with the local v, use a copy of v instead.
// equiv-conv: FUN_0021e110 ecx eax edi
extern "C" void FUN_0021e110(LuaVMLexState* ls, LuaVMLHSAssign* lh, LuaVMExpDesc* v) {
    LuaVMFuncState* fs = ls->fs;
    int extra = fs->freereg;
    bool conflict = false;
    for (; lh; lh = lh->prev) {
        if (lh->v.k == 8) { // VINDEXED
            if (lh->v.info == v->info) {
                conflict = true;
                lh->v.info = extra;
            }
            if (lh->v.aux == v->info) {
                conflict = true;
                lh->v.aux = extra;
            }
        }
    }
    if (conflict) {
        FUN_00220bd0(fs, 0, fs->freereg, (unsigned int)v->info, 0); // OP_MOVE
        FUN_00220850(fs, 1);
    }
}


// 0x0021e170 FUN_0021e170 (308 B): equivalent/0x0021e170.cpp
// sym: _FUN_0021e170
// STATUS: equivalent (tools/equiv.py level 3: 3037 inputs, branch coverage 14/14)
// equiv-conv: FUN_0021d830 eax esi
// equiv-conv: FUN_0021e110 ecx eax edi
// equiv-conv: FUN_0021c2e0 esi eax
// equiv-conv: FUN_0021d5c0 esi edi
// equiv-conv: FUN_0021c8b0 eax ecx edx stack
// restassign: the rest of an assignment's targets (, primaryexp), then = explist1; stores right to left.
extern "C" void __cdecl FUN_0021e170(LuaVMLexState* ls, LuaVMLHSAssign* lh, int nvars) {
    struct {
        LuaVMExpDesc e;
        LuaVMLHSAssign nv;
    } f;
    if (lh->v.k < 5 || lh->v.k > 8)
        FUN_0021b060(ls, "syntax error");
    if (ls->t.token == ',') {
        f.nv.prev = lh;
        ls->lastline = ls->linenumber;
        if (ls->lookahead.token != 0x11f) {
            ls->t.token = ls->lookahead.token;
            ls->t.seminfo = ls->lookahead.seminfo;
            ls->lookahead.token = 0x11f;
        } else {
            ls->t.token = FUN_0021bbc0(ls, &ls->t.seminfo);
        }
        FUN_0021d830(&f.nv.v, ls);
        if (f.nv.v.k == 5)
            FUN_0021e110(ls, lh, &f.nv.v);
        FUN_0021e170(ls, &f.nv, nvars + 1);
    } else {
        FUN_0021c2e0(ls, '=');
        int nexps = FUN_0021d5c0(ls, &f.e);
        if (nexps == nvars) {
            FUN_00220a50(ls->fs, &f.e, 1);
            FUN_00221280(ls->fs, &lh->v, &f.e);
            return;
        }
        FUN_0021c8b0(ls, &f.e, nexps, nvars);
        if (nexps > nvars)
            ls->fs->freereg += nvars - nexps;
    }
    LuaVMFuncState* fs = ls->fs;
    f.e.info = fs->freereg - 1;
    f.e.t = -1;
    f.e.f = -1;
    f.e.k = 11; // VNONRELOC
    FUN_00221280(fs, &lh->v, &f.e);
}


// 0x0021e2b0 FUN_0021e2b0 (70 B): equivalent/0x0021e2b0.cpp
// sym: _FUN_0021e2b0
// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 2/2)
// cond: a condition (nil as false); jumps when true go here, returns the false list.
// equiv-conv: FUN_0021e2b0 esi
extern "C" int FUN_0021e2b0(LuaVMLexState* ls) {
    LuaVMExpDesc v;
    FUN_0021ded0(ls, &v, 0);
    if (v.k == 1) // VNIL
        v.k = 3;  // VFALSE
    FUN_002214b0(ls->fs, &v);
    FUN_00220d70(ls->fs, v.t);
    return v.f;
}


// 0x0021e300 FUN_0021e300 (673 B): equivalent/0x0021e300.cpp
// sym: _FUN_0021e300
// STATUS: equivalent (tools/equiv.py level 3: 3035 inputs, branch coverage 23/26, incomplete)
// equiv-conv: FUN_0021e080 eax
// equiv-conv: FUN_0021c340 eax esi edi stack
// whilestat: while cond do block end (the condition is coded after the block, its code copied there).
extern "C" void __cdecl FUN_0021e300(LuaVMLexState* ls, int line) {
    LuaVMInstruction codeexp[105];
    LuaVMBlockCnt bl;
    LuaVMExpDesc v;
    int whileinit;
    int expinit;
    int lineexp;
    int sizeexp;
    int blockinit;
    int i;
    LuaVMFuncState* fs = ls->fs;

    Next(ls);
    whileinit = FUN_00220cd0(fs);
    expinit = FUN_00220530(fs);
    FUN_0021ded0(ls, &v, 0);
    if (v.k == 4)
        v.k = 2;
    lineexp = ls->linenumber;
    FUN_00221560(fs, &v);
    FUN_002207c0(fs, &v.f, fs->jpc);
    sizeexp = fs->pc - expinit;
    fs->jpc = -1;
    if (sizeexp > 100)
        FUN_0021b060(ls, "`while' condition too complex");
    for (i = 0; i < sizeexp; i++)
        codeexp[i] = fs->f->code[expinit + i];
    fs->pc = expinit;

    bl.breaklist = -1;
    bl.isbreakable = 1;
    bl.nactvar = fs->nactvar;
    bl.upval = 0;
    bl.previous = fs->bl;
    fs->bl = &bl;

    if (ls->t.token == 0x103) {
        Next(ls);
    } else {
        FUN_0021b060(ls, FUN_00216320(ls->L, "`%s' expected", FUN_0021af00(ls, 0x103)));
    }

    blockinit = FUN_00220530(fs);
    FUN_0021e080(ls);
    FUN_00220d70(fs, whileinit);
    if (v.t != -1)
        v.t += fs->pc - expinit;
    if (v.f != -1)
        v.f += fs->pc - expinit;
    for (i = 0; i < sizeexp; i++)
        FUN_00220b20(fs, codeexp[i], lineexp);
    FUN_0021c340(line, ls, 0x106, 0x115);

    LuaVMBlockCnt* b = fs->bl;
    fs->bl = b->previous;
    LuaVMFuncState* fs2 = fs->ls->fs;
    int level = b->nactvar;
    while (fs2->nactvar > level) {
        fs2->nactvar--;
        fs2->f->locvars[fs2->actvar[fs2->nactvar]].endpc = fs2->pc;
    }
    if (b->upval)
        FUN_00220bd0(fs, 0x22, b->nactvar, 0, 0);
    fs->freereg = fs->nactvar;
    FUN_00220d70(fs, b->breaklist);
    FUN_00221ae0(fs, v.t, blockinit);
    FUN_00220d70(fs, v.f);
}


// 0x0021e5b0 FUN_0021e5b0 (287 B): equivalent/0x0021e5b0.cpp
// sym: _FUN_0021e5b0
// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 6/6)
// repeatstat: repeat block until cond (a loop block; the false list jumps back to the start).
// equiv-conv: FUN_0021e080 eax
// equiv-conv: FUN_0021c340 eax esi edi stack
// equiv-conv: FUN_0021c5b0 eax edx
// equiv-conv: FUN_0021e5b0 eax stack
extern "C" void FUN_0021e5b0(LuaVMLexState* ls, int line) {
    LuaVMFuncState* fs = ls->fs;
    int repeat_init = FUN_00220530(fs);
    LuaVMBlockCnt bl;
    bl.breaklist = -1;
    bl.isbreakable = 1;
    bl.nactvar = fs->nactvar;
    bl.upval = 0;
    bl.previous = fs->bl;
    fs->bl = &bl;
    ls->lastline = ls->linenumber;
    if (ls->lookahead.token != 0x11f) {
        ls->t.token = ls->lookahead.token;
        ls->t.seminfo = ls->lookahead.seminfo;
        ls->lookahead.token = 0x11f;
    } else
        ls->t.token = FUN_0021bbc0(ls, &ls->t.seminfo);
    FUN_0021e080(ls);
    FUN_0021c340(line, ls, 0x114, 0x110); // TK_UNTIL, TK_REPEAT
    LuaVMExpDesc v;
    FUN_0021ded0(ls, &v, 0);
    if (v.k == 1) // VNIL
        v.k = 3;  // VFALSE
    FUN_002214b0(ls->fs, &v);
    FUN_00220d70(ls->fs, v.t);
    FUN_00221ae0(fs, v.f, repeat_init);
    LuaVMBlockCnt* b = fs->bl;
    fs->bl = b->previous;
    FUN_0021c5b0(fs->ls, b->nactvar);
    if (b->upval)
        FUN_00220bd0(fs, 0x22, b->nactvar, 0, 0); // OP_CLOSE
    fs->freereg = fs->nactvar;
    FUN_00220d70(fs, b->breaklist);
}

} // namespace fn_f77c2fa8

// 0x0021e700 FUN_0021e700 (349 B): equivalent/0x0021e700.cpp [wrapped: code differs from its standalone build]
// sym: _FUN_0021e700
namespace fn_0021e700 {
// STATUS: equivalent (tools/equiv.py level 3: 110 inputs, branch coverage 10/10)

// equiv-conv: FUN_0021c2e0 esi eax
extern "C++" __declspec(nothrow) void FUN_0021c2e0(LuaVMLexState* ls, int c);
// equiv-conv: FUN_0021c570 eax edx
extern "C++" __declspec(nothrow) void FUN_0021c570(LuaVMLexState* ls, int nvars);
// equiv-conv: FUN_0021e080 eax
extern "C++" __declspec(nothrow) void FUN_0021e080(LuaVMLexState* ls);
// equiv-conv: FUN_0021c5b0 eax edx
extern "C++" __declspec(nothrow) void FUN_0021c5b0(LuaVMLexState* ls, int tolevel);
extern "C++" __declspec(nothrow) int __cdecl FUN_00220c10(LuaVMFuncState* fs, unsigned int o, int a, unsigned int bc);
extern "C++" __declspec(nothrow) int __cdecl FUN_00220bd0(LuaVMFuncState* fs, unsigned int o, int a, unsigned int b,
                                    unsigned int c);
extern "C++" __declspec(nothrow) void __cdecl FUN_00220850(LuaVMFuncState* fs, int n);
extern "C++" __declspec(nothrow) void __cdecl FUN_00220d70(LuaVMFuncState* fs, int list);
extern "C++" __declspec(nothrow) void __cdecl FUN_00220b00(LuaVMFuncState* fs, int line);
extern "C++" __declspec(nothrow) int __cdecl FUN_00220cd0(LuaVMFuncState* fs);
extern "C++" __declspec(nothrow) void __cdecl FUN_00221ae0(LuaVMFuncState* fs, int list, int target);

// forbody: a for loop body: activate the control variables, FORPREP / FORLOOP (numeric) or TFORLOOP; ls
// arrives in eax, the rest on the stack.
// equiv-conv: FUN_0021e700 eax stack stack stack stack
extern "C" void FUN_0021e700(LuaVMLexState* ls, int base, int line, int nvars, int isnum) {
    LuaVMBlockCnt bl;
    int prep;
    int i;
    int endfor;
    LuaVMFuncState* fs = ls->fs;
    LuaVMBlockCnt* b;

    fs->nactvar = (unsigned char)(fs->nactvar + 3);
    for (i = 3; i != 0; i--)
        fs->f->locvars[fs->actvar[fs->nactvar - i]].startpc = fs->pc;

    FUN_0021c2e0(ls, 0x103);

    prep = FUN_00220c10(fs, (unsigned int)(isnum ? 0x1d : 0x1f), base, 0x1fffe);
    bl.breaklist = -1;
    bl.isbreakable = 0;
    bl.nactvar = fs->nactvar;
    bl.upval = 0;
    bl.previous = fs->bl;
    fs->bl = &bl;

    FUN_0021c570(ls, nvars);
    FUN_00220850(fs, nvars);
    FUN_0021e080(ls);

    b = fs->bl;
    fs->bl = b->previous;
    FUN_0021c5b0(fs->ls, b->nactvar);
    if (b->upval)
        FUN_00220bd0(fs, 0x22, b->nactvar, 0, 0);
    fs->freereg = fs->nactvar;
    FUN_00220d70(fs, b->breaklist);
    FUN_00220d70(fs, prep);

    if (isnum)
        endfor = FUN_00220c10(fs, 0x1c, base, 0x1fffe);
    else
        endfor = FUN_00220bd0(fs, 0x1e, base, 0, (unsigned int)nvars);
    FUN_00220b00(fs, line);
    if (!isnum)
        endfor = FUN_00220cd0(fs);
    FUN_00221ae0(fs, endfor, prep + 1);
}
} // namespace fn_0021e700

namespace fn_f77c2fa8 {

// 0x0021e860 FUN_0021e860 (503 B): equivalent/0x0021e860.cpp
// sym: _FUN_0021e860
// STATUS: equivalent (tools/equiv.py level 3: 2993 inputs, branch coverage 12/12)
// equiv-conv: FUN_0021c240 esi ecx edx
// equiv-conv: FUN_0021c2e0 esi eax
// equiv-conv: FUN_0021e700 eax stack stack stack stack
// fornum: for v = e1, e2 [, e3] do body: the control locals (index, limit, step, v) and their values; ls
// arrives in edi, the rest on the stack.
// equiv-conv: FUN_0021e860 edi stack stack
extern "C" void FUN_0021e860(LuaVMLexState* ls, LuaVMString* varname, int line) {
    struct {
        int base;
        LuaVMExpDesc e;
    } fr;
    LuaVMFuncState* fs0 = ls->fs;
    LuaVMFuncState* fs;
    fr.base = fs0->freereg;

    LuaVMString* name = FUN_0021b080(ls, "(for index)", 11);
    fs = ls->fs;
    if (fs->nactvar + 1 > 200)
        FUN_0021c240(fs, "local variables", 200);
    fs->actvar[fs->nactvar + 0] = (unsigned short)FUN_0021c490(ls, name);

    name = FUN_0021b080(ls, "(for limit)", 11);
    fs = ls->fs;
    if (fs->nactvar + 2 > 200)
        FUN_0021c240(fs, "local variables", 200);
    fs->actvar[fs->nactvar + 1] = (unsigned short)FUN_0021c490(ls, name);

    name = FUN_0021b080(ls, "(for step)", 10);
    fs = ls->fs;
    if (fs->nactvar + 3 > 200)
        FUN_0021c240(fs, "local variables", 200);
    fs->actvar[fs->nactvar + 2] = (unsigned short)FUN_0021c490(ls, name);

    fs = ls->fs;
    if (fs->nactvar + 4 > 200)
        FUN_0021c240(fs, "local variables", 200);
    fs->actvar[fs->nactvar + 3] = (unsigned short)FUN_0021c490(ls, varname);

    FUN_0021c2e0(ls, '=');
    FUN_0021ded0(ls, &fr.e, 0);
    FUN_00221110(ls->fs, &fr.e);
    FUN_0021c2e0(ls, ',');
    FUN_0021ded0(ls, &fr.e, 0);
    FUN_00221110(ls->fs, &fr.e);

    if (ls->t.token == ',') {
        ls->lastline = ls->linenumber;
        if (ls->lookahead.token != 0x11f) {
            ls->t.token = ls->lookahead.token;
            ls->t.seminfo = ls->lookahead.seminfo;
            ls->lookahead.token = 0x11f;
        } else {
            ls->t.token = FUN_0021bbc0(ls, &ls->t.seminfo);
        }
        FUN_0021ded0(ls, &fr.e, 0);
        FUN_00221110(ls->fs, &fr.e);
    } else {
        int k = FUN_002209e0(fs0, 1.0f);
        FUN_00220c10(fs0, 1, fs0->freereg, (unsigned int)k);
        FUN_00220850(fs0, 1);
    }
    FUN_0021e700(ls, fr.base, line, 1, 1);
}


// 0x0021ea60 FUN_0021ea60 (615 B): equivalent/0x0021ea60.cpp
// sym: _FUN_0021ea60
// STATUS: equivalent (tools/equiv.py level 3: 3007 inputs, branch coverage 17/20, incomplete)
// equiv-conv: FUN_0021c240 esi ecx edx
// equiv-conv: FUN_0021c2e0 esi eax
// equiv-conv: FUN_0021d5c0 esi edi
// equiv-conv: FUN_0021c8b0 eax ecx edx stack
// equiv-conv: FUN_0021e700 eax stack stack stack stack
// forlist: for v1, ... in explist do body: the control locals (generator, state, control, the names); ls
// arrives in ebx, indexname on the stack.
// equiv-conv: FUN_0021ea60 ebx stack
extern "C" void FUN_0021ea60(LuaVMLexState* ls, LuaVMString* indexname) {
    LuaVMExpDesc e;
    LuaVMFuncState* fs0 = ls->fs;
    LuaVMFuncState* fs;
    int base = fs0->freereg;

    LuaVMString* name = FUN_0021b080(ls, "(for generator)", 15);
    fs = ls->fs;
    if (fs->nactvar + 1 > 200)
        FUN_0021c240(fs, "local variables", 200);
    fs->actvar[fs->nactvar + 0] = (unsigned short)FUN_0021c490(ls, name);

    name = FUN_0021b080(ls, "(for state)", 11);
    fs = ls->fs;
    if (fs->nactvar + 2 > 200)
        FUN_0021c240(fs, "local variables", 200);
    fs->actvar[fs->nactvar + 1] = (unsigned short)FUN_0021c490(ls, name);

    name = FUN_0021b080(ls, "(for control)", 13);
    fs = ls->fs;
    if (fs->nactvar + 3 > 200)
        FUN_0021c240(fs, "local variables", 200);
    fs->actvar[fs->nactvar + 2] = (unsigned short)FUN_0021c490(ls, name);

    fs = ls->fs;
    if (fs->nactvar + 4 > 200)
        FUN_0021c240(fs, "local variables", 200);
    fs->actvar[fs->nactvar + 3] = (unsigned short)FUN_0021c490(ls, indexname);

    int nvars = 4;
    while (ls->t.token == 0x2c) {
        Next(ls);
        if (ls->t.token != 0x116)
            FUN_0021b060(ls, "<name> expected");
        LuaVMString* nm = ls->t.seminfo.ts;
        Next(ls);
        fs = ls->fs;
        if (fs->nactvar + nvars + 1 > 200) {
            int line = fs->f->lineDefined;
            const char* msg;
            if (line != 0)
                msg = FUN_00216320(fs->L, "function at line %d has more than %d %s", line, 200,
                                   "local variables");
            else
                msg = FUN_00216320(fs->L, "main function has more than %d %s", 200, "local variables");
            FUN_0021afd0(fs->ls, msg, 0);
        }
        fs->actvar[fs->nactvar + nvars] = (unsigned short)FUN_0021c490(ls, nm);
        nvars++;
    }

    FUN_0021c2e0(ls, 0x10b);
    int line = ls->linenumber;
    int nexps = FUN_0021d5c0(ls, &e);
    FUN_0021c8b0(ls, &e, nexps, 3);
    FUN_00220810(fs0, 3);
    FUN_0021e700(ls, base, line, nvars - 3, 0);
}


// 0x0021ecd0 FUN_0021ecd0 (267 B): equivalent/0x0021ecd0.cpp
// sym: _FUN_0021ecd0
// STATUS: equivalent (tools/equiv.py level 3: 3010 inputs, branch coverage 10/10)
// forstat: for name = ... (fornum) or for name {, name} in ... (forlist) ... end, in a loop block.
// equiv-conv: FUN_0021c3d0 esi
// equiv-conv: FUN_0021e860 edi stack stack
// equiv-conv: FUN_0021ea60 ebx stack
// equiv-conv: FUN_0021c340 eax esi edi stack
// equiv-conv: FUN_0021c5b0 eax edx
// equiv-conv: FUN_0021ecd0 eax stack
extern "C" void FUN_0021ecd0(LuaVMLexState* ls, int line) {
    LuaVMFuncState* fs = ls->fs;
    LuaVMBlockCnt bl;
    bl.breaklist = -1;
    bl.isbreakable = 1;
    bl.nactvar = fs->nactvar;
    bl.upval = 0;
    bl.previous = fs->bl;
    fs->bl = &bl;
    ls->lastline = ls->linenumber;
    if (ls->lookahead.token != 0x11f) {
        ls->t.token = ls->lookahead.token;
        ls->t.seminfo = ls->lookahead.seminfo;
        ls->lookahead.token = 0x11f;
    } else
        ls->t.token = FUN_0021bbc0(ls, &ls->t.seminfo);
    LuaVMString* varname = FUN_0021c3d0(ls);
    if (ls->t.token == 0x3d)
        FUN_0021e860(ls, varname, line);
    else if (ls->t.token == 0x2c || ls->t.token == 0x10b) // ',' or TK_IN
        FUN_0021ea60(ls, varname);
    else
        FUN_0021b060(ls, "`=' or `in' expected");
    FUN_0021c340(line, ls, 0x106, 0x108); // TK_END, TK_FOR
    LuaVMBlockCnt* b = fs->bl;
    fs->bl = b->previous;
    FUN_0021c5b0(fs->ls, b->nactvar);
    if (b->upval)
        FUN_00220bd0(fs, 0x22, b->nactvar, 0, 0); // OP_CLOSE
    fs->freereg = fs->nactvar;
    FUN_00220d70(fs, b->breaklist);
}


// 0x0021ede0 FUN_0021ede0 (144 B): equivalent/0x0021ede0.cpp
// sym: _FUN_0021ede0
// STATUS: equivalent (tools/equiv.py level 3: 3011 inputs, branch coverage 4/4)
// test_then_block: skip IF/ELSEIF, parse the condition, expect THEN, parse the block; returns the false list.
// equiv-conv: FUN_0021c2e0 esi eax
// equiv-conv: FUN_0021e080 eax
 // block
// equiv-conv: FUN_0021ede0 eax
extern "C" int FUN_0021ede0(LuaVMLexState* ls) {
    LuaVMExpDesc v;
    ls->lastline = ls->linenumber;
    if (ls->lookahead.token != 287) {
        ls->t.token = ls->lookahead.token;
        ls->t.seminfo = ls->lookahead.seminfo;
        ls->lookahead.token = 287;
    } else {
        ls->t.token = FUN_0021bbc0(ls, &ls->t.seminfo);
    }
    FUN_0021ded0(ls, &v, 0);
    if (v.k == 1) // VNIL
        v.k = 3;  // VFALSE
    FUN_002214b0(ls->fs, &v);
    FUN_00220d70(ls->fs, v.t);
    FUN_0021c2e0(ls, 0x112); // TK_THEN
    FUN_0021e080(ls);
    return v.f;
}


// 0x0021ee70 FUN_0021ee70 (233 B): equivalent/0x0021ee70.cpp
// sym: _FUN_0021ee70
// STATUS: equivalent (tools/equiv.py level 3: 3022 inputs, branch coverage 8/8)
// ifstat: if cond then block {elseif cond then block} [else block] end.
// equiv-conv: FUN_0021ede0 eax
// equiv-conv: FUN_0021e080 eax
// equiv-conv: FUN_0021c340 eax esi edi stack
// equiv-conv: FUN_0021ee70 eax stack
extern "C" void FUN_0021ee70(LuaVMLexState* ls, int line) {
    LuaVMFuncState* fs = ls->fs;
    int escapelist = -1;
    int flist = FUN_0021ede0(ls);
    while (ls->t.token == 0x105) { // TK_ELSEIF
        int j = FUN_00220cd0(fs);
        FUN_002207c0(fs, &escapelist, j);
        FUN_00220d70(fs, flist);
        flist = FUN_0021ede0(ls);
    }
    if (ls->t.token == 0x104) { // TK_ELSE
        int j = FUN_00220cd0(fs);
        FUN_002207c0(fs, &escapelist, j);
        FUN_00220d70(fs, flist);
        int token = ls->lookahead.token;
        ls->lastline = ls->linenumber;
        if (token != 0x11f) {
            LuaVMSemInfo seminfo = ls->lookahead.seminfo;
            ls->lookahead.token = 0x11f;
            ls->t.token = token;
            ls->t.seminfo = seminfo;
        } else {
            ls->t.token = FUN_0021bbc0(ls, &ls->t.seminfo);
        }
        FUN_0021e080(ls);
    } else {
        FUN_002207c0(fs, &escapelist, flist);
    }
    FUN_00220d70(fs, escapelist);
    FUN_0021c340(line, ls, 0x106, 0x10a); // TK_END, TK_IF
}


// 0x0021ef60 FUN_0021ef60 (308 B): equivalent/0x0021ef60.cpp
// sym: _FUN_0021ef60
// STATUS: equivalent (tools/equiv.py level 3: 122 inputs, branch coverage 2/2)
// localfunc: local function name body (the local is active before the body, for recursion).
// equiv-conv: FUN_0021c3d0 esi
// equiv-conv: FUN_0021c240 esi ecx edx
// equiv-conv: FUN_0021cac0 ecx eax
// equiv-conv: FUN_0021c2e0 esi eax
// equiv-conv: FUN_0021d210 eax
// equiv-conv: FUN_0021c340 eax esi edi stack
// equiv-conv: FUN_0021ef60 ebx
extern "C" void FUN_0021ef60(LuaVMLexState* ls) {
    unsigned int cookie = DAT_004d9968;
    struct {
        LuaVMExpDesc v;
        LuaVMExpDesc b;
        LuaVMFuncState newfs;
    } f;
    LuaVMFuncState* fs = ls->fs;
    LuaVMString* name = FUN_0021c3d0(ls);

    LuaVMFuncState* cur = ls->fs;
    if (cur->nactvar + 1 > 200)
        FUN_0021c240(cur, "local variables", 200);
    cur->actvar[cur->nactvar] = (unsigned short)FUN_0021c490(ls, name);

    f.v.k = 5;
    f.v.info = fs->freereg;
    f.v.t = -1;
    f.v.f = -1;
    FUN_00220850(fs, 1);

    cur = ls->fs;
    cur->nactvar++;
    cur->f->locvars[cur->actvar[cur->nactvar - 1]].startpc = cur->pc;

    int line = ls->linenumber;
    FUN_0021cac0(ls, &f.newfs);
    f.newfs.f->lineDefined = line;
    FUN_0021c2e0(ls, '(');
    FUN_0021d210(ls);
    FUN_0021c2e0(ls, ')');
    FUN_0021f640(ls);
    FUN_0021c340(line, ls, 0x106, 0x109);
    FUN_0021cb80(ls);
    FUN_0021c9b0(ls, &f.newfs, &f.b);
    FUN_00221280(fs, &f.v, &f.b);
    fs->f->locvars[fs->actvar[fs->nactvar - 1]].startpc = fs->pc;
    __security_check_cookie(cookie);
}


// 0x0021f0a0 FUN_0021f0a0 (380 B): equivalent/0x0021f0a0.cpp
// sym: _FUN_0021f0a0
// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 13/16, incomplete)
// localstat: local name {, name} [= explist1].
// equiv-conv: FUN_0021d5c0 esi edi
// equiv-conv: FUN_0021c8b0 eax ecx edx stack
// equiv-conv: FUN_0021c570 eax edx
// equiv-conv: FUN_0021f0a0 eax
extern "C" void FUN_0021f0a0(LuaVMLexState* ls) {
    int nvars = 0;
    LuaVMExpDesc e;
    for (;;) {
        if (ls->t.token != 0x116)
            FUN_0021b060(ls, "<name> expected");
        LuaVMString* name = ls->t.seminfo.ts;
        Next(ls);
        LuaVMFuncState* fs = ls->fs;
        if (fs->nactvar + nvars + 1 > 200) {
            int line = fs->f->lineDefined;
            const char* msg;
            if (line != 0)
                msg = FUN_00216320(fs->L, "function at line %d has more than %d %s", line, 200,
                                   "local variables");
            else
                msg = FUN_00216320(fs->L, "main function has more than %d %s", 200, "local variables");
            FUN_0021afd0(fs->ls, msg, 0);
        }
        fs->actvar[fs->nactvar + nvars] = (unsigned short)FUN_0021c490(ls, name);
        nvars++;
        if (ls->t.token != 0x2c)
            break;
        Next(ls);
    }
    int nexps;
    if (ls->t.token == 0x3d) {
        Next(ls);
        nexps = FUN_0021d5c0(ls, &e);
    } else {
        e.k = 0;
        nexps = 0;
    }
    FUN_0021c8b0(ls, &e, nexps, nvars);
    FUN_0021c570(ls, nvars);
}


// 0x0021f220 FUN_0021f220 (92 B): equivalent/0x0021f220.cpp
// sym: _FUN_0021f220
// STATUS: equivalent (tools/equiv.py level 3: 3017 inputs, branch coverage 6/6)
// funcname: name {. name} [: name]; returns 1 for a method (needself).
// equiv-conv: FUN_0021c3d0 esi
// equiv-conv: FUN_0021ccb0 eax ebx
// equiv-conv: FUN_0021f220 ecx eax
extern "C" int FUN_0021f220(LuaVMLexState* ls, LuaVMExpDesc* v) {
    LuaVMString* name = FUN_0021c3d0(ls);
    FUN_0021c790(ls->fs, name, v, 1);
    while (ls->t.token == 0x2e)
        FUN_0021ccb0(ls, v);
    if (ls->t.token == 0x3a) {
        FUN_0021ccb0(ls, v);
        return 1;
    }
    return 0;
}


// 0x0021f280 FUN_0021f280 (114 B): equivalent/0x0021f280.cpp
// sym: _FUN_0021f280
// STATUS: equivalent (tools/equiv.py level 3: 3010 inputs, branch coverage 2/2)
// funcstat: function funcname body (stored to the name).
// equiv-conv: FUN_0021f220 ecx eax
// equiv-conv: FUN_0021d4b0 ebx stack stack stack
// equiv-conv: FUN_0021f280 eax esi
extern "C" void FUN_0021f280(LuaVMLexState* ls, int line) {
    struct {
        LuaVMExpDesc b;
        LuaVMExpDesc v;
    } f;
    ls->lastline = ls->linenumber;
    if (ls->lookahead.token != 287) {
        ls->t.token = ls->lookahead.token;
        ls->t.seminfo = ls->lookahead.seminfo;
        ls->lookahead.token = 287;
    } else {
        ls->t.token = FUN_0021bbc0(ls, &ls->t.seminfo);
    }
    int needself = FUN_0021f220(ls, &f.v);
    FUN_0021d4b0(ls, &f.b, needself, line);
    FUN_00221280(ls->fs, &f.v, &f.b);
    FUN_00220b00(ls->fs, line);
}


// 0x0021f300 FUN_0021f300 (78 B): equivalent/0x0021f300.cpp
// sym: _FUN_0021f300
// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 2/2)
// exprstat: a call statement (no results) or an assignment.
// equiv-conv: FUN_0021d830 eax esi
// equiv-conv: FUN_0021f300 eax
extern "C" void FUN_0021f300(LuaVMLexState* ls) {
    LuaVMFuncState* fs = ls->fs;
    LuaVMLHSAssign v;
    FUN_0021d830(&v.v, ls);
    if (v.v.k == 12) { // VCALL
        FUN_00220a50(fs, &v.v, 0);
    } else {
        v.prev = 0;
        FUN_0021e170(ls, &v, 1);
    }
}


// 0x0021f350 FUN_0021f350 (231 B): equivalent/0x0021f350.cpp
// sym: _FUN_0021f350
// STATUS: equivalent (tools/equiv.py level 3: 3034 inputs, branch coverage 13/14, incomplete)
// retstat: return [explist1] (a single call becomes a tail call).
// equiv-conv: FUN_0021d5c0 esi edi
// equiv-conv: FUN_0021f350 eax
extern "C" unsigned int FUN_0021f350(LuaVMLexState* ls) {
    LuaVMFuncState* fs = ls->fs;
    ls->lastline = ls->linenumber;
    if (ls->lookahead.token != 0x11f) {
        ls->t.token = ls->lookahead.token;
        ls->t.seminfo = ls->lookahead.seminfo;
        ls->lookahead.token = 0x11f;
    } else
        ls->t.token = FUN_0021bbc0(ls, &ls->t.seminfo);
    int nret;
    unsigned int first;
    if (ls->t.token == 0x3b) {
        nret = 0;
        first = 0;
    } else {
        LuaVMExpDesc e;
        nret = FUN_0021d5c0(ls, &e);
        if (e.k == 12) { // VCALL
            FUN_00220a50(fs, &e, -1);
            if (nret == 1) // a tail call
                fs->f->code[e.info] = (fs->f->code[e.info] & 0xffffffda) | 0x1a;
            first = fs->nactvar;
            nret = -1;
        } else if (nret == 1)
            first = (unsigned int)FUN_00221190(fs, &e);
        else {
            FUN_00221110(fs, &e);
            first = fs->nactvar;
        }
    }
    return (unsigned int)FUN_00220bd0(fs, 27, first, (unsigned int)(nret + 1), 0); // OP_RETURN
}


// 0x0021f460 FUN_0021f460 (145 B): equivalent/0x0021f460.cpp
// sym: _FUN_0021f460
// STATUS: equivalent (tools/equiv.py level 3: 3016 inputs, branch coverage 10/10)
// breakstat: break (closes the upvalues of the blocks left, jumps to the enclosing loop's break list).
 // luaK_concat
// equiv-conv: FUN_0021f460 edi
extern "C" void FUN_0021f460(LuaVMLexState* ls) {
    LuaVMFuncState* fs = ls->fs;
    LuaVMBlockCnt* bl = fs->bl;
    int upval = 0;

    // luaX_next(ls)
    ls->lastline = ls->linenumber;
    if (ls->lookahead.token != 0x11f) {
        ls->t = ls->lookahead;
        ls->lookahead.token = 0x11f;
    } else {
        ls->t.token = FUN_0021bbc0(ls, &ls->t.seminfo);
    }

    while (bl != 0 && !bl->isbreakable) {
        upval |= bl->upval;
        bl = bl->previous;
    }
    if (bl == 0)
        FUN_0021b060(ls, "no loop to break");
    if (upval)
        FUN_00220bd0(fs, 0x22, bl->nactvar, 0, 0); // OP_CLOSE
    FUN_002207c0(fs, &bl->breaklist, FUN_00220cd0(fs));
}


// 0x0021f500 FUN_0021f500 (251 B): equivalent/0x0021f500.cpp
// sym: _FUN_0021f500
// STATUS: equivalent (tools/equiv.py level 3: 3028 inputs, branch coverage 14/14)
// statement: one statement; returns 1 when the statement must be the last of its block.
// equiv-conv: FUN_0021c190 esi
// equiv-conv: FUN_0021c290 esi ecx
// equiv-conv: FUN_0021c340 eax esi edi stack
// equiv-conv: FUN_0021e080 eax
// equiv-conv: FUN_0021e5b0 eax stack
// equiv-conv: FUN_0021ecd0 eax stack
// equiv-conv: FUN_0021ee70 eax stack
// equiv-conv: FUN_0021ef60 ebx
// equiv-conv: FUN_0021f0a0 eax
// equiv-conv: FUN_0021f280 eax esi
// equiv-conv: FUN_0021f300 eax
// equiv-conv: FUN_0021f350 eax
// equiv-conv: FUN_0021f460 edi
// equiv-conv: FUN_0021f500 eax
extern "C" int FUN_0021f500(LuaVMLexState* ls) {
    int line = ls->linenumber;
    switch (ls->t.token) {
    case 0x10a: // if
        FUN_0021ee70(ls, line);
        return 0;
    case 0x115: // while
        FUN_0021e300(ls, line);
        return 0;
    case 0x103: // do
        FUN_0021c190(ls);
        FUN_0021e080(ls);
        FUN_0021c340(line, ls, 0x106, 0x103);
        return 0;
    case 0x108: // for
        FUN_0021ecd0(ls, line);
        return 0;
    case 0x110: // repeat
        FUN_0021e5b0(ls, line);
        return 0;
    case 0x109: // function
        FUN_0021f280(ls, line);
        return 0;
    case 0x10c: // local
        FUN_0021c190(ls);
        if (FUN_0021c290(ls, 0x109))
            FUN_0021ef60(ls);
        else
            FUN_0021f0a0(ls);
        return 0;
    case 0x111: // return
        FUN_0021f350(ls);
        return 1;
    case 0x102: // break
        FUN_0021f460(ls);
        return 1;
    default:
        FUN_0021f300(ls);
        return 0;
    }
}

} // namespace fn_f77c2fa8

// 0x0021f640 FUN_0021f640 (160 B): equivalent/0x0021f640.cpp [wrapped: helper definitions (3 out-of-line function bodies)]
// sym: _FUN_0021f640
namespace fn_0021f640 {
// STATUS: equivalent (tools/equiv.py level 3: 2728 inputs, branch coverage 12/12)
// chunk: { stat [';'] } with a nesting-depth guard

extern "C++" __declspec(nothrow) int __cdecl FUN_0021bbc0(LuaVMLexState* ls, LuaVMSemInfo* seminfo);
extern "C++" __declspec(nothrow) void __cdecl FUN_0021afd0(LuaVMLexState* ls, const char* msg, int token);
// equiv-conv: FUN_0021f500 eax
extern "C++" __declspec(nothrow) int FUN_0021f500(LuaVMLexState* ls);

static void next(LuaVMLexState* ls) {
    ls->lastline = ls->linenumber;
    if (ls->lookahead.token != 0x11f) {
        ls->t.token = ls->lookahead.token;
        ls->t.seminfo = ls->lookahead.seminfo;
        ls->lookahead.token = 0x11f;
    } else {
        ls->t.token = FUN_0021bbc0(ls, &ls->t.seminfo);
    }
}

// TK_ELSE, TK_ELSEIF, TK_END, TK_UNTIL, TK_EOS
static bool block_follow(int token) {
    switch (token) {
    case 0x104:
    case 0x105:
    case 0x106:
    case 0x114:
    case 0x11f:
        return true;
    default:
        return false;
    }
}

extern "C" void __cdecl FUN_0021f640(LuaVMLexState* ls) {
    ls->nestlevel++;
    if (ls->nestlevel > 200)
        FUN_0021afd0(ls, "chunk has too many syntax levels", 0);

    while (!block_follow(ls->t.token)) {
        int islast = FUN_0021f500(ls);
        if (ls->t.token == ';')
            next(ls);
        ls->fs->freereg = ls->fs->nactvar;
        if (islast)
            break;
    }
    ls->nestlevel--;
}
} // namespace fn_0021f640

