// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// hulkfight::motion::TankLocomotionAction::vfunc_3 @ 0x0018f350
struct Vec3 {
    float x, y, z;
};

struct Key {
    unsigned lo;
    unsigned hi;
    void FUN_0027b040(const char *name);
};

void *__cdecl FUN_00263ea0(unsigned int size);

class JointDriver {
public:
    virtual void AddRef();
    char pad4[4];
    Key name;
    char pad10[0x60];
    JointDriver *FUN_002248f0(int arg);
};

struct Fighter {
    char pad0[0x8c];
    int f8c;
    void FUN_00035980(char flag);
};

struct Skeleton {
    void FUN_00222890(JointDriver *drv, float a, float b, float c, float d, float e, float f);
};

struct Holder {
    Fighter *FUN_00059a30();
    Skeleton *FUN_00059a40();
    void FUN_00059a50(Vec3 *out);
};

struct HolderSource {
    Holder *FUN_000592a0();
};

struct Target {
    char pad0[0x68];
    Vec3 aim;
};

class TankLocomotionAction {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool vfunc_3(int a, int b);
    virtual void vfunc_4();
    virtual void vfunc_5();
    char pad04[0x18];
    Target *target;
    HolderSource *source;
    JointDriver *driver;
    char pad28[8];
    Vec3 p30;
    Vec3 p3c;
    Vec3 p48;
    Vec3 p54;
    Vec3 d60;
    Vec3 d6c;
    Vec3 d78;
    Vec3 d84;
    int f90;
};

bool TankLocomotionAction::vfunc_3(int a, int b)
{
    Holder *holder = source->FUN_000592a0();
    Fighter *fighter = holder->FUN_00059a30();
    Skeleton *skel = holder->FUN_00059a40();
    if (skel == 0)
        return false;

    float ax = target->aim.x;
    float ay = target->aim.y;
    float az = target->aim.z;

    void *mem = FUN_00263ea0(0x70);
    JointDriver *drv = 0;
    if (mem != 0)
        drv = ((JointDriver *)mem)->FUN_002248f0(0);
    driver = drv;
    drv->name.FUN_0027b040("tankLocomotion");
    driver->AddRef();
    skel->FUN_00222890(driver, -1.0f, ax, 1.0f, ay, az, -1.0f);

    f90 = fighter->f8c;
    Vec3 pos;
    holder->FUN_00059a50(&pos);
    p30 = pos;
    d60.x = 0;
    d60.y = 1.0f;
    d60.z = 0;
    p3c = pos;
    d6c.x = 0;
    d6c.y = 1.0f;
    d6c.z = 0;
    p48 = pos;
    d78.x = 0;
    d78.y = 1.0f;
    d78.z = 0;
    p54 = pos;
    d84.x = 0;
    d84.y = 1.0f;
    d84.z = 0;
    fighter->FUN_00035980(1);
    return true;
}
