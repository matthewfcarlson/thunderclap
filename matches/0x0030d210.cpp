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
    virtual void vfunc_22(unsigned int*);
    char pad[0x114 - 4];
};
void PhysicsJoint::vfunc_22(unsigned int* out) {
    out[0] = *(unsigned int*)((char*)this + 0x114);
    out[1] = *(unsigned int*)((char*)this + 0x118);
    out[2] = *(unsigned int*)((char*)this + 0x11c);
}