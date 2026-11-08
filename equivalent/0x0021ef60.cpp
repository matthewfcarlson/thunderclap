// STATUS: equivalent (tools/equiv.py level 3: 122 inputs, branch coverage 2/2)
// localfunc: local function name body (the local is active before the body, for recursion).
#include "decls/data/lua.h"
extern "C" unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int);

// equiv-conv: FUN_0021c3d0 esi
extern "C" LuaVMString* FUN_0021c3d0(LuaVMLexState* ls);
// equiv-conv: FUN_0021c240 esi ecx edx
extern "C" void FUN_0021c240(LuaVMFuncState* fs, const char* what, int limit);
extern "C" int __cdecl FUN_0021c490(LuaVMLexState* ls, LuaVMString* varname);
extern "C" void __cdecl FUN_00220850(LuaVMFuncState* fs, int n);
// equiv-conv: FUN_0021cac0 ecx eax
extern "C" void FUN_0021cac0(LuaVMLexState* ls, LuaVMFuncState* fs);
// equiv-conv: FUN_0021c2e0 esi eax
extern "C" void FUN_0021c2e0(LuaVMLexState* ls, int c);
// equiv-conv: FUN_0021d210 eax
extern "C" void FUN_0021d210(LuaVMLexState* ls);
extern "C" void __cdecl FUN_0021f640(LuaVMLexState* ls);
// equiv-conv: FUN_0021c340 eax esi edi stack
extern "C" void FUN_0021c340(int where, LuaVMLexState* ls, int what, int who);
extern "C" void __cdecl FUN_0021cb80(LuaVMLexState* ls);
extern "C" void __cdecl FUN_0021c9b0(LuaVMLexState* ls, LuaVMFuncState* func, LuaVMExpDesc* v);
extern "C" void __cdecl FUN_00221280(LuaVMFuncState* fs, LuaVMExpDesc* var, LuaVMExpDesc* ex);

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
