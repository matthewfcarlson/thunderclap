// STATUS: equivalent (tools/equiv.py level 3: 20033 inputs, branch coverage 13/16, incomplete)
// FUN_0021f0a0 @ 0x0021f0a0
// FUN_0021f0a0 @ 0x0021f0a0
struct Token_21f0a0 {
    int token;
    int seminfo;
};

struct Proto_21f0a0 {
    char pad00[0x3c];
    int lineDefined;
};

struct LexState_21f0a0;

struct FuncState_21f0a0 {
    Proto_21f0a0* f;
    char pad04[8];
    LexState_21f0a0* ls;
    void* L;
    char pad14[0x34 - 0x14];
    unsigned char nactvar;
    char pad35[0x76 - 0x35];
    unsigned short actvar[200];
};

struct LexState_21f0a0 {
    int pad00;
    int linenumber;
    int lastline;
    Token_21f0a0 t;
    Token_21f0a0 lookahead;
    FuncState_21f0a0* fs;
};

struct Exp_21f0a0 {
    int k;
    int info;
    int aux;
    int t;
    int f;
};

void FUN_0021b060(LexState_21f0a0* ls, const char* msg);
int FUN_0021bbc0(LexState_21f0a0* ls, int* seminfo);
const char* FUN_00216320(void* L, const char* fmt, ...);
void FUN_0021afd0(LexState_21f0a0* ls, const char* msg, int token);
unsigned short FUN_0021c490(LexState_21f0a0* ls, int name);
// equiv-conv: FUN_0021d5c0 esi edi
int FUN_0021d5c0(LexState_21f0a0* ls, Exp_21f0a0* e);
// equiv-conv: FUN_0021c8b0 eax ecx edx stack
void FUN_0021c8b0(LexState_21f0a0* ls, Exp_21f0a0* e, int nexps, int nvars);
// equiv-conv: FUN_0021c570 eax edx
void FUN_0021c570(LexState_21f0a0* ls, int nvars);

static inline void Next(LexState_21f0a0* ls)
{
    ls->lastline = ls->linenumber;
    if (ls->lookahead.token != 0x11f) {
        ls->t.token = ls->lookahead.token;
        ls->t.seminfo = ls->lookahead.seminfo;
        ls->lookahead.token = 0x11f;
    } else {
        ls->t.token = FUN_0021bbc0(ls, &ls->t.seminfo);
    }
}

// equiv-conv: FUN_0021f0a0 eax
void FUN_0021f0a0(LexState_21f0a0* ls)
{
    int nvars = 0;
    Exp_21f0a0 e;
    for (;;) {
        if (ls->t.token != 0x116)
            FUN_0021b060(ls, "<name> expected");
        int name = ls->t.seminfo;
        Next(ls);
        FuncState_21f0a0* fs = ls->fs;
        if (fs->nactvar + nvars + 1 > 200) {
            int line = fs->f->lineDefined;
            const char* msg;
            if (line != 0)
                msg = FUN_00216320(fs->L, "function at line %d has more than %d %s", line, 200, "local variables");
            else
                msg = FUN_00216320(fs->L, "main function has more than %d %s", 200, "local variables");
            FUN_0021afd0(fs->ls, msg, 0);
        }
        fs->actvar[fs->nactvar + nvars] = FUN_0021c490(ls, name);
        nvars++;
        if (ls->t.token != 0x2c)
            break;
        Next(ls);
    }
    int nexps;
    if (ls->t.token == 0x3d) {
        Next(ls);
        nexps = FUN_0021d5c0(ls, &e);
    } else {
        e.k = 0;
        nexps = 0;
    }
    FUN_0021c8b0(ls, &e, nexps, nvars);
    FUN_0021c570(ls, nvars);
}
