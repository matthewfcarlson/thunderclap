// STATUS: equivalent (tools/equiv.py level 3: 20011 inputs, branch coverage 10/10)
// hulkfight::motion::BounceAction::vfunc_3 @ 0x001347c0
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/hulkfight/motion.h"
struct Vec3_1347c0 { float x, y, z; };

struct Pose {
    char data[1];
};

struct Transform_1347c0 {
    void FUN_00221be0(const Pose *pose);
};

struct ResourceName_1347c0 {
    char data[12];
    void FUN_0027b040(const char *name);
};

class JointDriver_1347c0 {
public:
    virtual void vfunc_0();
    char pad04[4];
    ResourceName_1347c0 name;
    unsigned int flags;
    Transform_1347c0 transform;
    char rest[0x70 - 0x18 - sizeof(Transform_1347c0)];
    JointDriver_1347c0 *FUN_002248f0(unsigned int id);
};

struct Scene_1347c0 {
    char pad0[0x10];
    Pose pose;
    void FUN_00222890(JointDriver_1347c0 *obj, float a, float b, float c, float d, float e, float f);
};

struct Stats_1347c0 {
    float FUN_000354c0();
    void FUN_000356c0(Vec3_1347c0 *out);
};

struct BounceData_1347c0 {
    char pad0[0x14];
    float f14;
    float f18;
    char pad1c[4];
    float f20;
    char pad24[4];
    float f28;
    float f2c;
    float f30;
};

struct World;
struct Manager_1347c0 {
    void FUN_00099d20(World *g, Stats_1347c0 *s, float a, float b, float c);
};

struct World {
    char pad0[8];
    Manager_1347c0 *manager;
};

void *__fastcall FUN_000592a0(void *owner);
Stats_1347c0 *__fastcall FUN_00059a30(void *x);
Scene_1347c0 *__fastcall FUN_00059a40(void *x);
extern "C" void FUN_00224d70(float angle, Vec3_1347c0 *v);
void *__cdecl FUN_00263ea0(unsigned int size);

namespace hulkfight { namespace motion {

class BounceAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual char vfunc_3(int a, int b);
    virtual void vfunc_4();
    virtual void vfunc_5();
    char pad04[0x18];
    BounceData_1347c0 *data;
    void *owner;
    JointDriver_1347c0 *joint;
    float f28;
    float f2c;
    float f30;
};

char BounceAction::vfunc_3(int a, int b)
{
    void *fighter = FUN_000592a0(owner);
    Stats_1347c0 *stats = FUN_00059a30(fighter);
    Scene_1347c0 *scene = FUN_00059a40(fighter);
    if (scene == 0)
        return 0;

    BounceData_1347c0 *d = data;
    hulk_freg b28 = d->f28;
    hulk_freg b2c = d->f2c;
    hulk_freg b30 = d->f30;

    void *mem = FUN_00263ea0(0x70);
    JointDriver_1347c0 *obj = 0;
    if (mem)
        obj = ((JointDriver_1347c0 *)mem)->FUN_002248f0(0);
    joint = obj;

    obj->name.FUN_0027b040("bounce");
    joint->vfunc_0();
    joint->transform.FUN_00221be0(&scene->pose);
    scene->FUN_00222890(joint, -1.0f, b28, 1.0f, b2c, b30, -1.0f);

    Vec3_1347c0 w;
    w.x = (*(float*)&DAT_004abf64);
    w.y = (*(float*)((char*)&DAT_004abf64 + 4));
    w.z = (*(float*)((char*)&DAT_004abf64 + 8));
    FUN_00224d70(stats->FUN_000354c0(), &w);

    Vec3_1347c0 x;
    x.x = 0.0f;
    x.y = 0.0f;
    x.z = 0.0f;
    stats->FUN_000356c0(&x);

    d = data;
    hulk_freg dot = w.z * x.z + w.y * x.y + x.x * w.x;
    f2c = dot;
    hulk_freg lo = d->f20;
    if (dot < lo)
        f2c = lo;
    if (f2c < 0.0f)
        f2c = 0;
    hulk_freg dur = d->f14;
    if (dur > 0.0f) {
        hulk_freg twice = d->f18 + d->f18;
        f28 = twice / dur;
        f30 = twice / (dur * dur);
    }

    DAT_004dd700->manager->FUN_00099d20(DAT_004dd700, stats, f2c, f28, f30);
    return 1;
}

}}
