// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// physics::PhysicsJoint3D::vfunc_10 @ 0x0030c440
#include "decls/data/engine/physics.h"
#include "decls/data/game/hulkfight.h"

struct Vec3_30c440 {
    float x, y, z;
    void FUN_0022d110();
};


struct Matrix3_30c440 {
    // equiv-conv: FUN_0022c3b0 ecx stack stack
    void FUN_0022c3b0(Vec3_30c440 *in, Vec3_30c440 *out);
};

struct Chain3_30c440 {
    Matrix3_30c440 *FUN_0030f100();
};

struct Chain2_30c440 {
    Chain3_30c440 *FUN_0030edf0();
};

struct Skeleton {
    Chain2_30c440 *FUN_0030f490(int index);
};

struct Manager_30c440 {
    char pad0[0x208];
    Skeleton *skeleton;
    void FUN_00310490(int index, Vec3_30c440 *out, char flag);
};

namespace physics {

class PhysicsJoint {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void vfunc_10(void *arg);
};

class PhysicsJoint3D : public PhysicsJoint {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void vfunc_10(void *arg);
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();

    char pad04[8];
    int index;
    char pad10[8];
    Manager_30c440 *manager;
    char pad1c[0x7c];
    Vec3_30c440 axis;
    char pada4[0x58];
    Vec3_30c440 normal;

    void FUN_0030be90();
};

struct Frame_30c440 {
    Vec3_30c440 v;
    Vec3_30c440 w;
};

void PhysicsJoint3D::vfunc_10(void *arg)
{
    Frame_30c440 f;

    PhysicsJoint::vfunc_10(arg);
    manager->FUN_00310490(index, &f.v, 0);
    normal.x = f.v.y * axis.z - f.v.z * axis.y;
    normal.y = f.v.z * axis.x - f.v.x * axis.z;
    normal.z = f.v.x * axis.y - f.v.y * axis.x;
    normal.FUN_0022d110();

    if ((DAT_00555490 & 1) == 0) {
        DAT_00555490 |= 1;
        (*(Vec3_30c440*)&DAT_00555484).x = 0;
        (*(Vec3_30c440*)&DAT_00555484).y = 1.0f;
        (*(Vec3_30c440*)&DAT_00555484).z = 0;
    }
    manager->skeleton->FUN_0030f490(index)->FUN_0030edf0()->FUN_0030f100()->FUN_0022c3b0(((Vec3_30c440*)&DAT_00555484), &f.w);

    if (f.w.z * normal.z + f.w.y * normal.y + f.w.x * normal.x < 0.0f) {
        normal.x = normal.x * (*(float*)&DAT_003f3388);
        normal.y = normal.y * (*(float*)&DAT_003f3388);
        normal.z = normal.z * (*(float*)&DAT_003f3388);
    }
    FUN_0030be90();
    v25();
}

}
