// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// physics::PhysicsJoint1D::vfunc_17 @ 0x00309c10
struct V3_309c10 {
    float x, y, z;
};

namespace physics {

class PhysicsJoint1D {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void GetAxis(V3_309c10 *out);
    virtual void v16();
    virtual void vfunc_17(V3_309c10 *a, float s, V3_309c10 *out);
};

void PhysicsJoint1D::vfunc_17(V3_309c10 *a, float s, V3_309c10 *out)
{
    V3_309c10 l;
    GetAxis(&l);
    float cx = l.y * a->z - l.z * a->y;
    float cy = l.z * a->x - l.x * a->z;
    l.z = l.x * a->y - l.y * a->x;
    volatile float inv = 1.0f / s;
    l.x = cx * inv;
    float sy = cy * inv;
    float sz = l.z * inv;
    float dot = sy * out->y + l.x * out->x + sz * out->z;
    out->x = l.x * dot;
    out->y = sy * dot;
    out->z = sz * dot;
}

}
