// STATUS: equivalent (tools/equiv.py level 3: 80 inputs, branch coverage 10/10)
// hulkfight::ai::MotionTargetAction::vfunc_5 @ 0x00116ad0
struct Vec3 {
    float x, y, z;
    float FUN_0022d110();
};

void __cdecl FUN_00224d70(float angle, Vec3 *axis);
float __cdecl FUN_00224f10(Vec3 *v);

class RefTarget {
public:
    virtual void AddRef();
    virtual void Release();
    char pad4[0x3c];
    Vec3 position;
};

struct Sensor {
    void FUN_00059a50(Vec3 *out);
};

struct Actor {
    char pad0[0x10];
    Sensor *sensor;
    char pad14[0x328 - 0x14];
    RefTarget *target;
    char pad32c[0x2064 - 0x32c];
    Vec3 aim;
    float aimExtra;
};

struct Body {
    Actor *FUN_00059a30();
};

struct Owner {
    Body *FUN_000592a0();
};

struct Pose {
    char pad0[0x14];
    float offset;
    Vec3 dir;
    float extra;
};

class MotionTargetAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual bool vfunc_5(int skip, int unused);
    char pad4[0x18];
    Pose *pose;
    Owner *owner;
    RefTarget *current;
};

struct Frame {
    Vec3 tmp;
    Vec3 w;
    Vec3 v;
    Vec3 d;
};

bool MotionTargetAction::vfunc_5(int skip, int unused)
{
    if (skip)
        return true;
    if (!owner)
        return false;

    Actor *actor = owner->FUN_000592a0()->FUN_00059a30();
    RefTarget *t = actor->target;
    if (!t) {
        t = current;
        if (!t)
            return true;
    }
    Frame f;
    t->AddRef();
    if (current)
        current->Release();
    current = t;

    Vec3 *pos = &t->position;
    f.v.x = pos->x;
    f.v.y = pos->y;
    f.v.z = pos->z;
    f.w.x = 0;
    f.w.y = 0;
    f.w.z = 0;
    actor->sensor->FUN_00059a50(&f.w);
    f.d.x = f.v.x - f.w.x;
    f.d.y = f.v.y - f.w.y;
    f.d.z = f.v.z - f.w.z;
    float heading = FUN_00224f10(&f.d);
    f.tmp = pose->dir;
    FUN_00224d70(heading + pose->offset, &f.tmp);
    f.tmp.FUN_0022d110();
    actor->aim.x = f.tmp.x;
    actor->aim.y = f.tmp.y;
    actor->aim.z = f.tmp.z;
    actor->aimExtra = pose->extra;
    return true;
}
