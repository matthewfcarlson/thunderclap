// STATUS: equivalent (tools/equiv.py level 3: 86 inputs, branch coverage 26/26)
// FUN_0021e300 @ 0x0021e300
struct LocVar {
    int varname;
    int startpc;
    int endpc;
};

struct Proto {
    char pad0[0xc];
    unsigned int *code;         // 0xc
    char pad10[0x18 - 0x10];
    LocVar *locvars;            // 0x18
};

struct LexState;

struct BlockCnt {
    BlockCnt *previous;
    int breaklist;
    unsigned char nactvar;
    unsigned char upval;
    unsigned char isbreakable;
};

struct FuncState {
    Proto *f;                   // 0x0
    char pad4[8];
    LexState *ls;               // 0xc
    char pad10[4];
    BlockCnt *bl;               // 0x14
    int pc;                     // 0x18
    int lasttarget;             // 0x1c
    int jpc;                    // 0x20
    int freereg;                // 0x24
    char pad28[0x34 - 0x28];
    unsigned char nactvar;      // 0x34
    char pad35[0x76 - 0x35];
    unsigned short actvar[200];
};

struct LexState {
    int pad0;
    int linenumber;
    int lastline;
    int token;                  // 0xc
    int seminfo;
    int lookaheadToken;
    int lookaheadSeminfo;
    FuncState *fs;              // 0x1c
    void *L;                    // 0x20
};

struct Exp {
    int k;
    int info;
    int aux;
    int t;
    int f;
};

int __cdecl FUN_0021bbc0(LexState *ls, int *seminfo);
int __cdecl FUN_00220cd0(FuncState *fs);
int __cdecl FUN_00220530(FuncState *fs);
int __cdecl FUN_0021ded0(LexState *ls, Exp *v, unsigned int limit);
void __cdecl FUN_00221560(FuncState *fs, Exp *v);
void __cdecl FUN_002207c0(FuncState *fs, int *l1, int l2);
void FUN_0021b060(LexState *ls, const char *msg);
const char *__cdecl FUN_0021af00(LexState *ls, int token);
const char *FUN_00216320(void *L, const char *fmt, ...);
// equiv-conv: FUN_0021e080 eax
void FUN_0021e080(LexState *ls);
void __cdecl FUN_00220d70(FuncState *fs, int list);
void __cdecl FUN_00221ae0(FuncState *fs, int list, int target);
int __cdecl FUN_00220b20(FuncState *fs, unsigned int instr, int line);
int __cdecl FUN_00220bd0(FuncState *fs, int op, int a, int b, int c);
// equiv-conv: FUN_0021c340 esi edi stack eax
void FUN_0021c340(LexState *ls, int what, int who, int line);

static inline void Next(LexState *ls)
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

// Lua 5.0 whilestat(ls, line)
void FUN_0021e300(LexState *ls, int line)
{
    unsigned int codeexp[105];
    BlockCnt bl;
    Exp v;
    int whileinit;
    int expinit;
    int lineexp;
    int sizeexp;
    int blockinit;
    int i;
    FuncState *fs = ls->fs;

    Next(ls);
    whileinit = FUN_00220cd0(fs);
    expinit = FUN_00220530(fs);
    FUN_0021ded0(ls, &v, 0);
    if (v.k == 4)
        v.k = 2;
    lineexp = ls->linenumber;
    FUN_00221560(fs, &v);
    FUN_002207c0(fs, &v.f, fs->jpc);
    sizeexp = fs->pc - expinit;
    fs->jpc = -1;
    if (sizeexp > 100)
        FUN_0021b060(ls, "`while' condition too complex");
    for (i = 0; i < sizeexp; i++)
        codeexp[i] = fs->f->code[expinit + i];
    fs->pc = expinit;

    bl.breaklist = -1;
    bl.isbreakable = 1;
    bl.nactvar = fs->nactvar;
    bl.upval = 0;
    bl.previous = fs->bl;
    fs->bl = &bl;

    if (ls->token == 0x103) {
        Next(ls);
    } else {
        FUN_0021b060(ls, FUN_00216320(ls->L, "`%s' expected", FUN_0021af00(ls, 0x103)));
    }

    blockinit = FUN_00220530(fs);
    FUN_0021e080(ls);
    FUN_00220d70(fs, whileinit);
    if (v.t != -1)
        v.t += fs->pc - expinit;
    if (v.f != -1)
        v.f += fs->pc - expinit;
    for (i = 0; i < sizeexp; i++)
        FUN_00220b20(fs, codeexp[i], lineexp);
    FUN_0021c340(ls, 0x106, 0x115, line);

    BlockCnt *b = fs->bl;
    fs->bl = b->previous;
    FuncState *fs2 = fs->ls->fs;
    int level = b->nactvar;
    while (fs2->nactvar > level) {
        fs2->nactvar--;
        fs2->f->locvars[fs2->actvar[fs2->nactvar]].endpc = fs2->pc;
    }
    if (b->upval)
        FUN_00220bd0(fs, 0x22, b->nactvar, 0, 0);
    fs->freereg = fs->nactvar;
    FUN_00220d70(fs, b->breaklist);
    FUN_00221ae0(fs, v.t, blockinit);
    FUN_00220d70(fs, v.f);
}
