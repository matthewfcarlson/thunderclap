class ControllerState {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual float vfunc_4(int index);
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    char pad[8];
    float* values;
};
float ControllerState::vfunc_4(int index) {
    return values[index];
}