// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 8/8)
// FUN_0021ab30 @ 0x0021ab30
struct Dump {
    void* L;
    int (*writer)(void* L, const void* buf, int size, void* ud);
    void* ud;
    int strip;
};
struct Proto {
    char pad0[0xc];
    void* k;           // 0x0c
    void* code;        // 0x10 (unused)
    void* lines;       // 0x14
    char pad18[8];
    Proto* source;     // 0x20
    char pad24[8];
    int sizek;         // 0x2c
    int sizelines;     // 0x30
    char pad34[8];
    int linedefined;   // 0x3c
    char pad40[4];
    unsigned char nups;       // 0x44
    unsigned char numparams;  // 0x45
    unsigned char is_vararg;  // 0x46
    unsigned char maxstack;   // 0x47
};

// equiv-conv: FUN_0021a790 eax esi
void __stdcall FUN_0021a790(Proto* s, Dump* D);
// equiv-conv: FUN_0021a830 stack esi
void __stdcall FUN_0021a830(Proto* f, Dump* D);
// equiv-conv: FUN_0021a960 stack esi
void __stdcall FUN_0021a960(Proto* f, Dump* D);
// equiv-conv: FUN_0021aa00 stack esi
void __stdcall FUN_0021aa00(Proto* f, Dump* D);

static void put(Dump* D, const void* p, int n)
{
    D->writer(D->L, p, n, D->ud);
}

// One scratch slot serves every value handed to the writer, as in the original (it lives in a dead
// argument slot, so the bytes around a one-byte value are stale).
union Scratch {
    int i;
    unsigned char c;
};

void FUN_0021ab30(Proto* f, Proto* p, Dump* D)
{
    Scratch v;
    FUN_0021a790(f->source == p ? 0 : f->source, D);
    v.i = f->linedefined;
    put(D, &v, 4);
    v.c = f->nups;
    put(D, &v, 1);
    v.c = f->numparams;
    put(D, &v, 1);
    v.c = f->is_vararg;
    put(D, &v, 1);
    v.c = f->maxstack;
    put(D, &v, 1);
    if (D->strip) {
        v.i = 0;
        put(D, &v, 4);
    } else {
        v.i = f->sizelines;
        put(D, &v, 4);
        put(D, f->lines, f->sizelines * 4);
    }
    if (D->strip) {
        v.i = 0;
        put(D, &v, 4);
    } else {
        FUN_0021a830(f, D);
    }
    if (D->strip) {
        v.i = 0;
        put(D, &v, 4);
    } else {
        FUN_0021a960(f, D);
    }
    FUN_0021aa00(f, D);
    v.i = f->sizek;
    put(D, &v, 4);
    put(D, f->k, f->sizek * 4);
}
