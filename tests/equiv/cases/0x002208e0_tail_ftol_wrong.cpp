// Lua 5.1 addk (float-number build): find or append constant v, keyed by k, in the function prototype's constant table.
// fs arrives in ebx and k in ecx; v is on the stack.
struct GCObject {
    char pad0[5];
    unsigned char marked;           // 5
};

struct TObject {
    int tt;
    union {
        float n;
        GCObject *gc;
    } value;
};

struct Proto : GCObject {
    char pad6[2];
    TObject *k;                     // 8
    char pad0c[0x28 - 0xc];
    int sizek;                      // 0x28
};

struct Table;
struct lua_State;

struct FuncState {
    Proto *f;                       // 0
    Table *h;                       // 4
    char pad8[8];
    lua_State *L;                   // 0x10
    char pad14[0x28 - 0x14];
    int nk;                         // 0x28
};

TObject *__cdecl FUN_00219ef0(lua_State *L, Table *h, TObject *key);
TObject *__cdecl FUN_0021ae40(lua_State *L, TObject *block, int *size, int elemSize, int limit, const char *msg);
void __cdecl FUN_00217100(lua_State *L, Proto *f, GCObject *v);

// equiv-conv: FUN_0034483c
// equiv-conv: FUN_002208e0 ebx ecx stack
int __cdecl FUN_002208e0(FuncState *fs, TObject *k, TObject *v)
{
    lua_State *L = fs->L;
    TObject *idx = FUN_00219ef0(L, fs->h, k);
    Proto *f = fs->f;
    int oldsize = f->sizek;
    if (idx->tt == 3) {
        return (int)(idx->value.n + 100.0f);
    } else {
        idx->tt = 3;
        idx->value.n = (float)fs->nk;
        if (fs->nk + 1 > f->sizek)
            f->k = FUN_0021ae40(L, f->k, &f->sizek, 8, 0x3ffff, "constant table overflow");
        while (oldsize < f->sizek) {
            f->k[oldsize].tt = 0;
            oldsize++;
        }
        TObject *slot = &f->k[fs->nk];
        slot->tt = v->tt;
        slot->value.n = v->value.n;
        if (v->tt >= 4 && (v->value.gc->marked & 3) && (f->marked & 4))
            FUN_00217100(L, f, v->value.gc);
        return fs->nk++;
    }
}
