// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 8/8)
// hulkfight::motion::FlyingBrakeAction::vfunc_3 @ 0x00134190
struct V3 {
    float x, y, z;
    float FUN_0022d110();
};
struct Name {
    unsigned int lo, hi;
    void FUN_0027b040(const char* s);
};
struct Xform {
    char data[0x54];
    void FUN_00221be0(const Xform* src);
};
void* FUN_00263ea0(unsigned int size);

class JointDriver {
public:
    virtual void AddRef();
    char pad4[4];
    Name name;
    char pad10[4];
    int enabled;
    Xform xform;
    JointDriver* FUN_002248f0(int a);
};

struct Timing {
    bool FUN_000356c0(V3* out);
};
struct Skeleton {
    char pad0[0x10];
    Xform xform;
    void FUN_00222890(JointDriver* d, float a, float b, float c, float e, float f, float g);
};
struct Clock {
    Timing* FUN_00059a30();
    Skeleton* FUN_00059a40();
};
struct Target {
    Clock* FUN_000592a0();
};
class Config {
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
    Config* cfg;
    Target* target;
    JointDriver* driver;
    V3 pos;
    V3 vel;
};

bool FlyingBrakeAction::vfunc_3(int a, int b)
{
    Clock* clock = target->FUN_000592a0();
    Timing* timing = clock->FUN_00059a30();
    Skeleton* skel = clock->FUN_00059a40();
    if (skel == 0)
        return false;
    Config* c = cfg;
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
        V3 dir;
        dir.x = pos.x;
        dir.y = 0.0f;
        dir.z = pos.z;
        float len = dir.FUN_0022d110();
        float s = cfg->maxSpeed;
        if (s > len)
            s = len;
        vel.x = dir.x * s;
        vel.z = dir.z * s;
        vel.y = s * dir.y;
        vel.x = vel.x - pos.x;
        vel.y = vel.y - pos.y;
        vel.z = vel.z - pos.z;
        vel.y = 0.0f;
        float r = 1.0f / f;
        vel.x = vel.x * r;
        vel.y = vel.y * r;
        vel.z = vel.z * r;
    }
    return true;
}
