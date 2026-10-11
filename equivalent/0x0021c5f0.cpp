// STATUS: equivalent (tools/equiv.py level 3: 95 inputs, branch coverage 22/22)
// FUN_0021c5f0 @ 0x0021c5f0
struct LuaState;

struct TString {
    char pad0[5];
    unsigned char marked;
};

struct Proto {
    char pad0[5];
    unsigned char marked;
    char pad6[0x1c - 6];
    TString **upvalues;
    char pad20[4];
    int sizeupvalues;
    char pad28[0x3c - 0x28];
    int linedefined;
    char pad40[4];
    unsigned char nups;
};

struct UpvalDesc {
    unsigned char k;
    unsigned char info;
};

struct FuncState {
    Proto *f;
    char pad4[0xc - 4];
    void *ls;
    LuaState *L;
    char pad14[0x35 - 0x14];
    UpvalDesc upvalues[32];
};

struct ExpDesc {
    int k;
    int info;
};

const char *FUN_00216320(LuaState *L, const char *fmt, ...);
void FUN_0021afd0(void *ls, const char *msg, int token);
TString **FUN_0021ae40(LuaState *L, TString **block, int *size, int elemSize, int limit, const char *what);
void FUN_00217100(LuaState *L, Proto *f, TString *name);

// Lua 5.1 indexupvalue(fs, name, v): fs arrives in edi, name and v on the stack.
// equiv-conv: FUN_0021c5f0 edi stack stack
int FUN_0021c5f0(FuncState *fs, TString *name, ExpDesc *v)
{
    Proto *f = fs->f;
    int i;
    int oldsize;

    oldsize = f->sizeupvalues;
    for (i = 0; i < f->nups; i++) {
        if (fs->upvalues[i].k == v->k && fs->upvalues[i].info == v->info)
            return i;
    }

    if (f->nups + 1 > 32) {
        const char *msg;
        if (f->linedefined == 0)
            msg = FUN_00216320(fs->L, "main function has more than %d %s", 32, "upvalues");
        else
            msg = FUN_00216320(fs->L, "function at line %d has more than %d %s", f->linedefined, 32, "upvalues");
        FUN_0021afd0(fs->ls, msg, 0);
    }

    if (f->nups + 1 > f->sizeupvalues)
        f->upvalues = FUN_0021ae40(fs->L, f->upvalues, &f->sizeupvalues, 4, 0x7ffffffd, "");
    while (oldsize < f->sizeupvalues)
        f->upvalues[oldsize++] = 0;

    f->upvalues[f->nups] = name;
    if ((name->marked & 3) && (f->marked & 4))
        FUN_00217100(fs->L, f, name);
    fs->upvalues[f->nups].k = (unsigned char)v->k;
    fs->upvalues[f->nups].info = (unsigned char)v->info;
    return f->nups++;
}
