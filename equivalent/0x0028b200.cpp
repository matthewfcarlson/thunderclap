// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0028b200 @ 0x0028b200
struct Vec3 {
    float x, y, z;
};

class Curve {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4(int key, Vec3* out);
};

// Linearly interpolates between the values of two curves sampled at key.
void FUN_0028b200(Vec3* out, Curve* a, Curve* b, float t, int key)
{
    Vec3 va, vb;
    a->vfunc_4(key, &va);
    b->vfunc_4(key, &vb);
    va.x = (vb.x - va.x) * t + va.x;
    out->x = va.x;
    va.y = (vb.y - va.y) * t + va.y;
    out->y = va.y;
    va.z = (vb.z - va.z) * t + va.z;
    out->z = va.z;
}
