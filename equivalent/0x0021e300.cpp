// STATUS: equivalent (tools/equiv.py level 3: 86 inputs, branch coverage 26/26)
// FUN_0021e300 @ 0x0021e300
struct LocVar_21e300 {
    int varname;
    int startpc;
    int endpc;
};

struct Proto_21e300 {
    char pad0[0xc];
    unsigned int *code;         // 0xc
    char pad10[0x18 - 0x10];
    LocVar_21e300 *locvars;            // 0x18
};

struct LexState_21e300;

struct BlockCnt_21e300 {
    BlockCnt_21e300 *previous;
    int breaklist;
    unsigned char nactvar;
    unsigned char upval;
    unsigned char isbreakable;
};

struct FuncState_21e300 {
    Proto_21e300 *f;                   // 0x0
    char pad4[8];
    LexState_21e300 *ls;               // 0xc
    char pad10[4];
    BlockCnt_21e300 *bl;               // 0x14
    int pc;                     // 0x18
    int lasttarget;             // 0x1c
    int jpc;                    // 0x20
    int freereg;                // 0x24
    char pad28[0x34 - 0x28];
    unsigned char nactvar;      // 0x34
    char pad35[0x76 - 0x35];
    unsigned short actvar[200];
};

struct LexState_21e300 {
    int pad0;
    int linenumber;
    int lastline;
    int token;                  // 0xc
    int seminfo;
    int lookaheadToken;
    int lookaheadSeminfo;
    FuncState_21e300 *fs;              // 0x1c
    void *L;                    // 0x20
};

struct Exp_21e300 {
    int k;
    int info;
    int aux;
    int t;
    int f;
};

int __cdecl FUN_0021bbc0(LexState_21e300 *ls, int *seminfo);
int __cdecl FUN_00220cd0(FuncState_21e300 *fs);
int __cdecl FUN_00220530(FuncState_21e300 *fs);
int __cdecl FUN_0021ded0(LexState_21e300 *ls, Exp_21e300 *v, unsigned int limit);
void __cdecl FUN_00221560(FuncState_21e300 *fs, Exp_21e300 *v);
void __cdecl FUN_002207c0(FuncState_21e300 *fs, int *l1, int l2);
void FUN_0021b060(LexState_21e300 *ls, const char *msg);
const char *__cdecl FUN_0021af00(LexState_21e300 *ls, int token);
const char *FUN_00216320(void *L, const char *fmt, ...);
// equiv-conv: FUN_0021e080 eax
void FUN_0021e080(LexState_21e300 *ls);
void __cdecl FUN_00220d70(FuncState_21e300 *fs, int list);
void __cdecl FUN_00221ae0(FuncState_21e300 *fs, int list, int target);
int __cdecl FUN_00220b20(FuncState_21e300 *fs, unsigned int instr, int line);
int __cdecl FUN_00220bd0(FuncState_21e300 *fs, int op, int a, int b, int c);
// equiv-conv: FUN_0021c340 esi edi stack eax
void FUN_0021c340(LexState_21e300 *ls, int what, int who, int line);

static inline void Next(LexState_21e300 *ls)
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
void FUN_0021e300(LexState_21e300 *ls, int line)
{
    unsigned int codeexp[105];
    BlockCnt_21e300 bl;
    Exp_21e300 v;
    int whileinit;
    int expinit;
    int lineexp;
    int sizeexp;
    int blockinit;
    int i;
    FuncState_21e300 *fs = ls->fs;

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

    BlockCnt_21e300 *b = fs->bl;
    fs->bl = b->previous;
    FuncState_21e300 *fs2 = fs->ls->fs;
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
