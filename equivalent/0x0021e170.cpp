// STATUS: equivalent (tools/equiv.py level 3: 3037 inputs, branch coverage 14/14)
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_0021b060(LuaVMLexState* ls, const char* msg);
extern "C" int __cdecl FUN_0021bbc0(LuaVMLexState* ls, LuaVMSemInfo* seminfo);
// equiv-conv: FUN_0021d830 eax esi
extern "C" void FUN_0021d830(LuaVMExpDesc* v, LuaVMLexState* ls);
// equiv-conv: FUN_0021e110 ecx eax edi
extern "C" void FUN_0021e110(LuaVMLexState* ls, LuaVMLHSAssign* lh, LuaVMExpDesc* v);
// equiv-conv: FUN_0021c2e0 esi eax
extern "C" void FUN_0021c2e0(LuaVMLexState* ls, int c);
// equiv-conv: FUN_0021d5c0 esi edi
extern "C" int FUN_0021d5c0(LuaVMLexState* ls, LuaVMExpDesc* v);
// equiv-conv: FUN_0021c8b0 eax ecx edx stack
extern "C" void FUN_0021c8b0(LuaVMLexState* ls, LuaVMExpDesc* e, int nexps, int nvars);
extern "C" void __cdecl FUN_00220a50(LuaVMFuncState* fs, LuaVMExpDesc* e, int nresults);
extern "C" void __cdecl FUN_00221280(LuaVMFuncState* fs, LuaVMExpDesc* var, LuaVMExpDesc* ex);

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
