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
    virtual void f19(float*);
    char pad[0xfc - 4];
};
class PhysicsJoint1D : public PhysicsJoint {};
void PhysicsJoint::f19(float* p) {
    *(float*)((char*)this + 0x108) = *(float*)((char*)this + 0xfc) * p[0] +
                                     *(float*)((char*)this + 0x100) * p[1] +
                                     *(float*)((char*)this + 0x104) * p[2];
}