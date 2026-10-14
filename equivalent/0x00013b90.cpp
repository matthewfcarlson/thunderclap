// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 11/12, incomplete)
// CJumpAction::vfunc_6 @ 0x00013b90
struct Vec3_13b90 {
    float x, y, z;
};

struct Pose {
    char data[1];
};

struct Transform_13b90 {
    void FUN_00221be0(const Pose *pose);
    void FUN_00221d20(float v);
};

struct ResourceName_13b90 {
    char data[12];
    void FUN_0027b040(const char *name);
};

class JointObject_13b90 {
public:
    virtual void vfunc_0();
    char pad04[4];
    ResourceName_13b90 name;
    unsigned int flags;
    Transform_13b90 transform;
    char rest[0x70 - 0x18 - sizeof(Transform_13b90)];
    JointObject_13b90 *FUN_002248f0(unsigned int id);
};

struct Scene_13b90 {
    char pad0[0x10];
    Pose pose;
    void FUN_00222890(JointObject_13b90 *obj, float a, int b, float c, float d, float e, float f);
};

struct Mount_13b90 {
    void FUN_00059a50(Vec3_13b90 *out);
};

struct Stats_13b90 {
    char pad0[0x10];
    Mount_13b90 *mount;
    char pad14[0x2064 - 0x14];
    Vec3_13b90 charge;
    float chargeTime;
    float FUN_0003ec00(int arg);
    void FUN_000354e0(float v);
};

struct Controller_13b90 {
    void FUN_001ec980(Stats_13b90 *stats, const char *name);
};

struct Manager_13b90 {
    void FUN_00099d20(struct Globals_13b90 *g, Stats_13b90 *s, float a, float b, float c);
};

struct Globals_13b90 {
    char pad0[8];
    Manager_13b90 *manager;
    char pad0c[0x34 - 0xc];
    Controller_13b90 *controller;
};

class Input_13b90 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual int vfunc_26();
    virtual void vfunc_27();
    virtual float vfunc_28();
    virtual float vfunc_29();
    virtual void vfunc_30();
    virtual char vfunc_31();
    float FUN_0006b540(float v);
    float FUN_00069210(float v);
    float FUN_000692c0(float v);
};

void *__fastcall FUN_000592a0(void *owner);
Stats_13b90 *__fastcall FUN_00059a30(void *x);
Scene_13b90 *__fastcall FUN_00059a40(void *x);
extern "C" float FUN_00224f10(Vec3_13b90 *v);
void *__cdecl FUN_00263ea0(unsigned int size);
extern Globals_13b90 *DAT_004dd700;

class CJumpAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual char vfunc_6(int arg);
    virtual void vfunc_7();
    virtual void vfunc_8();
    char pad04[0x18];
    void *owner;
    Input_13b90 *input;
    JointObject_13b90 *joint;
    float f28;
    float f2c;
    float f30;
};

char CJumpAction::vfunc_6(int arg)
{
    void *fighter = FUN_000592a0(owner);
    Stats_13b90 *stats = FUN_00059a30(fighter);
    Scene_13b90 *scene = FUN_00059a40(fighter);
    if (scene == 0)
        return 0;

    void *mem = FUN_00263ea0(0x70);
    JointObject_13b90 *obj = 0;
    if (mem)
        obj = ((JointObject_13b90 *)mem)->FUN_002248f0(0);
    joint = obj;

    obj->name.FUN_0027b040("jump");
    joint->vfunc_0();
    joint->transform.FUN_00221be0(&scene->pose);

    if (input->vfunc_31() && stats->chargeTime > 0.0f) {
        float t = FUN_00224f10(&stats->charge);
        joint->transform.FUN_00221d20(t);
        stats->FUN_000354e0(t);
    }

    int a = input->vfunc_26();
    float e1 = input->vfunc_28();
    float e2 = input->vfunc_29();
    scene->FUN_00222890(joint, -1.0f, a, 1.0f, e1, e2, -1.0f);

    float speed = stats->FUN_0003ec00(0);
    f28 = input->FUN_0006b540(speed);
    f2c = input->FUN_00069210(speed);
    f30 = input->FUN_000692c0(speed);

    Globals_13b90 *g = DAT_004dd700;
    g->manager->FUN_00099d20(g, stats, f2c, f28, f30);

    Vec3_13b90 out;
    stats->mount->FUN_00059a50(&out);
    if (!(speed < 1.0f) && out.y > 100.0f)
        g->controller->FUN_001ec980(stats, "StartChargedJump");
    return 1;
}
