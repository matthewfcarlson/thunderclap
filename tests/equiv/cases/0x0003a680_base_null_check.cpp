// STATUS: equivalent (tools/equiv.py level 3: 68 inputs, branch coverage 23/24, incomplete)
// FUN_0003a680 @ 0x0003a680
struct Pose {
    int FUN_00221c40();
};

struct Transform {
    void FUN_00221c60(int v);
};

class JointObject {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    char pad04[0x14];
    Transform transform;
    char rest[0x70 - 0x18 - sizeof(Transform)];
    JointObject *FUN_002248f0(unsigned int id);
};

struct Scene {
    char pad0[0x10];
    Pose pose;
    void FUN_00222970(JointObject *obj, int flag);
    void FUN_00222d70(JointObject *obj, float v);
    void FUN_00222890(JointObject *obj, float a, float b, float c, float d, float e, float f);
};

struct Matrix {
    float m[16];
    void FUN_0022b980();
};

struct SubObject {
    void FUN_00232240();
};

Scene *__fastcall FUN_00059a40(void *x);
void *__cdecl FUN_00263ea0(unsigned int size);

class Entity {
public:
    char pad00[0x10];
    void *owner;
    char pad14[0xb4 - 0x14];
    SubObject sub;
    char padb5[0x338 - 0xb5];
    Entity *target;
    int id;
    int idB;
    int idC;
    Matrix matrix;
    JointObject *joint;
    int f38c;
    Entity *prevTarget;
    void FUN_00037000();
    char SetTarget(Entity *t, int a, int b, int c, const Matrix *m, float e5, float e6, float e7);
};

char Entity::SetTarget(Entity *t, int a, int b, int c, const Matrix *m, float e5, float e6, float e7)
{
    Entity *old = target;
    target = t;
    prevTarget = old;
    Scene *scene = FUN_00059a40(owner);
    FUN_00037000();
    sub.FUN_00232240();

    if (target != 0) {
        id = a;
        idB = b;
        idC = c;
        if (m != 0)
            matrix = *m;
        else
            matrix.FUN_0022b980();

        if (scene != 0) {
            scene->FUN_00222970(joint, 0);
            void *mem = FUN_00263ea0(0x70);
            JointObject *obj = 0;
            if (mem)
                obj = ((JointObject *)mem)->FUN_002248f0(0);
            if (obj)
                obj->vfunc_0();
            if (joint)
                joint->vfunc_1();
            joint = obj;
            int v = scene->pose.FUN_00221c40();
            joint->transform.FUN_00221c60(v);
            scene->FUN_00222890(joint, -1.0f, e5, e6, e7, e7, -1.0f);
        }
    } else {
        id = 0xffff;
        idB = 0;
        idC = 0;
        matrix.FUN_0022b980();
        if (joint != 0)
            scene->FUN_00222d70(joint, e7);
        if (scene != 0)
            scene->FUN_00222970(joint, 0);
        if (joint != 0) {
            joint->vfunc_1();
            joint = 0;
        }
    }

    Entity *cur = target;
    if (prevTarget != cur) {
        f38c = 0;
        if (cur != 0)
            cur->f38c = 0;
    }
    return 1;
}
