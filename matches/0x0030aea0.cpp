#include "gen/physics.h"

namespace physics {
class PhysicsJoint_30aea0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
};

} // namespace physics
void physics::PhysicsJoint1D::vfunc_9(float x, float y) {
    (*(float *)&this->f_10) = x;
    (*(float *)&this->f_14) = y;
    if (y == x && y > 0.0f) {
        this->f_f8 = 0;
        (*(float *)&this->f_10) = -y;
        return;
    }
    this->f_f8 = 1;
}
