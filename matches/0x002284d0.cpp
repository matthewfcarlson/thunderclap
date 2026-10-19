// choreo2::LocomotionStrafeDriver::vfunc_9 @ 0x002284d0
struct Vec3_2284d0 {
    float x, y, z;
};

class LocomotionStrafeDriver {
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
    virtual void vfunc_9(float dt);
    char pad04[0x14];
    int blocked;
    char pad1c[0x12dc - 0x1c];
    char applyMotion;
    char pad12dd[0x1320 - 0x12dd];
    Vec3_2284d0 offset;
    void FUN_00228120(float dt);
};

struct ThisCall_00226250 {
    void FUN_00226250(Vec3_2284d0* out);
};

void LocomotionStrafeDriver::vfunc_9(float dt) {
    if (applyMotion && blocked == 0) {
        Vec3_2284d0 d;
        ((ThisCall_00226250*)(this))->FUN_00226250(&d);
        volatile float* scaledZ = &d.z;
        float x = d.x * dt;
        float y = d.y * dt;
        *scaledZ = d.z * dt;
        offset.x = x + offset.x;
        offset.y = y + offset.y;
        offset.z = *scaledZ + offset.z;
    }
    FUN_00228120(dt);
}
