// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 18/18)
// FUN_003140d0 @ 0x003140d0
extern "C" double sqrt(double);

struct V3 {
    float x, y, z;
    void FUN_0022d180();
};

struct Box;

struct Shape {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual V3 *v4();
    char pad4[0x40];
    V3 dir;         // 0x44
    float halfLen;  // 0x50
    float radius;   // 0x54
    bool flag;      // 0x58
};

struct Box {
    char pad0[0x48];
    float ext[3];
    V3 axes[3];     // 0x54
    float FUN_002fbcd0(V3 *v);
    float FUN_002fbdc0(V3 *v, int i);
};

class Tester {
public:
    char pad0[0xc];
    float r;        // 0xc
    char pad10[4];
    V3 n;           // 0x14
    bool FUN_00313b70(Box *a, V3 *p, int z0, int z1, Shape **pb, float rad, int z2);
    bool FUN_003140d0(Box *a, Shape *b);
};

bool Tester::FUN_003140d0(Box *a, Shape *b)
{
    Shape *bb = b;
    if (!bb->flag) {
        V3 t;
        float h = bb->halfLen;
        t.x = h * bb->dir.x;
        t.y = h * bb->dir.y;
        t.z = h * bb->dir.z;
        V3 *p = bb->v4();
        t.x = t.x + p->x;
        t.y = t.y + p->y;
        t.z = t.z + p->z;
        if (FUN_00313b70(a, &t, 0, 0, &b, bb->radius, 0))
            return false;
        h = -bb->halfLen;
        t.x = h * bb->dir.x;
        t.y = h * bb->dir.y;
        t.z = h * bb->dir.z;
        p = bb->v4();
        t.x = t.x + p->x;
        t.y = t.y + p->y;
        t.z = t.z + p->z;
        if (FUN_00313b70(a, &t, 0, 0, &b, bb->radius, 0))
            return false;
    }
    union { float f; unsigned u; } ab;
    V3 *d = &bb->dir;
    double e = a->FUN_002fbcd0(d) + bb->halfLen;
    volatile float dot = d->z * n.z + d->y * n.y + d->x * n.x;
    ab.f = dot;
    ab.u &= 0x7fffffff;
    dot = ab.f;
    double reach = e + r;
    if (reach < dot)
        return true;
    for (int i = 0; i < 3; i++) {
        V3 *c = &a->axes[i];
        volatile float dd = d->x * c->x + d->z * c->z + d->y * c->y;
        volatile float nc = c->z * n.z + c->y * n.y + c->x * n.x;
        ab.f = dd;
        ab.u &= 0x7fffffff;
        volatile float a1 = ab.f;
        ab.f = nc;
        ab.u &= 0x7fffffff;
        volatile float a2 = ab.f;
        double s = sqrt(1.0f - a1 * a1) * bb->radius;
        s = s + a1 * bb->halfLen;
        s = s + a->ext[i];
        s = s + r;
        if (s < a2)
            return true;
    }
    for (int i = 0; i < 3; i++) {
        V3 *c = &a->axes[i];
        V3 cr;
        cr.x = c->y * d->z - d->y * c->z;
        cr.y = d->x * c->z - d->z * c->x;
        cr.z = d->y * c->x - d->x * c->y;
        if (r > 0.0f)
            cr.FUN_0022d180();
        double e2 = a->FUN_002fbdc0(&cr, i) + bb->radius;
        volatile float dc = cr.x * n.x + cr.y * n.y + cr.z * n.z;
        ab.f = dc;
        ab.u &= 0x7fffffff;
        dc = ab.f;
        double reach2 = e2 + r;
        if (reach2 < dc)
            return true;
    }
    return false;
}
