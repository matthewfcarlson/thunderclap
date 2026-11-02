// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 10/10)
// FUN_0021e700 @ 0x0021e700
struct LocVar_21e700 {
    void *name;
    int startpc;
    int endpc;
};

struct Proto_21e700 {
    char pad0[0x18];
    LocVar_21e700 *locvars;
};

struct BlockCnt_21e700 {
    BlockCnt_21e700 *previous;
    int breaklist;
    unsigned char nactvar;
    unsigned char upval;
    unsigned char isbreak;
};

struct FuncState_21e700 {
    Proto_21e700 *f;
    char pad4[8];
    void *ls;
    char pad10[4];
    BlockCnt_21e700 *bl;
    int pc;
    char pad1c[8];
    int freereg;
    char pad28[0xc];
    unsigned char nactvar;
    char pad35[0x41];
    unsigned short actvar[200];
};

struct LexState_21e700 {
    char pad0[0x1c];
    FuncState_21e700 *fs;
};

// equiv-conv: FUN_0021c2e0 esi eax
extern "C" void __cdecl FUN_0021c2e0(void *, int);
// equiv-conv: FUN_0021c570 eax edx
extern "C" void __cdecl FUN_0021c570(void *, int);
// equiv-conv: FUN_0021e080 eax
extern "C" void __cdecl FUN_0021e080(void *);
// equiv-conv: FUN_0021c5b0 eax edx
extern "C" void __cdecl FUN_0021c5b0(void *, int);
extern "C" int __cdecl FUN_00220c10(void *, unsigned int, int, unsigned int);
extern "C" int __cdecl FUN_00220bd0(void *, unsigned int, int, unsigned int, unsigned int);
extern "C" void __cdecl FUN_00220850(void *, int);
void __cdecl FUN_00220d70(FuncState_21e700 *fs, int list);
extern "C" void __cdecl FUN_00220b00(void *, int);
extern "C" int __cdecl FUN_00220cd0(void *);
extern "C" void __cdecl FUN_00221ae0(void *, int, int);

// Lua 5.0 forbody(ls, base, line, nvars, isnum): ls arrives in eax, the rest on the stack.
// equiv-conv: FUN_0021e700 eax stack stack stack stack
extern "C" void FUN_0021e700(void *ls, int base, int line, int nvars, int isnum)
{
    BlockCnt_21e700 bl;
    int prep;
    int i;
    int endfor;
    FuncState_21e700 *fs = ((LexState_21e700 *)ls)->fs;
    BlockCnt_21e700 *b;

    fs->nactvar = (unsigned char)(fs->nactvar + 3);
    for (i = 3; i != 0; i--)
        fs->f->locvars[fs->actvar[fs->nactvar - i]].startpc = fs->pc;

    FUN_0021c2e0((LexState_21e700 *)((LexState_21e700 *)ls), 0x103);

    prep = FUN_00220c10((FuncState_21e700 *)fs, (int)(isnum ? 0x1d : 0x1f), base, 0x1fffe);
    bl.breaklist = -1;
    bl.isbreak = 0;
    bl.nactvar = fs->nactvar;
    bl.upval = 0;
    bl.previous = fs->bl;
    fs->bl = &bl;

    FUN_0021c570((LexState_21e700 *)((LexState_21e700 *)ls), nvars);
    FUN_00220850((FuncState_21e700 *)fs, nvars);
    FUN_0021e080((LexState_21e700 *)((LexState_21e700 *)ls));

    b = fs->bl;
    fs->bl = b->previous;
    FUN_0021c5b0(fs->ls, b->nactvar);
    if (b->upval)
        FUN_00220bd0((FuncState_21e700 *)fs, 0x22, b->nactvar, 0, 0);
    fs->freereg = fs->nactvar;
    FUN_00220d70(fs, b->breaklist);
    FUN_00220d70(fs, prep);

    if (isnum)
        endfor = FUN_00220c10((FuncState_21e700 *)fs, 0x1c, base, 0x1fffe);
    else
        endfor = FUN_00220bd0((FuncState_21e700 *)fs, 0x1e, base, 0, (int)nvars);
    FUN_00220b00((FuncState_21e700 *)fs, line);
    if (!isnum)
        endfor = FUN_00220cd0((FuncState_21e700 *)fs);
    FUN_00221ae0((FuncState_21e700 *)fs, endfor, prep + 1);
}
