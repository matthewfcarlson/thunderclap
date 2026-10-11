// STATUS: equivalent (tools/equiv.py level 3: 65 inputs, branch coverage 20/20)
// hulkfight::motion::GroundSlideAction::vfunc_3 @ 0x00151220
extern "C" double sqrt(double);

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
    void FUN_00221d20(float a);
};
void* FUN_00263ea0(unsigned int size);
float FUN_00224f10(V3* v);

class JointDriver {
public:
    virtual void AddRef();
    char pad4[4];
    Name name;
    char pad10[8];
    Xform xform;
    JointDriver* FUN_002248f0(int a);
};

struct Timing {
    bool FUN_000356c0(V3* out);
};
struct Skeleton {
    void FUN_00222890(JointDriver* d, float a, float b, float c, float e, float f, float g);
};
struct Clock {
    Timing* FUN_00059a30();
    Skeleton* FUN_00059a40();
};
struct Target {
    Clock* FUN_000592a0();
};
struct Config {
    char pad0[0x14];
    float angleOffset;
    char pad18[0x20 - 0x18];
    float minSpeed;
    float f24;
    float f28;
    float f2c;
    float f30;
    float f34;
};

class GroundSlideAction {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual bool vfunc_3(int a, int b);
    char pad04[0x1c - 4];
    Config* cfg;
    Target* target;
    JointDriver* driver;
    float speed;
};

bool GroundSlideAction::vfunc_3(int a, int b)
{
    Clock* clock = target->FUN_000592a0();
    Timing* timing = clock->FUN_00059a30();
    Skeleton* skel = clock->FUN_00059a40();
    if (skel == 0)
        return false;
    V3 dir;
    dir.x = 0.0f; dir.y = 0.0f; dir.z = 0.0f;
    if (!timing->FUN_000356c0(&dir))
        return false;
    speed = (float)sqrt(dir.z * dir.z + dir.x * dir.x + dir.y * dir.y);
    dir.y = 0.0f;
    dir.FUN_0022d110();
    Config* c = cfg;
    if (c->minSpeed > 0.0f && c->minSpeed > speed)
        speed = c->minSpeed;
    float lim24 = c->f24;
    if (lim24 > 0.0f && speed <= lim24)
        return false;
    float lim28 = c->f28;
    if (lim28 > 0.0f && lim28 > lim24 && speed > lim28)
        speed = lim28;
    float c2c = c->f2c;
    float c30 = c->f30;
    float c34 = c->f34;
    void* mem = FUN_00263ea0(0x70);
    JointDriver* d;
    if (mem != 0)
        d = ((JointDriver*)mem)->FUN_002248f0(0);
    else
        d = 0;
    driver = d;
    d->name.FUN_0027b040("groundSlide");
    driver->AddRef();
    skel->FUN_00222890(driver, -1.0f, c2c, 1.0f, c30, c34, -1.0f);
    float ang = FUN_00224f10(&dir);
    driver->xform.FUN_00221d20(ang + cfg->angleOffset);
    return true;
}
