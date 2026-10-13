// STATUS: equivalent (tools/equiv.py level 3: 957 inputs, branch coverage 74/74)
// FUN_00042b40 @ 0x00042b40
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
extern unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern int DAT_004dc300;

void *thunk_FUN_0008d690(unsigned int size);
void *__cdecl FUN_0008d690(unsigned int size);
extern int __cdecl FUN_00267760(char *buf, int size, const char *fmt, ...);
unsigned __int64 __cdecl FUN_002672f0(const char *s, unsigned int lo, unsigned int hi);

struct V3 { float x, y, z; };

struct Mat {
    float m[16];
    void FUN_0022b980();
    void FUN_0022bc20(float x, float y, float z);
};

struct Str {
    char data[8];
    void FUN_0027af10(int a, int b);
    void FUN_0027af50();
    void FUN_0027af60(int a, int b);
    void FUN_0027af70(Str *s);
};

class RefObj {
public:
    virtual void AddRef();
    virtual void Release();
};

struct Skel {
    int FUN_0027b200(unsigned __int64 key);
    int FUN_00034ce0(const char *s);
    RefObj *FUN_0027b240();
};

struct Mat0x10 {
    Mat *FUN_00221c40();
};

struct P18 {
    char pad00[0x10];
    Mat0x10 m10;
};

struct Pair { int a; int b; };

class RigBase : public RefObj {};
struct RigSub;
class Rig : public RefObj {
public:
    char pad04[4];
    RigSub *f8;
    int fc;
    char pad10[4];
    int f14;
    char pad18[0x2c - 0x18];
    int f2c;
    float f30;
    float f34;
    V3 v38;
    char pad44[0x2f8 - 0x44];
    char b2f8;
    char pad2f9[3];
    float f2fc;
    char f300[0x2c];
    int w32c[9];
    char pad350[0x35c - 0x350];
    int w35c[8];
    unsigned char b37c;
    char pad37d;
    unsigned char b37e;
    unsigned char b37f;
    char pad380[4];
    unsigned char b384;
    char pad385[3];
    int w388;
    char pad38c[0x3b0 - 0x38c];
    V3 *FUN_00044360();
    Skel *FUN_00044410();
    int FUN_000446c0(int i);
    unsigned __int64 FUN_000446e0(int i);
    V3 *FUN_00044710(V3 *out, int i);
    V3 *FUN_00044760(V3 *out, int i);
};

struct RigSub { char pad[8]; int f8; int fc; };

struct Gadget {
    void FUN_002f2700(int a);
    void FUN_002f2730(float a);
};

struct EntrySub {
    char pad00[0x10];
    Str s10;
    char pad18[0x1c - 0x18];
    Gadget *g;
    char pad20[0x70 - 0x20];
    char b70;
    char pad71;
    char b72;
};

struct Chara;

struct Entry {
    char pad00[8];
    Chara *owner;
    int kind;
    char pad10[0x74 - 0x10];
    EntrySub *sub;
};

struct Obj2f0 { Obj2f0 *FUN_00222620(int a); };
struct Obj48 { Obj48 *FUN_002efe50(V3 *a, float b); };
struct Obj8c { Obj8c *FUN_002f3070(V3 *a, V3 *b, float c, float d, int e); };

struct Link10 {
    void FUN_00059d00(Obj2f0 *o);
    P18 *FUN_00059a40();
};

struct Node10 {
    char pad00[0x20];
    char b20;
    void FUN_001c5050(int a);
};
struct Node124 {
    char pad00[0x10];
    Node10 *f10;
    void FUN_001c5e20(RefObj *a);
};

struct Dir {
    void FUN_00065cb0(Pair *p);
    Dir *FUN_001c3d90();
    void FUN_001c3b30(Str *s);
    Node124 *FUN_001c3b20(Str *a, Str *b);
};
Dir *FUN_001c3d90();

struct Obj128;
struct Reg {
    Obj128 *FUN_001e4ae0(const char *name, V3 *a, V3 *b, int c, int d, int e);
    Obj128 *FUN_001e4760(int obj, char *name, int a, Mat *m, int b, int c, int d);
};

struct World {
    char pad00[0xc];
    Reg *f0c;
};

struct Obj128 {
    virtual void AddRef();
    virtual void Release();
    char pad04[0x11c - 4];
    struct Rig2 *f11c;
    char pad120[0x148 - 0x120];
    Chara *f148;
    char pad14c[0x1d8 - 0x14c];
    char b1d8;
    int FUN_001d68d0();
};

struct Rig2 { char pad00[0x18]; int f18; };

struct Sink284 { void FUN_00284820(int a); };

struct Holder { Dir *FUN_000678d0(); };

struct Mgr { Mgr *FUN_001b6580(); void FUN_001b4060(Chara *c); void FUN_001b4540(Obj128 *o); void FUN_001b4450(Obj128 *o, int a); };

extern World *DAT_004dd700;
Entry *__cdecl FUN_002efca0(void *obj, char *name);
void __cdecl FUN_00018810(RefObj **slot, Entry *e);
void __cdecl FUN_00037510(RefObj **slot, RefObj *r);
Dir *FUN_000678d0();
Mgr *FUN_001b6580();

struct Chara {
    char pad00[8];
    int f8;
    int fc;
    Link10 *f10;
    char pad14[0x11c - 0x14];
    Rig *rig;
    RefObj *f120;
    Node124 *f124;
    Obj128 *f128;
    RefObj *f12c;
    RefObj *f130;
    char pad134[0x148 - 0x134];
    int f148;
    char pad14c[0x1b0c - 0x14c];
    float f1b0c;
    char pad1b10[0x1ca8 - 0x1b10];
    int w1ca8[9];
    int w1ccc[8];
    unsigned char b1cec;
    unsigned char b1ced;
    unsigned char b1cee;
    unsigned char b1cef;
    int w1cf0;
    char pad1cf4[0x1e48 - 0x1cf4];
    float f1e48;
    char pad1e4c[0x1f54 - 0x1e4c];
    int f1f54;
    char pad1f58[0x20b8 - 0x1f58];
    char name[0x40];
    void FUN_0003b620(int a);
    void FUN_00035190(Mat *m);
    void FUN_000401a0();
    void FUN_0003acf0(int a, int b, int c, int d, int e, Mat *m);
    char Setup(Rig *r);
};

char Chara::Setup(Rig *r)
{
    unsigned int cookie = DAT_004d9968;
    World *world = DAT_004dd700;
    if (rig == r) {
        __security_check_cookie(cookie);
        return 1;
    }
    Mat m44;
    m44.FUN_0022b980();
    P18 *p = f10->FUN_00059a40();
    if (p) {
        Mat *src = p->m10.FUN_00221c40();
        m44 = *src;
    }
    FUN_0003b620(1);
    f10->FUN_00059d00(0);
    if (f124 != 0) {
        Str s1;
        s1.FUN_0027af10(f8, fc);
        FUN_001c3d90()->FUN_001c3b30(&s1);
        s1.FUN_0027af50();
        f124 = 0;
    }
    if (f120) {
        f120->Release();
        f120 = 0;
    }
    if (f130) {
        f130->Release();
        f130 = 0;
    }
    if (f12c) {
        f12c->Release();
        f12c = 0;
    }
    if (r)
        r->AddRef();
    if (rig)
        rig->Release();
    rig = r;
    if (!r) {
        __security_check_cookie(cookie);
        return 1;
    }
    Skel *sk = r->FUN_00044410();
    if (sk) {
        f1f54 = sk->FUN_0027b200(FUN_002672f0("Head", 0, 0));
        if (f1f54 == 0xffff) {
            f1f54 = sk->FUN_00034ce0("Neck");
            if (f1f54 == 0xffff) {
                f1f54 = sk->FUN_00034ce0("turret");
                if (f1f54 == 0xffff)
                    f1f54 = 0;
            }
        }
        Reg *reg = world->f0c;
        f128 = reg->FUN_001e4ae0(name, rig->FUN_00044360(), rig->FUN_00044360(), 1, 0, 0);
        if (f128) {
            f128->AddRef();
            f128->b1d8 = 1;
            FUN_00037510(&f120, (RefObj *)f128->f11c->f18);
        } else {
            FUN_00037510(&f120, sk->FUN_0027b240());
            Str sa;
            sa.FUN_0027af10(rig->f8->f8, rig->f8->fc);
            Str sb;
            sb.FUN_0027af10(f8, fc);
            f124 = FUN_001c3d90()->FUN_001c3b20(&sb, &sa);
            sb.FUN_0027af50();
            sa.FUN_0027af50();
            if (f124) {
                f124->FUN_001c5e20(f120);
                Node10 *n10 = f124->f10;
                int v = rig->fc;
                if (n10) {
                    n10->FUN_001c5050(v);
                    n10->b20 = (v == 0);
                }
            }
        }

        Obj2f0 *o2f0 = (Obj2f0 *)thunk_FUN_0008d690(0x2f0);
        Obj2f0 *eo;
        if (o2f0)
            eo = o2f0->FUN_00222620((int)f120);
        else
            eo = 0;
        ((Str *)((char *)eo + 8))->FUN_0027af70((Str *)&f8);
        f10->FUN_00059d00(eo);
        FUN_00035190(&m44);

        float f34 = rig->f34;
        float rr = rig->f30 * 0.5f - f34;
        V3 vA = rig->v38;
        vA.z = -vA.z;
        vA.y = vA.y + rr + f34;
        void *made;
        if (rr < 0.0f) {
            Obj48 *o48 = (Obj48 *)FUN_0008d690(0x48);
            if (o48)
                made = o48->FUN_002efe50(&vA, f34);
            else
                made = 0;
        } else {
            union { char c; int i; } bu;
            bu.c = 0;
            if (rig->f14 == 2 || rig->f14 == 3) {
                bu.c = 1;
                rr = rr + f34;
            }
            Obj8c *o8c = (Obj8c *)FUN_0008d690(0x8c);
            if (o8c) {
                V3 up;
                up.x = 0;
                up.y = 1.0f;
                up.z = 0;
                made = o8c->FUN_002f3070(&vA, &up, rr, f34, bu.i);
            } else {
                made = 0;
            }
        }
        Entry *e = FUN_002efca0(made, 0);
        if (e) {
            EntrySub *es = e->sub;
            es->g->FUN_002f2700(0);
            es->g->FUN_002f2730(1.0f);
            es->b70 = 1;
            es->s10.FUN_0027af60(0x29a, 0);
            e->kind = 1;
            e->owner = this;
            FUN_00018810(&f12c, e);
        }
        if (rig->b2f8) {
            Obj48 *o48 = (Obj48 *)FUN_0008d690(0x48);
            Obj48 *ob;
            if (o48)
                ob = o48->FUN_002efe50((V3 *)rig->f300, rig->f2fc);
            else
                ob = 0;
            char buf[0x40];
            FUN_00267760(buf, 0x40, "%s_csm", name);
            Entry *e2 = FUN_002efca0(ob, buf);
            if (e2) {
                EntrySub *es = e2->sub;
                es->b70 = 1;
                es->b72 = 0;
                es->s10.FUN_0027af60(0x309, 0);
                e2->kind = 2;
                e2->owner = this;
                FUN_00018810(&f130, e2);
            }
        }
        FUN_001b6580()->FUN_001b4060(this);
        if (f128) {
            f128->f148 = this;
            FUN_001b6580()->FUN_001b4540(f128);
            FUN_001b6580()->FUN_001b4450(f128, 0);
        }
    }

    f148 = rig->f2c;
    if (f1b0c < 0.0f)
        FUN_000401a0();
    for (int i = 0; i < 8; i++) {
        int pr = rig->FUN_000446c0(i);
        if (pr == 0)
            continue;
        Mat m88;
        m88.FUN_0022b980();
        char buf[0x100];
        FUN_00267760(buf, 0x100, "%s_attachedprop_%d", name, DAT_004dc300);
        Reg *reg = world->f0c;
        int cnt = DAT_004dc300;
        DAT_004dc300 = cnt + 1;
        Obj128 *po = reg->FUN_001e4760(pr, buf, 0, &m88, 1, 0, 0);
        if (po == 0)
            continue;
        po->b1d8 = 1;
        int tp = po->FUN_001d68d0();
        if (tp)
            ((Sink284 *)tp)->FUN_00284820(0);
        int bone = 0;
        if (sk) {
            bone = sk->FUN_0027b200(rig->FUN_000446e0(i));
            if (bone == 0xffff)
                bone = 0;
        }
        Mat mc8;
        mc8.FUN_0022b980();
        V3 t1;
        V3 *tr = rig->FUN_00044760(&t1, i);
        mc8.FUN_0022bc20(tr->x, tr->y, tr->z);
        V3 t2;
        V3 *tr2 = rig->FUN_00044710(&t2, i);
        mc8.m[12] = tr2->x;
        mc8.m[13] = tr2->y;
        mc8.m[14] = tr2->z;
        FUN_0003acf0(i, (int)po, bone, 0, 0, &mc8);
    }

    Rig *c = rig;
    if (c->f14 == 0)
        f1e48 = 100000.0f;
    for (int i = 0; i < 9; i++)
        w1ca8[i] = c->w32c[i];
    for (int i = 0; i < 8; i++)
        w1ccc[i] = c->w35c[i];
    b1cec = c->b37c;
    b1ced = c->b37e;
    b1cee = c->b37f;
    b1cef = c->b384;
    w1cf0 = c->w388;
    if (b1cee) {
        Pair ps;
        ps.a = f8;
        ps.b = fc;
        FUN_000678d0()->FUN_00065cb0(&ps);
    }
    __security_check_cookie(cookie);
    return 1;
}
