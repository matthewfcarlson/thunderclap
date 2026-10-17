// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 4/4)
// physics::ArticulatedPhysicsObject::vfunc_27 @ 0x00310ad0
namespace physics {
struct Joint {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
};
struct ArticulatedPhysicsObject {
    char padding0[0x148];
    unsigned char resetFlag;
    char padding1[3];
    int values[6];
    char padding2[0x1fc-0x164];
    Joint **joints;
    void vfunc_27(int index);
};
void ArticulatedPhysicsObject::vfunc_27(int index) {
    if (index == -1) {
        values[0] = 0;
        values[1] = 0;
        values[2] = 0;
        values[3] = 0;
        values[4] = 0;
        values[5] = 0;
        resetFlag = 1;
    } else {
        Joint *joint = joints[index];
        if (joint) joint->vfunc_3();
    }
}
}