// STATUS: equivalent (tools/equiv.py level 3: 80 inputs, branch coverage 10/10)
// hulkfight::ai::MotionTargetAction::vfunc_5 @ 0x00116ad0
struct Vec3_116ad0 {
    float x, y, z;
    float FUN_0022d110();
};

void __cdecl FUN_00224d70(float angle, Vec3_116ad0 *axis);
float __cdecl FUN_00224f10(Vec3_116ad0 *v);

class RefTarget {
public:
    virtual void AddRef();
    virtual void Release();
    char pad4[0x3c];
    Vec3_116ad0 position;
};

struct Sensor_116ad0 {
    void FUN_00059a50(Vec3_116ad0 *out);
};

struct Actor_116ad0 {
    char pad0[0x10];
    Sensor_116ad0 *sensor;
    char pad14[0x328 - 0x14];
    RefTarget *target;
    char pad32c[0x2064 - 0x32c];
    Vec3_116ad0 aim;
    float aimExtra;
};

struct Body_116ad0 {
    Actor_116ad0 *FUN_00059a30();
};

struct Owner_116ad0 {
    Body_116ad0 *FUN_000592a0();
};

struct Pose {
    char pad0[0x14];
    float offset;
    Vec3_116ad0 dir;
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
    Owner_116ad0 *owner;
    RefTarget *current;
};

struct Frame_116ad0 {
    Vec3_116ad0 tmp;
    Vec3_116ad0 w;
    Vec3_116ad0 v;
    Vec3_116ad0 d;
};

bool MotionTargetAction::vfunc_5(int skip, int unused)
{
    if (skip)
        return true;
    if (!owner)
        return false;

    Actor_116ad0 *actor = owner->FUN_000592a0()->FUN_00059a30();
    RefTarget *t = actor->target;
    if (!t) {
        t = current;
        if (!t)
            return true;
    }
    Frame_116ad0 f;
    t->AddRef();
    if (current)
        current->Release();
    current = t;

    Vec3_116ad0 *pos = &t->position;
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
