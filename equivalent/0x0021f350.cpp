// STATUS: equivalent (tools/equiv.py level 3: 3034 inputs, branch coverage 13/14, incomplete)
// retstat: return [explist1] (a single call becomes a tail call).
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_0021bbc0(LuaVMLexState* ls, LuaVMSemInfo* seminfo);
// equiv-conv: FUN_0021d5c0 esi edi
extern "C" int FUN_0021d5c0(LuaVMLexState* ls, LuaVMExpDesc* v);
extern "C" void __cdecl FUN_00220a50(LuaVMFuncState* fs, LuaVMExpDesc* e, int nresults);
extern "C" int __cdecl FUN_00221190(LuaVMFuncState* fs, LuaVMExpDesc* e);
extern "C" void __cdecl FUN_00221110(LuaVMFuncState* fs, LuaVMExpDesc* e);
extern "C" int __cdecl FUN_00220bd0(LuaVMFuncState* fs, unsigned int o, int a, unsigned int b,
                                    unsigned int c);
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
