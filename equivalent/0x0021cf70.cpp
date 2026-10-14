// STATUS: equivalent (tools/equiv.py level 3: 164 inputs, branch coverage 24/28, incomplete)
// FUN_0021cf70 @ 0x0021cf70
struct Proto_21cf70 {
    char pad00[0xc];
    unsigned int* code;         // 0xc
    char pad10[0x3c - 0x10];
    int lineDefined;            // 0x3c
};

struct LexState_21cf70;

struct FuncState_21cf70 {
    Proto_21cf70* f;
    char pad04[8];
    LexState_21cf70* ls;               // 0xc
    void* L;                    // 0x10
    char pad14[0x24 - 0x14];
    int freereg;                // 0x24
};

struct LexState_21cf70 {
    int pad00;
    int linenumber;
    int lastline;
    int token;                  // 0xc
    int seminfo;
    int lookaheadToken;
    int lookaheadSeminfo;
    FuncState_21cf70* fs;              // 0x1c
};

struct Exp_21cf70 {
    int k;
    int info;
    int aux;
    int t;
    int f;
};

struct ConsControl {
    Exp_21cf70 v;
    Exp_21cf70* t;
    int nh;
    int na;
    int tostore;
};

int __cdecl FUN_00220bd0(FuncState_21cf70* fs, int op, int a, int b, int c);
int __cdecl FUN_00220c10(FuncState_21cf70* fs, int op, int a, int bx);
void __cdecl FUN_00221110(FuncState_21cf70* fs, Exp_21cf70* e);
int __cdecl FUN_0021ded0(LexState_21cf70* ls, Exp_21cf70* v, unsigned int limit);
int __cdecl FUN_0021bbc0(LexState_21cf70* ls, int* seminfo);
const char* FUN_00216320(void* L, const char* fmt, ...);
void FUN_0021afd0(LexState_21cf70* ls, const char* msg, int token);
int FUN_00215f50(unsigned int x);
int FUN_00215f70(unsigned int x);
// equiv-conv: FUN_0021c2e0 esi eax
void FUN_0021c2e0(LexState_21cf70* ls, int token);
// equiv-conv: FUN_0021c340 esi edi stack eax
void FUN_0021c340(LexState_21cf70* ls, int what, int who, int line);
// equiv-conv: FUN_0021cec0 esi edi
void FUN_0021cec0(ConsControl* cc, FuncState_21cf70* fs);
void __cdecl FUN_0021cd90(LexState_21cf70* ls, ConsControl* cc);

static inline void Next(LexState_21cf70* ls)
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

// Lua 5.0 constructor(ls, t): ls arrives in ecx, t in eax.
// equiv-conv: FUN_0021cf70 ecx eax
void FUN_0021cf70(LexState_21cf70* ls, Exp_21cf70* t)
{
    FuncState_21cf70* fs = ls->fs;
    int line = ls->linenumber;
    int pc = FUN_00220bd0(fs, 0xa, 0, 0, 0);
    ConsControl cc;

    t->t = -1;
    t->f = -1;
    t->k = 0xa;
    t->info = pc;
    FuncState_21cf70* fs1 = ls->fs;
    cc.tostore = 0;
    cc.na = 0;
    cc.nh = 0;
    cc.t = t;
    cc.v.t = -1;
    cc.v.f = -1;
    cc.v.k = 0;
    cc.v.info = 0;
    FUN_00221110(fs1, t);
    FUN_0021c2e0(ls, 0x7b);

    for (;;) {
        if (ls->token == 0x3b)
            Next(ls);
        if (ls->token == 0x7d)
            break;

        if (cc.v.k != 0) {
            FUN_00221110(fs, &cc.v);
            cc.v.k = 0;
            if (cc.tostore == 0x20) {
                FUN_00220c10(fs, 0x20, cc.t->info, cc.na - 1);
                cc.tostore = 0;
                fs->freereg = cc.t->info + 1;
            }
        }

        bool rec = false;
        if (ls->token == '[') {
            rec = true;
        } else if (ls->token == 0x116) {
            ls->lookaheadToken = FUN_0021bbc0(ls, &ls->lookaheadSeminfo);
            rec = (ls->lookaheadToken == '=');
        }
        if (rec) {
            FUN_0021cd90(ls, &cc);
        } else {
            FUN_0021ded0(ls, &cc.v, 0);
            if (cc.na > 0x3ffff) {
                FuncState_21cf70* f2 = ls->fs;
                const char* msg;
                int ld = f2->f->lineDefined;
                if (ld != 0)
                    msg = FUN_00216320(f2->L, "function at line %d has more than %d %s", ld, 0x3ffff, "items in a constructor");
                else
                    msg = FUN_00216320(f2->L, "main function has more than %d %s", 0x3ffff, "items in a constructor");
                FUN_0021afd0(f2->ls, msg, 0);
            }
            cc.na++;
            cc.tostore++;
        }

        if (ls->token == ',') {
            Next(ls);
        } else if (ls->token == ';') {
            Next(ls);
        } else {
            break;
        }
    }

    FUN_0021c340(ls, 0x7d, 0x7b, line);
    FUN_0021cec0(&cc, fs);
    unsigned int* ip = &fs->f->code[pc];
    int fb = FUN_00215f50(cc.na);
    unsigned int i = *ip;
    *ip = (i & ~0xff8000u) | (((unsigned int)fb << 15) & 0xff8000u);
    ip = &fs->f->code[pc];
    int lg = FUN_00215f70(cc.nh);
    i = *ip;
    *ip = (i & ~0x7fc0u) | (((unsigned int)(lg + 1) << 6) & 0x7fc0u);
}
