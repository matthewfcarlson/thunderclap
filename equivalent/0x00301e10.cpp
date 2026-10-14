// STATUS: equivalent (tools/equiv.py level 3: 3017 inputs, branch coverage 30/30)
// FUN_00301e10 @ 0x00301e10
extern "C" double sqrt(double);
// equiv-conv: FUN_00314be0 ecx stack stack stack stack stack stack
struct Vec3_301e10 {
    float x, y, z;
    float FUN_0022d110();
    void FUN_00011160(float s, Vec3_301e10 *dir);
    void FUN_001f6bc0(Vec3_301e10 *base, float s, Vec3_301e10 *dir);
};

union FloatBits_301e10 {
    float f;
    unsigned int u;
};

struct PtrRange_301e10 {
    char *begin;
    char *end;
};

class Cap {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual Vec3_301e10 *GetPos();
    char pad04[0x10];
    PtrRange_301e10 *list;
    char pad18[0x44 - 0x18];
    Vec3_301e10 dir;
    float radius;
    float half;
};

extern char DAT_00555481;

class Collider_301e10 {
public:
    char pad00[0xc];
    float margin;
    char pad10[4];
    Vec3_301e10 d;

    char FUN_00315620(Vec3_301e10 *out, Vec3_301e10 *axis, float ext, Vec3_301e10 *u, Vec3_301e10 *b, float f50, float *kv, float L, float m, Cap *a, Cap *cap);
    void FUN_00314be0(Cap *a, Vec3_301e10 *p1, Cap *b, Vec3_301e10 *p2, float depth, Vec3_301e10 *dir);
    void FUN_00318bb0(Cap *a, Cap *b);
    void FUN_00318910(Cap *a, Cap *b);
    void FUN_00317700(Cap *a, Cap *b, int x, int y);
    void FUN_00301e10(Cap *a, Cap *b);
};

void Collider_301e10::FUN_00301e10(Cap *a, Cap *b)
{
    struct Frame {
        float gap2;
        Vec3_301e10 k;
        Vec3_301e10 ua;
        Vec3_301e10 q;
        Vec3_301e10 p;
        Vec3_301e10 ub;
    } f;

    Vec3_301e10 *pa = a->GetPos();
    Vec3_301e10 *pb = b->GetPos();
    d.x = pb->x - pa->x;
    d.y = pb->y - pa->y;
    d.z = pb->z - pa->z;

    Vec3_301e10 *ad = &a->dir;
    Vec3_301e10 *bd = &b->dir;
    double cx = ad->y * bd->z - ad->z * bd->y;
    double cy = ad->z * bd->x - ad->x * bd->z;
    volatile float cz = ad->x * bd->y - ad->y * bd->x;
    double k = b->radius * a->radius;
    volatile float kf = (float)k;
    f.k.x = (float)(k * cx);
    f.k.y = (float)(cy * kf);
    double kzx = cz * kf;
    f.k.z = (float)kzx;
    double Lx = kzx * f.k.z + f.k.y * f.k.y + f.k.x * f.k.x;
    volatile float Lf = (float)Lx;
    if (Lx > 9.99999997475243e-007f) {
        double dpx = f.k.z * d.z + f.k.y * d.y + f.k.x * d.x;
        FloatBits_301e10 ab;
        ab.f = (float)dpx;
        ab.u &= 0x7fffffff;
        if (ab.f > 9.99999997475243e-007f) {
            volatile float len = (float)sqrt((double)Lf);
            double invx = 1.0f / len;
            volatile float inv = (float)invx;
            double sx = invx * dpx;
            double sgn;
            if (sx < 0.0)
                sgn = -1.0f;
            else if (sx > 0.0)
                sgn = 1.0f;
            else
                sgn = 0.0f;
            double w = sgn * inv;
            double wa = w * a->half;
            f.ua.x = (float)(f.k.x * wa);
            f.ua.y = (float)(f.k.y * wa);
            f.ua.z = (float)(f.k.z * wa);
            double wb = -(w * b->half);
            f.ub.x = (float)(f.k.x * wb);
            f.ub.y = (float)(f.k.y * wb);
            f.ub.z = (float)(f.k.z * wb);
            FloatBits_301e10 sb;
            sb.f = (float)sx;
            sb.u &= 0x7fffffff;
            double m = sb.f - a->half - b->half;
            volatile float mf = (float)m;
            if (m < margin) {
                if (a->list && (int)(a->list->end - a->list->begin) & ~3)
                    goto tail;
                if (b->list && (int)(b->list->end - b->list->begin) & ~3)
                    goto tail;
                if (FUN_00315620(&f.ua, ad, a->radius, &f.ub, bd, b->radius, &f.k.x, len, mf, a, b) && DAT_00555481 == 0)
                    return;
            }
        }
    } else {
        double t = ad->z * d.z + ad->y * d.y + ad->x * d.x;
        f.p.x = (float)(t * ad->x);
        f.p.y = (float)(t * ad->y);
        f.p.z = (float)(t * ad->z);
        f.q.x = d.x - f.p.x;
        f.q.y = d.y - f.p.y;
        f.q.z = d.z - f.p.z;
        double qlen = f.q.FUN_0022d110();
        if (qlen > 9.99999997475243e-007f) {
            double gap = qlen - (b->half + a->half);
            volatile float gapf = (float)gap;
            if (gap <= margin) {
                double plen = f.p.FUN_0022d110();
                double g2 = plen - (b->radius + a->radius);
                if (g2 <= margin) {
                    f.gap2 = (float)g2;
                    FloatBits_301e10 u1;
                    u1.f = gapf;
                    u1.u &= 0x7fffffff;
                    FloatBits_301e10 u2;
                    u2.f = f.gap2;
                    u2.u &= 0x7fffffff;
                    if (u1.f < u2.f) {
                        f.ua.x = f.p.x * a->radius;
                        f.ua.y = f.p.y * a->radius;
                        f.ua.z = f.p.z * a->radius;
                        f.ua.FUN_00011160(a->half, &f.q);
                        Vec3_301e10 *ra = a->GetPos();
                        f.ua.x = f.ua.x + ra->x;
                        f.ua.y = f.ua.y + ra->y;
                        f.ua.z = f.ua.z + ra->z;
                        f.ub.FUN_001f6bc0(&f.ua, gapf, &f.q);
                        f.q.x = f.q.x * -1.0f;
                        f.q.y = f.q.y * -1.0f;
                        f.q.z = f.q.z * -1.0f;
                        FUN_00314be0(a, &f.ua, b, &f.ub, gapf, &f.q);
                    }
                }
            }
        }
    }
tail:
    FUN_00318bb0(a, b);
    FUN_00318910(a, b);
    FUN_00317700(a, b, 1, 1);
}
