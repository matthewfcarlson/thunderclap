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
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void vfunc_23();
};
class PhysicsJoint1D : public PhysicsJoint {
    char pad[0x108 - 4];

  public:
    float a;
    float b;
    void vfunc_23();
};
void PhysicsJoint1D::vfunc_23() {
    b = a + b;
}