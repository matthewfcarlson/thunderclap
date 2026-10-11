// STATUS: equivalent (tools/equiv.py level 3: 128 inputs, branch coverage 16/16)
// FUN_0021f0a0 @ 0x0021f0a0
struct Token {
    int token;
    int seminfo;
};

struct Proto {
    char pad00[0x3c];
    int lineDefined;
};

struct LexState;

struct FuncState {
    Proto* f;
    char pad04[8];
    LexState* ls;
    void* L;
    char pad14[0x34 - 0x14];
    unsigned char nactvar;
    char pad35[0x76 - 0x35];
    unsigned short actvar[200];
};

struct LexState {
    int pad00;
    int linenumber;
    int lastline;
    Token t;
    Token lookahead;
    FuncState* fs;
};

struct Exp {
    int k;
    int info;
    int aux;
    int t;
    int f;
};

void FUN_0021b060(LexState* ls, const char* msg);
int FUN_0021bbc0(LexState* ls, int* seminfo);
const char* FUN_00216320(void* L, const char* fmt, ...);
void FUN_0021afd0(LexState* ls, const char* msg, int token);
unsigned short FUN_0021c490(LexState* ls, int name);
// equiv-conv: FUN_0021d5c0 esi edi
int FUN_0021d5c0(LexState* ls, Exp* e);
// equiv-conv: FUN_0021c8b0 eax edx ecx stack
void FUN_0021c8b0(LexState* ls, int nexps, Exp* e, int nvars);
// equiv-conv: FUN_0021c570 eax edx
void FUN_0021c570(LexState* ls, int nvars);

static inline void Next(LexState* ls)
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
void FUN_0021f0a0(LexState* ls)
{
    int nvars = 0;
    Exp e;
    for (;;) {
        if (ls->t.token != 0x116)
            FUN_0021b060(ls, "<name> expected");
        int name = ls->t.seminfo;
        Next(ls);
        FuncState* fs = ls->fs;
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
    FUN_0021c8b0(ls, nexps, &e, nvars);
    FUN_0021c570(ls, nvars);
}
