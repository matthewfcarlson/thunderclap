// STATUS: equivalent (tools/equiv.py level 3: 83 inputs, branch coverage 14/14)
// FUN_0021e170 @ 0x0021e170
struct ExpDesc {
    int k;
    int info;
    int aux;
    int t;
    int f;
};
struct LHSAssign {
    LHSAssign *prev;
    ExpDesc v;
};
struct FuncState {
    char pad0[0x24];
    int freereg;
};
struct LexState {
    char pad0[4];
    int linenumber;
    int lastline;
    int token;
    int seminfo;
    int lookaheadToken;
    int lookaheadSeminfo;
    FuncState *fs;
};
struct Frame {
    ExpDesc e;
    LHSAssign nv;
};

void __cdecl FUN_0021b060(LexState *ls, const char *msg);
int __cdecl FUN_0021bbc0(LexState *ls, int *seminfo);
// equiv-conv: FUN_0021d830 eax esi
void FUN_0021d830(ExpDesc *v, LexState *ls);
// equiv-conv: FUN_0021e110 ecx eax edi
void FUN_0021e110(LexState *ls, LHSAssign *lh, ExpDesc *v);
// equiv-conv: FUN_0021c2e0 eax esi
void FUN_0021c2e0(int token, LexState *ls);
// equiv-conv: FUN_0021d5c0 esi edi
int FUN_0021d5c0(LexState *ls, ExpDesc *e);
// equiv-conv: FUN_0021c8b0 eax stack edx ecx
void FUN_0021c8b0(LexState *ls, int nvars, int nexps, ExpDesc *e);
void __cdecl FUN_00220a50(FuncState *fs, ExpDesc *e, int nresults);
void __cdecl FUN_00221280(FuncState *fs, ExpDesc *var, ExpDesc *e);

// Lua 5.0 restassign(ls, lh, nvars)
void __cdecl FUN_0021e170(LexState *ls, LHSAssign *lh, int nvars)
{
    Frame f;
    if (lh->v.k < 5 || lh->v.k > 8)
        FUN_0021b060(ls, "syntax error");
    if (ls->token == ',') {
        f.nv.prev = lh;
        ls->lastline = ls->linenumber;
        if (ls->lookaheadToken != 0x11f) {
            ls->token = ls->lookaheadToken;
            ls->seminfo = ls->lookaheadSeminfo;
            ls->lookaheadToken = 0x11f;
        } else {
            ls->token = FUN_0021bbc0(ls, &ls->seminfo);
        }
        FUN_0021d830(&f.nv.v, ls);
        if (f.nv.v.k == 5)
            FUN_0021e110(ls, lh, &f.nv.v);
        FUN_0021e170(ls, &f.nv, nvars + 1);
    } else {
        FUN_0021c2e0('=', ls);
        int nexps = FUN_0021d5c0(ls, &f.e);
        if (nexps == nvars) {
            FUN_00220a50(ls->fs, &f.e, 1);
            FUN_00221280(ls->fs, &lh->v, &f.e);
            return;
        }
        FUN_0021c8b0(ls, nvars, nexps, &f.e);
        if (nexps > nvars)
            ls->fs->freereg += nvars - nexps;
    }
    FuncState *fs = ls->fs;
    f.e.info = fs->freereg - 1;
    f.e.t = -1;
    f.e.f = -1;
    f.e.k = 11;
    FUN_00221280(fs, &lh->v, &f.e);
}
