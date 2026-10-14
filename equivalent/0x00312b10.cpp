// STATUS: equivalent (tools/equiv.py level 3: 15504 inputs, branch coverage 21/22, incomplete)
// physics::CollisionAABB::vfunc_8 @ 0x00312b10
// physics::CollisionAABB::vfunc_8 @ 0x00312b10
struct Vec3_312b10 { float x, y, z; };

namespace physics {

class CollisionAABB;

struct VolumeList {
    CollisionAABB **begin;
    CollisionAABB **end;
};

class CollisionAABB {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual Vec3_312b10 *GetCenter();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void RecomputeBounds();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    char pad04[0xc];
    CollisionAABB *parent;
    VolumeList *children;
    unsigned char active;
    unsigned char dirty;
    char pad1a[6];
    CollisionAABB *owned;
    char pad24[4];
    Vec3_312b10 halfExtent;
    float radius;
    void FUN_003129e0(Vec3_312b10 *hi, Vec3_312b10 *lo, CollisionAABB *child);
};

}

void physics::CollisionAABB::RecomputeBounds()
{
    bool first = true;
    dirty = 1;
    if (!active)
        return;
    if (children == 0)
        return;
    if ((unsigned int)(children->end - children->begin) == 0)
        return;

    Vec3_312b10 hi;
    Vec3_312b10 lo;
    for (unsigned int i = 0; i < (unsigned int)(children->end - children->begin); i++) {
        CollisionAABB *child = children->begin[i];
        if (child->active) {
            child->RecomputeBounds();
            if (first) {
                first = false;
                Vec3_312b10 *c = child->GetCenter();
                hi.x = c->x + child->halfExtent.x;
                hi.y = c->y + child->halfExtent.y;
                hi.z = c->z + child->halfExtent.z;
                c = child->GetCenter();
                lo.x = c->x - child->halfExtent.x;
                lo.y = c->y - child->halfExtent.y;
                lo.z = c->z - child->halfExtent.z;
            } else {
                FUN_003129e0(&hi, &lo, child);
            }
        }
    }

    Vec3_312b10 *c = GetCenter();
    c->x = lo.x + hi.x;
    c->y = lo.y + hi.y;
    c->z = lo.z + hi.z;
    c = GetCenter();
    c->x = c->x * 0.5f;
    c->y = c->y * 0.5f;
    c->z = c->z * 0.5f;

    // the difference is stored as a float before it is halved (it can overflow to infinity)
    volatile Vec3_312b10 *half = &halfExtent;
    half->x = hi.x - lo.x;
    half->y = hi.y - lo.y;
    half->z = hi.z - lo.z;
    half->x = half->x * 0.5f;
    half->y = half->y * 0.5f;
    half->z = half->z * 0.5f;

    if (parent != 0 && parent->owned == this) {
        float m = (halfExtent.y < halfExtent.z) ? halfExtent.z : halfExtent.y;
        if (!(m > halfExtent.x))
            m = halfExtent.x;
        radius = m * 1.732f;
    }
}
