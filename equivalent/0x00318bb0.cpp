// STATUS: equivalent (tools/equiv.py level 3: 3025 inputs, branch coverage 14/14)
// FUN_00318bb0 @ 0x00318bb0
struct Vec3_318bb0 { float x, y, z; };

union FloatBits_318bb0 {
    float f;
    unsigned int u;
};

class Shape_318bb0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual Vec3_318bb0 *position();
    char pad04[0x44 - 4];
    Vec3_318bb0 normal;
    float extent;
    float limit;
    unsigned char active;
};

bool __cdecl FUN_00314380(Shape_318bb0 *a, Shape_318bb0 *b, Vec3_318bb0 *dir, Vec3_318bb0 *out);

class Contact_318bb0 {
public:
    char pad00[0x14];
    Vec3_318bb0 delta;
    void FUN_00316410(Shape_318bb0 *a, Vec3_318bb0 *out, Vec3_318bb0 *normal, float extent, Shape_318bb0 *b, float d1, float d2, int one);
    void Test(Shape_318bb0 *a, Shape_318bb0 *b);
};

void Contact_318bb0::Test(Shape_318bb0 *a, Shape_318bb0 *b)
{
    struct Frame {
        char pad[3];
        bool parallel;
        int counter;
        float adot;
        float crossVal;
        float crossAbs;
        Vec3_318bb0 dir;
        Vec3_318bb0 out;
    } fr;
    Shape_318bb0 *p = b;
    Shape_318bb0 *q = a;
    FloatBits_318bb0 bits;

    bits.f = p->normal.z * q->normal.z + p->normal.y * q->normal.y + p->normal.x * q->normal.x;
    bits.u &= 0x7fffffff;
    fr.adot = bits.f;
    fr.counter = 2;
    do {
        if (p->active) {
            if (fr.adot < 0.1f) {
                fr.parallel = true;
                fr.dir = p->normal;
            } else {
                fr.parallel = false;
                Vec3_318bb0 *qp = q->position();
                Vec3_318bb0 *pp = p->position();
                fr.dir.x = pp->x - qp->x;
                fr.dir.y = pp->y - qp->y;
                fr.dir.z = pp->z - qp->z;
            }
            if (FUN_00314380(q, p, &fr.dir, &fr.out)) {
                bool ok = true;
                Vec3_318bb0 *pp = p->position();
                Vec3_318bb0 *qp = q->position();
                delta.x = qp->x - pp->x;
                delta.y = qp->y - pp->y;
                delta.z = qp->z - pp->z;
                if (fr.parallel) {
                    fr.dir.x = p->normal.y * q->normal.z - p->normal.z * q->normal.y;
                    fr.dir.y = q->normal.x * p->normal.z - p->normal.x * q->normal.z;
                    fr.dir.z = p->normal.x * q->normal.y - q->normal.x * p->normal.y;
                    fr.crossVal = (fr.out.z + delta.z) * fr.dir.z + (fr.out.y + delta.y) * fr.dir.y +
                                  (fr.out.x + delta.x) * fr.dir.x;
                    bits.f = fr.crossVal;
                    bits.u &= 0x7fffffff;
                    fr.crossAbs = bits.f;
                    if (fr.crossAbs > p->limit) {
                        Vec3_318bb0 *qp2 = q->position();
                        Vec3_318bb0 *pp2 = p->position();
                        fr.dir.x = pp2->x - qp2->x;
                        fr.dir.y = pp2->y - qp2->y;
                        fr.dir.z = pp2->z - qp2->z;
                        ok = FUN_00314380(q, p, &fr.dir, &fr.out);
                    }
                }
                if (ok) {
                    FUN_00316410(q, &fr.out, &q->normal, q->extent, p,
                                 p->normal.z * delta.z + p->normal.y * delta.y + p->normal.x * delta.x,
                                 (p->normal.z * q->normal.z + p->normal.y * q->normal.y + p->normal.x * q->normal.x) * q->extent,
                                 1);
                }
            }
        }
        q = b;
        p = a;
        fr.counter--;
    } while (fr.counter != 0);
}
