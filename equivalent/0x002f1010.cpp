// STATUS: equivalent (tools/equiv.py level 3: 71 inputs, branch coverage 6/6)
// FUN_002f1010 @ 0x002f1010
struct Vec3_2f1010 {
    float x, y, z;
};

class Shape_2f1010 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual Vec3_2f1010 *vfunc_4();
    char pad04[0x28 - 4];
    Vec3_2f1010 extent;
};

char FUN_002f0080(Vec3_2f1010 *p, Vec3_2f1010 *q, Vec3_2f1010 *extent);
char FUN_002f0e80(Vec3_2f1010 *p, Vec3_2f1010 *q, Vec3_2f1010 *d, float radius, Shape_2f1010 *shape, float *t);

// Segment p -> q tested against a shape grown by radius; on a hit writes the world-space hit point.
// The radius parameter slot receives the hit parameter t.
bool FUN_002f1010(Vec3_2f1010 p, Vec3_2f1010 q, Shape_2f1010 *shape, float radius, Vec3_2f1010 *out)
{
    Vec3_2f1010 ext;
    Vec3_2f1010 d;

    Vec3_2f1010 *o = shape->vfunc_4();
    p.x = p.x - o->x;
    p.y = p.y - o->y;
    p.z = p.z - o->z;
    o = shape->vfunc_4();
    q.x = q.x - o->x;
    q.y = q.y - o->y;
    q.z = q.z - o->z;
    ext.x = radius + shape->extent.x;
    ext.y = radius + shape->extent.y;
    ext.z = radius + shape->extent.z;
    if (FUN_002f0080(&p, &q, &ext))
        return false;

    d.x = q.x - p.x;
    d.y = q.y - p.y;
    d.z = q.z - p.z;
    if (!FUN_002f0e80(&p, &q, &d, radius, shape, &radius))
        return false;

    if (out) {
        o = shape->vfunc_4();
        out->x = p.x + o->x;
        out->y = p.y + o->y;
        out->z = p.z + o->z;
        out->x = d.x * radius + out->x;
        out->y = d.y * radius + out->y;
        out->z = d.z * radius + out->z;
    }
    return true;
}
