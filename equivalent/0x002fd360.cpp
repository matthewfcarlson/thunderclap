// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// physics::SimStateArticulated::vfunc_14 @ 0x002fd360
// 0x002fd360: SimStateArticulated::vfunc_14: re-arm the articulation and remember the first active joint
namespace physics {

struct Joints {
    void vfunc0();
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
    virtual void Reset();
    int FUN_00306190(int index, int mode);
};

struct Body {
    char pad00[0x20];
    Joints* joints;
    int count;
    char pad28[0x28];
    char enabled;
    void FUN_003046f0(int enable);
};

class SimState {
public:
    virtual void v0();
    void vfunc_14(int arg);
};

class SimStateArticulated : public SimState {
public:
    char pad04[0x70];
    Body* body;
    char pad78[0x18];
    int activeJoint;
    void vfunc_14(int arg);
};

void SimStateArticulated::vfunc_14(int arg)
{
    SimState::vfunc_14(arg);

    Body* b = body;
    if (b->enabled) {
        b->FUN_003046f0(0);
        body->joints->Reset();
        body->FUN_003046f0(1);
    } else {
        b->joints->Reset();
    }

    b = body;
    activeJoint = 0;
    int n = b->count;
    for (int i = 0; i < n; ) {
        if (body->joints->FUN_00306190(i, 1) != 0) {
            activeJoint = i;
            break;
        }
        i++;
        n = body->count;
    }
}

}
