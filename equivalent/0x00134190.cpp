// STATUS: equivalent (tools/equiv.py level 3: 19951 inputs, branch coverage 8/8)
// hulkfight::motion::FlyingBrakeAction::vfunc_3 @ 0x00134190
struct V3_134190 {
    float x, y, z;
    float FUN_0022d110();
};
struct Name_134190 {
    unsigned int lo, hi;
    void FUN_0027b040(const char* s);
};
struct Xform_134190 {
    char data[0x54];
    void FUN_00221be0(const Xform_134190* src);
};
void* FUN_00263ea0(unsigned int size);

class JointDriver {
public:
    virtual void AddRef();
    char pad4[4];
    Name_134190 name;
    char pad10[4];
    int enabled;
    Xform_134190 xform;
    JointDriver* FUN_002248f0(int a);
};

struct Timing_134190 {
    bool FUN_000356c0(V3_134190* out);
};
struct Skeleton {
    char pad0[0x10];
    Xform_134190 xform;
    void FUN_00222890(JointDriver* d, float a, float b, float c, float e, float f, float g);
};
struct Clock_134190 {
    Timing_134190* FUN_00059a30();
    Skeleton* FUN_00059a40();
};
struct Target_134190 {
    Clock_134190* FUN_000592a0();
};
class Config_134190 {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual float GetSpeed();
    char pad8[0x14 - 4];
    float maxSpeed;
    char pad18[0x24 - 0x18];
    float f24;
    float f28;
    float f2c;
};

class FlyingBrakeAction {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual bool vfunc_3(int a, int b);
    char pad04[0x1c - 4];
    Config_134190* cfg;
    Target_134190* target;
    JointDriver* driver;
    V3_134190 pos;
    V3_134190 vel;
};

bool FlyingBrakeAction::vfunc_3(int a, int b)
{
    Clock_134190* clock = target->FUN_000592a0();
    Timing_134190* timing = clock->FUN_00059a30();
    Skeleton* skel = clock->FUN_00059a40();
    if (skel == 0)
        return false;
    Config_134190* c = cfg;
    float c28 = c->f28;
    float c2c = c->f2c;
    float c24 = c->f24;
    void* mem = FUN_00263ea0(0x70);
    JointDriver* d;
    if (mem != 0)
        d = ((JointDriver*)mem)->FUN_002248f0(0);
    else
        d = 0;
    driver = d;
    d->name.FUN_0027b040("flyingBrake");
    driver->AddRef();
    driver->enabled = 1;
    driver->xform.FUN_00221be0(&skel->xform);
    skel->FUN_00222890(driver, -1.0f, c24, 1.0f, c28, c2c, -1.0f);
    timing->FUN_000356c0(&pos);
    float f = cfg->GetSpeed();
    if (f > 0.0f) {
        V3_134190 dir;
        dir.x = pos.x;
        dir.y = 0.0f;
        dir.z = pos.z;
        float len = dir.FUN_0022d110();
        float s = cfg->maxSpeed;
        if (s > len)
            s = len;
        // the original rounds each stage through the vel members
        volatile float *v = &vel.x;
        v[0] = dir.x * s;
        v[2] = dir.z * s;
        v[1] = s * dir.y;
        v[0] = v[0] - pos.x;
        v[1] = v[1] - pos.y;
        v[2] = v[2] - pos.z;
        v[1] = 0.0f;
        double r = 1.0f / f;
        v[0] = v[0] * r;
        v[1] = v[1] * r;
        v[2] = v[2] * r;
    }
    return true;
}
