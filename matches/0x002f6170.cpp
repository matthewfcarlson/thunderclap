extern int gSimVtable;
namespace physics {
struct SimCGSValue {
    void* vtable;
    float value;
    unsigned int extra;
    void Init(float);
    void Done();
};
class SimulatedObject {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual float vfunc_14();
    virtual float vfunc_15();
};
float SimulatedObject::vfunc_15() {
    SimCGSValue value;
    value.Init(10.0f);
    float denom = value.value;
    float result = vfunc_14() / denom;
    value.vtable = &gSimVtable;
    value.Done();
    return result;
}
} // namespace physics