// STATUS: equivalent (tools/equiv.py level 3: 3026 inputs, branch coverage 10/10)
// simpleexp: a number, string, nil, true, false, table constructor, function or primary expression.
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_002209e0(LuaVMFuncState* fs, float r);
// equiv-conv: FUN_0021c190 esi
extern "C" void FUN_0021c190(LuaVMLexState* ls);
// equiv-conv: FUN_0021c440 ecx eax esi
extern "C" void FUN_0021c440(LuaVMLexState* ls, LuaVMString* s, LuaVMExpDesc* e);
// equiv-conv: FUN_0021cf70 ecx eax
extern "C" void FUN_0021cf70(LuaVMLexState* ls, LuaVMExpDesc* t);
// equiv-conv: FUN_0021d4b0 ebx stack stack stack
extern "C" void __cdecl FUN_0021d4b0(LuaVMLexState* ls, LuaVMExpDesc* e, int needself, int line);
// equiv-conv: FUN_0021d830 eax esi
extern "C" void FUN_0021d830(LuaVMExpDesc* v, LuaVMLexState* ls);
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
