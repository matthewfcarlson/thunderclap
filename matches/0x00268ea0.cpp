class ControllerInputPointXBox {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual float vfunc_9(unsigned int*);
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    char pad[4];
    float a;
    float b;
    float c;
    char pad2[4];
    int out;
};
float ControllerInputPointXBox::vfunc_9(unsigned int* p) {
    if (p)
        *p = out;
    return (c - b) * a + b;
}