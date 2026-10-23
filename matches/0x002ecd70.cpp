#include "gen/physics.h"

namespace physics {
class SimCGSValue_2ecd70 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1(float);
    virtual void vfunc_2();
    virtual void vfunc_3();
    float a;
    float b;
};
class SimUnits_2ecd70 {};

} // namespace physics
void physics::SimTime::vfunc_1(float x) {
    this->f_08 = x;
    this->f_04 = x;
}
