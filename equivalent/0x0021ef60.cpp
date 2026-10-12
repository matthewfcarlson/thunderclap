// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_0021ef60 @ 0x0021ef60
extern "C" unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int);

struct LocVar {
    void *name;
    int startpc;
    int endpc;
};
struct Proto {
    char pad0[0x18];
    LocVar *locvars;
    char pad1c[0x20];
    int lineDefined;
};
struct FuncState {
    Proto *f;
    char pad4[0x14];
    int pc;
    char pad1c[8];
    int freereg;
    char pad28[0xc];
    unsigned char nactvar;
    char pad35[0x41];
    unsigned short actvar[200];
};
struct LexState {
    char pad0[4];
    int linenumber;
    int lastline;
    int token;
    char pad10[0xc];
    FuncState *fs;
    void *L;
};
struct ExpDesc {
    int k;
    int info;
    int aux;
    int t;
    int f;
};
struct Frame {
    ExpDesc v;
    ExpDesc b;
    FuncState newfs;
};

// equiv-conv: FUN_0021c3d0 esi
void *FUN_0021c3d0(LexState *ls);
// equiv-conv: FUN_0021c240 ecx edx
void FUN_0021c240(const char *what, int limit);
unsigned short __cdecl FUN_0021c490(LexState *ls, void *name);
void __cdecl FUN_00220850(FuncState *fs, int n);
// equiv-conv: FUN_0021cac0 eax ecx
void FUN_0021cac0(FuncState *newfs, LexState *ls);
// equiv-conv: FUN_0021c2e0 esi eax
void FUN_0021c2e0(LexState *ls, int token);
// equiv-conv: FUN_0021d210 eax
void FUN_0021d210(LexState *ls);
void __cdecl FUN_0021f640(LexState *ls);
// equiv-conv: FUN_0021c340 esi edi stack eax
void FUN_0021c340(LexState *ls, int what, int who, int line);
void __cdecl FUN_0021cb80(LexState *ls);
void __cdecl FUN_0021c9b0(LexState *ls, FuncState *newfs, ExpDesc *e);
void __cdecl FUN_00221280(FuncState *fs, ExpDesc *var, ExpDesc *e);

// equiv-conv: FUN_0021ef60 ebx
void FUN_0021ef60(LexState *ls)
{
    unsigned int cookie = DAT_004d9968;
    Frame f;
    FuncState *fs = ls->fs;
    void *name = FUN_0021c3d0(ls);

    FuncState *cur = ls->fs;
    if (cur->nactvar + 1 > 200)
        FUN_0021c240("local variables", 200);
    cur->actvar[cur->nactvar] = FUN_0021c490(ls, name);

    f.v.k = 5;
    f.v.info = fs->freereg;
    f.v.t = -1;
    f.v.f = -1;
    FUN_00220850(fs, 1);

    cur = ls->fs;
    cur->nactvar++;
    cur->f->locvars[cur->actvar[cur->nactvar - 1]].startpc = cur->pc;

    int line = ls->linenumber;
    FUN_0021cac0(&f.newfs, ls);
    f.newfs.f->lineDefined = line;
    FUN_0021c2e0(ls, '(');
    FUN_0021d210(ls);
    FUN_0021c2e0(ls, ')');
    FUN_0021f640(ls);
    FUN_0021c340(ls, 0x106, 0x109, line);
    FUN_0021cb80(ls);
    FUN_0021c9b0(ls, &f.newfs, &f.b);
    FUN_00221280(fs, &f.v, &f.b);
    fs->f->locvars[fs->actvar[fs->nactvar - 1]].startpc = fs->pc;
    __security_check_cookie(cookie);
}
