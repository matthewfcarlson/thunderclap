// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 10/10)
// hulkfight::motion::SyncToLocatorAction::vfunc_5 @ 0x00175e00
extern "C" double sqrt(double);

struct V3 {
    float x, y, z;
};

struct Xform {
    char pad00[0x30];
    V3 pos;
    char pad3c[0x54 - 0x3c];
    float FUN_002220d0();
    void FUN_00221d20(float angle);
    void FUN_0022be40(const V3* p);
};

struct Joint {
    char pad00[0x18];
    Xform xf;
};

struct Timing {
};

struct Clock {
    Timing* FUN_00059a30();
};

struct Target {
    Clock* FUN_000592a0();
};

float __cdecl FUN_00224fc0(float from, float to);

class SyncToLocatorAction {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual bool vfunc_5(int skip, float dt);
    char pad04[0x20 - 4];
    Target* owner;
    char pad24[0x30 - 0x24];
    Joint* joint;
    float targetAngle;
    V3 goal;
    float rate;
    V3 vel;
};

bool SyncToLocatorAction::vfunc_5(int skip, float dt)
{
    if (owner == 0)
        return false;
    if (joint == 0)
        return false;
    if (skip != 0)
        return true;
    owner->FUN_000592a0()->FUN_00059a30();
    float step = dt * rate;
    float cur = joint->xf.FUN_002220d0();
    float diff = FUN_00224fc0(targetAngle, cur);
    union {
        float f;
        unsigned int u;
    } ad, as;
    ad.f = diff;
    ad.u &= 0x7fffffff;
    as.f = step;
    as.u &= 0x7fffffff;
    if (ad.f < as.f)
        cur = targetAngle;
    else
        cur = cur - step;
    joint->xf.FUN_00221d20(cur);
    V3 v = vel;
    double xv = (double)v.x * dt;
    float yv = v.y * dt;
    float zv = v.z * dt;
    Joint* j = joint;
    V3 p = j->xf.pos;
    double dx = goal.x - p.x;
    double dy = goal.y - p.y;
    double dz = goal.z - p.z;
    double distGoal = sqrt(dz * dz + dy * dy + dx * dx);
    double distStep = sqrt(zv * zv + yv * yv + xv * xv);
    V3 np;
    if (!(distStep >= distGoal)) {
        np.x = (float)(xv + p.x);
        np.y = p.y + yv;
        np.z = p.z + zv;
    } else {
        np = goal;
    }
    j->xf.FUN_0022be40(&np);
    return true;
}
