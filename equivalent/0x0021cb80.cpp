// STATUS: equivalent (tools/equiv.py level 3: 84 inputs, branch coverage 4/4)
// FUN_0021cb80 @ 0x0021cb80
struct lua_State {
    char pad[8];
    char *top;
};

struct Proto {
    char pad0[8];
    void *k;
    void *code;
    void *p;
    void *lineinfo;
    void *locvars;
    void *upvalues;
    char pad1[4];
    int sizeupvalues;
    int sizek;
    int sizecode;
    int sizelineinfo;
    int sizep;
    int sizelocvars;
    char pad2[0x44 - 0x3c];
    unsigned char nups;
};

struct FuncState {
    Proto *f;
    char pad0[4];
    FuncState *prev;
    char pad1[0x18 - 0xc];
    int pc;
    char pad2[0x28 - 0x1c];
    int nk;
    int np;
    int nlocvars;
};

struct TokenInfo {
    char pad[0xc];
    int length;
};

struct LexState {
    char pad0[0xc];
    int token;
    TokenInfo *seminfo;
    char pad1[0x1c - 0x14];
    FuncState *fs;
    lua_State *L;
};

// equiv-conv: FUN_0021c5b0 eax edx
void FUN_0021c5b0(LexState *ls, int level);
void FUN_00220bd0(FuncState *fs, unsigned op, int a, unsigned b, unsigned c);
void *FUN_0021add0(lua_State *L, void *block, unsigned oldsize, unsigned newsize);
void FUN_0021b080(LexState *ls, void *str, int len);

void FUN_0021cb80(LexState *ls)
{
    lua_State *L = ls->L;
    FuncState *fs = ls->fs;
    Proto *f = fs->f;

    FUN_0021c5b0(ls, 0);
    FUN_00220bd0(fs, 0x1b, 0, 1, 0);

    f->code = FUN_0021add0(L, f->code, f->sizecode * 4, fs->pc * 4);
    f->sizecode = fs->pc;

    f->lineinfo = FUN_0021add0(L, f->lineinfo, f->sizelineinfo * 4, fs->pc * 4);
    f->sizelineinfo = fs->pc;

    f->k = FUN_0021add0(L, f->k, f->sizek * 8, fs->nk * 8);
    f->sizek = fs->nk;

    f->p = FUN_0021add0(L, f->p, f->sizep * 4, fs->np * 4);
    f->sizep = fs->np;

    f->locvars = FUN_0021add0(L, f->locvars, f->sizelocvars * 12, fs->nlocvars * 12);
    f->sizelocvars = fs->nlocvars;

    f->upvalues = FUN_0021add0(L, f->upvalues, f->sizeupvalues * 4, f->nups * 4);
    f->sizeupvalues = f->nups;

    ls->fs = fs->prev;
    L->top -= 16;

    if (ls->token == 0x116 || ls->token == 0x11e)
        FUN_0021b080(ls, (char *)ls->seminfo + 0x10, ls->seminfo->length);
}
