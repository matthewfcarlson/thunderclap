// STATUS: equivalent (tools/equiv.py level 3: 3045 inputs, branch coverage 42/50, incomplete)
// FUN_00314be0 @ 0x00314be0
struct Vec3 {
    float x, y, z;
};

union FloatBits {
    float f;
    unsigned int u;
};

class Contact {
public:
    int a;
    int b;
    char pad08[8];
    int x10;
    int x14;
    Vec3 n;
    float f24;
    char pad28[4];
    Vec3 v2c;
    Vec3 v38;
    Contact* FUN_002f8ec0(int a1, int a2, int a3, int a4, int a5, Vec3* a6);
    void FUN_002f7a90(Contact* other);
};

struct ContactVec {
    Contact* begin;
    Contact* end;
    Contact* cap;
};

class ContactManager {
public:
    char pad00[8];
    ContactVec* vec;
    char pad0c[4];
    float tolerance;
    char pad14[0x30 - 0x14];
    int count;
    char pad34[4];
    unsigned int flags;
    void FUN_00314be0(int a1, int a2, int a3, int a4, int a5, Vec3* normal);
};

void ContactManager::FUN_00314be0(int a1, int a2, int a3, int a4, int a5, Vec3* normal)
{
    struct Frame {
        ContactVec* vecSlot;
        Contact* elem;
        float absTmp;
        float tolsq;
        Vec3 qd;
        int bitA;
        Vec3 qB;
        int bitB;
        Vec3 pA;
        Vec3 pB;
        Contact c;
    } f;

    volatile float t = normal->x * normal->x + normal->y * normal->y + normal->z * normal->z - 1.0f;
    FloatBits ab;
    ab.f = t;
    ab.u &= 0x7fffffff;
    if (ab.f > 0.01f)
        return;
    f.c.FUN_002f8ec0(a1, a2, a3, a4, a5, normal);
    if (flags != 0 && count > 0) {
        f.bitB = flags & 2;
        if (f.bitB) {
            f.pB = f.c.v2c;
            f.qB = f.c.v38;
        }
        f.bitA = flags & 1;
        if (f.bitA)
            f.pA = f.c.n;
        f.vecSlot = vec;
        int n = vec->end - vec->begin;
        int idx = n - 1;
        if (idx >= n - count) {
            f.elem = vec->begin + idx;
            for (;;) {
                Contact* e = f.elem;
                int sign;
                if (a1 == e->a && a3 == e->b) {
                    sign = 0;
                    if (f.c.x10 == e->x10 && f.c.x14 == e->x14)
                        sign = 1;
                } else if (a1 == e->b && a3 == e->a) {
                    sign = 0;
                    if (f.c.x10 == e->x14 && f.c.x14 == e->x10)
                        sign = -1;
                } else {
                    break;
                }
                if (sign != 0) {
                    bool skipA = false;
                    if (f.bitB) {
                        Vec3* pa = sign == 1 ? &e->v2c : &e->v38;
                        Vec3* qa = sign == 1 ? &e->v38 : &e->v2c;
                        double dx = pa->x - f.pB.x;
                        double dy = pa->y - f.pB.y;
                        double dz = pa->z - f.pB.z;
                        double s1 = dz * dz + dy * dy + dx * dx;
                        f.qd.x = qa->x - f.qB.x;
                        f.qd.y = qa->y - f.qB.y;
                        f.qd.z = qa->z - f.qB.z;
                        double tol = tolerance * 0.001f;
                        f.tolsq = tol * tol;
                        if (s1 < f.tolsq) {
                            if (f.qd.z * f.qd.z + f.qd.y * f.qd.y + f.qd.x * f.qd.x < f.tolsq)
                                return;
                        }
                    }
                    if (f.bitA) {
                        f.absTmp = f.pA.x * e->n.x + f.pA.z * e->n.z + f.pA.y * e->n.y;
                        FloatBits d;
                        d.f = f.absTmp;
                        d.u &= 0x7fffffff;
                        if (d.f < 0.7f) {
                            if (f.c.f24 > f.elem->f24)
                                f.elem->FUN_002f7a90(&f.c);
                            return;
                        }
                    }
                }
                idx--;
                f.elem = f.elem - 1;
                if (!(idx >= n - count))
                    break;
            }
        }
        count = count + 1;
        Contact* dst = f.vecSlot->end;
        if (dst >= f.vecSlot->cap)
            return;
        f.vecSlot->end = dst + 1;
        if (dst != 0)
            *dst = f.c;
        return;
    }
    count = count + 1;
    ContactVec* v = vec;
    Contact* dst = v->end;
    if (dst >= v->cap)
        return;
    v->end = dst + 1;
    if (dst != 0)
        *dst = f.c;
}
