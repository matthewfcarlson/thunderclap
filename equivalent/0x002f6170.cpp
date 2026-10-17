// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// physics::SimulatedObject::vfunc_15 @ 0x002f6170
namespace physics {
struct SimCGSValue {
    void *vtable;
    float value;
    unsigned int extra;
    void FUN_002ecf20(float v);
    void FUN_002ecca0();
};
struct SimulatedObject {
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2();
    virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5();
    virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8();
    virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual float vfunc_14();
    virtual float vfunc_15();
};
float SimulatedObject::vfunc_15() {
    SimCGSValue value;
    value.FUN_002ecf20(10.0f);
    float result = vfunc_14() / value.value;
    value.FUN_002ecca0();
    return result;
}
}
