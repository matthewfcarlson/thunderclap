// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// physics::SimulatedObject::vfunc_14 @ 0x002f60f0
namespace physics {
struct SimCGSValue {
    virtual void vfunc_0();
    float value;
    int extra;
    void FUN_002ecca0();
    void FUN_002ecf20(float);
    void FUN_002ecf40(float);
};
struct SimulatedObject {
    float vfunc_14();
};
float SimulatedObject::vfunc_14() {
    SimCGSValue numerator;
    numerator.FUN_002ecf20(0.1f);
    SimCGSValue denominator;
    denominator.FUN_002ecf40(1.0f);
    float a = numerator.value;
    float b = denominator.value;
    numerator.FUN_002ecca0();
    denominator.FUN_002ecca0();
    return a / b;
}
}