#include "gen/physics.h"

extern int gSimVtable;
namespace physics {
struct SimCGSValue_2f6170 {
    void* vtable;
    float value;
    unsigned int extra;
    void Init(float);
    void Done();
};

} // namespace physics
hulk_freg physics::SimulatedObject::vfunc_15() {
    SimCGSValue_2f6170 value;
    value.Init(10.0f);
    float denom = value.value;
    float result = vfunc_14() / denom;
    value.vtable = &gSimVtable;
    value.Done();
    return result;
}
