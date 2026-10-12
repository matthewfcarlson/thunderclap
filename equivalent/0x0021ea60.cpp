// STATUS: equivalent (tools/equiv.py level 3: 106 inputs, branch coverage 16/20, incomplete)
// FUN_0021ea60 @ 0x0021ea60
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
    LexState* ls;               // 0xc
    void* L;                    // 0x10
    char pad14[0x24 - 0x14];
    int freereg;                // 0x24
    char pad28[0x34 - 0x28];
    unsigned char nactvar;      // 0x34
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

int __cdecl FUN_0021b080(LexState* ls, const char* s, int len);
void FUN_0021b060(LexState* ls, const char* msg);
int FUN_0021bbc0(LexState* ls, int* seminfo);
const char* FUN_00216320(void* L, const char* fmt, ...);
void FUN_0021afd0(LexState* ls, const char* msg, int token);
unsigned short FUN_0021c490(LexState* ls, int name);
void __cdecl FUN_00220810(FuncState* fs, int n);
// equiv-conv: FUN_0021c240 esi ecx edx
void FUN_0021c240(FuncState* fs, const char* what, int limit);
// equiv-conv: FUN_0021c2e0 esi eax
void FUN_0021c2e0(LexState* ls, int token);
// equiv-conv: FUN_0021d5c0 esi edi
int FUN_0021d5c0(LexState* ls, Exp* e);
// equiv-conv: FUN_0021c8b0 eax edx ecx stack
void FUN_0021c8b0(LexState* ls, int nexps, Exp* e, int nvars);
// equiv-conv: FUN_0021e700 eax stack stack stack stack
void FUN_0021e700(LexState* ls, int base, int line, int nvars, int isnum);

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

// Lua 5.0 forlist(ls, indexname): ls arrives in ebx, indexname on the stack.
// equiv-conv: FUN_0021ea60 ebx stack
void FUN_0021ea60(LexState* ls, int indexname)
{
    Exp e;
    FuncState* fs0 = ls->fs;
    FuncState* fs;
    int base = fs0->freereg;

    int name = FUN_0021b080(ls, "(for generator)", 15);
    fs = ls->fs;
    if (fs->nactvar + 1 > 200)
        FUN_0021c240(fs, "local variables", 200);
    fs->actvar[fs->nactvar + 0] = FUN_0021c490(ls, name);

    name = FUN_0021b080(ls, "(for state)", 11);
    fs = ls->fs;
    if (fs->nactvar + 2 > 200)
        FUN_0021c240(fs, "local variables", 200);
    fs->actvar[fs->nactvar + 1] = FUN_0021c490(ls, name);

    name = FUN_0021b080(ls, "(for control)", 13);
    fs = ls->fs;
    if (fs->nactvar + 3 > 200)
        FUN_0021c240(fs, "local variables", 200);
    fs->actvar[fs->nactvar + 2] = FUN_0021c490(ls, name);

    fs = ls->fs;
    if (fs->nactvar + 4 > 200)
        FUN_0021c240(fs, "local variables", 200);
    fs->actvar[fs->nactvar + 3] = FUN_0021c490(ls, indexname);

    int nvars = 4;
    while (ls->t.token == 0x2c) {
        Next(ls);
        if (ls->t.token != 0x116)
            FUN_0021b060(ls, "<name> expected");
        int nm = ls->t.seminfo;
        Next(ls);
        fs = ls->fs;
        if (fs->nactvar + nvars + 1 > 200) {
            int line = fs->f->lineDefined;
            const char* msg;
            if (line != 0)
                msg = FUN_00216320(fs->L, "function at line %d has more than %d %s", line, 200, "local variables");
            else
                msg = FUN_00216320(fs->L, "main function has more than %d %s", 200, "local variables");
            FUN_0021afd0(fs->ls, msg, 0);
        }
        fs->actvar[fs->nactvar + nvars] = FUN_0021c490(ls, nm);
        nvars++;
    }

    FUN_0021c2e0(ls, 0x10b);
    int line = ls->linenumber;
    int nexps = FUN_0021d5c0(ls, &e);
    FUN_0021c8b0(ls, nexps, &e, 3);
    FUN_00220810(fs0, 3);
    FUN_0021e700(ls, base, line, nvars - 3, 0);
}
