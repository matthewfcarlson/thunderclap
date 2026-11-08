// STATUS: equivalent (tools/equiv.py level 3: 3011 inputs, branch coverage 4/4)
// explist1: expr { , expr } (each but the last into the next register); returns the count.
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_00221110(LuaVMFuncState* fs, LuaVMExpDesc* e);
extern "C" int __cdecl FUN_0021ded0(LuaVMLexState* ls, LuaVMExpDesc* v, unsigned int limit);
extern "C" int __cdecl FUN_0021bbc0(LuaVMLexState* ls, LuaVMSemInfo* seminfo);

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
