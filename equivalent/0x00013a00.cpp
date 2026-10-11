// STATUS: equivalent (tools/equiv.py level 3: 71 inputs, branch coverage 10/10)
// CJointAction::vfunc_6 @ 0x00013a00
struct Vec3 {
    float x, y, z;
};

struct Quat {
    float x, y, z, w;
    void FUN_0022b220(float rx, float ry, float rz);
};

struct Transform {
    void FUN_0022be40(const Vec3 *pos);
    void FUN_00221cf0(const Quat *rot);
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

struct JointFinder {
    unsigned int FUN_0027b200(int a, int b);
};

struct Scene {
    JointFinder *FUN_002226b0();
    void FUN_00222890(JointObject *obj, float a, float b, float c, float d, float e, float f);
};

struct JointData {
    char pad0[0x18];
    int jointA;
    int jointB;
    unsigned char flag20;
    char pad21[3];
    Vec3 offset;
    unsigned char flag30;
    char pad31[3];
    Vec3 euler;
    float extentX;
    float extentY;
    float extentZ;
};

void *__fastcall FUN_000592a0(void *owner);
Scene *__fastcall FUN_00059a40(void *x);
void *__cdecl FUN_00263ea0(unsigned int size);

class CJointAction {
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
    JointData *data;
    JointObject *joint;
};

char CJointAction::vfunc_6(int arg)
{
    Vec3 pos;
    Quat rot;

    Scene *scene = FUN_00059a40(FUN_000592a0(owner));
    if (scene == 0)
        return 0;

    unsigned int id = scene->FUN_002226b0()->FUN_0027b200(data->jointA, data->jointB);
    if (id == 0xffff)
        return 0;

    void *mem = FUN_00263ea0(0x70);
    JointObject *obj = 0;
    if (mem)
        obj = ((JointObject *)mem)->FUN_002248f0(id);
    joint = obj;

    obj->name.FUN_0027b040("joint");
    joint->vfunc_0();

    unsigned int f = 0;
    if (data->flag20)
        f = 1;
    if (data->flag30)
        f |= 2;
    joint->flags = f;

    pos = data->offset;
    joint->transform.FUN_0022be40(&pos);

    rot.FUN_0022b220(data->euler.x, data->euler.y, data->euler.z);
    joint->transform.FUN_00221cf0(&rot);

    scene->FUN_00222890(joint, -1.0f, data->extentX, 1.0f, data->extentY, data->extentZ, -1.0f);
    return 1;
}
