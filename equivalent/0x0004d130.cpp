// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 28/28)
// CClimbableCondition::vfunc_7 @ 0x0004d130
extern "C" double sqrt(double);

struct Vec3 {
    float x, y, z;
    float FUN_0022d110();
};

union Bits {
    float f;
    unsigned int u;
};

union Arg {
    void *owner;
    float f;
    unsigned int u;
};

struct Link {
    char pad00[0x30];
    Bits f30;
    Bits f34;
};

struct Stats {
    char pad000[0x11c];
    Link *link;
    char pad120[0x140 - 0x120];
    int mode;
    char pad144[0x1af8 - 0x144];
    Vec3 v1af8;
    char pad1b04[4];
    char flag1b08;
    char pad1b09[0x2064 - 0x1b09];
    Vec3 v2064;
    void FUN_00035230(Vec3 *out);
    float FUN_000354c0();
    void FUN_00035550(Vec3 *out);
    bool FUN_0003f7b0(Vec3 *from, Vec3 *to, Vec3 *pt, Vec3 *n, int a, int b, int c);
    void FUN_000479e0(Vec3 *pt, Vec3 *n);
};

struct Fighter {
    Stats *FUN_00059a30();
    void FUN_00059a50(Vec3 *out);
};

Fighter *__fastcall FUN_000592a0(void *owner);
void __cdecl FUN_00224d70(float angle, Vec3 *v);
float __cdecl FUN_00224ea0(float x, float z);
float __cdecl FUN_00224f10(Vec3 *v);
float __cdecl FUN_00224fc0(float from, float to);

class CClimbableCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual char vfunc_7(Arg a);
    char pad04[8];
    union {
        float f0c;
        unsigned int u0c;
    };
    float f10;
    char b14;
};

char CClimbableCondition::vfunc_7(Arg a)
{
    struct Frame {
        Bits d;
        float L;
        float t14;
        Vec3 G;
        Vec3 W;
        union {
            Vec3 Q;
            Vec3 C;
            Vec3 H;
        };
        Vec3 A;
        Vec3 B;
        Vec3 n;
        Vec3 pt;
    } f;

    Fighter *fighter = FUN_000592a0(a.owner);
    Stats *st = fighter->FUN_00059a30();
    a.u = u0c & 0x7fffffff;
    if (a.f <= 1e-05f) {
        if (st->mode == 4)
            return st->flag1b08;
    }
    Link *p = st->link;
    if (p == 0)
        return false;
    a.u = p->f34.u;
    f.d.u = p->f30.u;
    f.A.x = 0.0f;
    f.A.y = 0.0f;
    f.A.z = 0.0f;
    fighter->FUN_00059a50(&f.A);
    f.B.x = 0.0f;
    f.B.y = 0.0f;
    f.B.z = 0.0f;
    st->FUN_00035230(&f.B);
    f.C = f.A;
    double dx = f.C.x - f.B.x;
    double dy = f.C.y - f.B.y;
    double dz = f.C.z - f.B.z;
    double len = sqrt(dz * dz + dy * dy + dx * dx);
    f.L = (float)len;
    if (len > 5.0f)
        f.L = 5.0f;
    f.G = f.A;
    if (st->mode == 1) {
        f.G.y = f.d.f * 0.5f + f.G.y;
    } else if (st->mode == 4) {
        f.H = st->v1af8;
        f.H.y = 0.0f;
        f.H.FUN_0022d110();
        double s = a.f * 1.25f;
        f.G.x = f.H.x * s + f.G.x;
        f.G.y = f.H.y * s + f.G.y;
        f.G.z = f.H.z * s + f.G.z;
    }
    char climb = b14;
    if (climb) {
        f.W = st->v2064;
        f.W.y = 0.0f;
        f.W.FUN_0022d110();
        f.t14 = st->FUN_000354c0();
        float a2 = FUN_00224f10(&f.W);
        f.d.f = FUN_00224fc0(f.t14, a2);
        f.d.u &= 0x7fffffff;
        if (f.d.f > f10)
            return false;
    } else {
        st->FUN_00035550(&f.W);
        f.W.y = 0.0f;
        f.W.FUN_0022d110();
        FUN_00224d70(f0c, &f.W);
    }
    double nr = -a.f;
    f.G.x = f.W.x * nr + f.G.x;
    f.G.y = f.W.y * nr + f.G.y;
    f.G.z = f.W.z * nr + f.G.z;
    double T = a.f * 3.0f + f.L;
    f.W.x = f.W.x * T;
    f.W.y = f.W.y * T;
    f.W.z = f.W.z * T;
    f.Q = f.W;
    f.Q.x = f.Q.x + f.G.x;
    f.Q.y = f.Q.y + f.G.y;
    f.Q.z = f.Q.z + f.G.z;
    if (!st->FUN_0003f7b0(&f.G, &f.Q, &f.pt, &f.n, 0, 0, 0)) {
        if (climb)
            return false;
        if (!(f10 > 0.0f))
            return false;
        FUN_00224d70(f10 * -0.5f, &f.W);
        f.Q.x = f.W.x + f.G.x;
        f.Q.y = f.W.y + f.G.y;
        f.Q.z = f.W.z + f.G.z;
        if (!st->FUN_0003f7b0(&f.G, &f.Q, &f.pt, &f.n, 0, 0, 0)) {
            FUN_00224d70(f10, &f.W);
            f.Q.x = f.W.x + f.G.x;
            f.Q.y = f.W.y + f.G.y;
            f.Q.z = f.W.z + f.G.z;
            if (!st->FUN_0003f7b0(&f.G, &f.Q, &f.pt, &f.n, 0, 0, 0))
                return false;
        }
    }
    f.t14 = st->FUN_000354c0() + f0c;
    a.f = FUN_00224ea0(-f.n.x, -f.n.z);
    a.f = FUN_00224fc0(f.t14, a.f);
    a.u &= 0x7fffffff;
    if (a.f > f10)
        return false;
    st->FUN_000479e0(&f.pt, &f.n);
    return true;
}
