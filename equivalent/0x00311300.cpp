// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// physics::ArticulatedPhysicsObject::vfunc_20 @ 0x00311300
struct Mat_311300 {
    void FUN_002fd0a0();
    void FUN_002fd0c0(Mat_311300 *m);
};

class Part_311300 {
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
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13(int a, Mat_311300 *m);
    char pad04[0xef - 4];
    char enabled;             // 0xef
};

namespace physics {

class PhysicsObject {
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
    virtual void vfunc_20(int a, Mat_311300 *m, int c, int d, int e);
};

class ArticulatedPhysicsObject : public PhysicsObject {
public:
    virtual void vfunc_20(int a, Mat_311300 *m, int c, int index, int e);
    char pad04[0x40 - 4];
    float f40;                // 0x40
    char pad44[0x1fc - 0x44];
    Part_311300 **parts;             // 0x1fc
    char pad200[0x214 - 0x200];
    int f214;
    int f218;
    char f21c;
    void FUN_00310b30(int c, int index, int e);
};

void ArticulatedPhysicsObject::vfunc_20(int a, Mat_311300 *m, int c, int index, int e)
{
    if (f40 == 0.0f) {
        m->FUN_002fd0a0();
        return;
    }
    PhysicsObject::vfunc_20(a, m, c, -1, -1);
    if (index >= 0 && parts[index]->enabled) {
        m->FUN_002fd0c0(m);
        FUN_00310b30(c, index, e);
        parts[index]->v13(a, m);
        m->FUN_002fd0c0(m);
        f218 = 0;
        f214 = 0;
        f21c = 0;
    }
}

}
