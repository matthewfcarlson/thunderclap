// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 28/28)
// CClimbableCondition::vfunc_7 @ 0x0004d130
extern "C" double sqrt(double);

struct Vec3_4d130 {
    float x, y, z;
    float FUN_0022d110();
};

union Bits_4d130 {
    float f;
    unsigned int u;
};

union Arg_4d130 {
    void *owner;
    float f;
    unsigned int u;
};

struct Link_4d130 {
    char pad00[0x30];
    Bits_4d130 f30;
    Bits_4d130 f34;
};

struct Stats_4d130 {
    char pad000[0x11c];
    Link_4d130 *link;
    char pad120[0x140 - 0x120];
    int mode;
    char pad144[0x1af8 - 0x144];
    Vec3_4d130 v1af8;
    char pad1b04[4];
    char flag1b08;
    char pad1b09[0x2064 - 0x1b09];
    Vec3_4d130 v2064;
    void FUN_00035230(Vec3_4d130 *out);
    float FUN_000354c0();
    void FUN_00035550(Vec3_4d130 *out);
    bool FUN_0003f7b0(Vec3_4d130 *from, Vec3_4d130 *to, Vec3_4d130 *pt, Vec3_4d130 *n, int a, int b, int c);
    void FUN_000479e0(Vec3_4d130 *pt, Vec3_4d130 *n);
};

struct Fighter_4d130 {
    Stats_4d130 *FUN_00059a30();
    void FUN_00059a50(Vec3_4d130 *out);
};

Fighter_4d130 *__fastcall FUN_000592a0(void *owner);
void __cdecl FUN_00224d70(float angle, Vec3_4d130 *v);
float __cdecl FUN_00224ea0(float x, float z);
float __cdecl FUN_00224f10(Vec3_4d130 *v);
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
    virtual char vfunc_7(Arg_4d130 a);
    char pad04[8];
    union {
        float f0c;
        unsigned int u0c;
    };
    float f10;
    char b14;
};

char CClimbableCondition::vfunc_7(Arg_4d130 a)
{
    struct Frame {
        Bits_4d130 d;
        float L;
        float t14;
        Vec3_4d130 G;
        Vec3_4d130 W;
        union {
            Vec3_4d130 Q;
            Vec3_4d130 C;
            Vec3_4d130 H;
        };
        Vec3_4d130 A;
        Vec3_4d130 B;
        Vec3_4d130 n;
        Vec3_4d130 pt;
    } f;

    Fighter_4d130 *fighter = FUN_000592a0(a.owner);
    Stats_4d130 *st = fighter->FUN_00059a30();
    a.u = u0c & 0x7fffffff;
    if (a.f <= 1e-05f) {
        if (st->mode == 4)
            return st->flag1b08;
    }
    Link_4d130 *p = st->link;
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
