// FUN_0021c490 @ 0x0021c490
// FUN_0021c490: Lua parser, register a new local variable name
struct lua_State;
struct TString_21c490 {
    char pad00[5];
    unsigned char marked;
};

struct LocVar_21c490 {
    TString_21c490 *varname;
    int startpc;
    int endpc;
};

struct Proto_21c490 {
    char pad00[5];
    unsigned char marked;
    char pad06[0x12];
    LocVar_21c490 *locvars;
    char pad1c[0x1c];
    int sizelocvars;
};

struct FuncState_21c490 {
    Proto_21c490 *f;
    char pad04[0x2c];
    int nactloc;
};

struct LexState_21c490 {
    char pad00[0x1c];
    FuncState_21c490 *fs;
    lua_State *L;
};

void *__cdecl FUN_0021ae40(lua_State *L, void *block, int *size, int elemSize, int limit, const char *msg);
void __cdecl FUN_00217100(lua_State *L, Proto_21c490 *p, TString_21c490 *s);

int __cdecl FUN_0021c490(LexState_21c490 *ls, TString_21c490 *name)
{
    FuncState_21c490 *fs = ls->fs;
    Proto_21c490 *f = fs->f;
    int oldsize = f->sizelocvars;
    if (fs->nactloc + 1 > oldsize)
        f->locvars = (LocVar_21c490 *)FUN_0021ae40(ls->L, f->locvars, &f->sizelocvars, 12, 0xffff, "too many local variables");
    while (oldsize < f->sizelocvars)
        f->locvars[oldsize++].varname = 0;
    f->locvars[fs->nactloc].varname = name;
    if ((name->marked & 3) && (f->marked & 4))
        FUN_00217100(ls->L, f, name);
    return fs->nactloc++;
}
