// STATUS: equivalent (tools/equiv.py level 3: 3026 inputs, branch coverage 37/39, incomplete)
// CEffectAction::vfunc_6 @ 0x00016680
struct V3_16680 {
    float x, y, z;
    char FUN_0022d2b0(const V3_16680 *other, float eps);
};

struct Name_16680 {
    unsigned int lo, hi;
};

struct Mat4_16680 {
    float m[16];
    void FUN_0022b980();
    void FUN_0022be40(V3_16680 *t);
    void FUN_0022bc20(float x, float y, float z);
    void FUN_0022ca90(Mat4_16680 *a, Mat4_16680 *b);
    void FUN_0022c120();
};

void FUN_00224db0(Mat4_16680 *m, V3_16680 *up, V3_16680 *fwd);

struct Lookup_16680 {
    char pad0[0x1c];
    char *base;
    int FUN_002843a0(unsigned int lo, unsigned int hi);
};

struct Agent_16680 {
    char pad0[0x120];
    Lookup_16680 *p120;
    char pad124[0x1a4c - 0x124];
    int f1a4c;
    void FUN_00035160(Mat4_16680 *out);
    int FUN_00036c60(int a);
    void FUN_00036c40(int a, int b);
};

struct Fx_16680 {
    int FUN_00283a40(Name_16680 *id, Mat4_16680 *m, float v, int f58);
    int FUN_00283b10(Name_16680 *id, Lookup_16680 *lk, Name_16680 *id2, Mat4_16680 *m, float v, int f58);
    int FUN_00283be0(Name_16680 *id, Lookup_16680 *lk, float v, int f58);
    void FUN_0027ffb0(int a);
};
Fx_16680 *FUN_0027f250();

struct Obj3_16680 {
    char pad0[8];
    V3_16680 v8;
    char pad14[0x18 - 0x14];
    V3_16680 v18;
};

class Src_16680 {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual Obj3_16680 *s3();
    Agent_16680 *FUN_000592a0x();
};
struct Mid_16680 {
    Agent_16680 *FUN_00059a30();
};
struct Top_16680 {
    Mid_16680 *FUN_000592a0();
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
    Name_16680 id18;
    int t1;
    int t2;
    Name_16680 id28;
    Name_16680 id30;
    V3_16680 pos;
    V3_16680 rot;
    char b50;
    char b51;
    char pad52[2];
    int f54;
    int f58;
};

struct Hub20_16680 {
    void FUN_00025590(Obj3_16680 *r, Name_16680 *a, int f58, Name_16680 *b, int f58b, Mat4_16680 *m, float v, int f54);
};
struct Hub_16680 {
    char pad0[0x20];
    Hub20_16680 *p20;
};
extern Hub_16680 *DAT_004dd700;

class CEffectAction {
public:
    char pad0[0x1c];
    Src_16680 *p1c;
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
        V3_16680 W;
        Mat4_16680 Mb;
        V3_16680 T4;
        V3_16680 U;
        V3_16680 T5;
        V3_16680 T1;
        V3_16680 T6;
        V3_16680 Vup2;
        V3_16680 T3;
        V3_16680 Vup;
        V3_16680 T2;
        Mat4_16680 Mc;
        Mat4_16680 M1;
    } fr;

    Agent_16680 *ag = ((Top_16680 *)p1c)->FUN_000592a0()->FUN_00059a30();
    Fx_16680 *fx = FUN_0027f250();
    fr.spill = (int)fx;
    unsigned int t1 = p20->t1;
    if (t1 > 4) {
    } else if (t1 == 0) {
        fr.M1.FUN_0022b980();
        fr.T1 = p20->pos;
        fr.M1.FUN_0022be40(&fr.T1);
        V3_16680 r = p20->rot;
        fr.M1.FUN_0022bc20(r.x, r.y, r.z);
    } else if (t1 == 1 || t1 == 2 || t1 == 3) {
        bool useVcall = false;
        Obj3_16680 *o3 = 0;
        if (t1 == 3) {
            o3 = p1c->s3();
            if (o3 != 0)
                useVcall = true;
        }
        if (!useVcall) {
            fr.Mb.FUN_0022b980();
            V3_16680 *tb = (t1 == 1) ? &fr.T2 : ((t1 == 2) ? &fr.T3 : &fr.T4);
            *tb = p20->pos;
            fr.Mb.FUN_0022be40(tb);
            V3_16680 r = p20->rot;
            fr.Mb.FUN_0022bc20(r.x, r.y, r.z);
            Mat4_16680 *second = 0;
            bool found = false;
            if (t1 == 2) {
                if (&p20->id28 != 0) {
                    int idx = ag->p120->FUN_002843a0(p20->id28.lo, p20->id28.hi);
                    if (idx != 0xffff) {
                        second = (Mat4_16680 *)(ag->p120->base + idx * 64);
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
            V3_16680 r = p20->rot;
            fr.Mc.FUN_0022bc20(r.x, r.y, r.z);
            fr.M1.FUN_0022ca90(&fr.Mc, &fr.Mb);
        }
    } else {
        fr.Mc.FUN_0022b980();
        fr.T6 = p20->pos;
        fr.Mc.FUN_0022be40(&fr.T6);
        V3_16680 r = p20->rot;
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
            Obj3_16680 *o = p1c->s3();
            Params *pp = p20;
            DAT_004dd700->p20->FUN_00025590(o, (Name_16680 *)&pp->id18, fr.f0c, (Name_16680 *)&pp->id18, fr.f0c, &fr.M1,
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
        Name_16680 *idp = &p20->id30;
        bool got = false;
        if (idp != 0) {
            int idx = ag->p120->FUN_002843a0(idp->lo, idp->hi);
            if (idx != 0xffff) {
                Mat4_16680 *src = (Mat4_16680 *)(ag->p120->base + idx * 64);
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
