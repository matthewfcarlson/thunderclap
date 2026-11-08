// STATUS: equivalent (tools/equiv.py level 3: 2847 inputs, branch coverage 4/4)
// body: a function body ( parlist ) chunk end, compiled in a new FuncState (with `self' first when needself);
// e is the closure.
#include "decls/data/lua.h"

extern unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int);
// equiv-conv: FUN_0021cac0 ecx eax
extern "C" void FUN_0021cac0(LuaVMLexState* ls, LuaVMFuncState* fs);
// equiv-conv: FUN_0021c2e0 esi eax
extern "C" void FUN_0021c2e0(LuaVMLexState* ls, int c);
extern "C" LuaVMString* __cdecl FUN_0021b080(LuaVMLexState* ls, const char* str, unsigned int l);
// equiv-conv: FUN_0021c240 esi ecx edx
extern "C" void FUN_0021c240(LuaVMFuncState* fs, const char* what, int limit);
extern "C" int __cdecl FUN_0021c490(LuaVMLexState* ls, LuaVMString* varname);
// equiv-conv: FUN_0021d210 eax
extern "C" void FUN_0021d210(LuaVMLexState* ls);
extern "C" void __cdecl FUN_0021f640(LuaVMLexState* ls);
// equiv-conv: FUN_0021c340 eax esi edi stack
extern "C" void FUN_0021c340(int where, LuaVMLexState* ls, int what, int who);
extern "C" void __cdecl FUN_0021cb80(LuaVMLexState* ls);
extern "C" void __cdecl FUN_0021c9b0(LuaVMLexState* ls, LuaVMFuncState* func, LuaVMExpDesc* v);
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
