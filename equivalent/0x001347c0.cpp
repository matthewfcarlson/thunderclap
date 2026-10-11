// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 9/10, incomplete)
// hulkfight::motion::BounceAction::vfunc_3 @ 0x001347c0
struct Vec3 { float x, y, z; };

struct Pose {
    char data[1];
};

struct Transform {
    void FUN_00221be0(const Pose *pose);
};

struct ResourceName {
    char data[12];
    void FUN_0027b040(const char *name);
};

class JointObject {
public:
    virtual void vfunc_0();
    char pad04[4];
    ResourceName name;
    unsigned int flags;
    Transform transform;
    char rest[0x70 - 0x18 - sizeof(Transform)];
    JointObject *FUN_002248f0(unsigned int id);
};

struct Scene {
    char pad0[0x10];
    Pose pose;
    void FUN_00222890(JointObject *obj, float a, float b, float c, float d, float e, float f);
};

struct Stats {
    float FUN_000354c0();
    void FUN_000356c0(Vec3 *out);
};

struct BounceData {
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

struct Globals;
struct Manager {
    void FUN_00099d20(Globals *g, Stats *s, float a, float b, float c);
};

struct Globals {
    char pad0[8];
    Manager *manager;
};

void *__fastcall FUN_000592a0(void *owner);
Stats *__fastcall FUN_00059a30(void *x);
Scene *__fastcall FUN_00059a40(void *x);
extern "C" void FUN_00224d70(float angle, Vec3 *v);
void *__cdecl FUN_00263ea0(unsigned int size);
extern Globals *DAT_004dd700;
extern float DAT_004abf64;
extern float DAT_004abf68;
extern float DAT_004abf6c;

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
    BounceData *data;
    void *owner;
    JointObject *joint;
    float f28;
    float f2c;
    float f30;
};

char BounceAction::vfunc_3(int a, int b)
{
    void *fighter = FUN_000592a0(owner);
    Stats *stats = FUN_00059a30(fighter);
    Scene *scene = FUN_00059a40(fighter);
    if (scene == 0)
        return 0;

    BounceData *d = data;
    float b28 = d->f28;
    float b2c = d->f2c;
    float b30 = d->f30;

    void *mem = FUN_00263ea0(0x70);
    JointObject *obj = 0;
    if (mem)
        obj = ((JointObject *)mem)->FUN_002248f0(0);
    joint = obj;

    obj->name.FUN_0027b040("bounce");
    joint->vfunc_0();
    joint->transform.FUN_00221be0(&scene->pose);
    scene->FUN_00222890(joint, -1.0f, b28, 1.0f, b2c, b30, -1.0f);

    Vec3 w;
    w.x = DAT_004abf64;
    w.y = DAT_004abf68;
    w.z = DAT_004abf6c;
    FUN_00224d70(stats->FUN_000354c0(), &w);

    Vec3 x;
    x.x = 0.0f;
    x.y = 0.0f;
    x.z = 0.0f;
    stats->FUN_000356c0(&x);

    d = data;
    float dot = w.z * x.z + w.y * x.y + x.x * w.x;
    f2c = dot;
    float lo = d->f20;
    if (dot < lo)
        f2c = lo;
    if (f2c < 0.0f)
        f2c = 0;
    float dur = d->f14;
    if (dur > 0.0f) {
        float twice = d->f18 + d->f18;
        f28 = twice / dur;
        f30 = twice / (dur * dur);
    }

    DAT_004dd700->manager->FUN_00099d20(DAT_004dd700, stats, f2c, f28, f30);
    return 1;
}

}}
