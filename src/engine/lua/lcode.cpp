// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002204e0..0x00221b30 (kind game, layer engine, confidence high)
#include "tree_prelude.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/lua.h"
#define TREE_TU_BEGIN namespace fn_f079174c {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f079174c {} using namespace fn_f079174c;
#include "engine/lua.h"

// ---- declarations shared by the functions below
namespace fn_f079174c {
extern "C" void __cdecl FUN_0021b060(LuaVMLexState* ls, const char* msg);
extern "C" void __cdecl FUN_00220650(int list, LuaVMFuncState* fs, int ttarget, int treg, int ftarget, int freg,
                                     int dtarget);
extern "C" void __cdecl FUN_002204e0(int dest, int pc, LuaVMFuncState* fs);
extern "C" LuaVMTObject* __cdecl FUN_00219ef0(LuaVMState* L, LuaVMTable* t, const LuaVMTObject* key);
extern "C" void* __cdecl FUN_0021ae40(LuaVMState* L, void* block, int* size, int size_elem, int limit,
                                      const char* errormsg);
extern "C" void __cdecl FUN_00217100(LuaVMState* L, LuaVMGCObject* o, LuaVMGCObject* v);
extern "C" int __cdecl FUN_002208e0(LuaVMFuncState* fs, LuaVMTObject* k, LuaVMTObject* v);
extern "C" int __cdecl FUN_00220b20(LuaVMFuncState* fs, LuaVMInstruction i, int line);
extern "C" void __cdecl FUN_002207c0(LuaVMFuncState* fs, int* l1, int l2);
extern "C" int __cdecl FUN_00220c10(LuaVMFuncState* fs, unsigned int o, int a, unsigned int bc);
extern "C" int __cdecl FUN_00220bd0(LuaVMFuncState* fs, unsigned int o, int a, unsigned int b, unsigned int c);
extern "C" void __cdecl FUN_00220a50(LuaVMFuncState* fs, LuaVMExpDesc* e, int nresults);
extern "C" void __cdecl FUN_00220d90(LuaVMFuncState* fs, LuaVMExpDesc* e);
extern "C" void __cdecl FUN_00220c40(LuaVMFuncState* fs, int from, int n);
extern "C" void __cdecl FUN_00220e90(LuaVMExpDesc* e, unsigned int reg, LuaVMFuncState* fs);
extern "C" int __cdecl FUN_002205a0(int list, LuaVMFuncState* fs, int cond);
extern "C" int __cdecl FUN_00220cd0(LuaVMFuncState* fs);
extern "C" int __cdecl FUN_00220fe0(LuaVMFuncState* fs, LuaVMExpDesc* e, int reg);
extern "C" void __cdecl FUN_00221110(LuaVMFuncState* fs, LuaVMExpDesc* e);
extern "C" int __cdecl FUN_00221190(LuaVMFuncState* fs, LuaVMExpDesc* e);
extern "C" int __cdecl FUN_00220a10(LuaVMFuncState* fs);
extern "C" int __cdecl FUN_00221200(LuaVMFuncState* fs, LuaVMExpDesc* e);
extern "C" unsigned int __cdecl FUN_00220d10(unsigned int a, LuaVMFuncState* fs, unsigned int op, unsigned int b,
                                             unsigned int c);
extern "C" void __cdecl FUN_00220f80(LuaVMFuncState* fs, LuaVMExpDesc* e);
extern "C" void __cdecl FUN_00220ab0(LuaVMFuncState* fs, LuaVMExpDesc* e);
extern "C" int __cdecl FUN_00221430(LuaVMFuncState* fs, LuaVMExpDesc* e, int cond);
extern "C" void __cdecl FUN_00221560(LuaVMFuncState* fs, LuaVMExpDesc* e);
extern "C" void __cdecl FUN_002214b0(LuaVMFuncState* fs, LuaVMExpDesc* e);
extern "C" void __cdecl FUN_00221860(int rkc, int rkb, int op, LuaVMExpDesc* res, LuaVMFuncState* fs);


// 0x002204e0 FUN_002204e0 (72 B): equivalent/0x002204e0.cpp
// sym: _FUN_002204e0 @bcfb5e9a0243 @wf2a3f9dc717d
// STATUS: equivalent (tools/equiv.py level 3: 2935 inputs, branch coverage 2/2)
// fixjump: point the jump at pc to dest (the sBx field), with the "control structure too long" check.
// equiv-conv: FUN_002204e0 eax ecx ebx
extern "C" void __cdecl FUN_002204e0(int dest, int pc, LuaVMFuncState* fs) {
    unsigned int length = (unsigned int)dest - (unsigned int)pc - 1;
    int signedLength = (int)length;
    unsigned int magnitude = signedLength < 0 ? 0u - length : length;
    LuaVMInstruction* jmp = &fs->f->code[pc];
    if ((int)magnitude > 0x1ffff)
        FUN_0021b060(fs->ls, "control structure too long");
    LuaVMInstruction oldValue = *jmp;
    unsigned int bits = (length + 0x1ffff) << 6;
    *jmp = oldValue ^ ((bits ^ oldValue) & 0xffffc0);
}


// 0x00220530 FUN_00220530 (11 B): matches/0x00220530.cpp
// sym: _FUN_00220530
// luaK_getlabel: mark the current pc as a jump target.
extern "C" int __cdecl FUN_00220530(LuaVMFuncState* fs) {
    return fs->lasttarget = fs->pc;
}


// 0x002205a0 FUN_002205a0 (119 B): equivalent/0x002205a0.cpp
// sym: _FUN_002205a0 @7b475e94dbe4 @w0463294e21bd
// STATUS: equivalent (tools/equiv.py level 3: 3009 inputs, branch coverage 13/14, incomplete)
// need_value: does any jump in the list need a value (its control is not a TEST with this condition)?
// equiv-conv: FUN_002205a0 ecx eax stack
extern "C" int __cdecl FUN_002205a0(int list, LuaVMFuncState* fs, int cond) {
    while (list != -1) {
        LuaVMInstruction* pi = &fs->f->code[list];
        LuaVMInstruction* control = pi;
        if (list >= 1 && (((unsigned char*)&DAT_00426ba4)[pi[-1] & 0x3f] & 0x80))
            control = pi - 1;
        LuaVMInstruction i = *control;
        if ((i & 0x3f) != 0x18 || (int)((i >> 6) & 0x1ff) != cond)
            return 1;
        int offset = (int)((*pi >> 6) & 0x3ffff) - 0x1ffff;
        if (offset == -1)
            break;
        list = list + offset + 1;
    }
    return 0;
}


// 0x00220650 FUN_00220650 (311 B): equivalent/0x00220650.cpp
// sym: _FUN_00220650 @941ab99a462b @w276d2f23258f
// STATUS: equivalent (tools/equiv.py level 3: 2964 inputs, branch coverage 22/22)
// patchlistaux: patch every jump of the list (TESTs to ttarget / ftarget with their registers, others to dtarget).
// equiv-conv: FUN_00220650 edx ebx stack stack stack stack stack
extern "C" void __cdecl FUN_00220650(int list, LuaVMFuncState* fs, int ttarget, int treg, int ftarget, int freg,
                                     int dtarget) {
    while (list != -1) {
        LuaVMInstruction* code = fs->f->code;
        LuaVMInstruction* cur = &code[list];
        int next;
        int delta = (int)((*cur >> 6) & 0x3ffff) - 0x1ffff;
        if (delta == -1)
            next = -1;
        else
            next = delta + list + 1;

        LuaVMInstruction* p = cur;
        if (list >= 1 && ((char*)&DAT_00426ba4)[code[list - 1] & 0x3f] < 0)
            p = &code[list - 1];

        LuaVMInstruction w = *p;
        int target;
        if ((w & 0x3f) != 0x18) {
            target = dtarget - list - 1;
        } else {
            unsigned int c;
            if ((w & 0x7fc0) != 0) {
                c = (unsigned int)treg;
                if (c == 0xff)
                    c = (w >> 15) & 0x1ff;
                *p = (w & 0xffffff) | (c << 24);
                target = ttarget;
            } else {
                c = (unsigned int)freg;
                if (c == 0xff)
                    c = (w >> 15) & 0x1ff;
                *p = (w & 0xffffff) | (c << 24);
                target = ftarget;
            }
            cur = &fs->f->code[list];
            target = target - list - 1;
        }
        int mag = target < 0 ? -target : target;
        if (mag > 0x1ffff)
            FUN_0021b060(fs->ls, "control structure too long");
        *cur ^= (*cur ^ (((unsigned int)(target + 0x1ffff)) << 6)) & 0xffffc0;
        list = next;
    }
}


// 0x00220790 FUN_00220790 (39 B): equivalent/0x00220790.cpp
// sym: _FUN_00220790 @d479a4a72d1d @w50c9c8651cbb
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// luaK_dischargejpc: patch the pending jumps to the current pc.
// equiv-conv: FUN_00220650 edx ebx stack stack stack stack stack
// equiv-conv: FUN_00220790 eax
extern "C" void __cdecl FUN_00220790(LuaVMFuncState* fs) {
    int pc = fs->pc;
    int jpc = fs->jpc;
    FUN_00220650(jpc, fs, pc, 0xff, pc, 0xff, pc);
    fs->jpc = -1;
}


// 0x002207c0 FUN_002207c0 (78 B): equivalent/0x002207c0.cpp
// sym: _FUN_002207c0 @54e4abe18ba4 @we5e39e96fd1f
// STATUS: equivalent (tools/equiv.py level 3: 50 inputs, branch coverage 7/8, incomplete)
// luaK_concat: append the jump list l2 to the list *l1.
// equiv-conv: FUN_002204e0 eax ecx ebx
extern "C" void __cdecl FUN_002207c0(LuaVMFuncState* fs, int* l1, int l2) {
    if (l2 == -1)
        return;
    int list = *l1;
    if (list == -1) {
        *l1 = l2;
        return;
    }
    LuaVMInstruction* code = fs->f->code;
    for (;;) {
        int offset = ((code[list] >> 6) & 0x3ffff) - 0x1ffff;
        if (offset == -1)
            break;
        list += offset + 1;
        if (list == -1)
            break;
    }
    FUN_002204e0(l2, list, fs);
    volatile int barrier = 0;
    (void)barrier;
}


// 0x00220810 FUN_00220810 (58 B): matches/0x00220810.cpp
// sym: _FUN_00220810
// luaK_checkstack: grow the prototype's maxstacksize to cover n more registers.
// data: msg = DAT_004271d4
extern "C" void __cdecl FUN_00220810(LuaVMFuncState* fs, int n) {
    int x = fs->freereg + n;
    if (x > (int)fs->f->maxstacksize) {
        if (x >= 250)
            FUN_0021b060(fs->ls, DAT_004271d4);
        fs->f->maxstacksize = (unsigned char)x;
    }
}


// 0x00220850 FUN_00220850 (68 B): matches/0x00220850.cpp
// sym: _FUN_00220850
// luaK_reserveregs: checkstack, then take n registers.
extern "C" void __cdecl FUN_00220850(LuaVMFuncState* fs, int n) {
    int sum = fs->freereg + n;
    if (sum > (int)fs->f->maxstacksize) {
        if (sum >= 0xfa)
            FUN_0021b060(fs->ls, "function or expression too complex");
        fs->f->maxstacksize = (unsigned char)sum;
    }
    fs->freereg += n;
}


// 0x002208e0 FUN_002208e0 (202 B): equivalent/0x002208e0.cpp
// sym: _FUN_002208e0 @e5832297dede @wbdde14b0c12c
// STATUS: equivalent (tools/equiv.py level 3: 2872 inputs, branch coverage 14/14)
// addk (float-number build): find or append constant v, keyed by k, in the prototype's constant table.
// fs arrives in ebx and k in ecx; v is on the stack.
// equiv-conv: FUN_0034483c
// equiv-conv: FUN_002208e0 ebx ecx stack
extern "C" int __cdecl FUN_002208e0(LuaVMFuncState* fs, LuaVMTObject* k, LuaVMTObject* v) {
    LuaVMState* L = fs->L;
    LuaVMTObject* idx = FUN_00219ef0(L, fs->h, k);
    LuaVMProto* f = fs->f;
    int oldsize = f->sizek;
    if (idx->tt == LUAVM_TNUMBER) {
        return (int)idx->value.n;
    } else {
        idx->tt = LUAVM_TNUMBER;
        idx->value.n = (float)fs->nk;
        if (fs->nk + 1 > f->sizek)
            f->k = (LuaVMTObject*)FUN_0021ae40(L, f->k, &f->sizek, (int)sizeof(LuaVMTObject), 0x3ffff,
                                               "constant table overflow");
        while (oldsize < f->sizek) {
            f->k[oldsize].tt = LUAVM_TNIL;
            oldsize++;
        }
        LuaVMTObject* slot = &f->k[fs->nk];
        LUAVM_SETOBJ(slot, v);
        if (v->tt >= LUAVM_TSTRING && (v->value.gc->marked & 3) && (f->marked & 4))
            FUN_00217100(L, (LuaVMGCObject*)f, v->value.gc);
        return fs->nk++;
    }
}


// 0x002209b0 FUN_002209b0 (42 B): equivalent/0x002209b0.cpp
// sym: _FUN_002209b0 @383080443d06 @waac8ce243925
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// luaK_stringK: the constant index of string s.
// equiv-conv: FUN_002208e0 ebx ecx stack
extern "C" int __cdecl FUN_002209b0(LuaVMFuncState* fs, LuaVMString* s) {
    LuaVMTObject o;
    o.tt = LUAVM_TSTRING;
    o.value.gc = (LuaVMGCObject*)s;
    return FUN_002208e0(fs, &o, &o);
}


// 0x002209e0 FUN_002209e0 (42 B): equivalent/0x002209e0.cpp
// sym: _FUN_002209e0 @e72f0c79ae9b @w3452b543c8c1
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// luaK_numberK: the constant index of number r.
// equiv-conv: FUN_002208e0 ebx ecx stack
extern "C" int __cdecl FUN_002209e0(LuaVMFuncState* fs, float r) {
    LuaVMTObject o;
    o.tt = LUAVM_TNUMBER;
    o.value.n = r;
    return FUN_002208e0(fs, &o, &o);
}


// 0x00220a10 FUN_00220a10 (51 B): equivalent/0x00220a10.cpp
// sym: _FUN_00220a10 @474f8220e044 @w391006bb3619
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// nilK: the constant index of nil (keyed by the constant table itself).
// equiv-conv: FUN_002208e0 ebx ecx stack
// equiv-conv: FUN_00220a10 eax
extern "C" int __cdecl FUN_00220a10(LuaVMFuncState* fs) {
    LuaVMTObject o[2];
    o[0].tt = LUAVM_TTABLE;
    o[0].value.gc = (LuaVMGCObject*)fs->h;
    o[1].tt = LUAVM_TNIL;
    return FUN_002208e0(fs, &o[0], &o[1]);
}


// 0x00220a50 FUN_00220a50 (83 B): equivalent/0x00220a50.cpp
// sym: _FUN_00220a50 @1de801280018 @we8b751a8c274
// STATUS: equivalent (tools/equiv.py level 3: 3007 inputs, branch coverage 4/4)
// luaK_setcallreturns: set a call's result count (C = nresults + 1); one result makes it a VNONRELOC in A.
extern "C" void __cdecl FUN_00220a50(LuaVMFuncState* fs, LuaVMExpDesc* e, int nresults) {
    if ((unsigned int)e->k != 12)
        return;
    LuaVMInstruction& word = fs->f->code[e->info];
    word ^= (((nresults + 1) << 6) ^ word) & 0x7fc0;
    if (nresults == 1) {
        e->k = 11;
        e->info = ((unsigned char*)&fs->f->code[e->info])[3];
    }
}


// 0x00220ab0 FUN_00220ab0 (67 B): equivalent/0x00220ab0.cpp
// sym: _FUN_00220ab0 @ded4c546c015 @w4f2b0110da6b
// STATUS: equivalent (tools/equiv.py level 3: 2722 inputs, branch coverage 4/4)
// invertjump: flip the condition (A) of the jump's control instruction.
// equiv-conv: FUN_00220ab0 ecx eax
extern "C" void __cdecl FUN_00220ab0(LuaVMFuncState* fs, LuaVMExpDesc* e) {
    LuaVMInstruction* word = fs->f->code + e->info;
    if (e->info > 0 && ((signed char*)&DAT_00426ba4)[word[-1] & 63] < 0)
        --word;
    LuaVMInstruction value = *word;
    *word = (value & 0x00ffffff) | ((value & 0xff000000) == 0 ? 0x01000000 : 0);
}


// 0x00220b00 FUN_00220b00 (21 B): matches/0x00220b00.cpp
// sym: _FUN_00220b00
// luaK_fixline: the line of the last instruction.
extern "C" void __cdecl FUN_00220b00(LuaVMFuncState* fs, int line) {
    fs->f->lineinfo[fs->pc - 1] = line;
}


// 0x00220b20 FUN_00220b20 (171 B): equivalent/0x00220b20.cpp
// sym: _FUN_00220b20 @05af1b487628 @w043b6ab3aaa8
// STATUS: equivalent (tools/equiv.py level 3: 2760 inputs, branch coverage 4/4)
// luaK_code: discharge the pending jumps, then append instruction i (and its line).
// equiv-conv: FUN_00220650 edx ebx stack stack stack stack stack
extern "C" int __cdecl FUN_00220b20(LuaVMFuncState* fs, LuaVMInstruction i, int line) {
    LuaVMProto* f = fs->f;
    int pc = fs->pc;
    FUN_00220650(fs->jpc, fs, pc, 255, pc, 255, pc);
    fs->jpc = -1;
    if (fs->pc + 1 > f->sizecode)
        f->code = (LuaVMInstruction*)FUN_0021ae40(fs->L, f->code, &f->sizecode, (int)sizeof(LuaVMInstruction),
                                                  0x7ffffffd, "code size overflow");
    f->code[fs->pc] = i;
    if (fs->pc + 1 > f->sizelineinfo)
        f->lineinfo = (int*)FUN_0021ae40(fs->L, f->lineinfo, &f->sizelineinfo, (int)sizeof(int), 0x7ffffffd,
                                         "code size overflow");
    f->lineinfo[fs->pc] = line;
    int result = fs->pc;
    fs->pc = result + 1;
    return result;
}


// 0x00220bd0 FUN_00220bd0 (53 B): matches/0x00220bd0.cpp
// sym: _FUN_00220bd0
// luaK_codeABC.
extern "C" int __cdecl FUN_00220bd0(LuaVMFuncState* fs, unsigned int o, int a, unsigned int b, unsigned int c) {
    return FUN_00220b20(fs, ((a << 9 | b) << 9 | c) << 6 | o, fs->ls->lastline);
}


// 0x00220c10 FUN_00220c10 (44 B): matches/0x00220c10.cpp
// sym: _FUN_00220c10
// luaK_codeABx.
extern "C" int __cdecl FUN_00220c10(LuaVMFuncState* fs, unsigned int o, int a, unsigned int bc) {
    return FUN_00220b20(fs, (a << 18 | bc) << 6 | o, fs->ls->lastline);
}


// 0x00220c40 FUN_00220c40 (143 B): matches/0x00220c40.cpp
// sym: _FUN_00220c40
// luaK_nil: merge consecutive OP_LOADNIL instructions.
extern "C" void __cdecl FUN_00220c40(LuaVMFuncState* fs, int from, int n) {
    if (fs->pc > fs->lasttarget) {
        LuaVMInstruction* previous = &fs->f->code[fs->pc - 1];
        LuaVMInstruction ins = *previous;
        if ((ins & 0x3f) == 3) {  // OP_LOADNIL
            int pfrom = ins >> 24;
            int pto = (ins >> 15) & 0x1ff;
            if (pfrom <= from && from <= pto + 1) {
                if (from + n - 1 > pto)
                    *previous = (ins & ~0xff8000u) | (((from + n - 1) << 15) & 0xff8000u);
                return;
            }
        }
    }
    FUN_00220b20(fs, (((from + n - 1) | (from << 9)) << 15) | 3, fs->ls->lastline);
}


// 0x00220cd0 FUN_00220cd0 (60 B): matches/0x00220cd0.cpp
// sym: _FUN_00220cd0
// luaK_jump: an unconditional jump, chained with the pending jumps.
extern "C" int __cdecl FUN_00220cd0(LuaVMFuncState* fs) {
    int old = fs->jpc;
    fs->jpc = -1;
    int result = FUN_00220b20(fs, 0x7fff94, fs->ls->lastline);
    FUN_002207c0(fs, &result, old);
    return result;
}


// 0x00220d10 FUN_00220d10 (93 B): equivalent/0x00220d10.cpp
// sym: _FUN_00220d10 @7b5196f8dd9e @w692646d7d77a
// STATUS: equivalent (tools/equiv.py level 3: 3004 inputs, branch coverage 0/0)
// condjump: emit op A B C, then a jump; returns the jump.
// equiv-conv: FUN_00220d10 eax esi stack stack stack
extern "C" unsigned int __cdecl FUN_00220d10(unsigned int a, LuaVMFuncState* fs, unsigned int op, unsigned int b,
                                             unsigned int c) {
    unsigned int code = ((((a << 9) | b) << 9 | c) << 6) | op;
    FUN_00220b20(fs, code, fs->ls->lastline);
    int previous = fs->jpc;
    fs->jpc = -1;
    unsigned int result = FUN_00220b20(fs, 0x7fff94, fs->ls->lastline);
    b = result;
    FUN_002207c0(fs, (int*)&b, previous);
    return b;
}


// 0x00220d70 FUN_00220d70 (29 B): matches/0x00220d70.cpp
// sym: _FUN_00220d70
// luaK_patchtohere: getlabel, then add the list to the pending jumps.
extern "C" void __cdecl FUN_00220d70(LuaVMFuncState* fs, int list) {
    fs->lasttarget = fs->pc;
    FUN_002207c0(fs, &fs->jpc, list);
}


// 0x00220d90 FUN_00220d90 (175 B): equivalent/0x00220d90.cpp
// sym: _FUN_00220d90 @e5364d29e6f4 @w3ae254844a1c
// STATUS: equivalent (tools/equiv.py level 3: 3007 inputs, branch coverage 18/18)
// luaK_dischargevars: turn a variable expression (local, upvalue, global, indexed, call) into a value.
extern "C" void __cdecl FUN_00220d90(LuaVMFuncState* fs, LuaVMExpDesc* e) {
    switch (e->k) {
    case 5:
        e->k = 11;
        break;
    case 6:
        e->info = FUN_00220bd0(fs, 4, 0, (unsigned int)e->info, 0);
        e->k = 10;
        break;
    case 7:
        e->info = FUN_00220c10(fs, 5, 0, (unsigned int)e->info);
        e->k = 10;
        break;
    case 8: {
        int limit = fs->nactvar;
        if (e->aux >= limit && e->aux < 250)
            --fs->freereg;
        if (e->info >= limit && e->info < 250)
            --fs->freereg;
        e->info = FUN_00220bd0(fs, 6, 0, (unsigned int)e->info, (unsigned int)e->aux);
        e->k = 10;
        break;
    }
    case 12:
        FUN_00220a50(fs, e, 1);
        break;
    }
}


// 0x00220e90 FUN_00220e90 (189 B): equivalent/0x00220e90.cpp
// sym: _FUN_00220e90 @e30d49c4890a @w18fb112d313e
// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 12/12)
// discharge2reg: put the expression's value into register reg (VNONRELOC).
// equiv-conv: FUN_00220e90 ebx esi edi
extern "C" void __cdecl FUN_00220e90(LuaVMExpDesc* e, unsigned int reg, LuaVMFuncState* fs) {
    FUN_00220d90(fs, e);
    switch ((unsigned int)e->k) {
    case 1:
        FUN_00220c40(fs, (int)reg, 1);
        break;
    case 2:
    case 3:
        FUN_00220bd0(fs, 2, (int)reg, (unsigned int)((unsigned int)e->k == 2), 0);
        break;
    case 4:
        FUN_00220c10(fs, 1, (int)reg, (unsigned int)e->info);
        break;
    case 10: {
        LuaVMInstruction& word = fs->f->code[e->info];
        word = (word & 0x00ffffffu) | (reg << 24);
        break;
    }
    case 11:
        if (reg != (unsigned int)e->info)
            FUN_00220bd0(fs, 0, (int)reg, (unsigned int)e->info, 0);
        break;
    default:
        return;
    }
    e->info = (int)reg;
    e->k = 11;
}


// 0x00220f80 FUN_00220f80 (82 B): equivalent/0x00220f80.cpp
// sym: _FUN_00220f80 @68a951a3756e @w658d22b12724
// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 6/6)
// discharge2anyreg: unless already in a register, reserve one and discharge the expression into it.
// equiv-conv: FUN_00220e90 ebx esi edi
// equiv-conv: FUN_00220f80 eax stack
extern "C" void __cdecl FUN_00220f80(LuaVMFuncState* fs, LuaVMExpDesc* e) {
    if (e->k != 11) {
        int next = fs->freereg + 1;
        if (next > fs->f->maxstacksize) {
            if (next >= 250)
                FUN_0021b060(fs->ls, "function or expression too complex");
            fs->f->maxstacksize = (unsigned char)next;
        }
        fs->freereg = fs->freereg + 1;
        FUN_00220e90(e, (unsigned int)(fs->freereg - 1), fs);
    }
}


// 0x00220fe0 FUN_00220fe0 (297 B): equivalent/0x00220fe0.cpp
// sym: _FUN_00220fe0 @96e5a67de8b7 @w721d01a9cdac
// STATUS: equivalent (tools/equiv.py level 3: 3007 inputs, branch coverage 10/10)
// luaK_exp2reg: put the expression (with its true / false jump lists) into register reg.
// equiv-conv: FUN_00220e90 ebx esi edi
// equiv-conv: FUN_002205a0 ecx eax stack
// equiv-conv: FUN_00220650 edx ebx stack stack stack stack stack
// equiv-conv: FUN_00220fe0 eax stack stack
extern "C" int __cdecl FUN_00220fe0(LuaVMFuncState* fs, LuaVMExpDesc* e, int reg) {
    FUN_00220e90(e, (unsigned int)reg, fs);
    if (e->k == 9)
        FUN_002207c0(fs, &e->t, e->info);
    if (e->t != e->f) {
        int f = e->f;
        int a = -1, b = -1;
        if (FUN_002205a0(e->t, fs, 1) || FUN_002205a0(f, fs, 0)) {
            int link = -1;
            if (e->k != 9)
                link = FUN_00220cd0(fs);
            fs->lasttarget = fs->pc;
            a = FUN_00220b20(fs, (LuaVMInstruction)((reg << 24) | 0x42), fs->ls->lastline);
            fs->lasttarget = fs->pc;
            b = FUN_00220b20(fs, (LuaVMInstruction)((reg << 24) | 0x8002), fs->ls->lastline);
            fs->lasttarget = fs->pc;
            FUN_002207c0(fs, &fs->jpc, link);
        }
        int position = fs->pc;
        fs->lasttarget = position;
        FUN_00220650(e->f, fs, a, 255, position, reg, a);
        FUN_00220650(e->t, fs, position, reg, b, 255, b);
    }
    e->t = -1;
    e->f = -1;
    e->info = reg;
    e->k = 11;
    return -1;
}


// 0x00221110 FUN_00221110 (119 B): equivalent/0x00221110.cpp
// sym: _FUN_00221110 @1c8d933f4faa @w1223980b79b1
// STATUS: equivalent (tools/equiv.py level 3: 3012 inputs, branch coverage 10/10)
// luaK_exp2nextreg: put the expression into the next free register.
// equiv-conv: FUN_00220fe0 eax stack stack
extern "C" void __cdecl FUN_00221110(LuaVMFuncState* fs, LuaVMExpDesc* e) {
    FUN_00220d90(fs, e);
    if (e->k == 0xb && e->info >= fs->nactvar && e->info < 0xfa)
        fs->freereg--;
    int newstack = fs->freereg + 1;
    if (newstack > fs->f->maxstacksize) {
        if (newstack >= 0xfa)
            FUN_0021b060(fs->ls, "function or expression too complex");
        fs->f->maxstacksize = (unsigned char)newstack;
    }
    fs->freereg = fs->freereg + 1;
    FUN_00220fe0(fs, e, fs->freereg - 1);
}


// 0x00221190 FUN_00221190 (80 B): equivalent/0x00221190.cpp
// sym: _FUN_00221190 @26c81eccf5c3 @w01f8697e3d07
// STATUS: equivalent (tools/equiv.py level 3: 3010 inputs, branch coverage 6/6)
// luaK_exp2anyreg: put the expression into some register; returns it.
// equiv-conv: FUN_00220fe0 eax stack stack
extern "C" int __cdecl FUN_00221190(LuaVMFuncState* fs, LuaVMExpDesc* e) {
    FUN_00220d90(fs, e);
    if (e->k == 11) {
        if (e->t == e->f)
            return e->info;
        if (e->info >= fs->nactvar) {
            FUN_00220fe0(fs, e, e->info);
            return e->info;
        }
    }
    FUN_00221110(fs, e);
    return e->info;
}


// 0x002211e0 FUN_002211e0 (26 B): matches/0x002211e0.cpp
// sym: _FUN_002211e0
// luaK_exp2val: an expression with jumps goes to a register, others are only discharged.
extern "C" void __cdecl FUN_002211e0(LuaVMFuncState* fs, LuaVMExpDesc* e) {
    if (e->t != e->f)
        FUN_00221190(fs, e);
    else
        FUN_00220d90(fs, e);
}


// 0x00221200 FUN_00221200 (114 B): equivalent/0x00221200.cpp
// sym: _FUN_00221200 @2a62eb8f430e @w494507a6fb87
// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 10/10)
// luaK_exp2RK: a register or a constant index (+ 250) for the expression.
// equiv-conv: FUN_00220a10 eax
extern "C" int __cdecl FUN_00221200(LuaVMFuncState* fs, LuaVMExpDesc* e) {
    if (e->t == e->f)
        FUN_00220d90(fs, e);
    else
        FUN_00221190(fs, e);
    switch (e->k) {
    case 1:
        if (fs->nk + 250 <= 511) {
            e->info = FUN_00220a10(fs);
            e->k = 4;
            return e->info + 250;
        }
        break;
    case 4:
        if (e->info + 250 <= 511)
            return e->info + 250;
        break;
    }
    return FUN_00221190(fs, e);
}


// 0x00221280 FUN_00221280 (204 B): equivalent/0x00221280.cpp
// sym: _FUN_00221280 @e4a6ab294bbe @w6f4c1b1ce991
// STATUS: equivalent (tools/equiv.py level 3: 3032 inputs, branch coverage 18/18)
// luaK_storevar: store expression ex into variable var (local, upvalue, global, indexed).
// equiv-conv: FUN_00220fe0 eax stack stack
extern "C" void __cdecl FUN_00221280(LuaVMFuncState* fs, LuaVMExpDesc* var, LuaVMExpDesc* ex) {
    unsigned int result;
    switch (var->k) {
    case 5:
        if (ex->k == 11 && ex->info >= fs->nactvar && ex->info < 250)
            --fs->freereg;
        FUN_00220fe0(fs, ex, var->info);
        return;
    case 6:
        result = (unsigned int)FUN_00221190(fs, ex);
        FUN_00220bd0(fs, 8, (int)result, (unsigned int)var->info, 0);
        break;
    case 7:
        result = (unsigned int)FUN_00221190(fs, ex);
        FUN_00220b20(fs, ((result << 18) | (unsigned int)var->info) << 6 | 7, fs->ls->lastline);
        break;
    case 8:
        result = (unsigned int)FUN_00221200(fs, ex);
        FUN_00220bd0(fs, 9, var->info, (unsigned int)var->aux, result);
        break;
    }
    if (ex->k == 11 && ex->info >= fs->nactvar && ex->info < 250)
        --fs->freereg;
}


// 0x00221360 FUN_00221360 (197 B): matches/0x00221360.cpp
// sym: _FUN_00221360
// luaK_self: e:key(...) puts the function and the object in two consecutive registers (OP_SELF).
extern "C" void __cdecl FUN_00221360(LuaVMFuncState* fs, LuaVMExpDesc* e, LuaVMExpDesc* key) {
    FUN_00221190(fs, e);
    if (e->k == 11 && e->info >= fs->nactvar && e->info < 250)
        --fs->freereg;
    int func = fs->freereg;
    int required = func + 2;
    if (required > fs->f->maxstacksize) {
        if (required >= 250)
            FUN_0021b060(fs->ls, "function or expression too complex");
        fs->f->maxstacksize = (unsigned char)required;
    }
    fs->freereg += 2;
    unsigned int result = (unsigned int)FUN_00221200(fs, key);
    int line = fs->ls->lastline;
    LuaVMInstruction instruction = ((((unsigned int)func << 9) | (unsigned int)e->info) << 9 | result) << 6 | 11;
    FUN_00220b20(fs, instruction, line);
    if (key->k == 11 && key->info >= fs->nactvar && key->info < 250)
        --fs->freereg;
    e->info = func;
    e->k = 11;
}


// 0x00221430 FUN_00221430 (127 B): equivalent/0x00221430.cpp
// sym: _FUN_00221430 @0125623dfeda @w8d52d5525ff0
// STATUS: equivalent (tools/equiv.py level 3: 3009 inputs, branch coverage 12/12)
// jumponcond: emit a TEST on the expression and a jump; folds a preceding NOT, otherwise discharges it first.
// equiv-conv: FUN_00220d10 eax esi stack stack stack
// equiv-conv: FUN_00220f80 eax stack
// equiv-conv: FUN_00221430 eax edi ebx
extern "C" int __cdecl FUN_00221430(LuaVMFuncState* fs, LuaVMExpDesc* e, int cond) {
    if (e->k == 10) {
        LuaVMInstruction i = fs->f->code[e->info];
        if ((i & 0x3f) == 0x12) {
            fs->pc--;
            return (int)FUN_00220d10(0xff, fs, 0x18, (i >> 15) & 0x1ff, (unsigned int)(cond == 0));
        }
    }
    FUN_00220f80(fs, e);
    if (e->k == 11) {
        if (e->info >= fs->nactvar && e->info < 0xfa)
            fs->freereg--;
    }
    return (int)FUN_00220d10(0xff, fs, 0x18, (unsigned int)e->info, (unsigned int)cond);
}


// 0x002214b0 FUN_002214b0 (140 B): equivalent/0x002214b0.cpp
// sym: _FUN_002214b0 @336b7b3906a9 @w6f6792d79672
// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 10/10)
// luaK_goiftrue: jump when the expression is false (added to its false list); the true list falls through.
// equiv-conv: FUN_00220ab0 ecx eax
// equiv-conv: FUN_00221430 eax edi ebx
extern "C" void __cdecl FUN_002214b0(LuaVMFuncState* fs, LuaVMExpDesc* e) {
    FUN_00220d90(fs, e);
    int value;
    switch (e->k) {
    case 2:
    case 4:
        value = -1;
        break;
    case 3:
        value = FUN_00220cd0(fs);
        break;
    case 9:
        FUN_00220ab0(fs, e);
        value = e->info;
        break;
    default:
        value = FUN_00221430(fs, e, 0);
        break;
    }
    FUN_002207c0(fs, &e->f, value);
}


// 0x00221560 FUN_00221560 (139 B): equivalent/0x00221560.cpp
// sym: _FUN_00221560 @064fb845cfdf @w2ab35aaf2613
// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 6/6)
// luaK_goiffalse: jump when the expression is true (added to its true list).
// equiv-conv: FUN_00221430 eax edi ebx
extern "C" void __cdecl FUN_00221560(LuaVMFuncState* fs, LuaVMExpDesc* e) {
    FUN_00220d90(fs, e);
    int value;
    switch (e->k) {
    case 1:
    case 3:
        value = -1;
        break;
    case 2:
        value = FUN_00220cd0(fs);
        break;
    case 9:
        value = e->info;
        break;
    default:
        value = FUN_00221430(fs, e, 1);
        break;
    }
    FUN_002207c0(fs, &e->t, value);
}


// 0x00221610 FUN_00221610 (176 B): equivalent/0x00221610.cpp
// sym: _FUN_00221610 @81b6804114fb @we1297b2163ea
// STATUS: equivalent (tools/equiv.py level 3: 3011 inputs, branch coverage 12/13, incomplete)
// codenot: the logical negation of the expression (constants fold, jumps invert, values get OP_NOT); swaps t / f.
// equiv-conv: FUN_00220ab0 ecx eax
// equiv-conv: FUN_00220f80 eax stack
// equiv-conv: FUN_00221610 esi edi
extern "C" int __cdecl FUN_00221610(LuaVMExpDesc* e, LuaVMFuncState* fs) {
    FUN_00220d90(fs, e);
    switch (e->k) {
    case 1:
    case 3:
        e->k = 2;
        break;
    case 2:
    case 4:
        e->k = 3;
        break;
    case 9:
        FUN_00220ab0(fs, e);
        break;
    case 10:
    case 11:
        FUN_00220f80(fs, e);
        if (e->k == 11 && e->info >= fs->nactvar && e->info < 250)
            --fs->freereg;
        e->info = FUN_00220bd0(fs, 18, 0, (unsigned int)e->info, 0);
        e->k = 10;
        break;
    }
    int r = e->f;
    e->f = e->t;
    e->t = r;
    return r;
}


// 0x002216e0 FUN_002216e0 (32 B): matches/0x002216e0.cpp
// sym: _FUN_002216e0
// luaK_indexed: t[k] (VINDEXED, the key as an RK operand).
extern "C" void __cdecl FUN_002216e0(LuaVMFuncState* fs, LuaVMExpDesc* t, LuaVMExpDesc* k) {
    t->aux = FUN_00221200(fs, k);
    t->k = 8;
}

} // namespace fn_f079174c

// 0x00221700 FUN_00221700 (178 B): equivalent/0x00221700.cpp [wrapped: code differs from its standalone build]
// sym: _FUN_00221700 @58903e9d23e9 @wcc8433eafc1a
namespace fn_00221700 {
// STATUS: equivalent (tools/equiv.py level 3: 3037 inputs, branch coverage 14/14)
// luaK_prefix: unary minus (a numeric constant folds) or not.

extern "C++" __declspec(nothrow) int __cdecl FUN_00221190(LuaVMFuncState* fs, LuaVMExpDesc* e);
extern "C++" __declspec(nothrow) void __cdecl FUN_00220d90(LuaVMFuncState* fs, LuaVMExpDesc* e);
extern "C++" __declspec(nothrow) int __cdecl FUN_002209e0(LuaVMFuncState* fs, float r);
extern "C++" __declspec(nothrow) int __cdecl FUN_00220b20(LuaVMFuncState* fs, LuaVMInstruction i, int line);
// equiv-conv: FUN_00221610 esi edi
extern "C++" __declspec(nothrow) int __cdecl FUN_00221610(LuaVMExpDesc* e, LuaVMFuncState* fs);

extern "C" void __cdecl FUN_00221700(LuaVMFuncState* fs, int op, LuaVMExpDesc* e) {
    if (op) {
        FUN_00221610(e, fs);
        return;
    }
    if (e->t != e->f)
        FUN_00221190(fs, e);
    else
        FUN_00220d90(fs, e);
    if (e->k == 4) {
        LuaVMTObject* constant = &fs->f->k[e->info];
        if (constant->tt == LUAVM_TNUMBER) {
            e->info = FUN_002209e0(fs, -constant->value.n);
            return;
        }
    }
    FUN_00221190(fs, e);
    if (e->k == 11 && e->info >= fs->nactvar && e->info < 250)
        --fs->freereg;
    e->info = FUN_00220b20(fs, (LuaVMInstruction)(((unsigned int)e->info << 15) | 17), fs->ls->lastline);
    e->k = 10;
}
} // namespace fn_00221700

namespace fn_f079174c {

// 0x002217c0 FUN_002217c0 (155 B): equivalent/0x002217c0.cpp
// sym: _FUN_002217c0 @b3c6682c129d @w35cfc3599d4c
// STATUS: equivalent (tools/equiv.py level 3: 3017 inputs, branch coverage 6/6)
// luaK_infix: prepare the first operand of a binary operator (and / or / concat / RK operand).
extern "C" void __cdecl FUN_002217c0(LuaVMFuncState* fs, int op, LuaVMExpDesc* v) {
    switch (op) {
    case 5:
        FUN_00221110(fs, v);
        break;
    case 12:
        FUN_002214b0(fs, v);
        fs->lasttarget = fs->pc;
        FUN_002207c0(fs, &fs->jpc, v->t);
        v->t = -1;
        break;
    case 13:
        FUN_00221560(fs, v);
        fs->lasttarget = fs->pc;
        FUN_002207c0(fs, &fs->jpc, v->f);
        v->f = -1;
        break;
    default:
        FUN_00221200(fs, v);
        break;
    }
}


// 0x00221860 FUN_00221860 (112 B): equivalent/0x00221860.cpp
// sym: _FUN_00221860 @edc40a0bc24c @w98e222902394
// STATUS: equivalent (tools/equiv.py level 3: 3004 inputs, branch coverage 6/6)
// codebinop: an arithmetic instruction (B = rkb, C = rkc), or a comparison and its jump (operands swapped for > / >=).
// equiv-conv: FUN_00220d10 eax esi stack stack stack
// equiv-conv: FUN_00221860 eax ecx edx edi stack
extern "C" void __cdecl FUN_00221860(int rkc, int rkb, int op, LuaVMExpDesc* res, LuaVMFuncState* fs) {
    if (op <= 4) {
        res->info = FUN_00220b20(fs, (LuaVMInstruction)((((rkb << 9) | rkc) << 6) | (op + 12)), fs->ls->lastline);
        res->k = 10;
        return;
    }
    int cond = 1;
    if (op >= 10) {
        int tmp = rkb;
        rkb = rkc;
        rkc = tmp;
    } else if (op == 6) {
        cond = 0;
    }
    // the comparison opcodes of the operators ne, eq, lt, le, gt, ge (6..11)
    res->info = (int)FUN_00220d10((unsigned int)cond, fs, DAT_0042720c[op - 6],
                                  (unsigned int)rkb, (unsigned int)rkc);
    res->k = 9;
}


// 0x002218d0 FUN_002218d0 (515 B): equivalent/0x002218d0.cpp
// sym: _FUN_002218d0 @2feee3c1766a @wec9b0084b035
// STATUS: equivalent (tools/equiv.py level 3: 3095 inputs, branch coverage 41/42, incomplete)
// luaK_posfix: finish a binary operator (and / or merge jump lists, concat merges OP_CONCATs, the rest codebinop).
// equiv-conv: FUN_00221860 eax ecx edx edi stack
extern "C" void __cdecl FUN_002218d0(LuaVMFuncState* fs, int op, LuaVMExpDesc* e1, LuaVMExpDesc* e2) {
    if (op == 5) {
        if (e2->t != e2->f)
            FUN_00221190(fs, e2);
        else
            FUN_00220d90(fs, e2);
        if (e2->k == 0xa) {
            LuaVMProto* f = fs->f;
            if ((f->code[e2->info] & 0x3f) == 0x13) {
                if (e1->k == 0xb) {
                    if (e1->info >= (int)fs->nactvar && e1->info < 0xfa)
                        fs->freereg--;
                }
                LuaVMInstruction* code = f->code;
                LuaVMInstruction old = code[e2->info];
                code[e2->info] = old ^ (((unsigned int)e1->info << 15 ^ old) & 0xff8000);
                e1->k = e2->k;
                e1->info = e2->info;
                return;
            }
        }
        FUN_00221110(fs, e2);
        if (e2->k == 0xb) {
            if (e2->info >= (int)fs->nactvar && e2->info < 0xfa)
                fs->freereg--;
        }
        if (e1->k == 0xb) {
            if (e1->info >= (int)fs->nactvar && e1->info < 0xfa)
                fs->freereg--;
        }
        e1->info = FUN_00220b20(fs, (LuaVMInstruction)(((e1->info << 9 | e2->info) << 6) | 0x13), fs->ls->lastline);
        e1->k = 0xa;
        return;
    }
    if (op == 12) {
        FUN_00220d90(fs, e2);
        FUN_002207c0(fs, &e1->f, e2->f);
        e1->k = e2->k;
        e1->info = e2->info;
        e1->aux = e2->aux;
        e1->t = e2->t;
        return;
    }
    if (op == 13) {
        FUN_00220d90(fs, e2);
        FUN_002207c0(fs, &e1->t, e2->t);
        e1->k = e2->k;
        e1->info = e2->info;
        e1->aux = e2->aux;
        e1->f = e2->f;
        return;
    }
    int rkb = FUN_00221200(fs, e1);
    int rkc = FUN_00221200(fs, e2);
    if (e2->k == 0xb) {
        if (e2->info >= (int)fs->nactvar && e2->info < 0xfa)
            fs->freereg--;
    }
    if (e1->k == 0xb) {
        if (e1->info >= (int)fs->nactvar && e1->info < 0xfa)
            fs->freereg--;
    }
    FUN_00221860(rkc, rkb, op, e1, fs);
}


// 0x00221ae0 FUN_00221ae0 (66 B): equivalent/0x00221ae0.cpp
// sym: _FUN_00221ae0 @f228a32a46ee @wd72700e9ec3c
// STATUS: equivalent (tools/equiv.py level 3: 3003 inputs, branch coverage 2/2)
// luaK_patchlist: patch the list to target (to the pending jumps when target is the current pc).
// equiv-conv: FUN_00220650 edx ebx stack stack stack stack stack
extern "C" void __cdecl FUN_00221ae0(LuaVMFuncState* fs, int list, int target) {
    if (target == fs->pc) {
        fs->lasttarget = fs->pc;
        FUN_002207c0(fs, &fs->jpc, list);
    } else {
        FUN_00220650(list, fs, target, 0xff, target, 0xff, target);
    }
}

} // namespace fn_f079174c
