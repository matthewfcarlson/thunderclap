// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// CMoveAddYAction::vfunc_7 @ 0x00014f50
struct Vec3_14f50 { float x, y, z; };

struct Target_14f50 {
    void FUN_00035720(Vec3_14f50 *v);
};

struct Globals_14f50 {
    Target_14f50 *FUN_00059a30();
};

struct Table_14f50 {
    Globals_14f50 *FUN_00059a30();
};

struct Owner_14f50 {
    Table_14f50 *FUN_000592a0();
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
    Owner_14f50 *owner;
    Driver *driver;
};

bool CMoveAddYAction::vfunc_7(float scale)
{
    Target_14f50 *target = (Target_14f50 *)owner->FUN_000592a0()->FUN_00059a30();
    float rate = driver->v7();
    if (rate <= 0.0f)
        return false;
    Vec3_14f50 v;
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
