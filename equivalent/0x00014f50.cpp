// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// CMoveAddYAction::vfunc_7 @ 0x00014f50
struct Vec3 { float x, y, z; };

struct Target {
    void FUN_00035720(Vec3 *v);
};

struct Globals {
    Target *FUN_00059a30();
};

struct Table {
    Globals *FUN_00059a30();
};

struct Owner {
    Table *FUN_000592a0();
};

class Driver {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6();
    virtual float v7();
    char pad04[0x10];
    float f14;
};

class CMoveAddYAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual bool vfunc_7(float scale);
    virtual void vfunc_8();
    char pad04[0x18];
    Owner *owner;
    Driver *driver;
};

bool CMoveAddYAction::vfunc_7(float scale)
{
    Target *target = (Target *)owner->FUN_000592a0()->FUN_00059a30();
    float rate = driver->v7();
    if (rate <= 0.0f)
        return false;
    Vec3 v;
    v.x = 0.0f;
    v.y = 1.0f;
    v.z = 0.0f;
    float t = driver->f14 / rate * scale;
    v.x = 0.0f * t;
    v.y = t;
    v.z = 0.0f * t;
    target->FUN_00035720(&v);
    return true;
}
