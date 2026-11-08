// STATUS: equivalent (tools/equiv.py level 3: 2751 inputs, branch coverage 16/16)
// subexpr: (simpleexp | unop subexpr) { binop subexpr } while the operator's left priority exceeds limit;
// returns the first operator not handled.
#include "decls/data/lua.h"
#include "decls/data/engine/unknown.h"
// data: priority = DAT_00426e00 ({left, right} per binary operator)

extern "C" int __cdecl FUN_0021bbc0(LuaVMLexState* ls, LuaVMSemInfo* seminfo);
extern "C" void __cdecl FUN_0021afd0(LuaVMLexState* ls, const char* msg, int token);
// equiv-conv: FUN_0021db50 eax edi
extern "C" void FUN_0021db50(LuaVMLexState* ls, LuaVMExpDesc* v);
// equiv-conv: FUN_0021dd30 eax
extern "C" int FUN_0021dd30(int op);
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
