// STATUS: equivalent (tools/equiv.py level 3: 3039 inputs, branch coverage 15/16, incomplete)
// funcargs: a call's arguments: ( explist ), a table constructor or a string; f becomes the CALL (VCALL).
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_0021b060(LuaVMLexState* ls, const char* msg);
extern "C" int __cdecl FUN_0021bbc0(LuaVMLexState* ls, LuaVMSemInfo* seminfo);
// equiv-conv: FUN_0021c190 esi
extern "C" void FUN_0021c190(LuaVMLexState* ls);
// equiv-conv: FUN_0021c340 eax esi edi stack
extern "C" void FUN_0021c340(int where, LuaVMLexState* ls, int what, int who);
// equiv-conv: FUN_0021cf70 ecx eax
extern "C" void FUN_0021cf70(LuaVMLexState* ls, LuaVMExpDesc* t);
// equiv-conv: FUN_0021d5c0 esi edi
extern "C" int FUN_0021d5c0(LuaVMLexState* ls, LuaVMExpDesc* v);
extern "C" int __cdecl FUN_002209b0(LuaVMFuncState* fs, LuaVMString* s);
extern "C" void __cdecl FUN_00220a50(LuaVMFuncState* fs, LuaVMExpDesc* e, int nresults);
extern "C" int __cdecl FUN_00220bd0(LuaVMFuncState* fs, unsigned int o, int a, unsigned int b,
                                    unsigned int c);
extern "C" void __cdecl FUN_00220b00(LuaVMFuncState* fs, int line);
extern "C" void __cdecl FUN_00221110(LuaVMFuncState* fs, LuaVMExpDesc* e);

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
