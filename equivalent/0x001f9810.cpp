// STATUS: equivalent (tools/equiv.py level 3: 20095 inputs, branch coverage 85/94, incomplete)
// FUN_001f9810 @ 0x001f9810
typedef unsigned __int64 u64;
extern unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int cookie);
extern "C" int memcmp(const void *a, const void *b, unsigned int n);

struct V3 {
    float x, y, z;
    float FUN_00018990();
};

struct Name {
    char d[8];
    void FUN_0027b0e0(const char *s);
    void FUN_0027af50();
};

struct Key {
    char name[8];
    unsigned char b8;
    unsigned char idx;               // this+0x39
    char pad_a[6];
    Key(const Key &o);
};

struct NameObj {
    char *FUN_00044400();
    char *FUN_00044360();
};

struct Obj {
    virtual void o0(); virtual void o1(); virtual void o2(); virtual void o3();
    virtual void o4(); virtual void o5(); virtual void o6(); virtual void o7();
    virtual void v8(V3 *out);
    virtual float v9();
    char pad_o[0xc - 4];
    char name[4];
    int FUN_001fba60();
};

struct Finder {
    Obj *FUN_001fc8c0(u64 id);
};

struct Inst {
    char FUN_001d1cb0();
    char FUN_001d2ba0(const char *s, int a, int b);
    void FUN_001d1d50(const char *key, const void *v);
    void FUN_001d19d0(int a);
    void FUN_001d1d30();
    char FUN_001d1930(int a);
    void FUN_001d2b10(int a, int b);
};

struct Actor {
    char pad0[0x1d7c];
    int f1d7c;
    void FUN_00037180(V3 v);
    void FUN_000371b0(int a);
    void FUN_0003ec70(void *p);
    void FUN_00037160(int a);
    void FUN_00037170(int a);
};

struct Q1 {
    char d[0x58];
    void FUN_001ca000(const char *a, const char *b);
};

struct Spawner {
    void FUN_001cbc20(Q1 *q);
};

struct ZObj {
    char pad;
};

struct Entry {
    NameObj *obj;                    // 0
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    char pad24[4];
    char FUN_001f8aa0(ZObj *z, Obj *r);
};

struct Cfg {
    char pad0[0x41c];
    char name[12];                   // 0x41c
    char pad428[0x448 - 0x428];
    int f448;
    char pad44c[0x454 - 0x44c];
    int f454;
    char pad458[0x460 - 0x458];
    Entry entries[1];                // 0x460
    char pad_tail[0x6e0 - 0x460 - 0x28];
    int count;                       // 0x6e0
    short FUN_001f9630(Key o);
    void FUN_001f9670(Key o, short s);
};

struct Zone {
    char FUN_00099d60(float x, float y, float z, float w, int a);
};

struct Fighter {
    int FUN_00024b00(void *p);
    Actor *FUN_00024280(u64 id);
    char FUN_0002bf80(const char *nm, V3 v, float rr, const char *name, const char *none, int z, char *buf);
    Actor *FUN_000259f0(char *buf);
};

struct Y {
    ZObj *FUN_00059a30();
    char FUN_00059a50(V3 *out);
};

struct X {
    Y *FUN_00059ba0(int id);
};

struct World {
    char pad0[8];
    Zone *f8;
    char pad0c[0x20 - 0xc];
    Fighter *f20;
    char pad24[0x28 - 0x24];
    Finder *f28;
    char pad2c[0x30 - 0x2c];
    Spawner *f30;
    char pad34[0x44 - 0x34];
    X *f44;
};
extern World *DAT_004dd700;
extern float DAT_004e58e0;

struct Hold2 {
    int FUN_001c59d0(Name *n);
};
struct HolderObj {
    char pad0[0xc];
    Hold2 *f0c;
};
HolderObj *__cdecl FUN_001c3d90();
Inst *__cdecl FUN_001d4c90();
u64 __cdecl FUN_0027b020(const char *s);
u64 __cdecl FUN_002672f0(const char *s, int a, int b);
void __cdecl FUN_00267760(char *buf, int n, const char *fmt, ...);
void __cdecl FUN_00224d70(float a, V3 *v);
float __cdecl FUN_0004af40(int a, float b, float c);

class Self;

union FS {
    int i;
    float f;
};

struct Frame {
    unsigned char pad0c[3];
    unsigned char strike;            // S'+0x0f
    FS s10;                          // 0x10
    Self *self;                      // 0x14
    int s;                           // 0x18
    int off;                         // 0x1c
    int n;                           // 0x20
    int i;                           // 0x24
    Obj *r2;                         // 0x28
    V3 tmp;                          // 0x2c
    Fighter *W;                      // 0x38
    Obj *R;                          // 0x3c
    V3 v40;                          // 0x40
    V3 pos;                          // 0x4c
    ZObj *Zp;                        // 0x58
    float rr;                        // 0x5c
    Name nm;                         // 0x60
    V3 v68;                          // 0x68
    V3 d;                            // 0x74
    char buf2[256];                  // 0x80
    Q1 q;                            // 0x180
    char buf1[256];                  // 0x1d8
    int pad2d8;
    unsigned int cookie;             // 0x2dc
};

class Self {
public:
    char pad0[8];
    Cfg *f8;
    char name[0x30 - 0xc];           // 0xc
    Key key;                         // 0x30
    int f40;
    float f44;
    float f48;
    float f4c;
    unsigned char b50;
    unsigned char b51;
    short f52;

    Obj *FUN_001f8b40(int a, Obj *r, V3 pos);
    void FUN_001f9810(float dt);
};

void Self::FUN_001f9810(float dt)
{
    Frame f;
    f.cookie = DAT_004d9968;
    f48 = dt + f48;
    f.self = this;
    do {
        if (b50 != 0)
            break;
        if (b51 == 0)
            break;
        float t = f4c - dt;
        f4c = t;
        f.W = DAT_004dd700->f20;
        if (f8 == 0)
            break;
        if (!(t <= 0.0f))
            break;
        f4c = f44;
        Y *y = DAT_004dd700->f44->FUN_00059ba0(f40);
        f.Zp = y->FUN_00059a30();
        if (f.Zp == 0)
            break;
        if (y == 0)
            break;
        if (!y->FUN_00059a50(&f.pos))
            break;
        u64 id = FUN_0027b020(name);
        f.R = DAT_004dd700->f28->FUN_001fc8c0(id);
        f.i = 0;
        if (f8->count <= 0)
            break;
        f.off = 0x460;
        bool finish = false;
        do {
            do {
                if (!(f52 & (1 << f.i)))
                    break;
                if (!((Entry *)((char *)f8 + f.off))->FUN_001f8aa0(f.Zp, f.R))
                    break;
                key.idx = (unsigned char)f.i;
                f.s10.i = f.W->FUN_00024b00(&key);
                short s = f8->FUN_001f9630(key);
                if (s == 0) {
                    if (f.s10.i != 0)
                        break;
                    b50 = 1;
                    Spawner *sp = DAT_004dd700->f30;
                    if (sp == 0)
                        break;
                    f.q.FUN_001ca000(f8->name, name);
                    sp->FUN_001cbc20(&f.q);
                    break;
                }
                if (!(s > 0 || s == -1 || s == -2))
                    break;

                Cfg *c = f8;
                f.strike = memcmp(c->name, "strike_team", 12) == 0;
                Entry *E = (Entry *)((char *)c + f.off);
                char *entryName = E->obj->FUN_00044400();
                FUN_00267760(f.buf1, 0x100, "%s+%s+%d+%s", f8->name, name, f.i, entryName);
                if (f.s10.i >= E->f4)
                    break;
                f.n = E->f8 - f.s10.i;
                if (s > 0 && f.n > s)
                    f.n = s;
                f.r2 = FUN_001f8b40(E->f10, f.R, f.pos);
                if (f.r2 == 0 || f.r2 == f.R) {
                    if (f.strike) {
                        int j;
                        for (j = 1; j < 6; j++) {
                            f.r2 = FUN_001f8b40(j, f.R, f.pos);
                            if (f.r2 != 0 && f.r2 != f.R)
                                break;
                        }
                    }
                }
                if (f.r2 == 0) {
                    finish = true;
                    break;
                }
                f.r2->v8(&f.v40);
                f.rr = f.r2->v9();
                if (!f.strike) {
                    f.d.x = f.v40.x - f.pos.x;
                    f.d.y = f.v40.y - f.pos.y;
                    f.d.z = f.v40.z - f.pos.z;
                    f.s10.f = f.d.FUN_00018990();
                    Zone *zone = DAT_004dd700->f8;
                    char near_ = zone->FUN_00099d60(f.v40.x, f.v40.y, f.v40.z, 1.0f, 0);
                    float thr = near_ ? 70.0f : 20.0f;
                    if (f.s10.f < thr) {
                        finish = true;
                        break;
                    }
                }

                if (f.n > 0) {
                    do {
                        int k = 0;
                        Actor *a;
                        int r3;
                        for (;;) {
                            if (s != -1 && s != -2)
                                FUN_00267760(f.buf2, 0x100, "%s+%d.%d", f.buf1, (int)s, k);
                            else
                                FUN_00267760(f.buf2, 0x100, "%s+%d", f.buf1, k);
                            u64 hid = FUN_002672f0(f.buf2, 0, 0);
                            a = f.W->FUN_00024280(hid);
                            f.nm.FUN_0027b0e0(f.buf2);
                            r3 = FUN_001c3d90()->f0c->FUN_001c59d0(&f.nm);
                            f.nm.FUN_0027af50();
                            k++;
                            if (a == 0 && r3 == 0)
                                break;
                        }
                        float ang = DAT_004e58e0;
                        f.tmp.x = 2.0f;
                        f.tmp.y = 0.0f;
                        f.tmp.z = 0.0f;
                        FUN_00224d70(ang, &f.tmp);
                        f.tmp.x = f.tmp.x + f.v40.x;
                        f.tmp.y = f.tmp.y + f.v40.y;
                        f.tmp.z = f.tmp.z + f.v40.z;
                        DAT_004e58e0 = DAT_004e58e0 + 1.7453293f;
                        DAT_004e58e0 = FUN_0004af40(0, 6.2831855f, DAT_004e58e0);
                        if (!f.W->FUN_0002bf80(E->obj->FUN_00044360(), f.tmp, f.rr, name, "none", 0, f.buf2))
                            continue;
                        if (s > 0)
                            s = s - 1;
                        Actor *na = f.W->FUN_000259f0(f.buf2);
                        if (na == 0)
                            continue;
                        f.R->v8(&f.v68);
                        na->FUN_00037180(f.v68);
                        na->FUN_000371b0(E->f1c);
                        na->FUN_0003ec70(&key);
                        na->FUN_00037160(E->f14);
                        na->FUN_00037170(E->f18);
                        na->f1d7c = f8->f454;
                        Inst *inst = FUN_001d4c90();
                        if (inst == 0)
                            continue;
                        if (!inst->FUN_001d1cb0())
                            continue;
                        char nb = inst->FUN_001d2ba0("newborn", 0, 1);
                        f.strike = nb;
                        if (nb) {
                            inst->FUN_001d1d50("name", f.buf2);
                            inst->FUN_001d1d50("locator_eg", name);
                            inst->FUN_001d1d50("locator_spawn", (const void *)f.r2->FUN_001fba60());
                            inst->FUN_001d19d0(1);
                        }
                        inst->FUN_001d1d30();
                        if (!nb)
                            continue;
                        if (inst->FUN_001d1930(f8->f448))
                            inst->FUN_001d2b10(-1, -1);
                        if (inst->FUN_001d1930(E->f20))
                            inst->FUN_001d2b10(-1, -1);
                    } while (--f.n != 0);
                }
                if (s >= 0)
                    f8->FUN_001f9670(key, s);
            } while (0);
            if (finish)
                break;
            f.i++;
            f.off += 0x28;
        } while (f.i < f8->count);
    } while (0);
    __security_check_cookie(f.cookie);
}
