// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// physics::SimpleFilter3D::vfunc_0 @ 0x003196a0
struct Vec3 {
    float x, y, z;
};

class SimpleFilter3D {
public:
    virtual bool vfunc_0(const Vec3* origin, const Vec3* extent, int unused);
    virtual void vfunc_1();
    virtual void vfunc_2();
    float inv[3];       // 0x04
    char pad10[0x1c - 0x10];
    int origin[3];      // 0x1c
    float field28;      // 0x28
};

// Stores the origin and the reciprocal of each extent; fails unless every extent is positive.
bool SimpleFilter3D::vfunc_0(const Vec3* o, const Vec3* e, int unused)
{
    if (e->x > 0.0f && e->y > 0.0f && e->z > 0.0f) {
        const int* src = (const int*)o;
        origin[0] = src[0];
        origin[1] = src[1];
        origin[2] = src[2];
        inv[0] = 1.0f / e->x;
        inv[1] = 1.0f / e->y;
        field28 = 0.0f;
        inv[2] = 1.0f / e->z;
        return true;
    }
    return false;
}
