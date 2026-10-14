// STATUS: equivalent (tools/equiv.py level 3: 71 inputs, branch coverage 4/4)
// FUN_00301650 @ 0x00301650
struct Vec3_301650 {
    float x, y, z;
};

class Shape_301650 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual Vec3_301650 *GetPos();
    virtual void v5();
    virtual int GetType();
    char pad4[0x24];
    Vec3_301650 normal;
    char pad34[4];
    Vec3_301650 dir;
};

class Contact_301650 {
public:
    char pad0[0xc];
    float f0c;
    char pad10[4];
    Vec3_301650 delta;
    char pad20[0xc];
    float dist;

    // equiv-conv: FUN_00314be0 ecx stack stack stack stack stack stack
    void FUN_00314be0(Shape_301650 *a, Vec3_301650 *p1, Shape_301650 *b, Vec3_301650 *p2, float depth, Vec3_301650 *dir);
    void FUN_00301650(Shape_301650 *b, Shape_301650 *a);
};

void Contact_301650::FUN_00301650(Shape_301650 *b, Shape_301650 *a)
{
    if (a->GetType() == 8)
        return;

    Vec3_301650 *bp = b->GetPos();
    Vec3_301650 *ap = a->GetPos();
    delta.x = ap->x - bp->x;
    delta.y = ap->y - bp->y;
    delta.z = ap->z - bp->z;

    Vec3_301650 *dir = &b->dir;
    float s = dir->z * a->normal.z + dir->y * a->normal.y + dir->x * a->normal.x;
    float absS = s;
    *(unsigned *)&absS = *(unsigned *)&s & 0x7fffffff;

    float d = dir->z * delta.z + dir->y * delta.y + dir->x * delta.x;
    dist = d;
    if (d < absS + f0c) {
        float t = -absS;
        Vec3_301650 p1;
        Vec3_301650 p2;
        ap = a->GetPos();
        p1.x = t * dir->x + ap->x;
        p1.y = t * dir->y + ap->y;
        p1.z = t * dir->z + ap->z;
        t = -dist;
        ap = a->GetPos();
        p2.x = t * dir->x + ap->x;
        p2.y = t * dir->y + ap->y;
        p2.z = t * dir->z + ap->z;
        FUN_00314be0(a, &p1, b, &p2, dist - absS, dir);
    }
}
