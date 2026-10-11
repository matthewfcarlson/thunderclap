// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// FUN_00302200 @ 0x00302200
extern "C" double sqrt(double);

struct Vec3 { float x, y, z; };

struct Vec3N {
    float x, y, z;
    void FUN_0022d180();
};

class Body {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual Vec3 *GetPos();
    char pad4[0x34 - 4];
    float radius;
};

struct Resolver {
    char pad0[0xc];
    float margin;
    void FUN_00314be0(Body *a, Vec3 *pa, Body *b, Vec3 *pb, float depth, Vec3N *normal);
    void Resolve(Body *a, Body *b);
};

void Resolver::Resolve(Body *a, Body *b)
{
    Vec3 d;
    Vec3 *pb = b->GetPos();
    Vec3 *pa = a->GetPos();
    d.x = pa->x - pb->x;
    d.y = pa->y - pb->y;
    d.z = pa->z - pb->z;
    float len = (float)sqrt(d.z * d.z + d.y * d.y + d.x * d.x);

    if (a->radius + b->radius + margin > len) {
        Vec3N n;
        n.x = d.x;
        n.y = d.y;
        n.z = d.z;
        if (!(len > 0.0f))
            n.x = 1.0f;
        n.FUN_0022d180();

        n.x = n.x * -1.0f;
        n.y = n.y * -1.0f;
        n.z = n.z * -1.0f;

        float ra = a->radius;
        Vec3 *q = a->GetPos();
        Vec3 p1;
        p1.x = ra * n.x + q->x;
        p1.y = n.y * ra + q->y;
        p1.z = n.z * ra + q->z;

        float rb = b->radius;
        n.x = n.x * -1.0f;
        n.y = n.y * -1.0f;
        n.z = n.z * -1.0f;
        q = b->GetPos();
        Vec3 p2;
        p2.x = rb * n.x + q->x;
        p2.y = n.y * rb + q->y;
        p2.z = n.z * rb + q->z;

        FUN_00314be0(a, &p1, b, &p2, len - (a->radius + b->radius), &n);
    }
}
