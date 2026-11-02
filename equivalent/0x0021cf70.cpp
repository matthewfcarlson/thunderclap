// STATUS: equivalent (tools/equiv.py level 3: 12371 inputs, branch coverage 24/28, incomplete)
// FUN_0021cf70 @ 0x0021cf70
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

extern "C" int __cdecl FUN_00220bd0(void *, unsigned int, int, unsigned int, unsigned int);
extern "C" int __cdecl FUN_00220c10(void *, unsigned int, int, unsigned int);
extern "C" void __cdecl FUN_00221110(void *, void *);
extern "C" int __cdecl FUN_0021ded0(void *, void *, unsigned int);
extern "C" int __cdecl FUN_0021bbc0(void *, void *);
const char* FUN_00216320(void* L, const char* fmt, ...);
void FUN_0021afd0(LexState_21cf70* ls, const char* msg, int token);
extern "C" unsigned int __cdecl FUN_00215f50(unsigned int);
int FUN_00215f70(unsigned int x);
// equiv-conv: FUN_0021c2e0 esi eax
extern "C" void __cdecl FUN_0021c2e0(void *, int);
// equiv-conv: FUN_0021c340 eax esi edi stack
void FUN_0021c340(int line, LexState_21cf70* ls, int what, int who);
// equiv-conv: FUN_0021cec0 esi edi
extern "C" void __cdecl FUN_0021cec0(void *, void *);
void __cdecl FUN_0021cd90(LexState_21cf70* ls, ConsControl* cc);

static inline void Next(LexState_21cf70* ls)
{
    ls->lastline = ls->linenumber;
    if (ls->lookaheadToken != 0x11f) {
        ls->token = ls->lookaheadToken;
        ls->seminfo = ls->lookaheadSeminfo;
        ls->lookaheadToken = 0x11f;
    } else {
        ls->token = FUN_0021bbc0((LexState_21cf70 *)ls, (int *)(&ls->seminfo));
    }
}

// Lua 5.0 constructor(ls, t): ls arrives in ecx, t in eax.
// equiv-conv: FUN_0021cf70 ecx eax
extern "C" void FUN_0021cf70(void * ls_, void * t)
{
    LexState_21cf70 * ls = (LexState_21cf70 *)ls_;
    FuncState_21cf70* fs = ls->fs;
    int line = ls->linenumber;
    int pc = FUN_00220bd0((FuncState_21cf70 *)fs, 0xa, 0, 0, 0);
    ConsControl cc;

    ((Exp_21cf70 *)t)->t = -1;
    ((Exp_21cf70 *)t)->f = -1;
    ((Exp_21cf70 *)t)->k = 0xa;
    ((Exp_21cf70 *)t)->info = pc;
    FuncState_21cf70* fs1 = ls->fs;
    cc.tostore = 0;
    cc.na = 0;
    cc.nh = 0;
    cc.t = ((Exp_21cf70 *)t);
    cc.v.t = -1;
    cc.v.f = -1;
    cc.v.k = 0;
    cc.v.info = 0;
    FUN_00221110((FuncState_21cf70 *)fs1, (Exp_21cf70 *)((Exp_21cf70 *)t));
    FUN_0021c2e0((LexState_21cf70 *)ls, 0x7b);

    for (;;) {
        if (ls->token == 0x3b)
            Next(ls);
        if (ls->token == 0x7d)
            break;

        if (cc.v.k != 0) {
            FUN_00221110((FuncState_21cf70 *)fs, (Exp_21cf70 *)(&cc.v));
            cc.v.k = 0;
            if (cc.tostore == 0x20) {
                FUN_00220c10((FuncState_21cf70 *)fs, 0x20, cc.t->info, (int)(cc.na - 1));
                cc.tostore = 0;
                fs->freereg = cc.t->info + 1;
            }
        }

        bool rec = false;
        if (ls->token == '[') {
            rec = true;
        } else if (ls->token == 0x116) {
            ls->lookaheadToken = FUN_0021bbc0((LexState_21cf70 *)ls, (int *)(&ls->lookaheadSeminfo));
            rec = (ls->lookaheadToken == '=');
        }
        if (rec) {
            FUN_0021cd90(ls, &cc);
        } else {
            FUN_0021ded0((LexState_21cf70 *)ls, (Exp_21cf70 *)(&cc.v), 0);
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

    FUN_0021c340(line, ls, 0x7d, 0x7b);
    FUN_0021cec0((ConsControl *)(&cc), (FuncState_21cf70 *)fs);
    unsigned int* ip = &fs->f->code[pc];
    int fb = ((int)FUN_00215f50(cc.na));
    unsigned int i = *ip;
    *ip = (i & ~0xff8000u) | (((unsigned int)fb << 15) & 0xff8000u);
    ip = &fs->f->code[pc];
    int lg = FUN_00215f70(cc.nh);
    i = *ip;
    *ip = (i & ~0x7fc0u) | (((unsigned int)(lg + 1) << 6) & 0x7fc0u);
}
