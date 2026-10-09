class IDollyControllerState {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual float vfunc_5(int);
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
};
class ControllerState : public IDollyControllerState {
  public:
    char pad[12];
    float* values;
    float vfunc_5(int index);
};
float ControllerState::vfunc_5(int index) {
    return values[index];
}