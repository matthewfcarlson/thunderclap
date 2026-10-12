// STATUS: equivalent (tools/equiv.py level 3: 68 inputs, branch coverage 18/18)
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
    V3 *d = &bb->dir;
    double e = a->FUN_002fbcd0(d) + bb->halfLen;
    float dot = d->z * n.z + d->y * n.y + d->x * n.x;
    if (dot < 0)
        dot = -dot;
    if (e + r < dot)
        return true;
    for (int i = 0; i < 3; i++) {
        V3 *c = &a->axes[i];
        float dd = d->x * c->x + d->z * c->z + d->y * c->y;
        float nc = c->z * n.z + c->y * n.y + c->x * n.x;
        float a1 = dd < 0 ? -dd : dd;
        float a2 = nc < 0 ? -nc : nc;
        if (sqrt(1.0f - a1 * a1) * bb->radius + a1 * bb->halfLen + a->ext[i] + r < a2)
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
        float dc = cr.x * n.x + cr.y * n.y + cr.z * n.z;
        if (dc < 0)
            dc = -dc;
        if (e2 + r < dc)
            return true;
    }
    return false;
}
