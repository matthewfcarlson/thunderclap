// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// pure3d::Camera::vfunc_19 @ 0x00292a90
struct Vec3_292a90 {
    float x, y, z;
};

class Camera {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18();
    virtual unsigned int vfunc_19(const Vec3_292a90 *p);
    char pad04[0x14];
    float yScale;            // 0x18
    float nearDist;          // 0x1c
    float farDist;           // 0x20
    float xFactor;           // 0x24
    float yFactor;           // 0x28
};

// Frustum outcode of a point: bit 0/1 near/far, 2/3 top/bottom, 4/5 left/right.
unsigned int Camera::vfunc_19(const Vec3_292a90 *p) {
    unsigned int code = 0;
    float z = p->z;
    float x = xFactor * p->x;
    float y = yFactor * p->y;
    if (z > farDist)
        code = 2;
    else if (z < nearDist)
        code = 1;
    if (y * yScale > z)
        code |= 4;
    else if (-(y * yScale) > z)
        code |= 8;
    if (x > z)
        code |= 0x20;
    else if (-x > z)
        code |= 0x10;
    return code;
}
