// STATUS: equivalent (tools/equiv.py level 3: 20051 inputs, branch coverage 31/32, incomplete)
// hulkfight::motion::SyncToLocatorAction::vfunc_3 @ 0x00171e60
// cl-flags: /GS
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
#include "compat/ptr.h"
#include "decls/address.h"
struct V3_171e60 {
    float x, y, z;
    void FUN_00011220(V3_171e60 *v);
    void FUN_00011140(float s);
};

struct Id64_171e60 {
    unsigned int lo, hi;
    void FUN_0027af70(Id64_171e60 *src);
    void FUN_0027b040(const char *name);
};

struct Xform_171e60 {
    char data[0x54];
    void FUN_00221d20(float a);
    void FUN_0022be40(const V3_171e60 *pos);
};

struct Name_171e60 {
    unsigned int lo, hi;
    void FUN_0027b040(const char *s);
};

class JointDriver {
public:
    virtual void AddRef();
    char pad4[4];
    Name_171e60 name;
    char pad10[8];
    Xform_171e60 xform;
    JointDriver *FUN_002248f0(int a);
};

struct Skeleton {
    char pad0[0x10];
    char sub10[4];
    void FUN_00222890(JointDriver *d, float a, float b, float c, float e, float f, float g);
};

struct SubSkel {
    float FUN_002220d0();
};

struct Anchor_171e60 {
    char FUN_00059a50(V3_171e60 *out);
};

struct Timing_171e60 {
    char pad0[0x10];
    Anchor_171e60 *anchor;
    float FUN_000354c0();
};

struct Clock_171e60 {
    Skeleton *FUN_00059a40();
    Timing_171e60 *FUN_00059a30();
};

struct Target_171e60 {
    Clock_171e60 *FUN_000592a0();
};

class Located {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual V3_171e60 *v8(V3_171e60 *out);
    virtual float v9();
};

class Cfg_171e60 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual float v6();
    virtual float v7();
    char pad04[0x14 - 4];
    float f14;
    float f18;
    char pad1c[4];
    Id64_171e60 id20;
    const char *name28;
    int f2c;
    int mode30;
    float f34;
    V3_171e60 v38;
    float f44;
    float f48;
    float f4c;
};

struct Registry_171e60 {
    int FUN_001d35a0(const char *name, const char *tag, int v);
    char FUN_001d19f0(char *buf, int size, int flag);
};
Registry_171e60 *FUN_001d4c90();

struct Finder_171e60 {
    Located *FUN_001fc8c0(unsigned int lo, unsigned int hi);
};
struct World {
    char pad0[0x28];
    Finder_171e60 *f28;
};

void *thunk_FUN_0008d690(unsigned int size);
float __cdecl FUN_00224fc0(float a, float b);

class SyncToLocatorAction {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual bool vfunc_3(int a, int b);
    virtual void f4();
    virtual void f5();
    char pad04[0x1c - 4];
    Cfg_171e60 *cfg;              // 0x1c
    Target_171e60 *target;        // 0x20
    char pad24[4];
    Id64_171e60 id;               // 0x28
    JointDriver *driver;   // 0x30
    float f34;
    V3_171e60 v38;                // 0x38
    float f44;
    V3_171e60 v48;                // 0x48
};

struct Frame_171e60 {
    float d;               // 0x10
    float t14;             // 0x14
    int t18;               // 0x18
    V3_171e60 tmp;                // 0x1c
    int t28;               // 0x28
    V3_171e60 p;                  // 0x2c
    char buf[0x400];       // 0x38
};

bool SyncToLocatorAction::vfunc_3(int a, int b)
{
    Frame_171e60 f;
    if (target == 0 || cfg->v7() <= 0.0f) {
        return false;
    }
    Clock_171e60 *clock = target->FUN_000592a0();
    Skeleton *skel = clock->FUN_00059a40();
    if (skel == 0) {
        return false;
    }
    Timing_171e60 *timing = clock->FUN_00059a30();
    hulk_freg c4c = cfg->f4c;
    hulk_freg c48 = cfg->f48;
    hulk_freg c44 = cfg->f44;
    void *mem = thunk_FUN_0008d690(0x70);
    JointDriver *drv = 0;
    if (mem)
        drv = ((JointDriver *)mem)->FUN_002248f0(0);
    driver = drv;
    drv->name.FUN_0027b040("syncToLocator");
    driver->AddRef();
    f.d = ((SubSkel *)skel->sub10)->FUN_002220d0();
    driver->xform.FUN_00221d20(f.d);
    driver->xform.FUN_0022be40((V3_171e60 *)((char *)skel + 0x40));
    skel->FUN_00222890(driver, -1.0f, c44, 1.0f, c48, c4c, -1.0f);

    id.FUN_0027af70(&cfg->id20);
    if (id.lo == 0 && id.hi == 0) {
        const char *name = cfg->name28;
        int tag = cfg->f2c;
        if (name == 0) {
            return false;
        }
        Registry_171e60 *reg = FUN_001d4c90();
        if (reg->FUN_001d35a0(name, "syncToLocator", tag) != 3 || !reg->FUN_001d19f0(f.buf, 0x400, 1)) {
            return false;
        }
        id.FUN_0027b040(f.buf);
        if (id.lo == 0 && id.hi == 0) {
            return false;
        }
    }
    Located *obj = DAT_004dd700->f28->FUN_001fc8c0(id.lo, id.hi);
    if (obj == 0) {
        return false;
    }
    f34 = obj->v9();
    f34 = f34 + cfg->f34;
    hulk_freg ang = timing->FUN_000354c0();
    f.d = FUN_00224fc0(f34, ang);
    int mode = cfg->mode30;
    if (mode == 2 && f.d < 0.0f)
        f.d = f.d + 6.2831855f;
    else if (mode == 1 && f.d > 0.0f)
        f.d = f.d - 6.2831855f;
    hulk_freg c14 = cfg->f14;
    hulk_freg x = c14 - cfg->v6();
    if (!(x <= 0.0f))
        f44 = f.d / x;
    else
        f44 = f.d / cfg->v7();

    V3_171e60 *pos = obj->v8(&f.tmp);
    v38.x = pos->x;
    v38.y = pos->y;
    v38.z = pos->z;
    f.tmp = cfg->v38;
    v38.FUN_00011220(&f.tmp);
    timing->anchor->FUN_00059a50(&f.p);
    hulk_freg nx = v38.x - f.p.x;
    hulk_freg ny = v38.y - f.p.y;
    hulk_freg nz = v38.z - f.p.z;
    v48.z = nz;
    v48.x = nx;
    v48.y = ny;
    hulk_freg c18 = cfg->f18;
    hulk_freg y = c18 - cfg->v6();
    if (!(y <= 0.0f))
        v48.FUN_00011140(1.0f / y);
    else
        v48.FUN_00011140(1.0f / cfg->v7());
    return true;
}
