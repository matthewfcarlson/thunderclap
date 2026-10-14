// STATUS: equivalent (tools/equiv.py level 3: 304 inputs, branch coverage 10/10)
// FUN_0021c490 @ 0x0021c490
// FUN_0021c490: Lua parser, register a new local variable name
struct lua_State;
struct TString {
    char pad00[5];
    unsigned char marked;
};

struct LocVar {
    TString *varname;
    int startpc;
    int endpc;
};

struct Proto {
    char pad00[5];
    unsigned char marked;
    char pad06[0x12];
    LocVar *locvars;
    char pad1c[0x1c];
    int sizelocvars;
};

struct FuncState {
    Proto *f;
    char pad04[0x2c];
    int nactloc;
};

struct LexState {
    char pad00[0x1c];
    FuncState *fs;
    lua_State *L;
};

void *__cdecl FUN_0021ae40(lua_State *L, void *block, int *size, int elemSize, int limit, const char *msg);
void __cdecl FUN_00217100(lua_State *L, Proto *p, TString *s);

int __cdecl FUN_0021c490(LexState *ls, TString *name)
{
    FuncState *fs = ls->fs;
    Proto *f = fs->f;
    int oldsize = f->sizelocvars;
    if (fs->nactloc + 1 > oldsize)
        f->locvars = (LocVar *)FUN_0021ae40(ls->L, f->locvars, &f->sizelocvars, 12, 0xffff, "too many local variables");
    while (oldsize < f->sizelocvars)
        f->locvars[oldsize++].varname = 0;
    f->locvars[fs->nactloc].varname = name;
    if ((name->marked & 3) && (f->marked & 4))
        FUN_00217100(ls->L, f, name);
    return fs->nactloc++;
}
