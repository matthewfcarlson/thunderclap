// STATUS: equivalent (tools/equiv.py level 3: 3028 inputs, branch coverage 14/14)
// statement: one statement; returns 1 when the statement must be the last of its block.
#include "decls/data/lua.h"

// equiv-conv: FUN_0021c190 esi
extern "C" void FUN_0021c190(LuaVMLexState* ls);
// equiv-conv: FUN_0021c290 esi ecx
extern "C" int FUN_0021c290(LuaVMLexState* ls, int c);
// equiv-conv: FUN_0021c340 eax esi edi stack
extern "C" void FUN_0021c340(int where, LuaVMLexState* ls, int what, int who);
// equiv-conv: FUN_0021e080 eax
extern "C" void FUN_0021e080(LuaVMLexState* ls);
extern "C" void __cdecl FUN_0021e300(LuaVMLexState* ls, int line);
// equiv-conv: FUN_0021e5b0 eax stack
extern "C" void FUN_0021e5b0(LuaVMLexState* ls, int line);
// equiv-conv: FUN_0021ecd0 eax stack
extern "C" void FUN_0021ecd0(LuaVMLexState* ls, int line);
// equiv-conv: FUN_0021ee70 eax stack
extern "C" void FUN_0021ee70(LuaVMLexState* ls, int line);
// equiv-conv: FUN_0021ef60 ebx
extern "C" void FUN_0021ef60(LuaVMLexState* ls);
// equiv-conv: FUN_0021f0a0 eax
extern "C" void FUN_0021f0a0(LuaVMLexState* ls);
// equiv-conv: FUN_0021f280 eax esi
extern "C" void FUN_0021f280(LuaVMLexState* ls, int line);
// equiv-conv: FUN_0021f300 eax
extern "C" void FUN_0021f300(LuaVMLexState* ls);
// equiv-conv: FUN_0021f350 eax
extern "C" unsigned int FUN_0021f350(LuaVMLexState* ls);
// equiv-conv: FUN_0021f460 edi
extern "C" void FUN_0021f460(LuaVMLexState* ls);

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
