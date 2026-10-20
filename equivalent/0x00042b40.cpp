// STATUS: equivalent (tools/equiv.py level 3: 1716 inputs, branch coverage 74/74)
// FUN_00042b40 @ 0x00042b40
// cl-flags: /GS
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"

void *thunk_FUN_0008d690(unsigned int size);
void *__cdecl FUN_0008d690(hulk_uintptr size);
extern int __cdecl FUN_00267760(char *buf, int size, const char *fmt, ...);

struct V3_42b40 { float x, y, z; };

struct Mat_42b40 {
    float m[16];
    void FUN_0022b980();
    void FUN_0022bc20(float x, float y, float z);
};

struct Str_42b40 {
    char data[8];
    void FUN_0027af10(int a, int b);
    void FUN_0027af50();
    void FUN_0027af60(int a, int b);
    void FUN_0027af70(Str_42b40 *s);
};

class RefObj_42b40 {
public:
    virtual void AddRef();
    virtual void Release();
};

struct Skel_42b40 {
    int FUN_0027b200(unsigned __int64 key);
    int FUN_00034ce0(const char *s);
    RefObj_42b40 *FUN_0027b240();
};

struct Mat0x10 {
    Mat_42b40 *FUN_00221c40();
};

struct P18_42b40 {
    char pad00[0x10];
    Mat0x10 m10;
};

struct Pair_42b40 { int a; int b; };

class RigBase : public RefObj_42b40 {};
struct RigSub;
class Rig_42b40 : public RefObj_42b40 {
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
    V3_42b40 v38;
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
    V3_42b40 *FUN_00044360();
    Skel_42b40 *FUN_00044410();
    int FUN_000446c0(int i);
    unsigned __int64 FUN_000446e0(int i);
    V3_42b40 *FUN_00044710(V3_42b40 *out, int i);
    V3_42b40 *FUN_00044760(V3_42b40 *out, int i);
};

struct RigSub { char pad[8]; int f8; int fc; };

struct Gadget_42b40 {
    void FUN_002f2700(int a);
    void FUN_002f2730(float a);
};

struct EntrySub {
    char pad00[0x10];
    Str_42b40 s10;
    char pad18[0x1c - 0x18];
    Gadget_42b40 *g;
    char pad20[0x70 - 0x20];
    char b70;
    char pad71;
    char b72;
};

struct Chara_42b40;

struct Entry_42b40 {
    char pad00[8];
    Chara_42b40 *owner;
    int kind;
    char pad10[0x74 - 0x10];
    EntrySub *sub;
};

struct Obj2f0 { Obj2f0 *FUN_00222620(hulk_intptr a); };
struct Obj48 { Obj48 *FUN_002efe50(V3_42b40 *a, float b); };
struct Obj8c_42b40 { Obj8c_42b40 *FUN_002f3070(V3_42b40 *a, V3_42b40 *b, float c, float d, int e); };

struct Link10 {
    void FUN_00059d00(Obj2f0 *o);
    P18_42b40 *FUN_00059a40();
};

struct Node10 {
    char pad00[0x20];
    char b20;
    void FUN_001c5050(int a);
};
struct Node124_42b40 {
    char pad00[0x10];
    Node10 *f10;
    void FUN_001c5e20(RefObj_42b40 *a);
};

struct Dir_42b40 {
    void FUN_00065cb0(Pair_42b40 *p);
    Dir_42b40 *FUN_001c3d90();
    void FUN_001c3b30(Str_42b40 *s);
    Node124_42b40 *FUN_001c3b20(Str_42b40 *a, Str_42b40 *b);
};
Dir_42b40 *FUN_001c3d90();

struct Obj128_42b40;
struct Reg_42b40 {
    Obj128_42b40 *FUN_001e4ae0(const char *name, V3_42b40 *a, V3_42b40 *b, int c, int d, int e);
    Obj128_42b40 *FUN_001e4760(int obj, char *name, int a, Mat_42b40 *m, int b, int c, int d);
};

struct World {
    char pad00[0xc];
    Reg_42b40 *f0c;
};

struct Obj128_42b40 {
    virtual void AddRef();
    virtual void Release();
    char pad04[0x11c - 4];
    struct Rig2 *f11c;
    char pad120[0x148 - 0x120];
    Chara_42b40 *f148;
    char pad14c[0x1d8 - 0x14c];
    char b1d8;
    int FUN_001d68d0();
};

struct Rig2 { char pad00[0x18]; hulk_intptr f18; };

struct Sink284 { void FUN_00284820(int a); };

struct Holder_42b40 { Dir_42b40 *FUN_000678d0(); };

struct Mgr_42b40 { Mgr_42b40 *FUN_001b6580(); void FUN_001b4060(Chara_42b40 *c); void FUN_001b4540(Obj128_42b40 *o); void FUN_001b4450(Obj128_42b40 *o, int a); };

Entry_42b40 *__cdecl FUN_002efca0(void *obj, char *name);
void __cdecl FUN_00018810(RefObj_42b40 **slot, Entry_42b40 *e);
void __cdecl FUN_00037510(RefObj_42b40 **slot, RefObj_42b40 *r);
Dir_42b40 *FUN_000678d0();
Mgr_42b40 *FUN_001b6580();

struct Chara_42b40 {
    char pad00[8];
    int f8;
    int fc;
    Link10 *f10;
    char pad14[0x11c - 0x14];
    Rig_42b40 *rig;
    RefObj_42b40 *f120;
    Node124_42b40 *f124;
    Obj128_42b40 *f128;
    RefObj_42b40 *f12c;
    RefObj_42b40 *f130;
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
    void FUN_00035190(Mat_42b40 *m);
    void FUN_000401a0();
    void FUN_0003acf0(int a, hulk_intptr b, int c, int d, int e, Mat_42b40 *m);
    char Setup(Rig_42b40 *r);
};

char Chara_42b40::Setup(Rig_42b40 *r)
{
    World *world = DAT_004dd700;
    if (rig == r) {
        return 1;
    }
    Mat_42b40 m44;
    m44.FUN_0022b980();
    P18_42b40 *p = f10->FUN_00059a40();
    if (p) {
        Mat_42b40 *src = p->m10.FUN_00221c40();
        m44 = *src;
    }
    FUN_0003b620(1);
    f10->FUN_00059d00(0);
    if (f124 != 0) {
        Str_42b40 s1;
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
        return 1;
    }
    Skel_42b40 *sk = r->FUN_00044410();
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
        Reg_42b40 *reg = world->f0c;
        f128 = reg->FUN_001e4ae0(name, rig->FUN_00044360(), rig->FUN_00044360(), 1, 0, 0);
        if (f128) {
            f128->AddRef();
            f128->b1d8 = 1;
            FUN_00037510(&f120, (RefObj_42b40 *)f128->f11c->f18);
        } else {
            FUN_00037510(&f120, sk->FUN_0027b240());
            Str_42b40 sa;
            sa.FUN_0027af10(rig->f8->f8, rig->f8->fc);
            Str_42b40 sb;
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
            eo = o2f0->FUN_00222620((hulk_intptr)f120);
        else
            eo = 0;
        ((Str_42b40 *)((char *)eo + 8))->FUN_0027af70((Str_42b40 *)&f8);
        f10->FUN_00059d00(eo);
        FUN_00035190(&m44);

        float f34 = rig->f34;
        float rr = rig->f30 * 0.5f - f34;
        V3_42b40 vA = rig->v38;
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
            Obj8c_42b40 *o8c = (Obj8c_42b40 *)FUN_0008d690(0x8c);
            if (o8c) {
                V3_42b40 up;
                up.x = 0;
                up.y = 1.0f;
                up.z = 0;
                made = o8c->FUN_002f3070(&vA, &up, rr, f34, bu.i);
            } else {
                made = 0;
            }
        }
        Entry_42b40 *e = FUN_002efca0(made, 0);
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
                ob = o48->FUN_002efe50((V3_42b40 *)rig->f300, rig->f2fc);
            else
                ob = 0;
            char buf[0x40];
            FUN_00267760(buf, 0x40, "%s_csm", name);
            Entry_42b40 *e2 = FUN_002efca0(ob, buf);
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
        Mat_42b40 m88;
        m88.FUN_0022b980();
        char buf[0x100];
        FUN_00267760(buf, 0x100, "%s_attachedprop_%d", name, DAT_004dc300);
        Reg_42b40 *reg = world->f0c;
        int cnt = DAT_004dc300;
        DAT_004dc300 = cnt + 1;
        Obj128_42b40 *po = reg->FUN_001e4760(pr, buf, 0, &m88, 1, 0, 0);
        if (po == 0)
            continue;
        po->b1d8 = 1;
        hulk_intptr tp = po->FUN_001d68d0();
        if (tp)
            ((Sink284 *)tp)->FUN_00284820(0);
        int bone = 0;
        if (sk) {
            bone = sk->FUN_0027b200(rig->FUN_000446e0(i));
            if (bone == 0xffff)
                bone = 0;
        }
        Mat_42b40 mc8;
        mc8.FUN_0022b980();
        V3_42b40 t1;
        V3_42b40 *tr = rig->FUN_00044760(&t1, i);
        mc8.FUN_0022bc20(tr->x, tr->y, tr->z);
        V3_42b40 t2;
        V3_42b40 *tr2 = rig->FUN_00044710(&t2, i);
        mc8.m[12] = tr2->x;
        mc8.m[13] = tr2->y;
        mc8.m[14] = tr2->z;
        FUN_0003acf0(i, (hulk_intptr)po, bone, 0, 0, &mc8);
    }

    Rig_42b40 *c = rig;
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
        Pair_42b40 ps;
        ps.a = f8;
        ps.b = fc;
        FUN_000678d0()->FUN_00065cb0(&ps);
    }
    return 1;
}
