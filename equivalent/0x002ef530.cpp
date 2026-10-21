// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 0/0)
// physics::SimState::vfunc_8 @ 0x002ef530
struct Vec3_2ef530 {
    float x, y, z;
};

class SimState {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8(const Vec3_2ef530 *p, Vec3_2ef530 *out, int unused);
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    char pad04[0x3c];
    Vec3_2ef530 origin;
    char pad4c[4];
    Vec3_2ef530 offset;
    Vec3_2ef530 axis;
};

void SimState::vfunc_8(const Vec3_2ef530 *p, Vec3_2ef530 *out, int unused)
{
    double dx = p->x - origin.x;
    double dy = p->y - origin.y;
    double dz = p->z - origin.z;
    // ny and nz are rounded frame copies in the original; nx stays in a register
    volatile float ny = dx * axis.z - dz * axis.x;
    volatile float nz = dy * axis.x - dx * axis.y;
    double nx = dz * axis.y - dy * axis.z;
    volatile float *o = &out->x;
    o[1] = ny;
    o[2] = nz;
    o[0] = nx;
    o[0] = o[0] + offset.x;
    o[1] = ny + offset.y;
    o[2] = nz + offset.z;
}
