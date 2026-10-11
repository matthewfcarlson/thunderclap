// STATUS: equivalent (tools/equiv.py level 3: 137 inputs, branch coverage 15/16, incomplete)
// FUN_0021d630 @ 0x0021d630
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
    int lookahead_token;
    int lookahead_seminfo;
    FuncState *fs;
};

struct ExpDesc {
    int k;
    int info;
    int aux;
    int t;
    int f;
};

struct Frame {
    int line;
    ExpDesc args;
};

void __cdecl FUN_0021b060(LexState *ls, const char *msg);
int __cdecl FUN_0021bbc0(LexState *ls, int *seminfo);
// equiv-conv: FUN_0021c190 esi
void FUN_0021c190(LexState *ls);
// equiv-conv: FUN_0021c340 esi edi stack eax
void FUN_0021c340(LexState *ls, int what, int who, int line);
// equiv-conv: FUN_0021cf70 ecx eax
void FUN_0021cf70(LexState *ls, void *e);
// equiv-conv: FUN_0021d5c0 esi edi
int FUN_0021d5c0(LexState *ls, void *e);
int __cdecl FUN_002209b0(FuncState *fs, int ts);
void __cdecl FUN_00220a50(FuncState *fs, ExpDesc *e, int nresults);
int __cdecl FUN_00220bd0(FuncState *fs, int op, int a, int b, int c);
void __cdecl FUN_00220b00(FuncState *fs, int line);
void __cdecl FUN_00221110(FuncState *fs, void *e);

// funcargs(ls, f): ls arrives in eax, f on the stack.
// equiv-conv: FUN_0021d630 eax stack
void FUN_0021d630(LexState *ls, ExpDesc *f)
{
    FuncState *fs = ls->fs;
    Frame fr;
    int line;
    fr.line = ls->linenumber;
    line = fr.line;
    int nparams;
    int base;

    switch (ls->token) {
    case '(':
        if (line != ls->lastline)
            FUN_0021b060(ls, "ambiguous syntax (function call x new statement)");
        ls->lastline = ls->linenumber;
        if (ls->lookahead_token != 0x11f) {
            ls->token = ls->lookahead_token;
            ls->seminfo = ls->lookahead_seminfo;
            ls->lookahead_token = 0x11f;
        } else {
            ls->token = FUN_0021bbc0(ls, &ls->seminfo);
        }
        if (ls->token == ')') {
            fr.args.k = 0;
        } else {
            FUN_0021d5c0(ls, &fr.args);
            FUN_00220a50(fs, &fr.args, -1);
        }
        FUN_0021c340(ls, ')', '(', line);
        break;
    case '{':
        FUN_0021cf70(ls, &fr.args);
        break;
    case 0x11e:
        fr.args.k = 4;
        fr.args.info = FUN_002209b0(fs, ls->seminfo);
        fr.args.t = -1;
        fr.args.f = -1;
        fr.args.aux = -1;
        FUN_0021c190(ls);
        break;
    default:
        FUN_0021b060(ls, "function arguments expected");
        return;
    }

    base = f->info;
    if (fr.args.k == 12) {
        nparams = -1;
    } else {
        if (fr.args.k != 0)
            FUN_00221110(fs, &fr.args);
        nparams = fs->freereg - base - 1;
    }
    f->info = FUN_00220bd0(fs, 0x19, base, nparams + 1, 2);
    f->t = -1;
    f->f = -1;
    f->k = 12;
    FUN_00220b00(fs, line);
    fs->freereg = base + 1;
}
