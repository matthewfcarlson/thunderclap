// STATUS: equivalent (tools/equiv.py level 3: 156 inputs, branch coverage 22/28, incomplete)
// FUN_0021d210 @ 0x0021d210
struct Proto {
    char pad00[0x3c];
    int lineDefined;            // 0x3c
    char pad40[0x45 - 0x40];
    unsigned char numparams;    // 0x45
    unsigned char isVararg;     // 0x46
};

struct LexState;

struct FuncState {
    Proto* f;
    char pad04[8];
    LexState* ls;               // 0xc
    void* L;                    // 0x10
    char pad14[0x34 - 0x14];
    unsigned char nactvar;      // 0x34
    char pad35[0x76 - 0x35];
    unsigned short actvar[200];
};

struct LexState {
    int pad00;
    int linenumber;
    int lastline;
    int token;                  // 0xc
    int seminfo;
    int lookaheadToken;
    int lookaheadSeminfo;
    FuncState* fs;              // 0x1c
};

int __cdecl FUN_0021bbc0(LexState* ls, int* seminfo);
void FUN_0021b060(LexState* ls, const char* msg);
int __cdecl FUN_0021b080(LexState* ls, const char* s, int len);
unsigned short FUN_0021c490(LexState* ls, int name);
const char* FUN_00216320(void* L, const char* fmt, ...);
void FUN_0021afd0(LexState* ls, const char* msg, int token);
void __cdecl FUN_00220850(FuncState* fs, int n);
// equiv-conv: FUN_0021c2e0 esi eax
void FUN_0021c2e0(LexState* ls, int token);
// equiv-conv: FUN_0021c570 eax edx
void FUN_0021c570(LexState* ls, int n);

static inline void Next(LexState* ls)
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

static inline void CheckLocalLimit(FuncState* fs, int count)
{
    if (fs->nactvar + count > 200) {
        int line = fs->f->lineDefined;
        const char* msg;
        if (line != 0)
            msg = FUN_00216320(fs->L, "function at line %d has more than %d %s", line, 200, "local variables");
        else
            msg = FUN_00216320(fs->L, "main function has more than %d %s", 200, "local variables");
        FUN_0021afd0(fs->ls, msg, 0);
    }
}

// Lua 5.0 parlist(ls): ls arrives in eax.
// equiv-conv: FUN_0021d210 eax
void FUN_0021d210(LexState* ls)
{
    FuncState* fs0 = ls->fs;
    FuncState* fs;
    Proto* f = fs0->f;
    int nparams = 0;

    f->isVararg = 0;
    if (ls->token != ')') {
        for (;;) {
            if (ls->token == 0x116) {
                int name = ls->seminfo;
                Next(ls);
                fs = ls->fs;
                CheckLocalLimit(fs, nparams + 1);
                fs->actvar[fs->nactvar + nparams] = FUN_0021c490(ls, name);
                nparams++;
                if (ls->token == '=') {
                    Next(ls);
                    FUN_0021c2e0(ls, 0x118);
                    f->isVararg = 1;
                    break;
                }
            } else if (ls->token == 0x118) {
                Next(ls);
                int name = FUN_0021b080(ls, "arg", 3);
                FuncState* cur = ls->fs;
                CheckLocalLimit(cur, nparams + 1);
                cur->actvar[cur->nactvar + nparams] = FUN_0021c490(ls, name);
                nparams++;
                f->isVararg = 1;
                break;
            } else {
                FUN_0021b060(ls, "<name> or `...' expected");
            }

            if (f->isVararg)
                break;
            if (ls->token != ',')
                break;
            Next(ls);
        }
    }

    FUN_0021c570(ls, nparams);
    f->numparams = (unsigned char)(fs0->nactvar - f->isVararg);
    FUN_00220850(fs0, fs0->nactvar);
}
