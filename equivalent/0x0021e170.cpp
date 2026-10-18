// STATUS: equivalent (tools/equiv.py level 3: 20023 inputs, branch coverage 14/14)
// FUN_0021e170 @ 0x0021e170
// FUN_0021e170 @ 0x0021e170
struct ExpDesc_21e170 {
    int k;
    int info;
    int aux;
    int t;
    int f;
};
struct LHSAssign {
    LHSAssign *prev;
    ExpDesc_21e170 v;
};
struct FuncState_21e170 {
    char pad0[0x24];
    int freereg;
};
struct LexState_21e170 {
    char pad0[4];
    int linenumber;
    int lastline;
    int token;
    int seminfo;
    int lookaheadToken;
    int lookaheadSeminfo;
    FuncState_21e170 *fs;
};
struct Frame_21e170 {
    ExpDesc_21e170 e;
    LHSAssign nv;
};

void __cdecl FUN_0021b060(LexState_21e170 *ls, const char *msg);
int __cdecl FUN_0021bbc0(LexState_21e170 *ls, int *seminfo);
// equiv-conv: FUN_0021d830 eax esi
void FUN_0021d830(ExpDesc_21e170 *v, LexState_21e170 *ls);
// equiv-conv: FUN_0021e110 ecx eax edi
void FUN_0021e110(LexState_21e170 *ls, LHSAssign *lh, ExpDesc_21e170 *v);
// equiv-conv: FUN_0021c2e0 esi eax
void FUN_0021c2e0(LexState_21e170 *ls, int token);
// equiv-conv: FUN_0021d5c0 esi edi
int FUN_0021d5c0(LexState_21e170 *ls, ExpDesc_21e170 *e);
// equiv-conv: FUN_0021c8b0 eax ecx edx stack
void FUN_0021c8b0(LexState_21e170 *ls, ExpDesc_21e170 *e, int nexps, int nvars);
void __cdecl FUN_00220a50(FuncState_21e170 *fs, ExpDesc_21e170 *e, int nresults);
void __cdecl FUN_00221280(FuncState_21e170 *fs, ExpDesc_21e170 *var, ExpDesc_21e170 *e);

// Lua 5.0 restassign(ls, lh, nvars)
void __cdecl FUN_0021e170(LexState_21e170 *ls, LHSAssign *lh, int nvars)
{
    Frame_21e170 f;
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
    FuncState_21e170 *fs = ls->fs;
    f.e.info = fs->freereg - 1;
    f.e.t = -1;
    f.e.f = -1;
    f.e.k = 11;
    FUN_00221280(fs, &lh->v, &f.e);
}
