// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// CNISCamera::vfunc_27 @ 0x000ac4f0
struct Vec3_ac4f0 { float x, y, z; };
struct CameraPose {
    char pad00[0x20];
    Vec3_ac4f0 a;
    float pad2c;
    Vec3_ac4f0 b;
};
class CNISCamera {
  public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13();
    virtual CameraPose* GetPose();
    Vec3_ac4f0* FUN_000ac4f0(Vec3_ac4f0* out);
};
Vec3_ac4f0* CNISCamera::FUN_000ac4f0(Vec3_ac4f0* out) {
    CameraPose* p = GetPose();
    float x = p->a.x * 10.0f;
    float y = p->a.y * 10.0f;
    float z = p->a.z * 10.0f;
    CameraPose* q = GetPose();
    out->x = x + q->b.x;
    out->y = y + q->b.y;
    out->z = z + q->b.z;
    return out;
}
