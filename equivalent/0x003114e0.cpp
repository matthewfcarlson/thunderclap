// STATUS: equivalent (tools/equiv.py level 3: 74 inputs, branch coverage 19/20, incomplete)
// physics::ArticulatedPhysicsObject::vfunc_19 @ 0x003114e0
struct Vec3_3114e0 { float x, y, z; };

struct Shape_3114e0 {
    char pad00[0x6c];
    int state;
    char pad70[0x94 - 0x70];
    char frozen;
};

struct Joint_3114e0 {
    void FUN_0030bf70();
};

struct Solver_3114e0 {
    void FUN_0030a7b0(Vec3_3114e0 a, Vec3_3114e0 b);
    void FUN_0030a9d0(Vec3_3114e0 a, Vec3_3114e0 b, int flag);
};

struct Chain_3114e0 {
    char pad00[0x34];
    void FUN_002fd020(float* in, Vec3_3114e0* out);
};

extern char DAT_004d3388;

namespace physics {

class ArticulatedPhysicsObject;

class PhysicsObject {
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18();
    virtual void vfunc_19(int a, int b, int c);
};

class ArticulatedPhysicsObject : public PhysicsObject {
public:
    virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23();
    virtual void vfunc_24(); virtual void vfunc_25(); virtual void vfunc_26();
    virtual void vfunc_27(int a);
    char pad04[0x10 - 4];
    Shape_3114e0* shape;
    char pad14[0x114 - 0x14];
    Chain_3114e0 chain;
    char noChain;
    char pad149[3];
    Vec3_3114e0 anchor;
    float v158[3];
    char pad164[0x1f8 - 0x164];
    Solver_3114e0** solver;
    char pad1fc[0x214 - 0x1fc];
    int cur214;
    Joint_3114e0* joint;
    char flag21c;
    char done;
    char pad21e[0x234 - 0x21e];
    char enabled;
    void FUN_00310b30(ArticulatedPhysicsObject* who, int idx, int idx2);
    void vfunc_19(int a1, int a2, int a3);
};

void ArticulatedPhysicsObject::vfunc_19(int a1, int a2, int a3)
{
    if (done)
        return;
    if (shape->state != 1)
        vfunc_27(-1);
    if (!shape->frozen && a2 >= 0) {
        if (!DAT_004d3388 || !enabled)
            a1 &= ~0xff;
        FUN_00310b30(a3 >= 0 ? this : 0, a2, a3);
        if (joint) {
            joint->FUN_0030bf70();
        } else {
            Vec3_3114e0 v;
            v.x = 0.0f;
            v.y = 0.0f;
            v.z = 0.0f;
            if (!noChain)
                chain.FUN_002fd020(v158, &v);
            if (!(char)a1) {
                (*solver)->FUN_0030a7b0(anchor, v);
            } else {
                (*solver)->FUN_0030a9d0(anchor, v, 1);
            }
        }
        joint = 0;
        cur214 = 0;
        flag21c = 0;
    }
    PhysicsObject::vfunc_19(a1, -1, -1);
    done = 1;
}

}
