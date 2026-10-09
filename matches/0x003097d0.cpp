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
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    char pad[0x138 - 4];
};
namespace physics {
class PhysicsJoint3D : public PhysicsJoint {
  public:
    void vfunc_2();
};
void PhysicsJoint3D::vfunc_2() {
    f1();
    *(int*)((char*)this + 0x140) = 0;
    *(int*)((char*)this + 0x13c) = 0;
    *(int*)((char*)this + 0x138) = 0;
    *(int*)((char*)this + 0x14c) = 0;
    *(int*)((char*)this + 0x148) = 0;
    *(int*)((char*)this + 0x144) = 0;
    *((char*)this + 0x150) = 1;
}
} // namespace physics