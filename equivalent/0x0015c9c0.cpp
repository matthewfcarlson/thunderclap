// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0015c9c0 @ 0x0015c9c0
extern char DAT_00415b00[];

struct Vec3_15c9c0 { float x, y, z; };
struct RefObj_15c9c0 {
    virtual void addRef();
    virtual void release();
};
struct Source_15c9c0 {
    char pad[0x74];
    Vec3_15c9c0 pos;
    Vec3_15c9c0 vel;
};

struct HeliLocomotionAction {
    int vptr;
    char pad04[0x18];
    Source_15c9c0 *f1c;
    RefObj_15c9c0 *f20;
    int f24, f28, f2c, f30, f34, f38;
    Vec3_15c9c0 pos;
    Vec3_15c9c0 vel;
    int f54, f58, f5c, f60, f64;
    void FUN_00232660();
    HeliLocomotionAction *FUN_0015c9c0(Source_15c9c0 *src, RefObj_15c9c0 *target);
};

HeliLocomotionAction *HeliLocomotionAction::FUN_0015c9c0(Source_15c9c0 *src, RefObj_15c9c0 *target)
{
    FUN_00232660();
    f1c = src;
    f20 = target;
    vptr = (int)DAT_00415b00;
    f24 = 0;
    f28 = 0;
    f2c = 0;
    f30 = 0;
    f34 = 0;
    f38 = 0;
    f54 = 0;
    f58 = 0;
    f5c = 0;
    f60 = 0;
    f64 = 0;
    f20->addRef();
    pos = f1c->pos;
    vel = f1c->vel;
    return this;
}
