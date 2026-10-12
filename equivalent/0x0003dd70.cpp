// STATUS: equivalent (tools/equiv.py level 3: 3028 inputs, branch coverage 68/70, incomplete)
// FUN_0003dd70 @ 0x0003dd70
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
void *FUN_0008d690(unsigned int size);

struct V3 {
    union {
        float x;
        int ix;
    };
    union {
        float y;
        int iy;
    };
    union {
        float z;
        int iz;
    };
    float FUN_000111f0();
};

struct Mat {
    float m[16];
    void FUN_0022b980();
};

struct Id64 {
    unsigned int lo;
    unsigned int hi;
};

class Releasable {
public:
    virtual void v0();
    virtual void v1();
};

struct Desc {
    char pad0[0x28];
    V3 rel;
    char pad34[0x5c - 0x34];
    float f5c;
    char pad60[0x98 - 0x60];
    void FUN_00059820();
    void FUN_00059300();
};

struct Obj2 : public Releasable {
    Obj2 *FUN_000598e0(void *a, Desc *d);
};

struct ListHead {
    void *first;
    void FUN_00232240();
};

class Emitter {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual Emitter *v8(Obj2 *o, int z);
    bool FUN_00231a40(ListHead *h, Obj2 *o);
    void FUN_00231ad0(ListHead *h, Obj2 *o, unsigned int flags);
};

struct Singleton {
    void FUN_00283a40(const Id64 *id, Mat *m, float a, float b);
};
Singleton *FUN_0027f250();

extern "C" float __cdecl FUN_000186b0(float *a, float *b, float *c);
extern "C" int __cdecl FUN_00266da0(int v);

struct Pool {
    int first;
    void FUN_00059a50(V3 *out);
};

struct P11c {
    char pad0[0x1c];
    float f1c;
    char pad20[0x30 - 0x20];
    float f30;
    char pad34[0x104 - 0x34];
    Emitter *emit;
};

struct Cfg {
    char pad0[0x18];
    float lim;
    char pad1c[4];
    Id64 id;
    char name[1];
};

class Finder {
public:
    char FUN_001fe380(V3 *o, V3 *out);
};

class Host;

struct Notify {
    void FUN_001ebfd0(Host *h, const char *s);
};

struct Target20 {
    char pad0[0x124];
    Host *host;
};

struct Arg0 {
    char pad0[0x20];
    Target20 *p20;
    Cfg *cfg;
    Finder *finder;
    char pad2c[0x34 - 0x2c];
    Notify *notify;
};

class Host {
public:
    char pad0[0x10];
    Pool *p10;
    char pad14[0x48 - 0x14];
    float t48;
    char pad4c[0x74 - 0x4c];
    V3 w74;
    char pad80[0xb4 - 0x80];
    ListHead l_b4;
    char padbc[0xdc - 0xb8];
    ListHead head;
    char pade4[0x11c - 0xe0];
    P11c *p11c;
    char pad120[0x140 - 0x120];
    int mode;
    char pad144[0x1a39 - 0x144];
    bool b1a39;
    char pad1a3a[2];
    V3 home;
    char pad1a48[0x1a88 - 0x1a48];
    float f1a88;
    char pad1a8c[0x22ec - 0x1a8c];
    V3 last;
    float t;
    void FUN_00037000();
    void FUN_0003dd70(Arg0 *a0, float dt);
};

struct Frame {
    float sc;       // S0
    float lim;      // S4
    V3 v;           // S8
    float vy;       // S20
    V3 d;           // S24
    float t48;      // S36
    union {         // S40
        float half;
        int saved;
    };
    V3 out;         // S44
    float four;     // S56
    Mat mat;        // S60
    Desc desc;      // S124
};

void Host::FUN_0003dd70(Arg0 *a0, float dt)
{
    if (p11c == 0)
        return;
    Frame f;
    t = dt + t;
    f.v.x = 0.0f;
    f.v.y = 0.0f;
    f.v.z = 0.0f;
    p10->FUN_00059a50(&f.v);
    float tcur = t;
    Cfg *cfg = a0->cfg;
    f.lim = cfg->lim;
    f.vy = f.v.y;
    f.t48 = t48;

    bool update = false;
    bool cross = false;
    if (tcur > 1.0f) {
        if (f.v.y <= f.lim) {
            if (f.t48 > f.lim)
                cross = true;
        }
        if (!cross) {
            if (f.v.y >= f.lim) {
                if (f.t48 < f.lim)
                    cross = true;
            }
        }
    }
    if (cross) {
        update = true;
    } else {
        float sumsq = (w74.x * w74.x + w74.y * w74.y) + w74.z * w74.z;
        if (sumsq > 0.0f) {
            P11c *pc = p11c;
            float s0 = pc->f30;
            float a;
            float s0v;
            if (mode > 0 && mode <= 2) {
                a = f.v.y;
                s0v = s0 + f.v.y;
            } else {
                s0 = s0 * 0.5f;
                a = f.v.y - s0;
                s0v = s0 + f.v.y;
            }
            f.sc = s0v;
            if (a < f.lim && s0v > f.lim) {
                if (t > 1.0f) {
                    update = true;
                } else {
                    f.d.x = last.x - f.v.x;
                    f.d.iy = 0;
                    f.d.z = last.z - f.v.z;
                    float c2 = pc->f30 + pc->f30;
                    f.sc = c2;
                    float len = f.d.FUN_000111f0();
                    if ((double)f.sc * (double)f.sc < (double)len)
                        update = true;
                }
            }
        }
    }

    if (update) {
        t = 0.0f;
        last.ix = f.v.ix;
        last.iy = f.v.iy;
        last.iz = f.v.iz;
        const Id64 *id = &cfg->id;
        if ((id->lo | id->hi) != 0) {
            Singleton *sg = FUN_0027f250();
            f.mat.FUN_0022b980();
            f.mat.m[12] = f.v.x;
            f.mat.m[13] = f.lim;
            f.mat.m[14] = f.v.z;
            float sc;
            if (p11c == 0) {
                sc = 1.0f;
            } else {
                float c1c = p11c->f1c;
                if (c1c < 1000.0f)
                    sc = c1c * 0.001f;
                else if (c1c < 10000.0f)
                    sc = (c1c - 1000.0f) * 0.00011111111f + 1.0f;
                else if (c1c < 100000.0f)
                    sc = ((c1c - 10000.0f) * 1.1111111e-05f + 1.0f) * 2.0f;
                else
                    sc = 4.0f;
            }
            f.sc = sc;
            f.four = 4.0f;
            f.half = 0.5f;
            float r = FUN_000186b0(&f.sc, &f.half, &f.four);
            f.sc = r;
            sg->FUN_00283a40(id, &f.mat, -1.0f, r);
        }
        const char *name = cfg->name;
        if (*name)
            a0->notify->FUN_001ebfd0(this, name);
    }

    if (a0->p20->host == this) {
        if (!(f.vy <= f.lim))
            return;
        if (!(f.vy < f.t48))
            return;
        if (b1a39) {
            if (!(f.lim - 10.0f > f1a88))
                return;
        }
    } else {
        if (!(f.vy <= f.lim))
            return;
        if (!(f.t48 > f.lim))
            return;
    }

    int saved = FUN_00266da0(0xd);
    Emitter *emit = p11c->emit;
    if (emit != 0) {
        bool found = false;
        void *cur = head.first;
        while (cur != 0) {
            if (cur == (void *)emit) {
                found = true;
                break;
            }
            cur = *(void **)((char *)cur + 0x14);
        }
        if (!found) {
            f.d.ix = home.ix;
            f.d.iy = home.iy;
            f.d.iz = home.iz;
            f.out.x = 0.0f;
            f.out.y = 0.0f;
            f.out.z = 0.0f;
            if (a0->finder->FUN_001fe380(&f.v, &f.out)) {
                f.d.ix = f.out.ix;
                f.d.iy = f.out.iy;
                f.d.iz = f.out.iz;
            }
            f.desc.FUN_00059820();
            f.desc.rel.x = f.d.x - f.v.x;
            f.desc.f5c = 1.0f;
            f.desc.rel.y = f.d.y - f.v.y;
            f.desc.rel.z = f.d.z - f.v.z;
            void *mem = FUN_0008d690(0xb0);
            Obj2 *o = 0;
            if (mem)
                o = ((Obj2 *)mem)->FUN_000598e0(*(void **)p10, &f.desc);
            o->v0();
            Emitter *em2 = emit->v8(o, 0);
            if (em2 != 0) {
                if (em2->FUN_00231a40(&head, o)) {
                    head.FUN_00232240();
                    FUN_00037000();
                    l_b4.FUN_00232240();
                }
                em2->FUN_00231ad0(&head, o, 0x80000000u);
            }
            o->v1();
            f.desc.FUN_00059300();
        }
    }
    FUN_00266da0(saved);
}
