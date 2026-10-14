// STATUS: equivalent (tools/equiv.py level 3: 349 inputs, branch coverage 32/32)
// hulkfight::motion::ClimbLocomotionAction::vfunc_3 @ 0x0015ed10
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
// equiv-map: ??_R0?AVDriver@choreo2@@@8 = 0x0048d534
// equiv-map: ??_R0?AVLocomotionStrafeDriver@choreo2@@@8 = 0x0048d554
struct V3_15ed10 {
    float x, y, z;
};

struct Name_15ed10 {
    unsigned int lo, hi;
    void FUN_0027b040(const char *s);
};

class JointDriver {
public:
    virtual void AddRef();
    char pad4[4];
    Name_15ed10 name;
    char pad10[4];
    int f14;
    JointDriver *FUN_002248f0(int a);
};

namespace choreo2 {
class Driver {
public:
    virtual void AddRef();
    virtual void v1();
    char pad04[4];
    unsigned int lo;       // 8
    unsigned int hi;       // 0xc
};

class LocomotionStrafeDriver : public Driver {
public:
    virtual void v2();
    char pad10[0x24 - 0x10];
    float f24;
};
}

struct Skeleton;
struct SubSkel {
    float FUN_002220d0();
};

struct Timing_15ed10 {
    void FUN_00035660(V3_15ed10 *out);
    void FUN_00035980(int v);
};

struct Skeleton {
    char pad0[0x10];
    char sub10[4];
    char pad14[0x64 - 0x14];
    int f64;
    unsigned int f68;
    int FUN_002226b0();
    choreo2::Driver *FUN_00222e20(unsigned int i);
    void FUN_00222890(void *driver, float a, int b, float c, float d, float e, float f);
};

struct Clock_15ed10 {
    Timing_15ed10 *FUN_00059a30();
    Skeleton *FUN_00059a40();
};

struct Target_15ed10 {
    Clock_15ed10 *FUN_000592a0();
};

struct Frame_15ed10 {
    char pad0[3];
    char padx;
    float a;               // 0x10
    float best;            // 0x14
    choreo2::LocomotionStrafeDriver *found;  // 0x18
    float s1c;             // 0x1c
    float s20;             // 0x20
    int n24;               // 0x24
    float f28, f2c, f30, f34, f38, f3c, f40;  // 0x28
    int x44;               // 0x44
    unsigned int t48;      // 0x48
    int i4c;               // 0x4c
    int i50;               // 0x50
    char pad54[4];
    unsigned int hi;       // 0x58
    V3_15ed10 q;                  // 0x5c
};

class Climb;
void __cdecl FUN_0015cfd0(int x, Climb *c);
float __cdecl FUN_000964e0();
void *thunk_FUN_0008d690(unsigned int size);

class Climb {
public:
    virtual void v0();
    virtual void release();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual unsigned int v7();
    char pad04[0x18 - 4];
    int f18;
    char pad1c[0x24 - 0x1c];
    float f24;
    char pad28[0x12dc - 0x28];
    char b12dc;
    char b12dd;
    char pad12de[2];
    float f12e0;
    float f12e4;
    float f12e8;
    void FUN_002268f0(V3_15ed10 *v);
};

class ClimbLocomotionAction {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual bool vfunc_3(int a, int b);
    virtual void f4();
    virtual void f5();
    virtual unsigned long long id6();
    virtual void gather(int x, float *p40, float *p3c, float *p38, float *p34, float *p30, float *p2c,
                        float *p28, float *pa, int *p4c, int *p24, float *p20, float *p1c);
    virtual void f8();
    char pad04[0x1c - 4];
    Target_15ed10 *target;        // 0x1c
    Climb *climb;          // 0x20
    JointDriver *driver;   // 0x24

    void FUN_0015c780(float a, float b, float c, float d, float e, float f);
    float FUN_0015ebc0(float a, float b, float c);
};

bool ClimbLocomotionAction::vfunc_3(int a, int b)
{
    Frame_15ed10 f;
    Clock_15ed10 *clock = target->FUN_000592a0();
    Timing_15ed10 *timing = clock->FUN_00059a30();
    Skeleton *skel = clock->FUN_00059a40();
    if (skel == 0)
        return false;
    f.t48 = (unsigned int)timing;
    f.x44 = skel->FUN_002226b0();
    unsigned long long id = id6();
    unsigned int lo = (unsigned int)id;
    f.hi = (unsigned int)(id >> 32);
    f.a = -1.0f;
    f.best = -1.0f;
    f.found = 0;
    for (unsigned int i = 0; i < skel->f68; i++) {
        choreo2::Driver *node = skel->FUN_00222e20(i);
        choreo2::LocomotionStrafeDriver *c = dynamic_cast<choreo2::LocomotionStrafeDriver *>(node);
        if (c) {
            if (f.best < 0.0f)
                f.best = c->f24;
            if ((lo | f.hi) != 0 && c->lo == lo && c->hi == f.hi) {
                f.found = c;
                break;
            }
        }
    }
    if (f.found)
        f.found->AddRef();
    if (climb)
        climb->release();
    climb = (Climb *)f.found;

    f.i4c = 0;
    f.i50 = 0;
    f.n24 = 0;
    f.s1c = 0.1f;
    f.s20 = 0.1f;
    f.f28 = f.f2c = f.f30 = f.f34 = f.f38 = f.f3c = f.f40 = -1.0f;
    f.a = -1.0f;
    int x = f.x44;
    gather(x, &f.f40, &f.f3c, &f.f38, &f.f34, &f.f30, &f.f2c, &f.f28, &f.a, &f.i4c, &f.n24, &f.s20, &f.s1c);
    FUN_0015cfd0(x, climb);
    FUN_0015c780(f.f3c, f.f38, f.f34, f.f30, f.f2c, f.f28);
    if (f.a < 0.0f) {
        f.a = f.best;
        if (f.best < 0.0f)
            f.a = FUN_000964e0();
    }
    climb->f24 = f.a;
    float ft = ((SubSkel *)skel->sub10)->FUN_002220d0();
    climb->f12e0 = ft;
    Timing_15ed10 *tm = (Timing_15ed10 *)f.t48;
    f.q.x = 0.0f;
    f.q.y = 0.0f;
    f.q.z = 0.0f;
    tm->FUN_00035660(&f.q);
    climb->FUN_002268f0(&f.q);
    f.t48 = *(unsigned int *)&climb->f12e0;
    f.x44 = *(int *)&climb->f12e4;
    float v = FUN_0015ebc0(1.0f, climb->f12e4, climb->f12e0);
    if (v > 0.0f && v < climb->f12e8)
        climb->f12e8 = v;
    if (climb->v7() == 0)
        climb->f18 = 1;
    climb->b12dc = 0;
    climb->b12dd = 0;
    skel->FUN_00222890(climb, f.f40, f.n24, 1.0f, f.s20, f.s1c, -1.0f);

    void *mem = thunk_FUN_0008d690(0x70);
    JointDriver *drv = 0;
    if (mem)
        drv = ((JointDriver *)mem)->FUN_002248f0(0);
    driver = drv;
    drv->name.FUN_0027b040("climbLocomotion");
    driver->f14 = 1;
    driver->AddRef();
    skel->FUN_00222890(driver, -1.0f, f.n24 - 1, 1.0f, f.s20, f.s1c, -1.0f);
    tm->FUN_00035980(1);
    return true;
}
