// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// physics::SimulatedObject::vfunc_15 @ 0x002f6170
#include "gen/physics.h"

namespace physics {
struct SimCGSValue_2f6170 {
    void *vtable;
    float value;
    unsigned int extra;
    void FUN_002ecf20(float v);
    void FUN_002ecca0();
};

}
float physics::SimulatedObject::vfunc_15() {
    SimCGSValue_2f6170 value;
    value.FUN_002ecf20(10.0f);
    float result = vfunc_14() / value.value;
    value.FUN_002ecca0();
    return result;
}
