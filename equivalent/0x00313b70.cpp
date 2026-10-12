// STATUS: equivalent (tools/equiv.py level 3: 2161 inputs, branch coverage 50/50)
// FUN_00313b70 @ 0x00313b70
extern "C" double sqrt(double);

struct Vec3 {
    float x, y, z;
    float FUN_0022d110() throw();
    void FUN_00011160(float s, Vec3 *d) throw();
    void FUN_00095e80(float s, Vec3 *axis) throw();
};

class Box {
public:
    virtual void v0() throw();
    virtual void v1() throw();
    virtual void v2() throw();
    virtual void v3() throw();
    virtual Vec3 *v4() throw();
    char pad04[0x34];
    int f38;
    char pad3c[0xc];
    float ext[3];
    Vec3 axis[3];
};

union FloatBits {
    float f;
    unsigned int u;
};

union Arg1 {
    Box *box;
    float f;
    unsigned int u;
};

union Arg2 {
    Vec3 *p;
    float f;
};

union Arg3 {
    Vec3 *out;
    Vec3 *axis;
};

union Arg7 {
    char flag;
    float s;
};

float __cdecl FUN_00083d90(float *w) throw();
char __cdecl FUN_00018960(float a, float b, float eps) throw();

class Sweeper {
public:
    char pad00[0xc];
    float f0c;
    float f10;
    void FUN_00313540(int *out, unsigned int e0, unsigned int e1, unsigned int e2) throw();
    void FUN_003137f0(Box *box, Vec3 *pt, unsigned int r1, unsigned int r2, int idx) throw();
    char FUN_00313b70(Arg1 a1, Arg2 a2, Arg3 a3, Vec3 *a4, float *a5, float a6, Arg7 a7);
};

char Sweeper::FUN_00313b70(Arg1 a1, Arg2 a2, Arg3 a3, Vec3 *a4, float *a5, float a6, Arg7 a7)
{
    union IntF {
        int i;
        float f;
    };
    struct Frame {
        float c;
        float tmp1;
        float tmp2;
        Sweeper *self;
        float R;
        float E[3];
        float W[3];
        IntF G[3];
    } f;

    Box *box = a1.box;
    Vec3 *P = a2.p;
    f.R = a6 + f10;
    f.self = this;
    const Vec3 *cen = box->v4();
    double dx = P->x - cen->x;
    double dy = P->y - cen->y;
    f.G[1].f = (float)dy;
    double dz = P->z - cen->z;
    f.G[2].f = (float)dz;
    if (box->f38 == 0) {
        double w0 = f.G[2].f * box->axis[0].z + dy * box->axis[0].y + dx * box->axis[0].x;
        f.W[0] = (float)w0;
        a1.f = (float)w0;
        a1.u &= 0x7fffffff;
        f.E[0] = a1.f - a6 - box->ext[0];
        double w1 = f.G[2].f * box->axis[1].z + dy * box->axis[1].y + dx * box->axis[1].x;
        f.W[1] = (float)w1;
        a1.f = (float)w1;
        a1.u &= 0x7fffffff;
        f.E[1] = a1.f - a6 - box->ext[1];
        double w2 = f.G[2].f * box->axis[2].z + dy * box->axis[2].y + dx * box->axis[2].x;
        f.W[2] = (float)w2;
        a1.f = (float)w2;
    } else {
        f.W[0] = (float)dx;
        f.W[2] = f.G[2].f;
        f.W[1] = (float)dy;
        a1.f = (float)dx;
        a1.u &= 0x7fffffff;
        f.E[0] = a1.f - a6 - box->ext[0];
        a1.f = f.G[1].f;
        a1.u &= 0x7fffffff;
        f.E[1] = a1.f - a6 - box->ext[1];
        a1.f = f.G[2].f;
    }
    a1.u &= 0x7fffffff;
    f.E[2] = a1.f - a6 - box->ext[2];
    FUN_00313540(&f.G[0].i, *(unsigned int *)&f.E[0], *(unsigned int *)&f.E[1], *(unsigned int *)&f.E[2]);
    int idx = f.G[0].i;
    double m = (a6 < box->ext[idx]) ? a6 : box->ext[idx];
    if (f.E[idx] < f0c) {
        if (-m > f.E[idx]) {
            if (a7.flag == 0)
                return 1;
            Vec3 *cp = a3.out;
            *cp = *P;
            float w = f.W[idx];
            double sg;
            if (w < 0.0f)
                sg = -1.0;
            else if (w > 0.0f)
                sg = 1.0;
            else
                sg = 0.0;
            double ns = -sg;
            Vec3 *ax = &box->axis[idx];
            a4->x = ns * ax->x;
            a4->y = ns * ax->y;
            a4->z = ns * ax->z;
            double t = a6 + f.E[idx];
            cp->x = t * a4->x + cp->x;
            cp->y = t * a4->y + cp->y;
            cp->z = t * a4->z + cp->z;
            P->x = a6 * a4->x + P->x;
            P->y = a6 * a4->y + P->y;
            unsigned int eb = *(volatile unsigned int *)&f.E[idx];
            P->z = a6 * a4->z + P->z;
            *(unsigned int *)a5 = eb;
            return 1;
        }
    }
    for (int k = 0; k < 3; k++) {
        int bp = f.G[k].i;
        f.c = f.E[bp];
        *a5 = f.c;
        double m2 = (a6 < box->ext[bp]) ? a6 : box->ext[bp];
        if (!(f.c < f0c))
            continue;
        if (!(-m2 < f.c))
            continue;
        int n1 = (bp < 2) ? bp + 1 : 0;
        f.tmp1 = f.W[n1];
        *(unsigned int *)&f.tmp1 &= 0x7fffffff;
        double v1 = f.tmp1 - box->ext[n1];
        a2.f = (0.0f < v1) ? (float)v1 : 0.0f;
        if (!(a2.f <= f.R))
            continue;
        int n2 = (n1 < 2) ? n1 + 1 : 0;
        f.tmp2 = f.W[n2];
        *(unsigned int *)&f.tmp2 &= 0x7fffffff;
        double v2 = f.tmp2 - box->ext[n2];
        a1.f = (0.0f < v2) ? (float)v2 : 0.0f;
        if (!(a1.f <= f.R))
            continue;
        if (a2.f > 0.0f || a1.f > 0.0f) {
            double t = f.c + a6;
            double sq = t * t;
            sq = sq + a1.f * a1.f;
            sq = sq + a2.f * a2.f;
            *a5 = (float)(sqrt(sq) - a6);
        }
        if (!(*a5 < f0c))
            continue;
        if (a7.flag == 0)
            return 1;
        double r = FUN_00083d90(&f.W[bp]);
        a7.s = (float)(-r);
        Vec3 *cp = a3.out;
        *cp = *P;
        double q = (a6 + f.E[bp]) * a7.s;
        Vec3 *ax = &box->axis[bp];
        cp->x = q * ax->x + cp->x;
        cp->y = q * ax->y + cp->y;
        cp->z = q * ax->z + cp->z;
        a3.axis = ax;
        if (a2.f > 0.0f || a1.f > 0.0f) {
            if (a6 + *a5 > 0.001f) {
                FUN_003137f0(box, cp, *(unsigned int *)&a2.f, *(unsigned int *)&a1.f, bp);
                a4->x = cp->x - P->x;
                a4->y = cp->y - P->y;
                a4->z = cp->z - P->z;
                float len = a4->FUN_0022d110();
                if (FUN_00018960(len, 0.0f, 1e-05f))
                    a4->FUN_00095e80(a7.s, a3.axis);
                P->FUN_00011160(a6, a4);
                return 1;
            }
        }
        a4->x = a7.s * ax->x;
        a4->y = a7.s * ax->y;
        a4->z = a7.s * ax->z;
        P->x = a6 * a4->x + P->x;
        P->y = a6 * a4->y + P->y;
        P->z = a6 * a4->z + P->z;
        return 1;
    }
    return 0;
}
