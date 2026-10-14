// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 6/6)
// hulkfight::motion::AirToGroundTargetAction::vfunc_3 @ 0x001349a0
struct V3_1349a0 {
    float x, y, z;
    float FUN_0022d110();
};
struct Name_1349a0 {
    unsigned int lo, hi;
    void FUN_0027b040(const char* s);
};
struct Xform_1349a0 {
    char data[0x54];
    void FUN_00221be0(const Xform_1349a0* src);
};
void* FUN_00263ea0(unsigned int size);

class JointDriver {
public:
    virtual void AddRef();
    char pad4[4];
    Name_1349a0 name;
    char pad10[8];
    Xform_1349a0 xform;
    JointDriver* FUN_002248f0(int a);
};

struct Timing_1349a0 {
    bool FUN_00035550(V3_1349a0* out);
    bool FUN_000356c0(V3_1349a0* out);
};
struct Skeleton {
    char pad0[0x10];
    Xform_1349a0 xform;
    void FUN_00222890(JointDriver* d, float a, float b, float c, float e, float f, float g);
};
struct Clock_1349a0 {
    Timing_1349a0* FUN_00059a30();
    Skeleton* FUN_00059a40();
};
struct Target_1349a0 {
    Clock_1349a0* FUN_000592a0();
};
struct Config_1349a0 {
    char pad0[0x20];
    float f20;
    char pad24[8];
    float f2c;
    float f30;
    float f34;
};
struct Sink_1349a0 {
    void FUN_00099d40(struct World* w, Timing_1349a0* t, float v);
};
struct World {
    char pad0[8];
    Sink_1349a0* sink;
};
extern World* DAT_004dd700;
extern float DAT_003f32e0;

class AirToGroundTargetAction {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual bool vfunc_3(int a, int b);
    char pad04[0x1c - 4];
    Config_1349a0* cfg;
    Target_1349a0* target;
    JointDriver* driver;
    char pad28[4];
    float speed;
    float lateral;
};

bool AirToGroundTargetAction::vfunc_3(int a, int b)
{
    Clock_1349a0* clock = target->FUN_000592a0();
    Timing_1349a0* timing = clock->FUN_00059a30();
    Skeleton* skel = clock->FUN_00059a40();
    if (skel == 0)
        return false;
    Config_1349a0* c = cfg;
    float c30 = c->f30;
    float c34 = c->f34;
    float c2c = c->f2c;
    void* mem = FUN_00263ea0(0x70);
    JointDriver* d;
    if (mem != 0)
        d = ((JointDriver*)mem)->FUN_002248f0(0);
    else
        d = 0;
    driver = d;
    d->name.FUN_0027b040("airToGroundTarget");
    driver->AddRef();
    driver->xform.FUN_00221be0(&skel->xform);
    skel->FUN_00222890(driver, -1.0f, c2c, 1.0f, c30, c34, -1.0f);
    V3_1349a0 fwd;
    fwd.x = 0.0f;
    fwd.y = 0.0f;
    fwd.z = -1.0f;
    timing->FUN_00035550(&fwd);
    fwd.y = 0.0f;
    fwd.FUN_0022d110();
    V3_1349a0 vel;
    vel.x = 0.0f;
    vel.y = 0.0f;
    vel.z = 0.0f;
    timing->FUN_000356c0(&vel);
    lateral = vel.y;
    vel.y = 0.0f;
    float s = vel.x * fwd.x + vel.z * fwd.z + fwd.y * 0.0f;
    if (s < 0.0f)
        speed = 0.0f;
    else
        speed = s;
    DAT_004dd700->sink->FUN_00099d40(DAT_004dd700, timing, cfg->f20);
    return true;
}
