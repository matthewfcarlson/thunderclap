// STATUS: equivalent (tools/equiv.py level 3: 3036 inputs, branch coverage 42/46, incomplete)
// FUN_00314430 @ 0x00314430
extern "C" double sqrt(double);

struct V3 {
    float x;
    float y;
    float z;
    void FUN_00095e80(float s, V3 *v);
    void FUN_001f6bc0(V3 *a, float s, V3 *b);
    void FUN_00011110(V3 *a, V3 *b);
    float FUN_0022d110();
    void FUN_00034440(V3 *a, V3 *b);
    void FUN_00011160(float s, V3 *b);
    void FUN_00011140(float s);
    float FUN_000111f0();
    void FUN_000110d0(V3 *b);
};

float __cdecl FUN_00083d90(float *x);

class Prim {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual V3 *v4();
    char pad04[0x44 - 4];
    V3 v;
    float f50;
    float f54;
    char b58;
};

class Sweeper;
class Sweeper {
public:
    char pad0[0xc];
    float r;
    char pad10[4];
    V3 n;
    bool FUN_00314430(Prim *p, V3 *a1, float a2, V3 *a3, float *a4, V3 *a5, V3 *a6, char a7);
};

bool Sweeper::FUN_00314430(Prim *p, V3 *a1, float a2, V3 *a3, float *a4, V3 *a5, V3 *a6, char a7)
{
    struct {
        float d;
        float absd;
        Sweeper *self;
        V3 *np;
    } l;
    double d = p->v.z * n.z + p->v.y * n.y + p->v.x * n.x;
    l.self = this;
    l.np = &n;
    l.d = (float)d;
    double t = *a4 - d * l.d;
    float u;
    if (0.0 < t)
        u = (float)t;
    else
        u = 0.0f;
    char cl = p->b58;
    double L;
    if (cl)
        L = 0.0;
    else
        L = p->f54;
    L = L + p->f50;
    union {
        float f;
        unsigned int i;
    } ab;
    ab.f = l.d;
    ab.i &= 0x7fffffff;
    l.absd = ab.f;
    if (!(L + a2 + r > ab.f))
        return false;
    double R = a2 + p->f54 + r;
    if (!(u < R * R))
        return false;
    if (a5 == 0 || a6 == 0)
        return true;
    float f54c = p->f54;
    if (u < 0.0f)
        return false;
    u = (float)sqrt(u);
    if (cl) {
        double X = ab.f - p->f50;
        double Y = u - f54c;
        if (Y < X && u < f54c) {
            double W = ab.f - (a2 + p->f50);
            *a4 = (float)W;
            if (!(W < r))
                return false;
            a3->FUN_00095e80(FUN_00083d90(&l.d), &p->v);
            a6->FUN_001f6bc0(a1, a2, a3);
            a5->FUN_001f6bc0(a6, *a4, a3);
            return true;
        }
    } else if (ab.f >= p->f50) {
        if (!a7)
            return false;
        a5->FUN_001f6bc0(p->v4(), -(FUN_00083d90(&l.d) * p->f50), &p->v);
        a3->FUN_00011110(a5, a1);
        double len = a3->FUN_0022d110();
        double X2 = len - p->f54 - a2;
        *a4 = (float)X2;
        if (!(X2 < l.self->r))
            return false;
        a5->FUN_00011160(-p->f54, a3);
        a6->FUN_001f6bc0(a5, -*a4, a3);
        return true;
    }

    if (!(u > 1.0e-6f))
        return false;
    V3 tmp;
    tmp.FUN_00095e80(-l.d, &p->v);
    a3->FUN_00034440(l.np, &tmp);
    *a4 = (float)(u - f54c - a2);
    a3->FUN_00011140(1.0f / u);
    double len2 = a3->FUN_000111f0();
    union {
        float f;
        unsigned int i;
    } e;
    e.f = (float)(len2 - 1.0);
    e.i &= 0x7fffffff;
    if (e.f > 0.01f)
        a3->FUN_00011140((float)(1.0 / sqrt(len2)));
    ab.f = l.d;
    ab.i &= 0x7fffffff;
    if (ab.f > p->f50) {
        union {
            float f;
            unsigned int i;
        } b2;
        b2.f = l.d;
        b2.i &= 0x7fffffff;
        double q = p->f50 / b2.f;
        tmp.x = tmp.x * q;
        tmp.y = tmp.y * q;
        tmp.z = tmp.z * q;
    }
    a5->FUN_001f6bc0(&tmp, -f54c, a3);
    a5->FUN_000110d0(p->v4());
    ab.f = l.d;
    ab.i &= 0x7fffffff;
    if (ab.f <= p->f50) {
        a6->FUN_001f6bc0(a1, a2, a3);
        return true;
    }
    if (!p->b58)
        return false;
    a3->FUN_00011110(a5, a1);
    double len = a3->FUN_0022d110();
    *a4 = (float)len;
    if (len == 0.0) {
        a3->FUN_00011110(a5, a1);
        a3->x = a3->x * 1000.0f;
        a3->y = a3->y * 1000.0f;
        a3->z = a3->z * 1000.0f;
        double len3 = a3->FUN_0022d110() * 0.001f;
        *a4 = (float)len3;
        if (len3 == 0.0)
            return false;
    }
    if (!(a2 + l.self->r >= *a4))
        return false;
    *a4 = *a4 - a2;
    a6->FUN_001f6bc0(a5, -*a4, a3);
    return true;
}
