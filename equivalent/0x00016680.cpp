// STATUS: equivalent (tools/equiv.py level 3: 3026 inputs, branch coverage 37/39, incomplete)
// CEffectAction::vfunc_6 @ 0x00016680
struct V3 {
    float x, y, z;
    char FUN_0022d2b0(const V3 *other, float eps);
};

struct Name {
    unsigned int lo, hi;
};

struct Mat4 {
    float m[16];
    void FUN_0022b980();
    void FUN_0022be40(V3 *t);
    void FUN_0022bc20(float x, float y, float z);
    void FUN_0022ca90(Mat4 *a, Mat4 *b);
    void FUN_0022c120();
};

void FUN_00224db0(Mat4 *m, V3 *up, V3 *fwd);

struct Lookup {
    char pad0[0x1c];
    char *base;
    int FUN_002843a0(unsigned int lo, unsigned int hi);
};

struct Agent {
    char pad0[0x120];
    Lookup *p120;
    char pad124[0x1a4c - 0x124];
    int f1a4c;
    void FUN_00035160(Mat4 *out);
    int FUN_00036c60(int a);
    void FUN_00036c40(int a, int b);
};

struct Fx {
    int FUN_00283a40(Name *id, Mat4 *m, float v, int f58);
    int FUN_00283b10(Name *id, Lookup *lk, Name *id2, Mat4 *m, float v, int f58);
    int FUN_00283be0(Name *id, Lookup *lk, float v, int f58);
    void FUN_0027ffb0(int a);
};
Fx *FUN_0027f250();

struct Obj3 {
    char pad0[8];
    V3 v8;
    char pad14[0x18 - 0x14];
    V3 v18;
};

class Src {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual Obj3 *s3();
    Agent *FUN_000592a0x();
};
struct Mid {
    Agent *FUN_00059a30();
};
struct Top {
    Mid *FUN_000592a0();
};

class Params {
public:
    virtual void p0();
    virtual void p1();
    virtual void p2();
    virtual void p3();
    virtual void p4();
    virtual void p5();
    virtual float p6();
    char pad04[0xc];
    float f10;
    char pad14[4];
    Name id18;
    int t1;
    int t2;
    Name id28;
    Name id30;
    V3 pos;
    V3 rot;
    char b50;
    char b51;
    char pad52[2];
    int f54;
    int f58;
};

struct Hub20 {
    void FUN_00025590(Obj3 *r, Name *a, int f58, Name *b, int f58b, Mat4 *m, float v, int f54);
};
struct Hub {
    char pad0[0x20];
    Hub20 *p20;
};
extern Hub *DAT_004dd700;

class CEffectAction {
public:
    char pad0[0x1c];
    Src *p1c;
    Params *p20;
    char pad24[4];
    int f28;
    char F(int unused);
};

char CEffectAction::F(int unused)
{
    struct Frame {
        int f0c;
        float v;
        int spill;
        V3 W;
        Mat4 Mb;
        V3 T4;
        V3 U;
        V3 T5;
        V3 T1;
        V3 T6;
        V3 Vup2;
        V3 T3;
        V3 Vup;
        V3 T2;
        Mat4 Mc;
        Mat4 M1;
    } fr;

    Agent *ag = ((Top *)p1c)->FUN_000592a0()->FUN_00059a30();
    Fx *fx = FUN_0027f250();
    fr.spill = (int)fx;
    unsigned int t1 = p20->t1;
    if (t1 > 4) {
    } else if (t1 == 0) {
        fr.M1.FUN_0022b980();
        fr.T1 = p20->pos;
        fr.M1.FUN_0022be40(&fr.T1);
        V3 r = p20->rot;
        fr.M1.FUN_0022bc20(r.x, r.y, r.z);
    } else if (t1 == 1 || t1 == 2 || t1 == 3) {
        bool useVcall = false;
        Obj3 *o3 = 0;
        if (t1 == 3) {
            o3 = p1c->s3();
            if (o3 != 0)
                useVcall = true;
        }
        if (!useVcall) {
            fr.Mb.FUN_0022b980();
            V3 *tb = (t1 == 1) ? &fr.T2 : ((t1 == 2) ? &fr.T3 : &fr.T4);
            *tb = p20->pos;
            fr.Mb.FUN_0022be40(tb);
            V3 r = p20->rot;
            fr.Mb.FUN_0022bc20(r.x, r.y, r.z);
            Mat4 *second = 0;
            bool found = false;
            if (t1 == 2) {
                if (&p20->id28 != 0) {
                    int idx = ag->p120->FUN_002843a0(p20->id28.lo, p20->id28.hi);
                    if (idx != 0xffff) {
                        second = (Mat4 *)(ag->p120->base + idx * 64);
                        found = true;
                    }
                }
            }
            if (!found) {
                ag->FUN_00035160(&fr.Mc);
                second = &fr.Mc;
            }
            fr.M1.FUN_0022ca90(&fr.Mb, second);
        } else {
            fr.U = o3->v8;
            fr.W = o3->v18;
            fr.Mb.FUN_0022b980();
            fr.Vup.x = 0;
            fr.Vup.y = 1.0f;
            fr.Vup.z = 0;
            if (!fr.W.FUN_0022d2b0(&fr.Vup, 1.0e-5f)) {
                fr.Vup2.x = 0;
                fr.Vup2.y = 1.0f;
                fr.Vup2.z = 0;
                FUN_00224db0(&fr.Mb, &fr.Vup2, &fr.W);
            }
            fr.Mb.FUN_0022be40(&fr.U);
            fr.Mc.FUN_0022b980();
            fr.T5 = p20->pos;
            fr.Mc.FUN_0022be40(&fr.T5);
            V3 r = p20->rot;
            fr.Mc.FUN_0022bc20(r.x, r.y, r.z);
            fr.M1.FUN_0022ca90(&fr.Mc, &fr.Mb);
        }
    } else {
        fr.Mc.FUN_0022b980();
        fr.T6 = p20->pos;
        fr.Mc.FUN_0022be40(&fr.T6);
        V3 r = p20->rot;
        fr.Mc.FUN_0022bc20(r.x, r.y, r.z);
        ag->FUN_00035160(&fr.Mb);
        *(int *)&fr.Mb.m[13] = ag->f1a4c;
        fr.M1.FUN_0022ca90(&fr.Mc, &fr.Mb);
    }
    Params *P = p20;
    fr.f0c = *(int *)&P->f10;
    fr.v = *(float *)&fr.f0c - P->p6();
    P = p20;
    fr.f0c = P->f58;
    if (P->b51 || P->b50)
        fr.v = -1.0f;
    unsigned int t2 = P->t2;
    int res = 0;
    bool setf28 = true;
    switch (t2) {
    case 0:
        if (P->t1 == 3 && !P->b51 && !P->b50 && p1c->s3() != 0) {
            Obj3 *o = p1c->s3();
            Params *pp = p20;
            DAT_004dd700->p20->FUN_00025590(o, (Name *)&pp->id18, fr.f0c, (Name *)&pp->id18, fr.f0c, &fr.M1,
                                            fr.v, pp->f54);
            f28 = 0;
            setf28 = false;
        } else {
            res = fx->FUN_00283a40(&p20->id18, &fr.M1, fr.v, fr.f0c);
        }
        break;
    case 1:
        ag->FUN_00035160(&fr.Mc);
        fr.Mc.FUN_0022c120();
        fr.Mb.FUN_0022ca90(&fr.M1, &fr.Mc);
        res = fx->FUN_00283b10(&p20->id18, ag->p120, 0, &fr.Mb, fr.v, fr.f0c);
        break;
    case 2: {
        Name *idp = &p20->id30;
        bool got = false;
        if (idp != 0) {
            int idx = ag->p120->FUN_002843a0(idp->lo, idp->hi);
            if (idx != 0xffff) {
                Mat4 *src = (Mat4 *)(ag->p120->base + idx * 64);
                fr.Mc = *src;
                got = true;
            }
        }
        if (!got)
            ag->FUN_00035160(&fr.Mc);
        fr.Mc.FUN_0022c120();
        fr.Mb.FUN_0022ca90(&fr.M1, &fr.Mc);
        Params *pp = p20;
        res = fx->FUN_00283b10(&pp->id18, ag->p120, &pp->id30, &fr.Mb, fr.v, fr.f0c);
        break;
    }
    case 3: {
        Params *pp = p20;
        res = fx->FUN_00283be0(&pp->id18, ag->p120, fr.v, fr.f0c);
        break;
    }
    default:
        break;
    }
    if (t2 <= 3 && setf28)
        f28 = res;
    if (p20->b51) {
        int r = ag->FUN_00036c60(p20->f54);
        fx->FUN_0027ffb0(r);
        ag->FUN_00036c40(p20->f54, f28);
        return p20->b50;
    }
    return p20->b50;
}
