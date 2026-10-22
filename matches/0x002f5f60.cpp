#include "gen/physics.h"

class Helper_2f5f60 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i(float*, float*, int);
};

float physics::PhysicsObject::vfunc_31() {
    float t[3];
    if (vfunc_11()) {
        (*(class Helper_2f5f60 * *)&this->f_10)->i((*(float (*)[3])&this->f_98), t, -1);
        return (t[1] * t[1] + (t[0] * t[0] + t[2] * t[2])) * this->f_40 * 0.5f;
    }
    return 0.0f;
}
