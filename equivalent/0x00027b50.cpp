// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00027b50 @ 0x00027b50
extern unsigned __int64 __cdecl FUN_002672f0(const char *s, int a, int b);
extern unsigned __int64 __cdecl FUN_0027b020(const char *s);
extern void __cdecl FUN_00224d70(float angle, struct V3 *v);

struct V3 {
    float x, y, z;
};

struct Sub {
    char FUN_00059a50(V3 *out);
};

struct Desc {
    unsigned int idLo, idHi;
    V3 pos;
    int pad14;
    V3 dir;
    char f24;
    char pad25[0x54 - 0x25];
    int f54;
    float f58;
    char pad5c[0x68 - 0x5c];
    int f68;
    char pad6c[0x74 - 0x6c];
    int f74;
    char pad78[0x98 - 0x78];
    Desc *FUN_00059820();
    void FUN_000595f0(V3 *v, int a, float b, int c);
    void FUN_00059300();
};

struct Obj {
    char pad0[0x10];
    Sub *sub;
    char FUN_00035550(V3 *out);
    char FUN_000437a0(int a, Desc *d, int b, int c, int e);
};

struct Table {
    Obj *FUN_00024280(unsigned __int64 key);
    void FUN_00027b50(const char *name, float a1, int a2, float a3, int a4, int a5, const char *s);
};

struct Frame {
    V3 v;
    Desc d;
};

void Table::FUN_00027b50(const char *name, float a1, int a2, float a3, int a4, int a5, const char *s) {
    Obj *o = FUN_00024280(FUN_002672f0(name, 0, 0));
    if (o) {
        Frame f;
        o->FUN_00035550(&f.v);
        f.v.y = 0.0f;
        FUN_00224d70(3.1415927f, &f.v);
        f.d.FUN_00059820();
        f.d.f74 = 2;
        o->sub->FUN_00059a50(&f.d.pos);
        f.d.dir = f.v;
        unsigned __int64 id = FUN_0027b020(s);
        f.d.idLo = (unsigned int)id;
        f.d.idHi = (unsigned int)(id >> 32);
        f.d.f68 = a5;
        f.d.f54 = 0x7fffffff;
        f.d.f24 = 1;
        f.d.f58 = a1;
        if (a3 <= 0.0f) {
            a3 = a1;
        }
        f.d.FUN_000595f0(&f.v, a2, a3, a4);
        o->FUN_000437a0(0, &f.d, 0, 0, 0);
        f.d.FUN_00059300();
    }
}
