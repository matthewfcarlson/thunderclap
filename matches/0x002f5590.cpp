// Same code shape as 0x0023d2e0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/physics.h"

namespace fight {
class Condition_2f5590 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
};
class Param_2f5590 {
  public:
    virtual void pvfunc_0();
    virtual void pvfunc_1();
};

} // namespace fight
bool physics::SimulatedObject::vfunc_24(hulk_intptr , hulk_intptr , int ) {
    return false;
}
