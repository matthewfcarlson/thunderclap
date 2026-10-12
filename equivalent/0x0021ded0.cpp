// STATUS: equivalent (tools/equiv.py level 3: 121 inputs, branch coverage 16/16)
// FUN_0021ded0 @ 0x0021ded0
struct ExpDesc {
    int k;
    int info;
    int aux;
    int t;
    int f;
};

struct FuncState;

struct LexState {
    char pad0[4];
    int linenumber;
    int lastline;
    int token;
    int seminfo;
    int lookaheadToken;
    int lookaheadSeminfo;
    FuncState *fs;
    char pad20[0x30 - 0x20];
    int nestlevel;
};

int FUN_0021bbc0(LexState *ls, int *seminfo);
void FUN_0021afd0(LexState *ls, const char *msg, int token);
// equiv-conv: FUN_0021db50 eax edi
void FUN_0021db50(LexState *ls, ExpDesc *v);
// equiv-conv: FUN_0021dd30 eax
int FUN_0021dd30(int token);
void FUN_00221700(FuncState *fs, int op, ExpDesc *v);
void FUN_002217c0(FuncState *fs, int op, ExpDesc *v);
void FUN_002218d0(FuncState *fs, int op, ExpDesc *v, ExpDesc *v2);

extern const unsigned char DAT_00426e00[];

static void next(LexState *ls)
{
    ls->lastline = ls->linenumber;
    if (ls->lookaheadToken != 0x11f) {
        ls->token = ls->lookaheadToken;
        ls->seminfo = ls->lookaheadSeminfo;
        ls->lookaheadToken = 0x11f;
    } else {
        ls->token = FUN_0021bbc0(ls, &ls->seminfo);
    }
}

int FUN_0021ded0(LexState *ls, ExpDesc *v, unsigned int limit)
{
    ExpDesc v2;
    int op;

    ls->nestlevel++;
    if (ls->nestlevel > 200)
        FUN_0021afd0(ls, "chunk has too many syntax levels", 0);

    if (ls->token == '-' || ls->token == 0x10e) {
        int uop = (ls->token == 0x10e);
        next(ls);
        FUN_0021ded0(ls, v, 8);
        FUN_00221700(ls->fs, uop, v);
    } else {
        FUN_0021db50(ls, v);
    }
    op = FUN_0021dd30(ls->token);
    while (op != 0xe && DAT_00426e00[op * 2] > limit) {
        next(ls);
        FUN_002217c0(ls->fs, op, v);
        int nextop = FUN_0021ded0(ls, &v2, DAT_00426e00[op * 2 + 1]);
        FUN_002218d0(ls->fs, op, v, &v2);
        op = nextop;
    }
    ls->nestlevel--;
    return op;
}
