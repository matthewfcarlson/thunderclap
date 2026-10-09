class IControllerOutputPoint {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void vfunc_6(float);
};
class ControllerOutputPointXBox : public IControllerOutputPoint {
  public:
    char pad[0x0c - sizeof(void*)];
    float value;
    void vfunc_6(float);
};
void ControllerOutputPointXBox::vfunc_6(float x) {
    if (x < 0.0f)
        value = 0.0f;
    else if (x > 1.0f)
        value = 1.0f;
    else
        value = x;
}