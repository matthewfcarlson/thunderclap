// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 4/4)
// physics::ArticulatedPhysicsObject::vfunc_27 @ 0x00310ad0
#include "gen/physics.h"

namespace physics {
struct Joint {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
};

}
void physics::ArticulatedPhysicsObject::vfunc_27(int index) {
    if (index == -1) {
        (*(int (*)[6])&this->f_14c)[0] = 0;
        (*(int (*)[6])&this->f_14c)[1] = 0;
        (*(int (*)[6])&this->f_14c)[2] = 0;
        (*(int (*)[6])&this->f_14c)[3] = 0;
        (*(int (*)[6])&this->f_14c)[4] = 0;
        (*(int (*)[6])&this->f_14c)[5] = 0;
        this->f_148 = 1;
    } else {
        Joint *joint = (*(Joint ** *)&this->f_1fc)[index];
        if (joint) joint->vfunc_3();
    }
}
