namespace physics {
class PhysicsJoint3D {
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
    virtual void vfunc_16(unsigned int* src, unsigned int* dst);
};
void PhysicsJoint3D::vfunc_16(unsigned int* src, unsigned int* dst) {
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}
} // namespace physics