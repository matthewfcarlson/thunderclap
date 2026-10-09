class PhysicsJoint {
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
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void vfunc_18(float*, float*);
    char pad[0xe4];
    float value;
};
void PhysicsJoint::vfunc_18(float* a, float* b) {
    float x = value;
    b[0] = x * a[0];
    b[1] = x * a[1];
    b[2] = x * a[2];
}